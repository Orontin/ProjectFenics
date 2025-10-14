#include "schemeoblique.h"

#include "Scheme/Oblique/File/Read/schemeobliquefilereadfbd.h"
#include "Scheme/Oblique/File/Read/schemeobliquefilereadrnx.h"
#include "Scheme/Oblique/File/Read/schemeobliquefilereadpfco.h"
#include "Scheme/Oblique/File/Write/schemeobliquefilewritepfco.h"

#include "Scheme/Oblique/Chart/schemeobliquechartview.h"
#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"
#include "Scheme/Oblique/File/Setting/schemeobliquefilesetting.h"

#include "Scheme/Oblique/Widget/CreateScheme/schemeobliquewidgetcreatescheme.h"
#include "Scheme/Oblique/Widget/EditDirectionForNewNode/schemeobliquewidgeteditdirectionfornewnodechartwindow.h"

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

void SchemeOblique::setMenuCreate(QMenu &menuCreate)
{
    menuCreate.addAction(&this->actionCreate);
}

void SchemeOblique::setMenuSettings(QMenu &menuSettings)
{
    menuSettings.addMenu(&this->menuSettings);
}

void SchemeOblique::setMenuHistory(QMenu &menuHistory)
{
    menuHistory.addAction(&this->actionBack);
    menuHistory.addAction(&this->actionNext);
}

void SchemeOblique::setMenuManagment(QMenu &menuManagment)
{
    menuManagment.addMenu(&this->menuThread);
    menuManagment.addMenu(&this->menuHalfrow);
}

void SchemeOblique::setMenuSettingsOpenScheme(QMenu &menuSettingsOpenScheme)
{
    Q_UNUSED(menuSettingsOpenScheme);
}

void SchemeOblique::setMenuView(QMenu &menuView)
{
    menuView.addMenu(&this->menuZoom);
    menuView.addMenu(&this->menuTo);
    menuView.addMenu(&this->menuRotate);
}

QList<AbstractSchemeFileRead *> &SchemeOblique::getListFileRead()
{
    return this->listFileRead;
}

AbstractSchemeFileWrite &SchemeOblique::getFileWrite()
{
    return SchemeObliqueFileWritePFCO::getInstance();
}

void SchemeOblique::connects(AbstractSchemeChartView &view)
{
    connectsView(view);
    connectsScene(static_cast<AbstractSchemeChartScene&>(*view.scene()));

    emit this->createOut(view);
}

void SchemeOblique::connectsView(AbstractSchemeChartView &view)
{
    connect(&this->actionZoomOut, &QAction::triggered, static_cast<SchemeObliqueChartView*>(&view), &SchemeObliqueChartView::zoomOut);
    connect(&this->actionZoomIn, &QAction::triggered, static_cast<SchemeObliqueChartView*>(&view), &SchemeObliqueChartView::zoomIn);
    connect(&this->actionToBottom, &QAction::triggered, static_cast<SchemeObliqueChartView*>(&view), &SchemeObliqueChartView::toBottom);
    connect(&this->actionToTop, &QAction::triggered, static_cast<SchemeObliqueChartView*>(&view), &SchemeObliqueChartView::toTop);
    connect(&this->actionToLeft, &QAction::triggered, static_cast<SchemeObliqueChartView*>(&view), &SchemeObliqueChartView::toLeft);
    connect(&this->actionToRight, &QAction::triggered, static_cast<SchemeObliqueChartView*>(&view), &SchemeObliqueChartView::toRight);
    connect(&this->actionRotateLeft, &QAction::triggered, static_cast<SchemeObliqueChartView*>(&view), &SchemeObliqueChartView::rotateLeft);
    connect(&this->actionRotateRight, &QAction::triggered, static_cast<SchemeObliqueChartView*>(&view), &SchemeObliqueChartView::rotateRight);
}

