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

    connect(&this->actionEditDirectionNewNode, &QAction::triggered, &schemeObliqueWidgetEditDirectionForNewNodeWindow, &SchemeObliqueWidgetEditDirectionForNewNodeWindow::open);

    this->commonCreate();
}

SchemeOblique::~SchemeOblique()
{

}

void SchemeOblique::setMenuCreate(QMenu &menuCreate)
{
    menuCreate.addAction(&this->actionCreate);
}

void SchemeOblique::setMenuSettings(QMenu &menuSettings)
{
    menuSettings.addAction(&this->actionEditDirectionNewNode);
}

void SchemeOblique::updateShortcut()
{
    this->actionCreate.setShortcuts(SchemeObliqueFileSetting::getShortcut_Action_Create());
    this->actionEditDirectionNewNode.setShortcuts(SchemeObliqueFileSetting::getShortcut_Action_EditDirectionNewNode());
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

    this->menuSettings.setTitle(this->getTypeScheme());
    this->actionEditDirectionNewNode.setText("Изменить направление для новых узлов");
    this->menuSettings.addAction(&this->actionEditDirectionNewNode);

    this->updateShortcut();
}
