/****************************************************************************
** Meta object code from reading C++ file 'colibrateitemlist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "colibrateitemlist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'colibrateitemlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ColibrateItemList_t {
    QByteArrayData data[14];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ColibrateItemList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ColibrateItemList_t qt_meta_stringdata_ColibrateItemList = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ColibrateItemList"
QT_MOC_LITERAL(1, 18, 15), // "preItemAppended"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 16), // "postItemAppended"
QT_MOC_LITERAL(4, 52, 14), // "preItemRemoved"
QT_MOC_LITERAL(5, 67, 5), // "index"
QT_MOC_LITERAL(6, 73, 15), // "postItemRemoved"
QT_MOC_LITERAL(7, 89, 21), // "notifyInfoDataChanged"
QT_MOC_LITERAL(8, 111, 10), // "appendItem"
QT_MOC_LITERAL(9, 122, 13), // "ColibrateItem"
QT_MOC_LITERAL(10, 136, 4), // "temp"
QT_MOC_LITERAL(11, 141, 10), // "removeItem"
QT_MOC_LITERAL(12, 152, 4), // "name"
QT_MOC_LITERAL(13, 157, 13) // "reRenderModel"

    },
    "ColibrateItemList\0preItemAppended\0\0"
    "postItemAppended\0preItemRemoved\0index\0"
    "postItemRemoved\0notifyInfoDataChanged\0"
    "appendItem\0ColibrateItem\0temp\0removeItem\0"
    "name\0reRenderModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ColibrateItemList[] = {

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

void ColibrateItemList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ColibrateItemList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->preItemAppended(); break;
        case 1: _t->postItemAppended(); break;
        case 2: _t->preItemRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->postItemRemoved(); break;
        case 4: _t->notifyInfoDataChanged(); break;
        case 5: _t->appendItem((*reinterpret_cast< ColibrateItem(*)>(_a[1]))); break;
        case 6: _t->removeItem((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->removeItem((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->reRenderModel(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ColibrateItemList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ColibrateItemList::preItemAppended)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ColibrateItemList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ColibrateItemList::postItemAppended)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ColibrateItemList::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ColibrateItemList::preItemRemoved)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ColibrateItemList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ColibrateItemList::postItemRemoved)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ColibrateItemList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ColibrateItemList::notifyInfoDataChanged)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ColibrateItemList::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ColibrateItemList.data,
    qt_meta_data_ColibrateItemList,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ColibrateItemList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ColibrateItemList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ColibrateItemList.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ColibrateItemList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ColibrateItemList::preItemAppended()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ColibrateItemList::postItemAppended()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ColibrateItemList::preItemRemoved(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ColibrateItemList::postItemRemoved()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ColibrateItemList::notifyInfoDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
