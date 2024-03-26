#ifndef HTTPSTUBRESPONSE_H
#define HTTPSTUBRESPONSE_H

#include <QJsonDocument>

#include <http-request_global.h>

#include <status/httpstatuscodeenum.h>

class HTTPREQUEST_EXPORT HttpStubResponse {
public:
    HttpStubResponse();
    virtual ~HttpStubResponse() = default;
    virtual void fromJson( QJsonDocument& document ) = 0;

    HttpStatusCodeEnum status() const;
    void setStatus(HttpStatusCodeEnum newStatus);

    bool isSuccess() const;
private:
    bool isStatusCodeType( const QList<HttpStatusCodeEnum>& types ) const;

    HttpStatusCodeEnum _status;
};

#endif // HTTPSTUBRESPONSE_H
