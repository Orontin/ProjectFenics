// #include <vld.h>

#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QStyleFactory>

#include "mainwindow.h"

#include "Scheme/Oblique/schemeoblique.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("windows11");

    QString locale = QLocale::system().name();
    QTranslator qtTranslator;
    if (qtTranslator.load("qt_" + locale, QLibraryInfo::path(QLibraryInfo::TranslationsPath))) {
        a.installTranslator(&qtTranslator);
    }

    QList<AbstractScheme*> schemes{QList<AbstractScheme*>{&SchemeOblique::getInstance()}};

    MainWindow w(schemes);
    w.show();

    int returnCode = a.exec();

    for (AbstractScheme *scheme : schemes) {
        delete scheme;
    }

    return returnCode;
}