void SchemeOblique::connectsScene(AbstractSchemeChartScene &scene)
{
    connect(&this->actionBack, &QAction::triggered, static_cast<SchemeObliqueChartScene*>(&scene), &SchemeObliqueChartScene::backHistory);
    connect(&this->actionNext, &QAction::triggered, static_cast<SchemeObliqueChartScene*>(&scene), &SchemeObliqueChartScene::nextHistory);

    connect(&this->actionRemoveThreadLeft, &QAction::triggered, static_cast<SchemeObliqueChartScene*>(&scene), &SchemeObliqueChartScene::editNodesDirectionsRemoveLeft);
    connect(&this->actionRemoveThreadRight, &QAction::triggered, static_cast<SchemeObliqueChartScene*>(&scene), &SchemeObliqueChartScene::editNodesDirectionsRemoveRight);
    connect(&this->actionAddThreadLeft, &QAction::triggered, static_cast<SchemeObliqueChartScene*>(&scene), &SchemeObliqueChartScene::editNodesDirectionsAddLeft);
    connect(&this->actionAddThreadRight, &QAction::triggered, static_cast<SchemeObliqueChartScene*>(&scene), &SchemeObliqueChartScene::editNodesDirectionsAddRight);
    connect(&this->actionRemoveHalfrowDown, &QAction::triggered, static_cast<SchemeObliqueChartScene*>(&scene), &SchemeObliqueChartScene::editNodesDirectionsRemoveBottom);
    connect(&this->actionRemoveHalfrowTop, &QAction::triggered, static_cast<SchemeObliqueChartScene*>(&scene), &SchemeObliqueChartScene::editNodesDirectionsRemoveTop);
    connect(&this->actionAddHalfrowDown, &QAction::triggered, static_cast<SchemeObliqueChartScene*>(&scene), &SchemeObliqueChartScene::editNodesDirectionsAddBottom);
    connect(&this->actionAddHalfrowTop, &QAction::triggered, static_cast<SchemeObliqueChartScene*>(&scene), &SchemeObliqueChartScene::editNodesDirectionsAddTop);

    connect(static_cast<SchemeObliqueChartScene*>(&scene), &SchemeObliqueChartScene::actionEnableRemoveThreadLeftAndRight, this, &SchemeOblique::onActionEnableRemoveThreadLeftAndRight);
    connect(static_cast<SchemeObliqueChartScene*>(&scene), &SchemeObliqueChartScene::actionEnableRemoveHalfrowDownAndTop, this, &SchemeOblique::onActionEnableRemoveHalfrowDownAndTop);
    connect(static_cast<SchemeObliqueChartScene*>(&scene), &SchemeObliqueChartScene::actionEnableAddThreadLeftAndRight, this, &SchemeOblique::onActionEnableAddThreadLeftAndRight);
    connect(static_cast<SchemeObliqueChartScene*>(&scene), &SchemeObliqueChartScene::actionEnableAddHalfrowDownAndTop, this, &SchemeOblique::onActionEnableAddHalfrowDownAndTop);

    connect(static_cast<SchemeObliqueChartScene*>(&scene), &SchemeObliqueChartScene::actionEnableBack, this, &SchemeOblique::onActionEnableBack);
    connect(static_cast<SchemeObliqueChartScene*>(&scene), &SchemeObliqueChartScene::actionEnableNext, this, &SchemeOblique::onActionEnableNext);
}

void SchemeOblique::onActionEnableRemoveThreadLeftAndRight(const bool enable)
{
    this->actionRemoveThreadLeft.setEnabled(enable);
    this->actionRemoveThreadRight.setEnabled(enable);
}

void SchemeOblique::onActionEnableRemoveHalfrowDownAndTop(const bool enable)
{
    this->actionRemoveHalfrowDown.setEnabled(enable);
    this->actionRemoveHalfrowTop.setEnabled(enable);
}

void SchemeOblique::onActionEnableAddThreadLeftAndRight(const bool enable)
{
    this->actionAddThreadLeft.setEnabled(enable);
    this->actionAddThreadRight.setEnabled(enable);
}

void SchemeOblique::onActionEnableAddHalfrowDownAndTop(const bool enable)
{
    this->actionAddHalfrowDown.setEnabled(enable);
    this->actionAddHalfrowTop.setEnabled(enable);
}

void SchemeOblique::onActionEnableBack(const bool enable)
{
    this->actionBack.setEnabled(enable);
}

void SchemeOblique::onActionEnableNext(const bool enable)
{
    this->actionNext.setEnabled(enable);
}

SchemeOblique::SchemeOblique(): AbstractScheme(), listFileRead{QList<AbstractSchemeFileRead*>{&SchemeObliqueFileReadRNX::getInstance(*this), &SchemeObliqueFileReadFBD::getInstance(*this), &SchemeObliqueFileReadPFCO::getInstance(*this)}}
{
    connect(&this->actionCreate, &QAction::triggered, &SchemeObliqueWidgetCreateScheme::getInstance(*this), &SchemeObliqueWidgetCreateScheme::createIn);
    connect(&SchemeObliqueWidgetCreateScheme::getInstance(*this), &SchemeObliqueWidgetCreateScheme::createOut, this, &SchemeOblique::connects);

    for (AbstractSchemeFileRead *fileRead : listFileRead) {
        connect(fileRead, &AbstractSchemeFileRead::createOut, this, &SchemeOblique::connects);
    }

    connect(&this->actionEditDirectionNewNode, &QAction::triggered, &SchemeObliqueWidgetEditDirectionForNewNodeWindow::getInstance(), &SchemeObliqueWidgetEditDirectionForNewNodeWindow::open);

    this->createActions();
    this->onUpdateShortcut();
}

