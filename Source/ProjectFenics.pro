QT       += core gui concurrent opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Scheme/Oblique/File/Read/schemeobliquefilereadfbd.cpp \
    Scheme/Oblique/File/Read/schemeobliquefilereadpfco.cpp \
    Scheme/Oblique/File/Read/schemeobliquefilereadrnx.cpp \
    Scheme/Oblique/File/Setting/schemeobliquefilesetting.cpp \
    Scheme/Oblique/File/Write/schemeobliquefilewritepfco.cpp \
    Scheme/Oblique/Satellite/History/event.cpp \
    Scheme/Oblique/Satellite/History/eventabstractschemechartscenedirectionnode.cpp \
    Scheme/Oblique/Satellite/History/eventabstractschemechartscenedirections.cpp \
    Scheme/Oblique/Satellite/History/eventabstractschemechartscenesetcolorthread.cpp \
    Scheme/Oblique/Satellite/schemeobliquesatellitehistory.cpp \
    Scheme/Oblique/Widget/CreateScheme/schemeobliquewidgetcreatescheme.cpp \
    Scheme/Oblique/Widget/EditDirectionForNewNode/schemeobliquewidgeteditdirectionfornewnodescene.cpp \
    Scheme/Oblique/Widget/EditDirectionForNewNode/schemeobliquewidgeteditdirectionfornewnodeview.cpp \
    Scheme/Oblique/Chart/schemeobliquechartscene.cpp \
    Scheme/Oblique/Chart/schemeobliquechartview.cpp \
    Scheme/Oblique/Object/schemeobliqueobjectnode.cpp \
    Scheme/Oblique/Object/schemeobliqueobjectpart.cpp \
    Scheme/Oblique/Satellite/schemeobliquesatellitecolors.cpp \
    Scheme/Oblique/Satellite/schemeobliquesatelliteconnects.cpp \
    Scheme/Oblique/Satellite/schemeobliquesatelliteinfos.cpp \
    Scheme/Oblique/Satellite/schemeobliquesatellitenodes.cpp \
    Scheme/Oblique/Satellite/schemeobliquesatelliteparts.cpp \
    editdirectionfornewnodewindow.cpp \
    fileread.cpp \
    filewrite.cpp \
    tabwidget.cpp \
    mainwindow.cpp \
    main.cpp \

HEADERS += \
    Abstract/abstractscheme.h \
    Abstract/abstractschemechartscene.h \
    Abstract/abstractschemechartview.h \
    Abstract/abstractschemefileread.h \
    Abstract/abstractschemefilesetting.h \
    Abstract/abstractschemefilewrite.h \
    Abstract/abstractschemewidgetcreatescheme.h \
    Scheme/Oblique/File/Read/schemeobliquefilereadfbd.h \
    Scheme/Oblique/File/Read/schemeobliquefilereadpfco.h \
    Scheme/Oblique/File/Read/schemeobliquefilereadrnx.h \
    Scheme/Oblique/File/Setting/schemeobliquefilesetting.h \
    Scheme/Oblique/File/Write/schemeobliquefilewritepfco.h \
    Scheme/Oblique/Satellite/History/event.h \
    Scheme/Oblique/Satellite/History/eventabstractschemechartscenedirectionnode.h \
    Scheme/Oblique/Satellite/History/eventabstractschemechartscenedirections.h \
    Scheme/Oblique/Satellite/History/eventabstractschemechartscenesetcolorthread.h \
    Scheme/Oblique/Satellite/schemeobliquesatellitehistory.h \
    Scheme/Oblique/Widget/CreateScheme/schemeobliquewidgetcreatescheme.h \
    Scheme/Oblique/Widget/EditDirectionForNewNode/schemeobliquewidgeteditdirectionfornewnodescene.h \
    Scheme/Oblique/Widget/EditDirectionForNewNode/schemeobliquewidgeteditdirectionfornewnodeview.h \
    Scheme/Oblique/Chart/schemeobliquechartscene.h \
    Scheme/Oblique/Chart/schemeobliquechartview.h \
    Scheme/Oblique/Object/schemeobliqueobjectnode.h \
    Scheme/Oblique/Object/schemeobliqueobjectpart.h \
    Scheme/Oblique/Satellite/schemeobliquesatellitecolors.h \
    Scheme/Oblique/Satellite/schemeobliquesatelliteconnects.h \
    Scheme/Oblique/Satellite/schemeobliquesatelliteinfos.h \
    Scheme/Oblique/Satellite/schemeobliquesatellitenodes.h \
    Scheme/Oblique/Satellite/schemeobliquesatelliteparts.h \
    editdirectionfornewnodewindow.h \
    fileread.h \
    filewrite.h \
    tabwidget.h \
    mainwindow.h

FORMS += \
    Scheme/Oblique/Widget/CreateScheme/schemeobliquewidgetcreatescheme.ui \
    editdirectionfornewnodewindow.ui \
    mainwindow.ui

# INCLUDEPATH += "C:/Program Files (x86)/Visual Leak Detector/include/"
# LIBS        += -L"C:/Program Files (x86)/Visual Leak Detector/lib/Win64"

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
