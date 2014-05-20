#include <QApplication>
#include <QTextCodec>
#include "ServerWindows.h"
#include "IpAddress.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForTr(codec);
	ServerWindows w;
    IpAddressWidget ipWid;
    ipWid.show();

    QObject::connect(&ipWid, SIGNAL(strIp(const QString&)), &w, SLOT(getIp(const QString&)));

    if (ipWid.exec() == QDialog::Accepted) {
        w.show();
    }
    w.show();
//	QApplication::connect(w.actExit, SIGNAL(triggered()),
//						&app, SLOT(quit()));
	return app.exec();
}
