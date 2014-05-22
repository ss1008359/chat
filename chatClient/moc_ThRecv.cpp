/****************************************************************************
** Meta object code from reading C++ file 'ThRecv.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ThRecv.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ThRecv.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ThRecv[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,
      25,    7,    7,    7, 0x05,
      47,    7,    7,    7, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ThRecv[] = {
    "ThRecv\0\0sigInfo(QString)\0request(sockaddr_in*)\0"
    "response(sockaddr_in*)\0"
};

void ThRecv::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ThRecv *_t = static_cast<ThRecv *>(_o);
        switch (_id) {
        case 0: _t->sigInfo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->request((*reinterpret_cast< sockaddr_in*(*)>(_a[1]))); break;
        case 2: _t->response((*reinterpret_cast< sockaddr_in*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ThRecv::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ThRecv::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ThRecv,
      qt_meta_data_ThRecv, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ThRecv::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ThRecv::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ThRecv::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThRecv))
        return static_cast<void*>(const_cast< ThRecv*>(this));
    return QThread::qt_metacast(_clname);
}

int ThRecv::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ThRecv::sigInfo(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ThRecv::request(sockaddr_in * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ThRecv::response(sockaddr_in * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
