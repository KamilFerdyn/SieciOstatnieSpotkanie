/****************************************************************************
** Meta object code from reading C++ file 'Manager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Manager.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN7ManagerE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN7ManagerE = QtMocHelpers::stringData(
    "Manager",
    "statusChanged",
    "",
    "status",
    "modeChanged",
    "isRegulator",
    "enableButtons",
    "enable",
    "dataReceivedChanged",
    "wykonajTakt",
    "setGenerator",
    "Sygnal",
    "typ",
    "std::vector<double>&",
    "ParametryGen",
    "setRegulatorPID",
    "ParametryPID",
    "setTrybPID",
    "Tryb",
    "setModelARX",
    "A",
    "B",
    "delay",
    "Z",
    "ResetSim",
    "ResetPID",
    "Symuluj",
    "std::vector<double>",
    "czas",
    "zapisz",
    "zaklucenia",
    "odczyt",
    "int&",
    "double&"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN7ManagerE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  104,    2, 0x06,    1 /* Public */,
       4,    1,  107,    2, 0x06,    3 /* Public */,
       6,    1,  110,    2, 0x06,    5 /* Public */,
       8,    1,  113,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,  116,    2, 0x0a,    9 /* Public */,
      10,    2,  117,    2, 0x0a,   10 /* Public */,
      15,    1,  122,    2, 0x0a,   13 /* Public */,
      17,    1,  125,    2, 0x0a,   15 /* Public */,
      19,    4,  128,    2, 0x0a,   17 /* Public */,
      19,    3,  137,    2, 0x2a,   22 /* Public | MethodCloned */,
      24,    0,  144,    2, 0x0a,   26 /* Public */,
      25,    0,  145,    2, 0x0a,   27 /* Public */,
      26,    1,  146,    2, 0x0a,   28 /* Public */,
      29,    6,  149,    2, 0x0a,   30 /* Public */,
      31,    6,  162,    2, 0x0a,   37 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 13,   12,   14,
    QMetaType::Void, 0x80000000 | 13,   16,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 13, QMetaType::Int, QMetaType::Double,   20,   21,   22,   23,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 13, QMetaType::Int,   20,   21,   22,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 27, QMetaType::Double,   28,
    QMetaType::Void, 0x80000000 | 27, 0x80000000 | 27, 0x80000000 | 27, QMetaType::Int, QMetaType::Double, 0x80000000 | 27,   16,   20,   21,   22,   30,   14,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 13, 0x80000000 | 13, 0x80000000 | 32, 0x80000000 | 33, 0x80000000 | 13,   16,   20,   21,   22,   30,   14,

       0        // eod
};

Q_CONSTINIT const QMetaObject Manager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN7ManagerE.offsetsAndSizes,
    qt_meta_data_ZN7ManagerE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN7ManagerE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Manager, std::true_type>,
        // method 'statusChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'modeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'enableButtons'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'dataReceivedChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'wykonajTakt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setGenerator'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Sygnal, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<double> &, std::false_type>,
        // method 'setRegulatorPID'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<double> &, std::false_type>,
        // method 'setTrybPID'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool, std::false_type>,
        // method 'setModelARX'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<double> &, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<double> &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'setModelARX'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<double> &, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<double> &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'ResetSim'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ResetPID'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Symuluj'
        QtPrivate::TypeAndForceComplete<std::vector<double>, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'zapisz'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<double> &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<double> &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<double> &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const double, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<double> &, std::false_type>,
        // method 'odczyt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<double> &, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<double> &, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<double> &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int &, std::false_type>,
        QtPrivate::TypeAndForceComplete<double &, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<double> &, std::false_type>
    >,
    nullptr
} };

void Manager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Manager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->statusChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->modeChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->enableButtons((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->dataReceivedChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->wykonajTakt(); break;
        case 5: _t->setGenerator((*reinterpret_cast< std::add_pointer_t<Sygnal>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::vector<double>&>>(_a[2]))); break;
        case 6: _t->setRegulatorPID((*reinterpret_cast< std::add_pointer_t<std::vector<double>&>>(_a[1]))); break;
        case 7: _t->setTrybPID((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->setModelARX((*reinterpret_cast< std::add_pointer_t<std::vector<double>&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::vector<double>&>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4]))); break;
        case 9: _t->setModelARX((*reinterpret_cast< std::add_pointer_t<std::vector<double>&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::vector<double>&>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 10: _t->ResetSim(); break;
        case 11: _t->ResetPID(); break;
        case 12: { std::vector<double> _r = _t->Symuluj((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::vector<double>*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->zapisz((*reinterpret_cast< std::add_pointer_t<std::vector<double>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::vector<double>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<std::vector<double>>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<std::vector<double>>>(_a[6]))); break;
        case 14: _t->odczyt((*reinterpret_cast< std::add_pointer_t<std::vector<double>&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::vector<double>&>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<std::vector<double>&>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int&>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double&>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<std::vector<double>&>>(_a[6]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (Manager::*)(const QString & );
            if (_q_method_type _q_method = &Manager::statusChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (Manager::*)(bool );
            if (_q_method_type _q_method = &Manager::modeChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (Manager::*)(bool );
            if (_q_method_type _q_method = &Manager::enableButtons; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (Manager::*)(bool );
            if (_q_method_type _q_method = &Manager::dataReceivedChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *Manager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Manager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN7ManagerE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Manager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Manager::statusChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Manager::modeChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Manager::enableButtons(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Manager::dataReceivedChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
