// #include <vld.h>

#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>

#include "mainwindow.h"

#include "Scheme/Oblique/schemeoblique.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString locale = QLocale::system().name();
    QTranslator qtTranslator;
    if (qtTranslator.load("qt_" + locale, QLibraryInfo::path(QLibraryInfo::TranslationsPath))) {
        a.installTranslator(&qtTranslator);
    }

    SchemeOblique *schemeOblique = new SchemeOblique();
    QList<AbstractScheme*> *schemes = new QList<AbstractScheme*>{schemeOblique};

    MainWindow w(*schemes);
    w.show();

    int returnCode = a.exec();

    for (AbstractScheme *scheme : *schemes) {
        delete scheme;
    }
    delete schemes;

    return returnCode;
}
