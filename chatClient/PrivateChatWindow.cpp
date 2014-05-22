#include "PrivateChatWindow.h"

void PrivateChatWindow::setName(QString &name)
{
    strName = name;
}

//void PrivateChatWindow::setMessage(loginData *data)
//{
//    strIp = data->ip;
//    port = data->port;
//}

//响应enter事件
void PrivateChatWindow::keyPressEvent(QKeyEvent *e)
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

void PrivateChatWindow::initClient()
{
    try {
        //初始化socket
        client.addr = realaddr;
        client.initSocket();
        //发送信息
        privateSendMessage.edtmsg = edtmsg;
        //privateSendMessage.edtinfo = edtinfo;
        privateSendMessage.name = strName;
        privateSendMessage.fd = client.fd;
        connect(&privateSendMessage, SIGNAL(sigInfo(const QString&)),
                edtinfo, SLOT(append(const QString&)));
        connect(btnsend, SIGNAL(clicked()),
                &privateSendMessage, SLOT(toMsgChat()));

        //接受信息线程
        thPrivateRecv.init();
        thPrivateRecv.fd = client.fd;
        connect(&thPrivateRecv, SIGNAL(sigInfo(const QString&)),
                edtinfo, SLOT(append(const QString&)));
        thPrivateRecv.start();
        edtinfo->append(tr("接受信息线程启动"));
        edtinfo->append("=============================");
    }
    catch(ChatException e) {
         edtinfo->append(tr("连接失败"));
    }
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
    this->setWindowTitle(tr("私聊客户端"));
    this->setCentralWidget(center);
    edtinfo->setReadOnly(true);
//    edtinfo->append(tr("欢迎使用聊天程序"));
    edtmsg->setFocus();
}
