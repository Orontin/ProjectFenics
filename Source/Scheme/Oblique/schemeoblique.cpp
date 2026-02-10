#include "schemeoblique.h"

#include "Scheme/Oblique/schemeobliqueaction.h"
#include "Scheme/Oblique/schemeobliqueshortcut.h"

#include "Scheme/Oblique/File/Read/schemeobliquefilereadfbd.h"
#include "Scheme/Oblique/File/Read/schemeobliquefilereadrnx.h"
#include "Scheme/Oblique/File/Read/schemeobliquefilereadpfco.h"
#include "Scheme/Oblique/File/Write/schemeobliquefilewritepfco.h"

#include "Scheme/Oblique/Chart/schemeobliquechartview.h"
#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"
#include "Scheme/Oblique/File/Setting/schemeobliquefilesettings.h"

#include "Scheme/Oblique/Widget/CreateScheme/schemeobliquewidgetcreateschemewindow.h"
#include "Scheme/Oblique/Widget/EditDirectionForNewNode/schemeobliquewidgeteditdirectionfornewnodewindow.h"
#include "Scheme/Oblique/Widget/ColorMap/schemeobliquewidgetcolormapwindow.h"

SchemeOblique *SchemeOblique::schemeOblique{nullptr};

SchemeOblique &SchemeOblique::getInstance()
{
    if (!SchemeOblique::schemeOblique) {
        SchemeOblique::schemeOblique = new SchemeOblique;
    }
    return *SchemeOblique::schemeOblique;
}

void SchemeOblique::onUpdateShortcut()
{
    onUpdateShortcutOblique();
    onUpdateShortcutView();
    onUpdateShortcutScene();
}

void SchemeOblique::disconnects()
{
    disconnectsView();
    disconnectsScene();
    disconnectsOblique();

    SchemeObliqueWidgetColorMapWindow::getInstance().visibleSchemeObliqueChartScene(nullptr);
}

void SchemeOblique::connects(AbstractSchemeChartView &view)
{
    connectsView(static_cast<SchemeObliqueChartView&>(view));
    connectsScene(static_cast<SchemeObliqueChartScene&>(*view.scene()));
    connectsOblique(static_cast<SchemeObliqueChartScene&>(*view.scene()));

    SchemeObliqueWidgetColorMapWindow::getInstance().visibleSchemeObliqueChartScene(static_cast<SchemeObliqueChartScene*>(view.scene()));
}

void SchemeOblique::setShortcut(QGridLayout &gridLayouShortcut)
{
    SchemeObliqueShortcut::getInstance().setShortcut(gridLayouShortcut);
}

void SchemeOblique::setMenuCreate(QMenu &menuCreate)
{
    SchemeObliqueAction::getInstance().setMenuCreate(menuCreate);
}

void SchemeOblique::setMenuSettings(QMenu &menuSettings)
{
    SchemeObliqueAction::getInstance().setMenuSettings(menuSettings);
}

void SchemeOblique::setMenuHistory(QMenu &menuHistory)
{
    SchemeObliqueAction::getInstance().setMenuHistory(menuHistory);
}

void SchemeOblique::setMenuManagment(QMenu &menuManagment)
{
    SchemeObliqueAction::getInstance().setMenuManagment(menuManagment);
}

void SchemeOblique::setMenuSettingsOpenScheme(QMenu &menuSettingsOpenScheme)
{
    Q_UNUSED(menuSettingsOpenScheme);
}

void SchemeOblique::setMenuView(QMenu &menuView)
{
    SchemeObliqueAction::getInstance().setMenuView(menuView);
}

QList<AbstractSchemeFileRead *> &SchemeOblique::getListFileRead()
{
    return this->listFileRead;
}

AbstractSchemeFileWrite &SchemeOblique::getFileWrite()
{
    return SchemeObliqueFileWritePFCO::getInstance();
}

