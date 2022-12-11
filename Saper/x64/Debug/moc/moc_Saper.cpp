/****************************************************************************
** Meta object code from reading C++ file 'Saper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Saper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Saper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Saper_t {
    QByteArrayData data[17];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Saper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Saper_t qt_meta_stringdata_Saper = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Saper"
QT_MOC_LITERAL(1, 6, 10), // "resetClick"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 11), // "setGeometry"
QT_MOC_LITERAL(4, 30, 13), // "createButtons"
QT_MOC_LITERAL(5, 44, 4), // "cols"
QT_MOC_LITERAL(6, 49, 4), // "rows"
QT_MOC_LITERAL(7, 54, 10), // "blockClick"
QT_MOC_LITERAL(8, 65, 6), // "Block*"
QT_MOC_LITERAL(9, 72, 1), // "b"
QT_MOC_LITERAL(10, 74, 14), // "blockLeftClick"
QT_MOC_LITERAL(11, 89, 9), // "showZeros"
QT_MOC_LITERAL(12, 99, 1), // "x"
QT_MOC_LITERAL(13, 101, 1), // "y"
QT_MOC_LITERAL(14, 103, 7), // "showAll"
QT_MOC_LITERAL(15, 111, 3), // "win"
QT_MOC_LITERAL(16, 115, 14) // "updateGametime"

    },
    "Saper\0resetClick\0\0setGeometry\0"
    "createButtons\0cols\0rows\0blockClick\0"
    "Block*\0b\0blockLeftClick\0showZeros\0x\0"
    "y\0showAll\0win\0updateGametime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Saper[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    2,   61,    2, 0x0a /* Public */,
       7,    1,   66,    2, 0x0a /* Public */,
      10,    1,   69,    2, 0x0a /* Public */,
      11,    2,   72,    2, 0x0a /* Public */,
      14,    0,   77,    2, 0x0a /* Public */,
      15,    0,   78,    2, 0x0a /* Public */,
      16,    0,   79,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Saper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Saper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->resetClick(); break;
        case 1: _t->setGeometry(); break;
        case 2: _t->createButtons((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->blockClick((*reinterpret_cast< Block*(*)>(_a[1]))); break;
        case 4: _t->blockLeftClick((*reinterpret_cast< Block*(*)>(_a[1]))); break;
        case 5: _t->showZeros((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->showAll(); break;
        case 7: _t->win(); break;
        case 8: _t->updateGametime(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Block* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Block* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Saper::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Saper.data,
    qt_meta_data_Saper,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Saper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Saper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Saper.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Saper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
