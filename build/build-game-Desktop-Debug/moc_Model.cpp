/****************************************************************************
** Meta object code from reading C++ file 'Model.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../code/game/model/Model.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Model.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Model_t {
    QByteArrayData data[12];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Model_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Model_t qt_meta_stringdata_Model = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Model"
QT_MOC_LITERAL(1, 6, 26), // "diamond_notification_model"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 2), // "id"
QT_MOC_LITERAL(4, 37, 29), // "lifting_platform_notification"
QT_MOC_LITERAL(5, 67, 3), // "pos"
QT_MOC_LITERAL(6, 71, 19), // "movable_item_status"
QT_MOC_LITERAL(7, 91, 6), // "status"
QT_MOC_LITERAL(8, 98, 26), // "trigger_lever_notification"
QT_MOC_LITERAL(9, 125, 5), // "angle"
QT_MOC_LITERAL(10, 131, 31), // "change_game_status_notification"
QT_MOC_LITERAL(11, 163, 10) // "GameStatus"

    },
    "Model\0diamond_notification_model\0\0id\0"
    "lifting_platform_notification\0pos\0"
    "movable_item_status\0status\0"
    "trigger_lever_notification\0angle\0"
    "change_game_status_notification\0"
    "GameStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Model[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    3,   37,    2, 0x06 /* Public */,
       8,    3,   44,    2, 0x06 /* Public */,
      10,    1,   51,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::QPointF, 0x80000000 | 6,    3,    5,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, 0x80000000 | 6,    3,    9,    7,
    QMetaType::Void, 0x80000000 | 11,    7,

       0        // eod
};

void Model::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Model *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->diamond_notification_model((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->lifting_platform_notification((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QPointF(*)>(_a[2])),(*reinterpret_cast< const movable_item_status(*)>(_a[3]))); break;
        case 2: _t->trigger_lever_notification((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2])),(*reinterpret_cast< const movable_item_status(*)>(_a[3]))); break;
        case 3: _t->change_game_status_notification((*reinterpret_cast< const GameStatus(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Model::*)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Model::diamond_notification_model)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Model::*)(const int & , const QPointF & , const movable_item_status & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Model::lifting_platform_notification)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Model::*)(const int & , const double & , const movable_item_status & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Model::trigger_lever_notification)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Model::*)(const GameStatus & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Model::change_game_status_notification)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Model::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Model.data,
    qt_meta_data_Model,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Model::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Model::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Model.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Model::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Model::diamond_notification_model(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Model::lifting_platform_notification(const int & _t1, const QPointF & _t2, const movable_item_status & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Model::trigger_lever_notification(const int & _t1, const double & _t2, const movable_item_status & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Model::change_game_status_notification(const GameStatus & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
