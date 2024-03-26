#ifndef HTTPREQUESTMANAGER_H
#define HTTPREQUESTMANAGER_H

#include "http-request_global.h"

#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QAuthenticator>
#include <QNetworkProxy>
#include <QJsonDocument>
#include <QTimer>
#include <QEventLoop>

#include "response/httpstubresponse.h"

class HTTPREQUEST_EXPORT HttpRequestManager : public QObject {
public:

    template<class StubResponse>
    StubResponse* get( const QString& baseUrl, const QStringList& paths, const int timeout = 30000 ) const {
        return get<StubResponse>( toUrl( baseUrl, paths ), timeout );
    };

    template<class StubResponse>
    StubResponse* get( const QString& url, const int timeout = 30000 ) const {

        qInfo() << "HttpRequestManager::get server ...";

        QByteArray data = {};

        QNetworkRequest request = QNetworkRequest( QUrl( url ) );
        request.setSslConfiguration( QSslConfiguration::defaultConfiguration() );

        QNetworkAccessManager networkManager;
        QNetworkReply* reply = networkManager.get( request );

        const HttpStatusCodeEnum status = awaitSync( timeout, reply, data );

        qInfo() << "HttpRequestManager::get [DATA]" << data;

        return toResponse<StubResponse>( data, status );
    };

private:
    template<class StubResponse>
    StubResponse* toResponse( const QByteArray& data, const HttpStatusCodeEnum status ) const {

        StubResponse* response = new StubResponse();
        QJsonDocument document = QJsonDocument::fromJson( data );

        HttpStubResponse* httpStubResponse = static_cast<HttpStubResponse*>( response );

        httpStubResponse->fromJson( document );
        httpStubResponse->setStatus( status );

        return response;

    };

    HttpStatusCodeEnum awaitSync( const int timeout, QNetworkReply* reply, QByteArray& data ) const;

    QString toUrl( const QString& base, const QStringList& paths ) const;
};

#endif // HTTPREQUESTMANAGER_H
