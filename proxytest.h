#ifndef __PROXYTEST_H__
#define __PROXYTEST_H__

#include <QtWidgets/QMainWindow>
#include "ui_proxytest.h"
#include "proxydescriptor.h"

//=================================================================================================
class ProxyTest : public QMainWindow
{
	Q_OBJECT

public:
	ProxyTest(QWidget *parent = 0);
	~ProxyTest();

private:
	Ui::ProxyTestClass ui;
	PROXYDESCRIPTOR _dscr;
	void getDataFromUi(PROXYDESCRIPTOR& dscr);
	QString proxyTypeToString(QNetworkProxy::ProxyType type);
	void printCurrentDescriptor(const PROXYDESCRIPTOR& dscr);
	QNetworkProxy::ProxyType proxyIndexToType(QComboBox *box);
	void printProxyCapabilities();

private slots:
	void Test();

public:
	void Info(const QString& msg);
};

//=================================================================================================

#endif // PROXYTEST_H

