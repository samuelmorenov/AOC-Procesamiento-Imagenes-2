/****************************************************************************
** Meta object code from reading C++ file 'pracaoc.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pracaoc.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pracaoc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_pracAOC[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      34,    8,    8,    8, 0x0a,
      43,    8,    8,    8, 0x0a,
      53,    8,    8,    8, 0x0a,
      66,   63,    8,    8, 0x0a,
      93,   90,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_pracAOC[] = {
    "pracAOC\0\0paintEvent(QPaintEvent*)\0"
    "cargar()\0guardar()\0process()\0zM\0"
    "zoomMethodChanged(bool)\0nz\0"
    "changeScrollLimits(int)\0"
};

void pracAOC::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        pracAOC *_t = static_cast<pracAOC *>(_o);
        switch (_id) {
        case 0: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 1: _t->cargar(); break;
        case 2: _t->guardar(); break;
        case 3: _t->process(); break;
        case 4: _t->zoomMethodChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->changeScrollLimits((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData pracAOC::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject pracAOC::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_pracAOC,
      qt_meta_data_pracAOC, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &pracAOC::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *pracAOC::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *pracAOC::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_pracAOC))
        return static_cast<void*>(const_cast< pracAOC*>(this));
    return QWidget::qt_metacast(_clname);
}

int pracAOC::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
