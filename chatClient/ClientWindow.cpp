#include "ClientWindow.h"
#include "ChatException.h"
//#include <QWidget>
#include <Qt>
#include <QMessageBox>
#include <cstdio>

QString ClientWindow::getName(void)
{
    return this->strName;
}

void ClientWindow::setMessage(loginData* data)
{
    this->strName = data->name;
    this->strIp = data->ip;
    edtinfo->append(this->strName);
    edtinfo->append(this->strIp);
}

void ClientWindow::onStart()
{
    if(sendMessage.info != edtmsg) {
        try {
            //初始化socket
            const char *ip = strIp.toLocal8Bit();
            sprintf(client.ip, "%s", ip);
            client.port = 8888;
            client.initSocket();
            //发送信息
            sendMessage.init();
            sendMessage.cli.fd = client.fd;
            sprintf(sendMessage.cli.ip, "%s", client.ip);
            sendMessage.cli.port = client.port;
            sendMessage.info = edtmsg;
            sendMessage.name = strName;
            sendMessage.toMsgName();

            edtinfo->append(tr("客户端启动成功"));
            connect(btnsend, SIGNAL(clicked()),
                    &sendMessage, SLOT(toMsgChat()));
            //接受信息线程
            thRecv.init();
            thRecv.cli.fd = client.fd;
            sprintf(thRecv.cli.ip, "%s", client.ip);
            thRecv.cli.port = client.port;

            connect(&thRecv, SIGNAL(sigInfo(const QString&)),
                    edtinfo, SLOT(append(const QString&)));
            thRecv.start();
            sendMessage.toMsgPort();
            sleep(1);   //延迟1秒等待服务器返回本机信息（有待改进）
            localAddr = thRecv.localAddr;
//            printf("localport=%d", ntohs(localAddr.sin_port));
            edtinfo->append(tr("接受信息线程启动"));
            edtinfo->append("=============================");
        }
        catch(ChatException e) {
             edtinfo->append(tr("连接服务器失败"));
        }
    }
    else {
        edtinfo->append(tr("客户端已启动"));
    }
}

//显示在线用户信息
void ClientWindow::onShowUesr()
{
    if (sendMessage.info != edtmsg) {
        QMessageBox::warning( this, tr("Error"), tr("客户端未启动") );
    }
    else {
        sendMessage.toMsgUser();
    }
}

//创建私聊聊天窗口
void ClientWindow::onPrivateChat()
{
    if (sendMessage.info != edtmsg) {
        QMessageBox::warning( this, tr("Error"), tr("客户端未启动") );
    }
    else {
        prw = new PrivateChatWindow;
        ipaw = new IpAddressWidget;
        connect(ipaw, SIGNAL(strMessage(loginData*)), prw, SLOT(setMessage(loginData*)));
        ipaw->show();
        if (ipaw->exec() == QDialog::Accepted) {
            //prw->setName(this->getName());
            prw->show();
        }
    }
}

void ClientWindow::onClientServer()
{
    if (sendMessage.info != edtmsg) {
        QMessageBox::warning( this, tr("Error"), tr("客户端未启动") );
    }
    else {
        try {
            thClientAccept.server.addr = localAddr;
            thClientAccept.info = edtinfo;
            thClientAccept.init();
        }
        catch(ChatException e) {
            edtinfo->append(tr(e.what()));
        }
    }
}

void ClientWindow::onExit()
{
    this->close();
}

//响应enter事件
void ClientWindow::keyPressEvent(QKeyEvent *e)
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

ClientWindow::ClientWindow(QWidget*p)
{
    center=new QWidget(this);
    edtinfo=new QTextEdit(center);
    edtmsg=new QLineEdit(center);
    btnsend=new QPushButton(tr("发送"),center);
    /*
    btnsend->setShortcut(QKeySequence::InsertParagraphSeparator);
    btnsend->setShortcut(Qt::Key_Enter);
    btnsend->setDefault(true);
    */
    vlay=new QVBoxLayout(center);
    vlay->addWidget(edtinfo);
	
    hlay=new QHBoxLayout();
	vlay->addLayout(hlay);
	
	
	hlay->addWidget(edtmsg);
	hlay->addWidget(btnsend);

    //初始化菜单
    bar = new QMenuBar(this);
    chatMenu = new QMenu(tr("客户端"), bar);
    actStart = new QAction(tr("启动"), chatMenu);
    actShowOnlineUser = new QAction(tr("显示在线用户"), chatMenu);
    actPrivateChat = new QAction(tr("私聊"), chatMenu);
    actClientServer = new QAction(tr("客户端服务器启动"), chatMenu);
    actExit = new QAction(tr("结束"), chatMenu);

    chatMenu->addAction(actStart);
    chatMenu->addSeparator();
    chatMenu->addAction(actShowOnlineUser);
    chatMenu->addSeparator();
    chatMenu->addAction(actPrivateChat);
    chatMenu->addSeparator();
    chatMenu->addAction(actClientServer);
    chatMenu->addSeparator();
    chatMenu->addAction(actExit);

    bar->addMenu(chatMenu);
    this->setMenuBar(bar);

    //初始化界面
	this->resize(800, 600);
	this->move((1366-800)/2, (768-600)/2);
	this->setWindowTitle(tr("聊天客户端"));
    this->setCentralWidget(center);
    edtinfo->setReadOnly(true);
    edtinfo->append(tr("欢迎使用聊天程序"));
    edtmsg->setFocus();

    connect(actStart, SIGNAL(triggered()),
            this, SLOT(onStart()));
    connect(actShowOnlineUser, SIGNAL(triggered()),
            this, SLOT(onShowUesr()));
    connect(actPrivateChat, SIGNAL(triggered()),
            this, SLOT(onPrivateChat()));
    connect(actClientServer, SIGNAL(triggered()),
            this, SLOT(onClientServer()));
    connect(actExit, SIGNAL(triggered()),
            this, SLOT(onExit()));

    //this->show();
}
