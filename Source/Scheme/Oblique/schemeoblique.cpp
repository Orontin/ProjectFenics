#include "schemeoblique.h"

#include "Scheme/Oblique/File/Read/schemeobliquefilereadfbd.h"
#include "Scheme/Oblique/File/Read/schemeobliquefilereadrnx.h"
#include "Scheme/Oblique/File/Read/schemeobliquefilereadpfco.h"
#include "Scheme/Oblique/File/Write/schemeobliquefilewritepfco.h"

#include "Scheme/Oblique/Chart/schemeobliquechartview.h"

SchemeOblique::SchemeOblique(): AbstractScheme{*(new QList<AbstractSchemeFileRead*>{new SchemeObliqueFileReadRNX(), new SchemeObliqueFileReadFBD(), new SchemeObliqueFileReadPFCO()}),
                                               *(new SchemeObliqueFileWritePFCO())}
{
    connect(&actionCreate, &QAction::triggered, &schemeObliqueWidgetCreateScheme, &SchemeObliqueWidgetCreateScheme::createIn);
    connect(&schemeObliqueWidgetCreateScheme, &SchemeObliqueWidgetCreateScheme::createOut, this, &SchemeOblique::createOut);

    actionCreate.setText(this->getTypeScheme());
}

SchemeOblique::~SchemeOblique()
{

}

QAction &SchemeOblique::getActionCreate()
{
    return actionCreate;
}

QList<AbstractSchemeFileRead *> &SchemeOblique::getListFileRead()
{
    return *listFileRead;
}

AbstractSchemeFileWrite &SchemeOblique::getFileWrite()
{
    return *fileWrite;
}

const QString &SchemeOblique::getTypeScheme()
{
    return SchemeObliqueChartView::getTypeSchemeStatic();
}