void SchemeOblique::onShortcutSetDefaultShortcut()
{
    SchemeObliqueShortcut::getInstance().setDefaultShortcutInWidget();
}

void SchemeOblique::onShortcutCancel()
{
    SchemeObliqueShortcut::getInstance().setShortcutInWidget();
}

void SchemeOblique::onShortcutSave()
{
    SchemeObliqueShortcut::getInstance().saveShortcutInFile();
    SchemeObliqueShortcut::getInstance().setShortcutInWidget();
    this->onUpdateShortcut();
}

SchemeOblique::SchemeOblique(): AbstractScheme(), listFileRead{QList<AbstractSchemeFileRead*>{&SchemeObliqueFileReadRNX::getInstance(*this), &SchemeObliqueFileReadFBD::getInstance(*this), &SchemeObliqueFileReadPFCO::getInstance(*this)}}
{
    connect(&SchemeObliqueAction::getInstance().actionCreate, &QAction::triggered, &SchemeObliqueWidgetCreateSchemeWindow::getInstance(*this), &SchemeObliqueWidgetCreateSchemeWindow::createIn);
    connect(&SchemeObliqueWidgetCreateSchemeWindow::getInstance(*this), &SchemeObliqueWidgetCreateSchemeWindow::createOut, this, &SchemeOblique::createOut);

    for (AbstractSchemeFileRead *fileRead : listFileRead) {
        connect(fileRead, &AbstractSchemeFileRead::createOut, this, &SchemeOblique::createOut);
    }

    connect(&SchemeObliqueAction::getInstance().actionEditDirectionNewNode, &QAction::triggered, &SchemeObliqueWidgetEditDirectionForNewNodeWindow::getInstance(), &SchemeObliqueWidgetEditDirectionForNewNodeWindow::open);

    SchemeObliqueAction::getInstance().actionColorMap.setChecked(SchemeObliqueFileSettings::getColorMapVisible());
    connect(&SchemeObliqueAction::getInstance().actionColorMap, &QAction::toggled, &SchemeObliqueWidgetColorMapWindow::getInstance(), &SchemeObliqueWidgetColorMapWindow::visible);

    this->onUpdateShortcut();
}

SchemeOblique::~SchemeOblique()
{

}

void SchemeOblique::disconnectsView()
{
    SchemeObliqueAction::getInstance().actionZoomOut.disconnect();
    SchemeObliqueAction::getInstance().actionZoomIn.disconnect();
    SchemeObliqueAction::getInstance().actionToBottom.disconnect();
    SchemeObliqueAction::getInstance().actionToTop.disconnect();
    SchemeObliqueAction::getInstance().actionToLeft.disconnect();
    SchemeObliqueAction::getInstance().actionToRight.disconnect();
    SchemeObliqueAction::getInstance().actionRotateLeft.disconnect();
    SchemeObliqueAction::getInstance().actionRotateRight.disconnect();
}

void SchemeOblique::disconnectsScene()
{
    SchemeObliqueAction::getInstance().actionBack.disconnect();
    SchemeObliqueAction::getInstance().actionNext.disconnect();

    SchemeObliqueAction::getInstance().actionRemoveThreadLeft.disconnect();
    SchemeObliqueAction::getInstance().actionRemoveThreadRight.disconnect();
    SchemeObliqueAction::getInstance().actionAddThreadLeft.disconnect();
    SchemeObliqueAction::getInstance().actionAddThreadRight.disconnect();
    SchemeObliqueAction::getInstance().actionRemoveHalfrowDown.disconnect();
    SchemeObliqueAction::getInstance().actionRemoveHalfrowTop.disconnect();
    SchemeObliqueAction::getInstance().actionAddHalfrowDown.disconnect();
    SchemeObliqueAction::getInstance().actionAddHalfrowTop.disconnect();
}

