#include "httprequestmanager.h"

HttpStatusCodeEnum HttpRequestManager::awaitSync( const int timeout, QNetworkReply* reply, QByteArray& data ) const {

    QTimer timer;
    QEventLoop loop;

    QObject::connect( &timer, &QTimer::timeout, &loop, &QEventLoop::quit );
    QObject::connect( reply, &QNetworkReply::finished, &loop, &QEventLoop::quit );

    timer.start( timeout );
    loop.exec();

    if ( !timer.isActive() ) {

        qInfo() << "HttpRequestManager::awaitSync timeout na requisição";

        QObject::disconnect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

        reply->abort();

        return HttpStatusCodeEnum::TIMEOUT_ERROR;

    }

    timer.stop();

    if ( reply->error() != QNetworkReply::NoError ) {
        qInfo() << "HttpRequestManager::awaitSync erro request";
        return HttpStatusCodeEnum::NOT_FOUND;
    }

    const HttpStatusCodeEnum tpStatusCode = HttpStatusCodeEnum( reply->attribute( QNetworkRequest::HttpStatusCodeAttribute ).toInt() );

    data = reply->readAll();

    qInfo() << "HttpRequestManager::awaitSync [TP_STATUS_CODE]" << static_cast<int>( tpStatusCode );

    return tpStatusCode;

}

QString HttpRequestManager::toUrl(const QString &base, const QStringList& paths ) const {
    return QString("%0/%1").arg( base, paths.join("/") );
}

