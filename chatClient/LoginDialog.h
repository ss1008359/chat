#ifndef LOGINDLALOG_H
#define LOGINDLALOG_H

#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
//#include <QString>

class LoginDialog: public QDialog {
Q_OBJECT
public:
    LoginDialog(QWidget *p=NULL);
signals:
    void strName(const QString &str);
private:
    QLabel *lblname;
    QLabel *lbluser;
    QLabel *lblpass;
    QLineEdit *letname;
    QLineEdit *letuser;
    QLineEdit *letpass;
    QPushButton *btnok;
    QPushButton *btncancel;
   // QString str;
public slots:
    void loginok();
    void logincancel();
};

#endif // LOGINDLALOG_H
