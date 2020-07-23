/****************************************************************************
** Meta object code from reading C++ file 'backend.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "backend.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'backend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Backend_t {
    QByteArrayData data[50];
    char stringdata0[665];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Backend_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Backend_t qt_meta_stringdata_Backend = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Backend"
QT_MOC_LITERAL(1, 8, 11), // "updateChart"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 16), // "QAbstractSeries*"
QT_MOC_LITERAL(4, 38, 11), // "chartSeries"
QT_MOC_LITERAL(5, 50, 8), // "floorNum"
QT_MOC_LITERAL(6, 59, 12), // "setAxisXTime"
QT_MOC_LITERAL(7, 72, 14), // "QDateTimeAxis*"
QT_MOC_LITERAL(8, 87, 4), // "axis"
QT_MOC_LITERAL(9, 92, 3), // "num"
QT_MOC_LITERAL(10, 96, 17), // "recieveSerialPort"
QT_MOC_LITERAL(11, 114, 9), // "timerSlot"
QT_MOC_LITERAL(12, 124, 14), // "setSensorsList"
QT_MOC_LITERAL(13, 139, 12), // "SensorsList*"
QT_MOC_LITERAL(14, 152, 11), // "sensorsList"
QT_MOC_LITERAL(15, 164, 19), // "setGroundMotionList"
QT_MOC_LITERAL(16, 184, 17), // "GroundMotionList*"
QT_MOC_LITERAL(17, 202, 8), // "tempList"
QT_MOC_LITERAL(18, 211, 20), // "setColibrateItemList"
QT_MOC_LITERAL(19, 232, 18), // "ColibrateItemList*"
QT_MOC_LITERAL(20, 251, 10), // "stopMoving"
QT_MOC_LITERAL(21, 262, 9), // "moveRight"
QT_MOC_LITERAL(22, 272, 8), // "moveLeft"
QT_MOC_LITERAL(23, 281, 8), // "readFile"
QT_MOC_LITERAL(24, 290, 13), // "fileDirectory"
QT_MOC_LITERAL(25, 304, 13), // "setSensorInfo"
QT_MOC_LITERAL(26, 318, 13), // "getMotorSpeed"
QT_MOC_LITERAL(27, 332, 12), // "getFloorData"
QT_MOC_LITERAL(28, 345, 11), // "getMaxValue"
QT_MOC_LITERAL(29, 357, 11), // "getMinValue"
QT_MOC_LITERAL(30, 369, 12), // "setFloorInfo"
QT_MOC_LITERAL(31, 382, 4), // "temp"
QT_MOC_LITERAL(32, 387, 12), // "getFloorInfo"
QT_MOC_LITERAL(33, 400, 11), // "setTimeStep"
QT_MOC_LITERAL(34, 412, 16), // "saveGroundMotion"
QT_MOC_LITERAL(35, 429, 18), // "removeGroundMotion"
QT_MOC_LITERAL(36, 448, 16), // "getGroundMotions"
QT_MOC_LITERAL(37, 465, 14), // "QList<QString>"
QT_MOC_LITERAL(38, 480, 20), // "getGroundMotionNames"
QT_MOC_LITERAL(39, 501, 23), // "setSelectedGroundMotion"
QT_MOC_LITERAL(40, 525, 12), // "sendFileData"
QT_MOC_LITERAL(41, 538, 5), // "index"
QT_MOC_LITERAL(42, 544, 13), // "runSimulation"
QT_MOC_LITERAL(43, 558, 15), // "getErrorMessage"
QT_MOC_LITERAL(44, 574, 15), // "visibleTimeAxis"
QT_MOC_LITERAL(45, 590, 9), // "colibrate"
QT_MOC_LITERAL(46, 600, 4), // "name"
QT_MOC_LITERAL(47, 605, 19), // "removeColibrateItem"
QT_MOC_LITERAL(48, 625, 18), // "getColibratesNames"
QT_MOC_LITERAL(49, 644, 20) // "setSelectedColibrate"

    },
    "Backend\0updateChart\0\0QAbstractSeries*\0"
    "chartSeries\0floorNum\0setAxisXTime\0"
    "QDateTimeAxis*\0axis\0num\0recieveSerialPort\0"
    "timerSlot\0setSensorsList\0SensorsList*\0"
    "sensorsList\0setGroundMotionList\0"
    "GroundMotionList*\0tempList\0"
    "setColibrateItemList\0ColibrateItemList*\0"
    "stopMoving\0moveRight\0moveLeft\0readFile\0"
    "fileDirectory\0setSensorInfo\0getMotorSpeed\0"
    "getFloorData\0getMaxValue\0getMinValue\0"
    "setFloorInfo\0temp\0getFloorInfo\0"
    "setTimeStep\0saveGroundMotion\0"
    "removeGroundMotion\0getGroundMotions\0"
    "QList<QString>\0getGroundMotionNames\0"
    "setSelectedGroundMotion\0sendFileData\0"
    "index\0runSimulation\0getErrorMessage\0"
    "visibleTimeAxis\0colibrate\0name\0"
    "removeColibrateItem\0getColibratesNames\0"
    "setSelectedColibrate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Backend[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,  174,    2, 0x0a /* Public */,
       6,    2,  179,    2, 0x0a /* Public */,
      10,    0,  184,    2, 0x08 /* Private */,
      11,    0,  185,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      12,    1,  186,    2, 0x02 /* Public */,
      15,    1,  189,    2, 0x02 /* Public */,
      18,    1,  192,    2, 0x02 /* Public */,
      20,    0,  195,    2, 0x02 /* Public */,
      21,    0,  196,    2, 0x02 /* Public */,
      22,    0,  197,    2, 0x02 /* Public */,
      23,    1,  198,    2, 0x02 /* Public */,
      25,    0,  201,    2, 0x02 /* Public */,
      26,    0,  202,    2, 0x02 /* Public */,
      27,    1,  203,    2, 0x02 /* Public */,
      28,    1,  206,    2, 0x02 /* Public */,
      29,    1,  209,    2, 0x02 /* Public */,
      30,    2,  212,    2, 0x02 /* Public */,
      32,    1,  217,    2, 0x02 /* Public */,
      33,    1,  220,    2, 0x02 /* Public */,
      34,    1,  223,    2, 0x02 /* Public */,
      35,    1,  226,    2, 0x02 /* Public */,
      36,    0,  229,    2, 0x02 /* Public */,
      38,    0,  230,    2, 0x02 /* Public */,
      39,    1,  231,    2, 0x02 /* Public */,
      40,    1,  234,    2, 0x02 /* Public */,
      42,    0,  237,    2, 0x02 /* Public */,
      43,    0,  238,    2, 0x02 /* Public */,
      44,    1,  239,    2, 0x02 /* Public */,
      45,    1,  242,    2, 0x02 /* Public */,
      47,    1,  245,    2, 0x02 /* Public */,
      48,    0,  248,    2, 0x02 /* Public */,
      49,    1,  249,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    8,    9,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 19,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Double, QMetaType::Int,    5,
    QMetaType::Int, QMetaType::Int,    5,
    QMetaType::Int, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    5,   31,
    QMetaType::QString, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Int, QMetaType::QString,   31,
    QMetaType::Void, QMetaType::QString,   31,
    0x80000000 | 37,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::Int,   31,
    QMetaType::Void, QMetaType::Int,   41,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString,   46,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::Int,   31,

       0        // eod
};

