/****************************************************************************
** Meta object code from reading C++ file 'view.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../code/game/view/view.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_View_t {
    QByteArrayData data[14];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_View_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_View_t qt_meta_stringdata_View = {
    {
QT_MOC_LITERAL(0, 0, 4), // "View"
QT_MOC_LITERAL(1, 5, 12), // "pause_signal"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 10), // "GameStatus"
QT_MOC_LITERAL(4, 30, 6), // "status"
QT_MOC_LITERAL(5, 37, 26), // "react_diamond_notification"
QT_MOC_LITERAL(6, 64, 2), // "id"
QT_MOC_LITERAL(7, 67, 24), // "react_lever_notification"
QT_MOC_LITERAL(8, 92, 5), // "angle"
QT_MOC_LITERAL(9, 98, 19), // "movable_item_status"
QT_MOC_LITERAL(10, 118, 27), // "react_platform_notification"
QT_MOC_LITERAL(11, 146, 3), // "pos"
QT_MOC_LITERAL(12, 150, 24), // "react_game_status_change"
QT_MOC_LITERAL(13, 175, 4) // "move"

    },
    "View\0pause_signal\0\0GameStatus\0status\0"
    "react_diamond_notification\0id\0"
    "react_lever_notification\0angle\0"
    "movable_item_status\0react_platform_notification\0"
    "pos\0react_game_status_change\0move"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_View[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   47,    2, 0x0a /* Public */,
       7,    3,   50,    2, 0x0a /* Public */,
      10,    3,   57,    2, 0x0a /* Public */,
      12,    1,   64,    2, 0x0a /* Public */,
      13,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, 0x80000000 | 9,    6,    8,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QPointF, 0x80000000 | 9,    6,   11,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void View::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<View *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pause_signal((*reinterpret_cast< const GameStatus(*)>(_a[1]))); break;
        case 1: _t->react_diamond_notification((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->react_lever_notification((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2])),(*reinterpret_cast< const movable_item_status(*)>(_a[3]))); break;
        case 3: _t->react_platform_notification((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QPointF(*)>(_a[2])),(*reinterpret_cast< const movable_item_status(*)>(_a[3]))); break;
        case 4: _t->react_game_status_change((*reinterpret_cast< const GameStatus(*)>(_a[1]))); break;
        case 5: _t->move(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (View::*)(const GameStatus & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&View::pause_signal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject View::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_View.data,
    qt_meta_data_View,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *View::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *View::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_View.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int View::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void View::pause_signal(const GameStatus & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
