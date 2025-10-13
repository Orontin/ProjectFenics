#include "schemeoblique.h"

#include "Scheme/Oblique/File/Read/schemeobliquefilereadfbd.h"
#include "Scheme/Oblique/File/Read/schemeobliquefilereadrnx.h"
#include "Scheme/Oblique/File/Read/schemeobliquefilereadpfco.h"
#include "Scheme/Oblique/File/Write/schemeobliquefilewritepfco.h"

#include "Scheme/Oblique/Chart/schemeobliquechartview.h"
#include "Scheme/Oblique/File/Setting/schemeobliquefilesetting.h"

#include "Scheme/Oblique/Widget/CreateScheme/schemeobliquewidgetcreatescheme.h"
#include "Scheme/Oblique/Widget/EditDirectionForNewNode/schemeobliquewidgeteditdirectionfornewnodechartwindow.h"

SchemeOblique *SchemeOblique::schemeOblique{nullptr};

SchemeOblique::SchemeOblique(): AbstractScheme(), listFileRead{QList<AbstractSchemeFileRead*>{&SchemeObliqueFileReadRNX::getInstance(), &SchemeObliqueFileReadFBD::getInstance(), &SchemeObliqueFileReadPFCO::getInstance()}}
{
    connect(&this->actionCreate, &QAction::triggered, &SchemeObliqueWidgetCreateScheme::getInstance(), &SchemeObliqueWidgetCreateScheme::createIn);
    connect(&SchemeObliqueWidgetCreateScheme::getInstance(), &SchemeObliqueWidgetCreateScheme::createOut, this, &SchemeOblique::connectUpdateShortcutAndView);

    connect(&this->actionEditDirectionNewNode, &QAction::triggered, &SchemeObliqueWidgetEditDirectionForNewNodeWindow::getInstance(), &SchemeObliqueWidgetEditDirectionForNewNodeWindow::open);

    connect(this, &SchemeOblique::updateShortcut, this, &SchemeOblique::onUpdateShortcut);

    this->commonCreate();
}

SchemeOblique::~SchemeOblique()
{

}

void SchemeOblique::connectUpdateShortcutAndView(AbstractSchemeChartView &view)
{
    connect(this, &SchemeOblique::updateShortcut, &view, &AbstractSchemeChartView::onUpdateShortcut);
    emit createOut(view);
}

SchemeOblique &SchemeOblique::getInstance()
{
    if (!SchemeOblique::schemeOblique) {
        SchemeOblique::schemeOblique = new SchemeOblique;
    }
    return *SchemeOblique::schemeOblique;
}

void SchemeOblique::setMenuCreate(QMenu &menuCreate)
{
    menuCreate.addAction(&this->actionCreate);
}

void SchemeOblique::setMenuSettings(QMenu &menuSettings)
{
    menuSettings.addMenu(&this->menuSettings);
}

void SchemeOblique::onUpdateShortcut()
{
    this->actionCreate.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutSceneCreate());
    this->actionEditDirectionNewNode.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutSceneHalfrowEditDirectionNewNode());
}

QList<AbstractSchemeFileRead *> &SchemeOblique::getListFileRead()
{
    return listFileRead;
}

AbstractSchemeFileWrite &SchemeOblique::getFileWrite()
{
    return SchemeObliqueFileWritePFCO::getInstance();
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

    this->onUpdateShortcut();
}
