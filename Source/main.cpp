// #include <vld.h>

#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>

#include "mainwindow.h"

#include "Abstract/abstractscheme.h"

#include "Scheme/Oblique/Chart/schemeobliquechartview.h"
#include "Scheme/Oblique/File/Read/schemeobliquefilereadfbd.h"
#include "Scheme/Oblique/File/Read/schemeobliquefilereadrnx.h"
#include "Scheme/Oblique/File/Read/schemeobliquefilereadpfco.h"
#include "Scheme/Oblique/File/Write/schemeobliquefilewritepfco.h"
#include "Scheme/Oblique/Widget/CreateOrEditScheme/schemeobliquewidgetcreateoreditscheme.h"
#include "Scheme/Oblique/Widget/EditDirectionForNewNode/schemeobliquewidgeteditdirectionfornewnodeview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString locale = QLocale::system().name();
    QTranslator qtTranslator;
    if (qtTranslator.load("qt_" + locale, QLibraryInfo::path(QLibraryInfo::TranslationsPath))) {
        a.installTranslator(&qtTranslator);
    }

    SchemeObliqueChartView view;
    AbstractSchemeFileRead *schemeObliqueFileReadRNX = new SchemeObliqueFileReadRNX();
    AbstractSchemeFileRead *schemeObliqueFileReadFBD = new SchemeObliqueFileReadFBD();
    AbstractSchemeFileRead *schemeObliqueFileReadPFCO = new SchemeObliqueFileReadPFCO();
    QList<AbstractSchemeFileRead*> *listFileRead = new QList<AbstractSchemeFileRead*>{schemeObliqueFileReadRNX, schemeObliqueFileReadFBD, schemeObliqueFileReadPFCO};
    AbstractSchemeFileWrite *fileWrite = new SchemeObliqueFileWritePFCO();
    QGraphicsView *schemeObliqueWidgetEditDirectionForNewNodeView = new SchemeObliqueWidgetEditDirectionForNewNodeView();
    AbstractSchemeWidgetCreateOrEditScheme *schemeObliqueWidgetCreateOrEditScheme = new SchemeObliqueWidgetCreateOrEditScheme();
    AbstractScheme *schemeOblique = new AbstractScheme(listFileRead, fileWrite, schemeObliqueWidgetCreateOrEditScheme, schemeObliqueWidgetEditDirectionForNewNodeView, view.getTypeScheme());

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
