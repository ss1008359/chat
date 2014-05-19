#include "LoginDialog.h"

void LoginDialog::loginok()
{
    emit strName(letname->text());
    accept();
}

void LoginDialog::logincancel()
{
    reject();
}

LoginDialog::LoginDialog(QWidget *p)
{
    //初始化登陆界面
    this->resize(400, 300);
    this->move((1366-400)/2, (768-300)/2);
    this->setWindowTitle(tr("登陆界面"));

    //
    lblname = new QLabel(tr("网名:"), this);
    lbluser = new QLabel(tr("用户名:"), this);
    lblpass = new QLabel(tr("密 码:"), this);
    letname = new QLineEdit(this);
    letuser = new QLineEdit(this);
    letpass = new QLineEdit(this);
    letpass->setEchoMode(QLineEdit::Password);

    lblname->move(100, 50);
    letname->move(200, 50);
    lbluser->move(100, 100);
    letuser->move(200, 100);
    lblpass->move(100, 150);
    letpass->move(200, 150);

    //
    btnok = new QPushButton(tr("登录"), this);
    btncancel = new QPushButton(tr("退出"), this);
    btnok->move(125, 200);
    btncancel->move(225, 200);

    //
    connect(btnok, SIGNAL(clicked()), this, SLOT(loginok()));
    connect(btncancel, SIGNAL(clicked()), this, SLOT(logincancel()));
}
