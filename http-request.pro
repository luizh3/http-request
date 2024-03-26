QT -= gui

QT += network

TEMPLATE = lib
DEFINES += HTTPREQUEST_LIBRARY

CONFIG += c++17

SOURCES += \
    httprequestmanager.cpp \
    response/httpstubresponse.cpp \
    status/httpstatuscodeenum.cpp

HEADERS += \
    http-request_global.h \
    httprequestmanager.h \
    response/httpstubresponse.h \
    status/httpstatuscodeenum.h

INCLUDEPATH += C:/Users/Luiz/Documents/FilmFlowWorkspace/http-request/

include($$PWD/../film-flow-generic.pri)
