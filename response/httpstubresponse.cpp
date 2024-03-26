#include "httpstubresponse.h"

HttpStubResponse::HttpStubResponse() :
    _status( HttpStatusCodeEnum::NOT_FOUND ){}

HttpStatusCodeEnum HttpStubResponse::status() const {
    return _status;
}

void HttpStubResponse::setStatus( HttpStatusCodeEnum newStatus ) {
    _status = newStatus;
}

bool HttpStubResponse::isSuccess() const {
    return isStatusCodeType( { HttpStatusCodeEnum::SUCCESS } );
}

bool HttpStubResponse::isStatusCodeType( const QList<HttpStatusCodeEnum>& types ) const {
    return types.contains( _status );
}
