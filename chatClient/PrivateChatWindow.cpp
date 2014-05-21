#include "PrivateChatWindow.h"

void PrivateChatWindow::setName(QString &name)
{
    strName = name;
}

void PrivateChatWindow::setMessage(loginData *data)
{
    strIp = data->ip;
    port = data->port;
}

PrivateChatWindow::PrivateChatWindow(QWidget *p)
{
    center=new QWidget(this);
    edtinfo=new QTextEdit(center);
    edtmsg=new QLineEdit(center);
    btnsend=new QPushButton(tr("发送"),center);

    vlay=new QVBoxLayout(center);
    vlay->addWidget(edtinfo);

    hlay=new QHBoxLayout();
    vlay->addLayout(hlay);

    hlay->addWidget(edtmsg);
    hlay->addWidget(btnsend);

    //初始化界面
    this->resize(800, 600);
    this->move((1366-800)/2, (768-600)/2);
    this->setWindowTitle(tr("聊天客户端"));
    this->setCentralWidget(center);
    edtinfo->setReadOnly(true);
    edtinfo->append(tr("欢迎使用聊天程序"));
    edtmsg->setFocus();
}
