#include <QNetworkProxy>
#include <QDebug>
#include <QComboBox>
#include <QStatusBar>
#include "proxytest.h"

//-------------------------------------------------------------------------------------------------
ProxyTest::ProxyTest(QWidget *parent)
	: QMainWindow(parent)
{
	//Base initialization
	_dscr.TYPE = QNetworkProxy::Socks5Proxy;
	_dscr.HOST = QString("127.0.0.1");
	_dscr.PASSWORD = QString("");
	_dscr.PORT = 9150;
	_dscr.USER = QString("");

	ui.setupUi(this);

	ui.proxyTypeBox->insertItem( 0, QString("No Proxy"), QNetworkProxy::NoProxy );
	ui.proxyTypeBox->insertItem( 1, QString("Default Proxy"), QNetworkProxy::DefaultProxy );
	ui.proxyTypeBox->insertItem( 2, QString("Socks 5 Proxy"), QNetworkProxy::Socks5Proxy );
	ui.proxyTypeBox->insertItem( 3, QString("Http Proxy"), QNetworkProxy::HttpProxy );
	ui.proxyTypeBox->insertItem( 4, QString("Http Caching Proxy"), QNetworkProxy::HttpCachingProxy );
	ui.proxyTypeBox->insertItem( 5, QString("Ftp Caching Proxy"), QNetworkProxy::FtpCachingProxy );

	ui.proxyTypeBox->setCurrentIndex(2);

	connect(ui.testButton, SIGNAL(clicked()), this, SLOT(Test()));
}



//-------------------------------------------------------------------------------------------------
ProxyTest::~ProxyTest()
{

}

//-------------------------------------------------------------------------------------------------
void ProxyTest::Test()
{
	Info("Pressed Test button");
	getDataFromUi(_dscr);
	printProxyCapabilities();
}

//-------------------------------------------------------------------------------------------------
void ProxyTest::Info(const QString& msg)
{
	qDebug() << msg;
	ui.statusBar->showMessage(msg, 5000);
	ui.textEdit->append(msg);
}

//-------------------------------------------------------------------------------------------------
void ProxyTest::getDataFromUi(PROXYDESCRIPTOR& dscr)
{
	printCurrentDescriptor(dscr);
	
	dscr.TYPE = proxyIndexToType(ui.proxyTypeBox);
	dscr.HOST = ui.proxyAddressEdit->text();
	dscr.PORT = ui.proxyPortEdit->text().toUInt();
	dscr.USER = ui.proxyUserEdit->text();
	dscr.PASSWORD = ui.proxyPasswordEdit->text();

	printCurrentDescriptor(dscr);
}

//-------------------------------------------------------------------------------------------------
QString ProxyTest::proxyTypeToString(QNetworkProxy::ProxyType type)
{
	QString res;

	switch (type)
	{
		case QNetworkProxy::NoProxy:
			res = QString("No Proxy");
			break;
		case QNetworkProxy::DefaultProxy:
			res = QString("Default Proxy");
			break;
		case QNetworkProxy::Socks5Proxy:
			res = QString("SOCKS 5 Proxy");
			break;
		case QNetworkProxy::HttpProxy:
			res = QString("HTTP Proxy");
			break;
		case QNetworkProxy::HttpCachingProxy:
			res = QString("HTTP Caching Proxy");
			break;
		case QNetworkProxy::FtpCachingProxy:
			res = QString("FTP Caching Proxy");
			break;
	default:
		res = QString("Unknown proxy type");
		break;
	}

	return res;
}

//-------------------------------------------------------------------------------------------------
void ProxyTest::printCurrentDescriptor(const PROXYDESCRIPTOR& dscr)
{
	Info("<<<___PRINT DESCRIPTOR: ");
	Info(proxyTypeToString(dscr.TYPE));
	Info(QString("HOST = %1").arg(dscr.HOST));
	Info(QString("PORT = %1").arg(dscr.PORT));
	Info(QString("USER = %1").arg(dscr.USER));
	Info(QString("PASSWORD = %1").arg(dscr.PASSWORD));
	Info(">>>___END OF DESCRIPTOR___>>>");
}

//-------------------------------------------------------------------------------------------------
QNetworkProxy::ProxyType ProxyTest::proxyIndexToType(QComboBox *box)
{
	QNetworkProxy::ProxyType res = QNetworkProxy::NoProxy;

	switch (box->currentIndex())
	{
	case 0:
		res = QNetworkProxy::NoProxy;
		break;
	case 1:
		res = QNetworkProxy::DefaultProxy;
		break;
	case 2:
		res = QNetworkProxy::Socks5Proxy;
		break;
	case 3:
		res = QNetworkProxy::HttpProxy;
		break;
	case 4:
		res = QNetworkProxy::HttpCachingProxy;
		break;
	case 5:
		res = QNetworkProxy::FtpCachingProxy;
		break;
	default:
		res = QNetworkProxy::DefaultProxy;
		break;
	}

	return res;
}

//-------------------------------------------------------------------------------------------------
