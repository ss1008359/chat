#include <QApplication>
#include <QTextCodec>
#include "ServerWindows.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	QTextCodec *codec = QTextCodec::codecForName("utf-8");
	QTextCodec::setCodecForTr(codec);
	ServerWindows w;
//	QApplication::connect(w.actExit, SIGNAL(triggered()),
//						&app, SLOT(quit()));
	return app.exec();
}
