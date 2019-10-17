/****************************************************************************
** Meta object code from reading C++ file 'coding_framework.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../coding_framework.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'coding_framework.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Coding_Framework_t {
    QByteArrayData data[14];
    char stringdata0[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Coding_Framework_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Coding_Framework_t qt_meta_stringdata_Coding_Framework = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Coding_Framework"
QT_MOC_LITERAL(1, 17, 17), // "on_KEY_UP_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 17), // "on_KEY_DN_clicked"
QT_MOC_LITERAL(4, 54, 17), // "on_KEY_LF_clicked"
QT_MOC_LITERAL(5, 72, 17), // "on_KEY_RT_clicked"
QT_MOC_LITERAL(6, 90, 17), // "on_KEY_OK_clicked"
QT_MOC_LITERAL(7, 108, 18), // "on_KEY_LUP_clicked"
QT_MOC_LITERAL(8, 127, 18), // "on_KEY_LDN_clicked"
QT_MOC_LITERAL(9, 146, 18), // "on_KEY_LLF_clicked"
QT_MOC_LITERAL(10, 165, 18), // "on_KEY_LRT_clicked"
QT_MOC_LITERAL(11, 184, 18), // "on_KEY_LOK_clicked"
QT_MOC_LITERAL(12, 203, 25), // "on_MainTab_currentChanged"
QT_MOC_LITERAL(13, 229, 3) // "tab"

    },
    "Coding_Framework\0on_KEY_UP_clicked\0\0"
    "on_KEY_DN_clicked\0on_KEY_LF_clicked\0"
    "on_KEY_RT_clicked\0on_KEY_OK_clicked\0"
    "on_KEY_LUP_clicked\0on_KEY_LDN_clicked\0"
    "on_KEY_LLF_clicked\0on_KEY_LRT_clicked\0"
    "on_KEY_LOK_clicked\0on_MainTab_currentChanged\0"
    "tab"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Coding_Framework[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a /* Public */,
       3,    0,   70,    2, 0x0a /* Public */,
       4,    0,   71,    2, 0x0a /* Public */,
       5,    0,   72,    2, 0x0a /* Public */,
       6,    0,   73,    2, 0x0a /* Public */,
       7,    0,   74,    2, 0x0a /* Public */,
       8,    0,   75,    2, 0x0a /* Public */,
       9,    0,   76,    2, 0x0a /* Public */,
      10,    0,   77,    2, 0x0a /* Public */,
      11,    0,   78,    2, 0x0a /* Public */,
      12,    1,   79,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void Coding_Framework::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Coding_Framework *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_KEY_UP_clicked(); break;
        case 1: _t->on_KEY_DN_clicked(); break;
        case 2: _t->on_KEY_LF_clicked(); break;
        case 3: _t->on_KEY_RT_clicked(); break;
        case 4: _t->on_KEY_OK_clicked(); break;
        case 5: _t->on_KEY_LUP_clicked(); break;
        case 6: _t->on_KEY_LDN_clicked(); break;
        case 7: _t->on_KEY_LLF_clicked(); break;
        case 8: _t->on_KEY_LRT_clicked(); break;
        case 9: _t->on_KEY_LOK_clicked(); break;
        case 10: _t->on_MainTab_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Coding_Framework::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Coding_Framework.data,
    qt_meta_data_Coding_Framework,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Coding_Framework::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Coding_Framework::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Coding_Framework.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Coding_Framework::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
