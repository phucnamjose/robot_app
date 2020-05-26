/****************************************************************************
** Meta object code from reading C++ file 'robotcontroll.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SCARA_GUI/robotcontroll.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'robotcontroll.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RobotControll_t {
    QByteArrayData data[25];
    char stringdata0[241];
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
QT_MOC_LITERAL(3, 30, 16), // "commandWorkStart"
QT_MOC_LITERAL(4, 47, 1), // "x"
QT_MOC_LITERAL(5, 49, 1), // "y"
QT_MOC_LITERAL(6, 51, 1), // "z"
QT_MOC_LITERAL(7, 53, 4), // "roll"
QT_MOC_LITERAL(8, 58, 4), // "var0"
QT_MOC_LITERAL(9, 63, 4), // "var1"
QT_MOC_LITERAL(10, 68, 4), // "var2"
QT_MOC_LITERAL(11, 73, 4), // "var3"
QT_MOC_LITERAL(12, 78, 6), // "lenght"
QT_MOC_LITERAL(13, 85, 8), // "time_run"
QT_MOC_LITERAL(14, 94, 10), // "time_total"
QT_MOC_LITERAL(15, 105, 18), // "commandWorkRunning"
QT_MOC_LITERAL(16, 124, 15), // "commandWorkStop"
QT_MOC_LITERAL(17, 140, 7), // "repsond"
QT_MOC_LITERAL(18, 148, 15), // "commandWorkDone"
QT_MOC_LITERAL(19, 164, 11), // "commandSend"
QT_MOC_LITERAL(20, 176, 7), // "command"
QT_MOC_LITERAL(21, 184, 13), // "commandAccept"
QT_MOC_LITERAL(22, 198, 11), // "commandDeny"
QT_MOC_LITERAL(23, 210, 15), // "respondPosition"
QT_MOC_LITERAL(24, 226, 14) // "respondArrived"

    },
    "RobotControll\0commandTimeOut\0\0"
    "commandWorkStart\0x\0y\0z\0roll\0var0\0var1\0"
    "var2\0var3\0lenght\0time_run\0time_total\0"
    "commandWorkRunning\0commandWorkStop\0"
    "repsond\0commandWorkDone\0commandSend\0"
    "command\0commandAccept\0commandDeny\0"
    "respondPosition\0respondArrived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RobotControll[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,   11,   65,    2, 0x06 /* Public */,
      15,   11,   88,    2, 0x06 /* Public */,
      16,    1,  111,    2, 0x06 /* Public */,
      18,   11,  114,    2, 0x06 /* Public */,
      19,    1,  137,    2, 0x06 /* Public */,
      21,    1,  140,    2, 0x06 /* Public */,
      22,    1,  143,    2, 0x06 /* Public */,
      23,    1,  146,    2, 0x06 /* Public */,
      24,    1,  149,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    4,    5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    4,    5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
    QMetaType::Void, QMetaType::QByteArray,   17,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    4,    5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
    QMetaType::Void, QMetaType::QByteArray,   20,
    QMetaType::Void, QMetaType::QByteArray,   17,
    QMetaType::Void, QMetaType::QByteArray,   17,
    QMetaType::Void, QMetaType::QByteArray,   17,
    QMetaType::Void, QMetaType::QByteArray,   17,

       0        // eod
};

void RobotControll::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RobotControll *_t = static_cast<RobotControll *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->commandTimeOut(); break;
        case 1: _t->commandWorkStart((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])),(*reinterpret_cast< double(*)>(_a[8])),(*reinterpret_cast< double(*)>(_a[9])),(*reinterpret_cast< double(*)>(_a[10])),(*reinterpret_cast< double(*)>(_a[11]))); break;
        case 2: _t->commandWorkRunning((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])),(*reinterpret_cast< double(*)>(_a[8])),(*reinterpret_cast< double(*)>(_a[9])),(*reinterpret_cast< double(*)>(_a[10])),(*reinterpret_cast< double(*)>(_a[11]))); break;
        case 3: _t->commandWorkStop((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->commandWorkDone((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])),(*reinterpret_cast< double(*)>(_a[8])),(*reinterpret_cast< double(*)>(_a[9])),(*reinterpret_cast< double(*)>(_a[10])),(*reinterpret_cast< double(*)>(_a[11]))); break;
        case 5: _t->commandSend((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 6: _t->commandAccept((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: _t->commandDeny((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: _t->respondPosition((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 9: _t->respondArrived((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
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
            typedef void (RobotControll::*_t)(double , double , double , double , double , double , double , double , double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotControll::commandWorkStart)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (RobotControll::*_t)(double , double , double , double , double , double , double , double , double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotControll::commandWorkRunning)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (RobotControll::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotControll::commandWorkStop)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (RobotControll::*_t)(double , double , double , double , double , double , double , double , double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotControll::commandWorkDone)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (RobotControll::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotControll::commandSend)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (RobotControll::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotControll::commandAccept)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (RobotControll::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotControll::commandDeny)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (RobotControll::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotControll::respondPosition)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (RobotControll::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotControll::respondArrived)) {
                *result = 9;
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void RobotControll::commandTimeOut()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RobotControll::commandWorkStart(double _t1, double _t2, double _t3, double _t4, double _t5, double _t6, double _t7, double _t8, double _t9, double _t10, double _t11)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)), const_cast<void*>(reinterpret_cast<const void*>(&_t10)), const_cast<void*>(reinterpret_cast<const void*>(&_t11)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RobotControll::commandWorkRunning(double _t1, double _t2, double _t3, double _t4, double _t5, double _t6, double _t7, double _t8, double _t9, double _t10, double _t11)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)), const_cast<void*>(reinterpret_cast<const void*>(&_t10)), const_cast<void*>(reinterpret_cast<const void*>(&_t11)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RobotControll::commandWorkStop(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void RobotControll::commandWorkDone(double _t1, double _t2, double _t3, double _t4, double _t5, double _t6, double _t7, double _t8, double _t9, double _t10, double _t11)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)), const_cast<void*>(reinterpret_cast<const void*>(&_t10)), const_cast<void*>(reinterpret_cast<const void*>(&_t11)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void RobotControll::commandSend(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void RobotControll::commandAccept(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void RobotControll::commandDeny(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void RobotControll::respondPosition(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void RobotControll::respondArrived(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
