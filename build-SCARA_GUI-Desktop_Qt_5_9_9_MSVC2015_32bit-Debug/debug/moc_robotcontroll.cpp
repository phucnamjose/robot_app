/****************************************************************************
** Meta object code from reading C++ file 'robotcontroll.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SCARA_GUI/robotcontroll.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'robotcontroll.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RobotControll_t {
    QByteArrayData data[7];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RobotControll_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RobotControll_t qt_meta_stringdata_RobotControll = {
    {
QT_MOC_LITERAL(0, 0, 13), // "RobotControll"
QT_MOC_LITERAL(1, 14, 14), // "commandTimeOut"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 16), // "commandStartWork"
QT_MOC_LITERAL(4, 47, 15), // "commandWorkDone"
QT_MOC_LITERAL(5, 63, 11), // "commandSend"
QT_MOC_LITERAL(6, 75, 7) // "command"

    },
    "RobotControll\0commandTimeOut\0\0"
    "commandStartWork\0commandWorkDone\0"
    "commandSend\0command"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RobotControll[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    6,

       0        // eod
};

void RobotControll::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RobotControll *_t = static_cast<RobotControll *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->commandTimeOut(); break;
        case 1: _t->commandStartWork(); break;
        case 2: _t->commandWorkDone(); break;
        case 3: _t->commandSend((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (RobotControll::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotControll::commandTimeOut)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RobotControll::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotControll::commandStartWork)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (RobotControll::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotControll::commandWorkDone)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (RobotControll::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotControll::commandSend)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject RobotControll::staticMetaObject = {
    { &QSerialPort::staticMetaObject, qt_meta_stringdata_RobotControll.data,
      qt_meta_data_RobotControll,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RobotControll::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RobotControll::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RobotControll.stringdata0))
        return static_cast<void*>(this);
    return QSerialPort::qt_metacast(_clname);
}

int RobotControll::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSerialPort::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void RobotControll::commandTimeOut()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RobotControll::commandStartWork()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void RobotControll::commandWorkDone()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void RobotControll::commandSend(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
