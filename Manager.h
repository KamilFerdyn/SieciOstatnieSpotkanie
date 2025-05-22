#pragma once
#include <QFile>
#include <QMessageBox>
#include <QObject>
#include <QString>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include <QWidget>
#include "GenWartZadana.h"
#include "SprzezenieZwrotne.h"
#include <cassert>
#include <vector>

class Manager : public QObject
{
    Q_OBJECT

public:
    Manager()
        : QObject()
        , server(nullptr) // Musi być najpierw
        , serverSocket(nullptr)
        , clientSocket(nullptr)
        , gen_wart()
        , sprzezeniezwrotne()
        , dataReceived(false)
    {
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Manager::wykonajTakt);
    }
    ~Manager() {}

    void startTaktowanie()
    {
        timer->start(1000); // milisekundy
        emit statusChanged("Taktowanie jednostronne rozpoczęte.");
    }

    void stopTaktowanie()
    {
        timer->stop();
        emit statusChanged("Taktowanie jednostronne zatrzymane.");
    }

    void stopServer()
    {
        if (server) {
            server->close();
            serverSocket = nullptr;
            delete server;
            server = nullptr;
            emit statusChanged("Serwer zatrzymany.");
        }
    }

    void disconnectClient()
    {
        if (clientSocket) {
            clientSocket->disconnectFromHost();
            delete clientSocket;
            clientSocket = nullptr;
            emit statusChanged("Rozłączono z serwerem.");
        }
    }

    void sendMessage(const QString &message)
    {
        if (serverSocket) {
            serverSocket->write(message.toUtf8());
        } else if (clientSocket) {
            clientSocket->write(message.toUtf8());
        }
    }

    void sendParameters()
    {
        if (clientSocket && clientSocket->isOpen()) {
            QString parametry = "PID=1.0,0.1,0.01;ARX=1.0,0.5,0.1";
            clientSocket->write(parametry.toUtf8());
            qDebug() << "Wysłano parametry: " << parametry;
        }
    }

    void receiveParameters(const QString &parametry)
    {
        QStringList parts = parametry.split(";");
        QStringList pidParams = parts[0].split(",");
        QStringList arxParams = parts[1].split(",");

        // Ustaw PID
        std::vector<double> parametryPID = {pidParams[0].toDouble(),
                                            pidParams[1].toDouble(),
                                            pidParams[2].toDouble()};
        sprzezeniezwrotne.setPID(parametryPID);

        // Ustaw ARX
        std::vector<double> A = {arxParams[0].toDouble()};
        std::vector<double> B = {arxParams[1].toDouble()};
        int delay = arxParams[2].toInt();
        sprzezeniezwrotne.setARX(A, B, delay);
        qDebug() << "Odebrano i ustawiono parametry: " << parametry;
    }

    void startServer(int port)
    {
        if (server)
            return;

        server = new QTcpServer(this);

        connect(server, &QTcpServer::newConnection, this, [this]() {
            serverSocket = server->nextPendingConnection();

            // connect(serverSocket, &QTcpSocket::readyRead, this, [this]() {
            //     QByteArray data = serverSocket->readAll();
            //     qDebug() << "Data: " << data.toStdString();
            //     double sygnalSterujacy = QString(data).toDouble();

            //     qDebug() << "Otrzymano sygnał sterujący: " << sygnalSterujacy;

            //     double wartoscRegulowana = sprzezeniezwrotne.zwrocY(
            //         sygnalSterujacy);

            //     serverSocket->write(QString::number(wartoscRegulowana).toUtf8());
            //     qDebug() << "Wysłano wartość regulowaną: " << wartoscRegulowana;
            //     dataReceived = true;
            // });

            emit statusChanged("Połączono z regulatorem (klientem)!");
        });

        if (!server->listen(QHostAddress::Any, port)) {
            emit statusChanged("Nie udało się uruchomić serwera!");
        } else {
            emit statusChanged(QString("Serwer działa na porcie %1").arg(port));
        }
    }

    void connectToServer(const QString &address, int port)
    {
        if (clientSocket)
            return;

        clientSocket = new QTcpSocket(this);

        connect(clientSocket, &QTcpSocket::connected, this, [=]() {
            emit statusChanged("Połączono z obiektem (serwerem)!");
        });

        connect(clientSocket, &QTcpSocket::disconnected, this, [=]() {
            emit statusChanged("Rozłączono z serwerem.");
        });

        clientSocket->connectToHost(address, port);

        if (!clientSocket->waitForConnected(3000)) {
            emit statusChanged("Nie udało się połączyć z serwerem!");
        }
    }

    void switchMode(bool isNetworkMode)
    {
        emit modeChanged(isNetworkMode);
        qDebug() << "Tryb pracy: " << (isNetworkMode ? "Online" : "Offline");
    }

signals:
    void statusChanged(const QString &status);
    void modeChanged(bool isRegulator);
    void enableButtons(bool enable);
    void dataReceivedChanged(bool status);

