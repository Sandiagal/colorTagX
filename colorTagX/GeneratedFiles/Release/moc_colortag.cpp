/****************************************************************************
** Meta object code from reading C++ file 'colortag.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../colortag.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'colortag.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_colorTag_t {
    QByteArrayData data[14];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_colorTag_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_colorTag_t qt_meta_stringdata_colorTag = {
    {
QT_MOC_LITERAL(0, 0, 8), // "colorTag"
QT_MOC_LITERAL(1, 9, 6), // "inPath"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 9), // "barChoose"
QT_MOC_LITERAL(4, 27, 7), // "outPath"
QT_MOC_LITERAL(5, 35, 3), // "out"
QT_MOC_LITERAL(6, 39, 9), // "changeTag"
QT_MOC_LITERAL(7, 49, 9), // "barChange"
QT_MOC_LITERAL(8, 59, 9), // "XGradient"
QT_MOC_LITERAL(9, 69, 12), // "beliefChange"
QT_MOC_LITERAL(10, 82, 13), // "segmentChange"
QT_MOC_LITERAL(11, 96, 12), // "colorRefresh"
QT_MOC_LITERAL(12, 109, 15), // "beliefMinChange"
QT_MOC_LITERAL(13, 125, 15) // "beliefMaxChange"

    },
    "colorTag\0inPath\0\0barChoose\0outPath\0"
    "out\0changeTag\0barChange\0XGradient\0"
    "beliefChange\0segmentChange\0colorRefresh\0"
    "beliefMinChange\0beliefMaxChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_colorTag[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    3,   79,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    2,   88,    2, 0x08 /* Private */,
      11,    2,   93,    2, 0x08 /* Private */,
      12,    0,   98,    2, 0x08 /* Private */,
      13,    0,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8, QMetaType::QString, QMetaType::Int,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor, QMetaType::QPoint,    2,    2,
    QMetaType::Void, QMetaType::QColor, QMetaType::Float,    2,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void colorTag::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        colorTag *_t = static_cast<colorTag *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->inPath(); break;
        case 1: _t->barChoose(); break;
        case 2: _t->outPath(); break;
        case 3: _t->out(); break;
        case 4: _t->changeTag(); break;
        case 5: _t->barChange((*reinterpret_cast< XGradient(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->beliefChange(); break;
        case 7: _t->segmentChange(); break;
        case 8: _t->colorRefresh((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 9: _t->colorRefresh((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 10: _t->beliefMinChange(); break;
        case 11: _t->beliefMaxChange(); break;
        default: ;
        }
    }
}

const QMetaObject colorTag::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_colorTag.data,
      qt_meta_data_colorTag,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *colorTag::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *colorTag::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_colorTag.stringdata0))
        return static_cast<void*>(const_cast< colorTag*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int colorTag::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
