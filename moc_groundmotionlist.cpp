/****************************************************************************
** Meta object code from reading C++ file 'groundmotionlist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "groundmotionlist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'groundmotionlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GroundMotionList_t {
    QByteArrayData data[14];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GroundMotionList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GroundMotionList_t qt_meta_stringdata_GroundMotionList = {
    {
QT_MOC_LITERAL(0, 0, 16), // "GroundMotionList"
QT_MOC_LITERAL(1, 17, 15), // "preItemAppended"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 16), // "postItemAppended"
QT_MOC_LITERAL(4, 51, 14), // "preItemRemoved"
QT_MOC_LITERAL(5, 66, 5), // "index"
QT_MOC_LITERAL(6, 72, 15), // "postItemRemoved"
QT_MOC_LITERAL(7, 88, 21), // "notifyInfoDataChanged"
QT_MOC_LITERAL(8, 110, 10), // "appendItem"
QT_MOC_LITERAL(9, 121, 12), // "GroundMotion"
QT_MOC_LITERAL(10, 134, 4), // "temp"
QT_MOC_LITERAL(11, 139, 10), // "removeItem"
QT_MOC_LITERAL(12, 150, 4), // "name"
QT_MOC_LITERAL(13, 155, 13) // "reRenderModel"

    },
    "GroundMotionList\0preItemAppended\0\0"
    "postItemAppended\0preItemRemoved\0index\0"
    "postItemRemoved\0notifyInfoDataChanged\0"
    "appendItem\0GroundMotion\0temp\0removeItem\0"
    "name\0reRenderModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GroundMotionList[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    1,   61,    2, 0x06 /* Public */,
       6,    0,   64,    2, 0x06 /* Public */,
       7,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   66,    2, 0x0a /* Public */,
      11,    1,   69,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      11,    1,   72,    2, 0x02 /* Public */,
      13,    0,   75,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Int,    5,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,

       0        // eod
};

void GroundMotionList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GroundMotionList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->preItemAppended(); break;
        case 1: _t->postItemAppended(); break;
        case 2: _t->preItemRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->postItemRemoved(); break;
        case 4: _t->notifyInfoDataChanged(); break;
        case 5: _t->appendItem((*reinterpret_cast< GroundMotion(*)>(_a[1]))); break;
        case 6: _t->removeItem((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->removeItem((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->reRenderModel(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GroundMotionList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GroundMotionList::preItemAppended)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GroundMotionList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GroundMotionList::postItemAppended)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GroundMotionList::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GroundMotionList::preItemRemoved)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GroundMotionList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GroundMotionList::postItemRemoved)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GroundMotionList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GroundMotionList::notifyInfoDataChanged)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GroundMotionList::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_GroundMotionList.data,
    qt_meta_data_GroundMotionList,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GroundMotionList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GroundMotionList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GroundMotionList.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GroundMotionList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void GroundMotionList::preItemAppended()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GroundMotionList::postItemAppended()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GroundMotionList::preItemRemoved(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GroundMotionList::postItemRemoved()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void GroundMotionList::notifyInfoDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