public slots:
    void wykonajTakt()
    {
        qInfo() << __FUNCTION__;

        // sendMessage("Testowa wiadomość z klienta");

        if (dataReceived) {
            processResponseData();
            emit dataReceivedChanged(dataReceived);
            qDebug() << "Emit: Symulacja wyrabia";

        } else {
            usePreviousData();
            emit dataReceivedChanged(dataReceived);
            qDebug() << "Emit: Symulacja nie wyrabia";
        }

        dataReceived = false;
    }

    void setGenerator(Sygnal typ, std::vector<double> &ParametryGen)
    {
        gen_wart.setGen(typ, ParametryGen);
    }
    void setRegulatorPID(std::vector<double> &ParametryPID)
    {
        sprzezeniezwrotne.setPID(ParametryPID);
    }
    void setTrybPID(const bool Tryb) { sprzezeniezwrotne.setTrybPID(Tryb); }
    void setModelARX(std::vector<double> &A, std::vector<double> &B, int delay, double Z = 0.0)
    {
        sprzezeniezwrotne.setARX(A, B, delay, Z);
    }
    void ResetSim() { sprzezeniezwrotne.ResetSim(); }
    void ResetPID() { sprzezeniezwrotne.ResetPID(); }

    std::vector<double> Symuluj(double czas)
    {
        double wartZadana = gen_wart.GenerujSygnal(czas);

        if (clientSocket && clientSocket->isOpen()) {
            wyniki = sprzezeniezwrotne.SimPIDOnline(wartZadana);

            // Wyślij sygnał sterujący (np. z wyniki[5])
            double sygnalSterujacy = wyniki[5];
            QString daneString = QString::number(wartZadana) + "," + QString::number(sygnalSterujacy);
            QByteArray daneDoWyslania = daneString.toUtf8();
            clientSocket->write(daneDoWyslania);
            clientSocket->flush();
            qDebug() << "Symuluj: Wysłano wartosc zadana i sygnał sterujący: " << wartZadana << ", " << sygnalSterujacy;

            if (clientSocket->waitForReadyRead(1000)) {
                QByteArray data = clientSocket->readAll();
                double wartoscRegulowana = QString(data).toDouble();

                sprzezeniezwrotne.setRegulowana(wartoscRegulowana);
                wyniki[6] = wartoscRegulowana;

                qDebug() << "Symuluj: Otrzymano wartość regulowaną: " << wartoscRegulowana;
                dataReceived = true;
            }else {
                qDebug() << "Symuluj: Brak odpowiedzi z serwera.";
            }

            return wyniki;
        } else if(serverSocket && serverSocket->isOpen()){
            if(serverSocket->waitForReadyRead(1000)){
                QByteArray data = serverSocket->readAll();
                qDebug() << "Data: " << data.toStdString();

                QString daneString = QString::fromUtf8(data);
                QStringList lista = daneString.split(',');

                double odebranaZadana = lista[0].toDouble();
                double sygnalSterujacy = lista[1].toDouble();

                qDebug() << "Otrzymano sygnał sterujący: " << sygnalSterujacy;

                double wartoscRegulowana = sprzezeniezwrotne.zwrocY(
                    sygnalSterujacy);

                serverSocket->write(QString::number(wartoscRegulowana).toUtf8());
                qDebug() << "Wysłano wartość regulowaną: " << wartoscRegulowana;

                dataReceived = true;
                return {odebranaZadana,0.0,0.0,0.0,0.0,sygnalSterujacy, wartoscRegulowana};
            }else {
                qDebug() << "Brak danych od klienta";
                return {0.0,0.0,0.0,0.0,0.0,0.0,0.0};
            }


        }else{
            return sprzezeniezwrotne.SimUAR(wartZadana);
        }
    }

    void zapisz(const std::vector<double> &ParametryPID,
                const std::vector<double> &A,
                const std::vector<double> &B,
                const int delay,
                const double zaklucenia,
                const std::vector<double> &ParametryGen)
    {
        QString nazwaPliku = "Dane.txt";
        QFile plik(nazwaPliku);

        if (!plik.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "Nie udało się otworzyć pliku!";
            return;
        }

        QTextStream out(&plik);

        // Zapis PID:
        zapiszWiersz(out, ParametryPID);
        out << "\n";

        // Zapis ARX:
        zapiszWiersz(out, A);
        out << "|";
        zapiszWiersz(out, B);
        out << "|" << delay << "|" << zaklucenia << "\n";

        // Zapis Generatora:
        zapiszWiersz(out, ParametryGen);

        plik.close();
    }

    void odczyt(std::vector<double> &ParametryPID,
                std::vector<double> &A,
                std::vector<double> &B,
                int &delay,
                double &zaklucenia,
                std::vector<double> &ParametryGen)
    {
        QString nazwaPliku = "Dane.txt";
        QFile plik(nazwaPliku);

        if (!plik.exists()) {
            QMessageBox::critical(nullptr, "Błąd!", "Plik nie istnieje!");
            return;
        }

        plik.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&plik);

        odczytajWiersz(in, ParametryPID);

        QString line;
        in.readLineInto(&line);
        QStringList parts = line.split("|");

        odczytajWiersz(parts[0], A);
        odczytajWiersz(parts[1], B);

        delay = parts[2].toInt();
        zaklucenia = parts[3].toDouble();

        odczytajWiersz(in, ParametryGen);

        plik.close();
    }

private slots:


private:
    QTcpServer *server;
    QTcpSocket *serverSocket;
    QTcpSocket *clientSocket;
    SprzezenieZwrotne sprzezeniezwrotne;
    GenWartZadana gen_wart;
    QTimer *timer; // Timer do taktowania
    bool dataReceived;
    std::vector<double> wyniki = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    void processResponseData() { qInfo() << "Przetwarzanie odebranych danych..."; }

    void usePreviousData() { qInfo() << "Brak danych - użycie poprzedniej wartości."; }

    void zapiszWiersz(QTextStream &out, const std::vector<double> &vec)
    {
        for (size_t i = 0; i < vec.size(); ++i) {
            out << vec[i];
            if (i < vec.size() - 1) {
                out << ",";
            }
        }
    }
    void odczytajWiersz(QTextStream &in, std::vector<double> &vec)
    {
        QString line;
        in.readLineInto(&line);
        odczytajWiersz(line, vec);
    }

    void odczytajWiersz(const QString &line, std::vector<double> &vec)
    {
        vec.clear();
        QStringList numbers = line.split(",");
        for (const QString &num : numbers) {
            vec.push_back(num.toDouble());
        }
    }
};
