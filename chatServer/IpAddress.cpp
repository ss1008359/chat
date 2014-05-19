#include "IpAddress.h"
#include <QHBoxLayout>
#include <QMessageBox>
#include <QEvent>

IpAddressWidget::IpAddressWidget(QWidget *parent)
{
    m_Separator = " : ";
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

    QHBoxLayout *hlay = new QHBoxLayout;
    //hlay->setSpacing(0);
    for(int i=0; i<3; i++)
    {
        hlay->addWidget(m_SpinBox[i]);
        hlay->addWidget(m_Label[i]);
    }
    hlay->addWidget(m_SpinBox[3]);
    setLayout(hlay);

    btnok = new QPushButton(tr("OK"), this);
    /*
    QVBoxLayout *vlay = new QVBoxLayout(this);
    vlay->addLayout(hlay);
    vlay->addWidget(btnok);
    */
    btnok->move(100, 100);
    connect(btnok, SIGNAL(clicked()), this, SLOT(okButton()));
    setWindowTitle(tr("设置ip地址"));
    this->resize(300, 150);
    this->move((1366-300)/2, (768-150)/2);
}

IpAddressWidget::~IpAddressWidget()
{

}

//获取IP地址，如果该地址不合法，则返回空字符串
QString IpAddressWidget::getIpAddressString()
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

bool IpAddressWidget::eventFilter(QObject *object, QEvent *event)
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

void IpAddressWidget::okButton()
{
    QString ipAddress = this->getIpAddressString();
    if( ipAddress.isEmpty() ) {
        QMessageBox::warning( this, tr("Error"), tr("非法ip地址") );
    }
    else {
        QMessageBox::information(this, tr("ip地址"), ipAddress);
        close();
    }
}