void Backend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Backend *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateChart((*reinterpret_cast< QAbstractSeries*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->setAxisXTime((*reinterpret_cast< QDateTimeAxis*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->recieveSerialPort(); break;
        case 3: _t->timerSlot(); break;
        case 4: _t->setSensorsList((*reinterpret_cast< SensorsList*(*)>(_a[1]))); break;
        case 5: _t->setGroundMotionList((*reinterpret_cast< GroundMotionList*(*)>(_a[1]))); break;
        case 6: _t->setColibrateItemList((*reinterpret_cast< ColibrateItemList*(*)>(_a[1]))); break;
        case 7: _t->stopMoving(); break;
        case 8: _t->moveRight(); break;
        case 9: _t->moveLeft(); break;
        case 10: _t->readFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->setSensorInfo(); break;
        case 12: { QString _r = _t->getMotorSpeed();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 13: { double _r = _t->getFloorData((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 14: { int _r = _t->getMaxValue((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 15: { int _r = _t->getMinValue((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 16: _t->setFloorInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 17: { QString _r = _t->getFloorInfo((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 18: _t->setTimeStep((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: { int _r = _t->saveGroundMotion((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 20: _t->removeGroundMotion((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: { QList<QString> _r = _t->getGroundMotions();
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 22: { QStringList _r = _t->getGroundMotionNames();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 23: _t->setSelectedGroundMotion((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->sendFileData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->runSimulation(); break;
        case 26: { QString _r = _t->getErrorMessage();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 27: _t->visibleTimeAxis((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->colibrate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 29: _t->removeColibrateItem((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 30: { QStringList _r = _t->getColibratesNames();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 31: _t->setSelectedColibrate((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSeries* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDateTimeAxis* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SensorsList* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GroundMotionList* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ColibrateItemList* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Backend::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Backend.data,
    qt_meta_data_Backend,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Backend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Backend::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Backend.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Backend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
