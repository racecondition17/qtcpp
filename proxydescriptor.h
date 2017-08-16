#ifndef __PROXYDESCRIPTOR_H__
#define __PROXYDESCRIPTOR_H__

#include <QString>
#include <QNetworkProxy>

//=================================================================================================
struct PROXYDESCRIPTOR
{
	QString HOST;
	unsigned short int PORT;
	QString USER;
	QString PASSWORD;
	QNetworkProxy::ProxyType TYPE;
};

//=================================================================================================

#endif
