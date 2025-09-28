#include "schemeoblique.h"

#include "Scheme/Oblique/File/Read/schemeobliquefilereadfbd.h"
#include "Scheme/Oblique/File/Read/schemeobliquefilereadrnx.h"
#include "Scheme/Oblique/File/Read/schemeobliquefilereadpfco.h"
#include "Scheme/Oblique/File/Write/schemeobliquefilewritepfco.h"

#include "Scheme/Oblique/Chart/schemeobliquechartview.h"
#include "Scheme/Oblique/File/Setting/schemeobliquefilesetting.h"

SchemeOblique::SchemeOblique(): AbstractScheme{*(new QList<AbstractSchemeFileRead*>{new SchemeObliqueFileReadRNX(), new SchemeObliqueFileReadFBD(), new SchemeObliqueFileReadPFCO()}),
                                               *(new SchemeObliqueFileWritePFCO())}
{
    connect(&this->actionCreate, &QAction::triggered, &this->schemeObliqueWidgetCreateScheme, &SchemeObliqueWidgetCreateScheme::createIn);
    connect(&this->schemeObliqueWidgetCreateScheme, &SchemeObliqueWidgetCreateScheme::createOut, this, &SchemeOblique::createOut);

    this->commonCreate();
}

SchemeOblique::~SchemeOblique()
{

}

QAction &SchemeOblique::getActionCreate()
{
    return this->actionCreate;
}

void SchemeOblique::updateShortcut()
{
    this->actionCreate.setShortcut(QKeySequence::fromString(SchemeObliqueFileSetting::getShortcut_Action_Create()));
}

QList<AbstractSchemeFileRead *> &SchemeOblique::getListFileRead()
{
    return *this->listFileRead;
}

AbstractSchemeFileWrite &SchemeOblique::getFileWrite()
{
    return *this->fileWrite;
}

const QString &SchemeOblique::getTypeScheme()
{
    return SchemeObliqueChartView::getTypeSchemeStatic();
}

void SchemeOblique::commonCreate()
{
    this->actionCreate.setText(this->getTypeScheme());

    this->updateShortcut();
}
