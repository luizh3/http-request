#include "httprequestmanager.h"

QByteArray HttpRequestManager::awaitSync( const int timeout, QNetworkReply* reply, HttpStatusCodeEnum& status ) const {

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

        status = HttpStatusCodeEnum::TIMEOUT_ERROR;

    }

    timer.stop();

    status = HttpStatusCodeEnum( reply->attribute( QNetworkRequest::HttpStatusCodeAttribute ).toInt() );

    if ( reply->error() != QNetworkReply::NoError ) {
        qInfo() << "HttpRequestManager::awaitSync erro request";
        return {};
    }

    const QByteArray data = reply->readAll();

    qInfo() << "HttpRequestManager::awaitSync [STATUS]" << static_cast<int>( status ) << "[DATA]" << data;

    return data;

}

QString HttpRequestManager::toUrl(const QString &base, const QStringList& paths ) const {
    return QString("%0/%1").arg( base, paths.join("/") );
}