void SchemeOblique::disconnectsOblique()
{
    disconnect(connectActionEnableRemoveThreadLeftAndRight);
    disconnect(connectActionEnableRemoveHalfrowDownAndTop);
    disconnect(connectActionEnableAddThreadLeftAndRight);
    disconnect(connectActionEnableAddHalfrowDownAndTop);
    disconnect(connectActionEnableBack);
    disconnect(connectActionEnableNext);
}

void SchemeOblique::connectsView(SchemeObliqueChartView &view)
{
    connect(&SchemeObliqueAction::getInstance().actionZoomOut, &QAction::triggered, &view, &SchemeObliqueChartView::zoomOut);
    connect(&SchemeObliqueAction::getInstance().actionZoomIn, &QAction::triggered, &view, &SchemeObliqueChartView::zoomIn);
    connect(&SchemeObliqueAction::getInstance().actionToBottom, &QAction::triggered, &view, &SchemeObliqueChartView::toBottom);
    connect(&SchemeObliqueAction::getInstance().actionToTop, &QAction::triggered, &view, &SchemeObliqueChartView::toTop);
    connect(&SchemeObliqueAction::getInstance().actionToLeft, &QAction::triggered, &view, &SchemeObliqueChartView::toLeft);
    connect(&SchemeObliqueAction::getInstance().actionToRight, &QAction::triggered, &view, &SchemeObliqueChartView::toRight);
    connect(&SchemeObliqueAction::getInstance().actionRotateLeft, &QAction::triggered, &view, &SchemeObliqueChartView::rotateLeft);
    connect(&SchemeObliqueAction::getInstance().actionRotateRight, &QAction::triggered, &view, &SchemeObliqueChartView::rotateRight);
}

void SchemeOblique::connectsScene(SchemeObliqueChartScene &scene)
{
    connect(&SchemeObliqueAction::getInstance().actionBack, &QAction::triggered, &scene, &SchemeObliqueChartScene::backHistory);
    connect(&SchemeObliqueAction::getInstance().actionNext, &QAction::triggered, &scene, &SchemeObliqueChartScene::nextHistory);

    connect(&SchemeObliqueAction::getInstance().actionRemoveThreadLeft, &QAction::triggered, &scene, &SchemeObliqueChartScene::editNodesDirectionsRemoveLeft);
    connect(&SchemeObliqueAction::getInstance().actionRemoveThreadRight, &QAction::triggered, &scene, &SchemeObliqueChartScene::editNodesDirectionsRemoveRight);
    connect(&SchemeObliqueAction::getInstance().actionAddThreadLeft, &QAction::triggered, &scene, &SchemeObliqueChartScene::editNodesDirectionsAddLeft);
    connect(&SchemeObliqueAction::getInstance().actionAddThreadRight, &QAction::triggered, &scene, &SchemeObliqueChartScene::editNodesDirectionsAddRight);
    connect(&SchemeObliqueAction::getInstance().actionRemoveHalfrowDown, &QAction::triggered, &scene, &SchemeObliqueChartScene::editNodesDirectionsRemoveBottom);
    connect(&SchemeObliqueAction::getInstance().actionRemoveHalfrowTop, &QAction::triggered, &scene, &SchemeObliqueChartScene::editNodesDirectionsRemoveTop);
    connect(&SchemeObliqueAction::getInstance().actionAddHalfrowDown, &QAction::triggered, &scene, &SchemeObliqueChartScene::editNodesDirectionsAddBottom);
    connect(&SchemeObliqueAction::getInstance().actionAddHalfrowTop, &QAction::triggered, &scene, &SchemeObliqueChartScene::editNodesDirectionsAddTop);
}

