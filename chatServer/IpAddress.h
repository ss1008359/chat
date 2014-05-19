#ifndef IPADDRESS_H
#define IPADDRESS_H

#include <QWidget>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>

class IpAddressWidget : public QWidget
{
    Q_OBJECT
private:
    QSpinBox *m_SpinBox[4];
    QLabel *m_Label[3];
    QString m_Separator;        //四个数字之间的分隔符
    QPushButton *btnok;
protected:
    bool eventFilter(QObject *object, QEvent *event);
public:
    IpAddressWidget(QWidget *parent = 0);
    ~IpAddressWidget();
    QString getIpAddressString();
    void setSeparator(const QString &separator);
public slots:
    void okButton();
};

#endif // IPADDRESS_H
