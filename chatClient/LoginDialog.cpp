#include "LoginDialog.h"
#include <QHBoxLayout>
#include <QMessageBox>
#include <QEvent>

//获取IP地址，如果该地址不合法，则返回空字符串
QString LoginDialog::getIpAddressString()
{
    QString ipAddress;
    for(int i=0; i<3; i++)
    {
        if( m_SpinBox[i]->text().isEmpty() )
        {
            ipAddress.clear();
            return ipAddress;
        }
        ipAddress += m_SpinBox[i]->text() + m_Separator;
    }
    ipAddress += m_SpinBox[3]->text();
    return ipAddress;
}

bool LoginDialog::eventFilter(QObject *object, QEvent *event)
{
    //如果object不是四个输入框，则返回
    int nowBox = -1;
    for(int i=0; i<4; i++)
    {
        if( object == m_SpinBox[i] )
            nowBox = i;
    }
    if( -1 == nowBox )
        return false;

    QSpinBox *spinBox = dynamic_cast<QSpinBox*>(object);

    //如果某个输入框得到了输入焦点，则将它们设为全选状态
    if( QEvent::FocusIn == event->type() )
    {
        spinBox->selectAll();
        return true;
    }
    //如果输入框内的字符为0，则清空该输入框（防止用户输入多个0）
    else if( QEvent::KeyPress == event->type() )
    {
        QString context = spinBox->text();
        if( "0" == context )
            spinBox->clear();
    }
    //如果输入框内的数字大于25，则输入焦点自动跳到下一格
    else if( QEvent::KeyRelease == event->type() )
    {
        int val = spinBox->value();
        if( spinBox->value() > 25 && nowBox < 3 )
        {
            m_SpinBox[nowBox+1]->setFocus();
        }
    }
    return false;
}

void LoginDialog::loginok()
{
    QString ipAddress = this->getIpAddressString();
    QString nameStr = letname->text();
    if( ipAddress.isEmpty() ) {
        QMessageBox::warning( this, tr("Error"), tr("非法ip地址") );
    }
    else if (nameStr.isEmpty()) {
        QMessageBox::warning(this, tr("Error"), tr("没有输入网名"));
    }
    else {
//        QMessageBox::information(this, tr("ip地址"), ipAddress);
        data.name = nameStr;
        data.ip = ipAddress;
        emit strMessage(&data);
        //emit strIp(ipAddress);
        accept();
    }
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
    m_Separator = ".";
    //四个数字的输入框，QSpinBox实现，范围是0~255，无“上下按钮”，文字居中
    //这里也可以用QLineEdit+QIntValidator实现，但个人觉得这种方法不好用
    for(int i=0; i<4; i++)
    {
        m_SpinBox[i] = new QSpinBox(this);
        m_SpinBox[i]->setRange(0, 255);
        m_SpinBox[i]->setButtonSymbols(QAbstractSpinBox::NoButtons);
        m_SpinBox[i]->setAlignment(Qt::AlignCenter);
        m_SpinBox[i]->setFixedWidth(40);
        m_SpinBox[i]->installEventFilter(this);
    }
    //四个输入框之间的分隔符
    for(int i=0; i<3; i++)
    {
        m_Label[i] = new QLabel(m_Separator, this);
        m_Label[i]->setFixedWidth(10);
        m_Label[i]->setAlignment(Qt::AlignCenter);
    }

    for (int i=0, j=0; i<3; i++, j+=45) {
        m_SpinBox[i]->move(165 + j, 125);
        m_Label[i]->move(202 + j, 135);
    }
    m_SpinBox[3]->move(300, 125);
//    QHBoxLayout *hlay = new QHBoxLayout;
//    //hlay->setSpacing(0);
//    for(int i=0; i<3; i++)
//    {
//        hlay->addWidget(m_SpinBox[i]);
//        hlay->addWidget(m_Label[i]);
//    }
//    hlay->addWidget(m_SpinBox[3]);
//    setLayout(hlay);

    //
    lblip = new QLabel(tr("服务器ip:"), this);
    lblname = new QLabel(tr("网名:"), this);
//    lbluser = new QLabel(tr("用户名:"), this);
//    lblpass = new QLabel(tr("密 码:"), this);
    letname = new QLineEdit(this);
//    letuser = new QLineEdit(this);
//    letpass = new QLineEdit(this);
//    letpass->setEchoMode(QLineEdit::Password);

    lblip->move(100,125);
    lblname->move(100, 50);
    letname->move(150, 50);
//    lbluser->move(100, 100);
//    letuser->move(200, 100);
//    lblpass->move(100, 150);
//    letpass->move(200, 150);

    //
    btnok = new QPushButton(tr("登录"), this);
    btncancel = new QPushButton(tr("退出"), this);
    btnok->move(75, 200);
    btncancel->move(225, 200);

    //
    connect(btnok, SIGNAL(clicked()), this, SLOT(loginok()));
    connect(btncancel, SIGNAL(clicked()), this, SLOT(logincancel()));
}