void SchemeOblique::connectsOblique(SchemeObliqueChartScene &scene)
{
    this->connectActionEnableRemoveThreadLeftAndRight = connect(&scene, &SchemeObliqueChartScene::actionEnableRemoveThreadLeftAndRight, &SchemeObliqueAction::getInstance(), &SchemeObliqueAction::onActionEnableRemoveThreadLeftAndRight);
    this->connectActionEnableRemoveHalfrowDownAndTop = connect(&scene, &SchemeObliqueChartScene::actionEnableRemoveHalfrowDownAndTop, &SchemeObliqueAction::getInstance(), &SchemeObliqueAction::onActionEnableRemoveHalfrowDownAndTop);
    this->connectActionEnableAddThreadLeftAndRight = connect(&scene, &SchemeObliqueChartScene::actionEnableAddThreadLeftAndRight, &SchemeObliqueAction::getInstance(), &SchemeObliqueAction::onActionEnableAddThreadLeftAndRight);
    this->connectActionEnableAddHalfrowDownAndTop = connect(&scene, &SchemeObliqueChartScene::actionEnableAddHalfrowDownAndTop, &SchemeObliqueAction::getInstance(), &SchemeObliqueAction::onActionEnableAddHalfrowDownAndTop);
    this->connectActionEnableBack = connect(&scene, &SchemeObliqueChartScene::actionEnableBack, &SchemeObliqueAction::getInstance(), &SchemeObliqueAction::onActionEnableBack);
    this->connectActionEnableNext = connect(&scene, &SchemeObliqueChartScene::actionEnableNext, &SchemeObliqueAction::getInstance(), &SchemeObliqueAction::onActionEnableNext);
}

void SchemeOblique::onUpdateShortcutOblique()
{
    SchemeObliqueAction::getInstance().actionCreate.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutSceneCreate());
    SchemeObliqueAction::getInstance().actionEditDirectionNewNode.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutSceneEditDirectionNewNode());
    SchemeObliqueAction::getInstance().actionColorMap.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutSceneColorMap());
    SchemeObliqueAction::getInstance().actionColorMap.setShortcutContext(Qt::ShortcutContext::ApplicationShortcut);
}

void SchemeOblique::onUpdateShortcutView()
{
    SchemeObliqueAction::getInstance().actionZoomOut.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutViewZoomOut());
    SchemeObliqueAction::getInstance().actionZoomIn.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutViewZoomIn());
    SchemeObliqueAction::getInstance().actionToBottom.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutViewToBottom());
    SchemeObliqueAction::getInstance().actionToTop.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutViewToTop());
    SchemeObliqueAction::getInstance().actionToLeft.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutViewToLeft());
    SchemeObliqueAction::getInstance().actionToRight.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutViewToRight());
    SchemeObliqueAction::getInstance().actionRotateLeft.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutViewRotateLeft());
    SchemeObliqueAction::getInstance().actionRotateRight.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutViewRotateRight());

    SchemeObliqueWidgetColorMapWindow::getInstance().onUpdateShortcutView();
}

void SchemeOblique::onUpdateShortcutScene()
{
    SchemeObliqueAction::getInstance().actionBack.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutHistoryBack());
    SchemeObliqueAction::getInstance().actionNext.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutHistoryNext());
    SchemeObliqueAction::getInstance().actionRemoveThreadLeft.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutSceneThreadRemoveLeft());
    SchemeObliqueAction::getInstance().actionRemoveThreadRight.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutSceneThreadRemoveRight());
    SchemeObliqueAction::getInstance().actionAddThreadLeft.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutSceneThreadAddLeft());
    SchemeObliqueAction::getInstance().actionAddThreadRight.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutSceneThreadAddRight());
    SchemeObliqueAction::getInstance().actionRemoveHalfrowDown.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutSceneHalfrowRemoveDown());
    SchemeObliqueAction::getInstance().actionRemoveHalfrowTop.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutSceneHalfrowRemoveTop());
    SchemeObliqueAction::getInstance().actionAddHalfrowDown.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutSceneHalfrowAddDown());
    SchemeObliqueAction::getInstance().actionAddHalfrowTop.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutSceneHalfrowAddTop());
}
