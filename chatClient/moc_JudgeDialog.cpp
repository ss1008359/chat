/****************************************************************************
** Meta object code from reading C++ file 'JudgeDialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "JudgeDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'JudgeDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JudgeDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,   12,   12,   12, 0x0a,
      40,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_JudgeDialog[] = {
    "JudgeDialog\0\0sendResult(bool)\0judgeOk()\0"
    "judgeCancel()\0"
};

void JudgeDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        JudgeDialog *_t = static_cast<JudgeDialog *>(_o);
        switch (_id) {
        case 0: _t->sendResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->judgeOk(); break;
        case 2: _t->judgeCancel(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData JudgeDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject JudgeDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_JudgeDialog,
      qt_meta_data_JudgeDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &JudgeDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *JudgeDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *JudgeDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JudgeDialog))
        return static_cast<void*>(const_cast< JudgeDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int JudgeDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void JudgeDialog::sendResult(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