SchemeOblique::~SchemeOblique()
{

}

void SchemeOblique::onUpdateShortcutOblique()
{
    this->actionCreate.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutSceneCreate());
    this->actionEditDirectionNewNode.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutSceneHalfrowEditDirectionNewNode());
}

void SchemeOblique::onUpdateShortcutView()
{
    this->actionZoomOut.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutViewZoomOut());
    this->actionZoomIn.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutViewZoomIn());
    this->actionToBottom.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutViewToBottom());
    this->actionToTop.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutViewToTop());
    this->actionToLeft.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutViewToLeft());
    this->actionToRight.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutViewToRight());
    this->actionRotateLeft.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutViewRotateLeft());
    this->actionRotateRight.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutViewRotateRight());
}

void SchemeOblique::onUpdateShortcutScene()
{
    this->actionBack.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutHistoryBack());
    this->actionNext.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutHistoryNext());
    this->actionRemoveThreadLeft.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutSceneThreadRemoveLeft());
    this->actionRemoveThreadRight.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutSceneThreadRemoveRight());
    this->actionAddThreadLeft.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutSceneThreadAddLeft());
    this->actionAddThreadRight.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutSceneThreadAddRight());
    this->actionRemoveHalfrowDown.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutSceneHalfrowRemoveDown());
    this->actionRemoveHalfrowTop.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutSceneHalfrowRemoveTop());
    this->actionAddHalfrowDown.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutSceneHalfrowAddDown());
    this->actionAddHalfrowTop.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutSceneHalfrowAddTop());
}

void SchemeOblique::createActions()
{
    createActionOblique();
    createActionView();
    createActionScene();
}

void SchemeOblique::createActionOblique()
{
    this->actionCreate.setText("Усложенная косая");
    this->menuSettings.setTitle("Усложенная косая");
    this->actionEditDirectionNewNode.setText("Изменить направление для новых узлов");

    this->menuSettings.addAction(&this->actionEditDirectionNewNode);
}

void SchemeOblique::createActionView()
{
    this->menuZoom.setTitle("Дальность");
    this->menuTo.setTitle("Перемещение");
    this->menuRotate.setTitle("Поворот");

    this->actionZoomOut.setText("Отдалить");
    this->actionZoomIn.setText("Приблизить");
    this->actionToBottom.setText("Вниз");
    this->actionToTop.setText("Вверх");
    this->actionToLeft.setText("Влево");
    this->actionToRight.setText("Вправо");
    this->actionRotateLeft.setText("Влево");
    this->actionRotateRight.setText("Вправо");

    this->menuZoom.addAction(&this->actionZoomOut);
    this->menuZoom.addAction(&this->actionZoomIn);
    this->menuTo.addAction(&this->actionToBottom);
    this->menuTo.addAction(&this->actionToTop);
    this->menuTo.addAction(&this->actionToLeft);
    this->menuTo.addAction(&this->actionToRight);
    this->menuRotate.addAction(&this->actionRotateLeft);
    this->menuRotate.addAction(&this->actionRotateRight);
}

void SchemeOblique::createActionScene()
{
    this->actionBack.setText("Назад");
    this->actionNext.setText("Вперед");

    this->menuThread.setTitle("Нити");
    this->menuHalfrow.setTitle("Полуряды");

    this->actionRemoveThreadLeft.setText("Убрать нить слева");
    this->actionRemoveThreadRight.setText("Убрать нить справа");
    this->actionAddThreadLeft.setText("Добавить нить слева");
    this->actionAddThreadRight.setText("Добавить нить справа");
    this->actionRemoveHalfrowDown.setText("Убрать полуряд снизу");
    this->actionRemoveHalfrowTop.setText("Убрать полуряд сверху");
    this->actionAddHalfrowDown.setText("Добавить полуряд снизу");
    this->actionAddHalfrowTop.setText("Добавить полуряд сверху");

    this->menuThread.addAction(&this->actionRemoveThreadLeft);
    this->menuThread.addAction(&this->actionRemoveThreadRight);
    this->menuThread.addSeparator();
    this->menuThread.addAction(&this->actionAddThreadLeft);
    this->menuThread.addAction(&this->actionAddThreadRight);
    this->menuHalfrow.addAction(&this->actionRemoveHalfrowDown);
    this->menuHalfrow.addAction(&this->actionRemoveHalfrowTop);
    this->menuHalfrow.addSeparator();
    this->menuHalfrow.addAction(&this->actionAddHalfrowDown);
    this->menuHalfrow.addAction(&this->actionAddHalfrowTop);
}
