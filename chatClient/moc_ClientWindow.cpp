/****************************************************************************
** Meta object code from reading C++ file 'ClientWindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ClientWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClientWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ClientWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      29,   13,   13,   13, 0x0a,
      39,   13,   13,   13, 0x0a,
      52,   13,   13,   13, 0x0a,
      80,   13,   13,   13, 0x0a,
      91,   13,   13,   13, 0x0a,
     100,   13,   13,   13, 0x0a,
     123,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ClientWindow[] = {
    "ClientWindow\0\0oppositeUser()\0onStart()\0"
    "onShowUesr()\0onPrivateChat(sockaddr_in*)\0"
    "onRealIp()\0onExit()\0setMessage(loginData*)\0"
    "bulidServer(sockaddr_in*)\0"
};

void ClientWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ClientWindow *_t = static_cast<ClientWindow *>(_o);
        switch (_id) {
        case 0: _t->oppositeUser(); break;
        case 1: _t->onStart(); break;
        case 2: _t->onShowUesr(); break;
        case 3: _t->onPrivateChat((*reinterpret_cast< sockaddr_in*(*)>(_a[1]))); break;
        case 4: _t->onRealIp(); break;
        case 5: _t->onExit(); break;
        case 6: _t->setMessage((*reinterpret_cast< loginData*(*)>(_a[1]))); break;
        case 7: _t->bulidServer((*reinterpret_cast< sockaddr_in*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ClientWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ClientWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ClientWindow,
      qt_meta_data_ClientWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ClientWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ClientWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ClientWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClientWindow))
        return static_cast<void*>(const_cast< ClientWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ClientWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
