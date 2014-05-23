#include "PrivateServerWindow.h"

int PrivateServerWindow::port = 10000;

//void PrivateServerWindow::setName(QString &name)
//{
//    strName = name;
//}

//void PrivateServerWindow::setMessage(loginData *data)
//{
//    strIp = data->ip;
//    port = data->port;
//}

void PrivateServerWindow::getResult(bool re)
{
    this->result = re;
}

void PrivateServerWindow::buildServer()
{
    try {
        ownAddr.sin_port = htons(port);
        thAccept.server.addr = ownAddr;
        thAccept.strName = strName;
        thAccept.edtmsg = edtmsg;
        thAccept.init();
        thAccept.edtinfo = edtinfo;
        connect(&thAccept, SIGNAL(sigInfo(const QString&)),
                edtinfo, SLOT(append(const QString&)));
        thAccept.start();
        port++;
        connect(btnsend, SIGNAL(clicked()),
                &thAccept.privateSendMessage, SLOT(toMsgChat()));
        edtinfo->append(strName);
    }
    catch(ChatException e) {
         edtinfo->append(tr(e.what()));
    }
}

//响应enter事件
void PrivateServerWindow::keyPressEvent(QKeyEvent *e)
{
    switch(e->key()) {
        case Qt::Key_Return:
            btnsend->click();
            break;
        default:
            break;
    }
    update();

    return QWidget::keyPressEvent(e);
}

PrivateServerWindow::PrivateServerWindow(QWidget *p)
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
    this->setWindowTitle(tr("私聊客户端"));
    this->setCentralWidget(center);
    edtinfo->setReadOnly(true);
//    edtinfo->append(tr("欢迎使用聊天程序"));
    edtmsg->setFocus();
}
