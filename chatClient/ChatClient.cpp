#include <QApplication>
#include "ClientWindow.h"
#include "LoginDialog.h"
#include <QTextCodec>

int main(int args,char**argv)
{
	QApplication app(args,argv);

	//解决乱码问题
	QTextCodec *codec = QTextCodec::codecForName("utf-8");
	QTextCodec::setCodecForTr(codec);

    LoginDialog login;
    ClientWindow w;

    QObject::connect(&login, SIGNAL(strMessage(loginData*)), &w, SLOT(setMessage(loginData*)));

    login.show();
    if (login.exec() == QDialog::Accepted) {
        w.show();
    }

    return app.exec();
    return 0;
}
