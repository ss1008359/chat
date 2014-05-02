#include <QApplication>
#include "ClientWindow.h"
#include <QTextCodec>

int main(int args,char**argv)
{
	QApplication app(args,argv);

	//解决乱码问题
	QTextCodec *codec = QTextCodec::codecForName("utf-8");
	QTextCodec::setCodecForTr(codec);

	ClientWindow w;
	return app.exec();
}
