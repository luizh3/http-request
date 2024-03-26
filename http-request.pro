QT -= gui

QT += network

TEMPLATE = lib
DEFINES += HTTPREQUEST_LIBRARY
INCLUDEPATH += $$PWD

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

CONFIG( debug, debug|release ) {
    DESTDIR = build/debug
}

CONFIG( release, debug|release ) {
    DESTDIR = build/release
}

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.u

unix {
    target.path = /usr/bin
    INSTALLS += target
}


