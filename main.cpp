#include "proxytest.h"
#include <QtWidgets/QApplication>

//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ProxyTest w;
	w.show();
	return a.exec();
}

//-------------------------------------------------------------------------------------------------
