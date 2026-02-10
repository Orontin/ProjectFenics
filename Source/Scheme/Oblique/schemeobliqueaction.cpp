#include "schemeobliqueaction.h"

SchemeObliqueAction *SchemeObliqueAction::schemeObliqueAction{nullptr};

SchemeObliqueAction &SchemeObliqueAction::getInstance()
{
    if (!SchemeObliqueAction::schemeObliqueAction) {
        SchemeObliqueAction::schemeObliqueAction = new SchemeObliqueAction;
    }
    return *SchemeObliqueAction::schemeObliqueAction;
}

void SchemeObliqueAction::setMenuCreate(QMenu &menuCreate)
{
    menuCreate.addAction(&this->actionCreate);
}

void SchemeObliqueAction::setMenuSettings(QMenu &menuSettings)
{
    menuSettings.addMenu(&this->menuSettings);
}

void SchemeObliqueAction::setMenuHistory(QMenu &menuHistory)
{
    menuHistory.addAction(&this->actionBack);
    menuHistory.addAction(&this->actionNext);
}

void SchemeObliqueAction::setMenuManagment(QMenu &menuManagment)
{
    menuManagment.addMenu(&this->menuThread);
    menuManagment.addMenu(&this->menuHalfrow);
}

void SchemeObliqueAction::setMenuSettingsOpenScheme(QMenu &menuSettingsOpenScheme)
{
    Q_UNUSED(menuSettingsOpenScheme);
}

void SchemeObliqueAction::setMenuView(QMenu &menuView)
{
    menuView.addMenu(&this->menuZoom);
    menuView.addMenu(&this->menuTo);
    menuView.addMenu(&this->menuRotate);
}

void SchemeObliqueAction::onActionEnableRemoveThreadLeftAndRight(const bool enable)
{
    this->actionRemoveThreadLeft.setEnabled(enable);
    this->actionRemoveThreadRight.setEnabled(enable);
}

void SchemeObliqueAction::onActionEnableRemoveHalfrowDownAndTop(const bool enable)
{
    this->actionRemoveHalfrowDown.setEnabled(enable);
    this->actionRemoveHalfrowTop.setEnabled(enable);
}

void SchemeObliqueAction::onActionEnableAddThreadLeftAndRight(const bool enable)
{
    this->actionAddThreadLeft.setEnabled(enable);
    this->actionAddThreadRight.setEnabled(enable);
}

void SchemeObliqueAction::onActionEnableAddHalfrowDownAndTop(const bool enable)
{
    this->actionAddHalfrowDown.setEnabled(enable);
    this->actionAddHalfrowTop.setEnabled(enable);
}

void SchemeObliqueAction::onActionEnableBack(const bool enable)
{
    this->actionBack.setEnabled(enable);
}

void SchemeObliqueAction::onActionEnableNext(const bool enable)
{
    this->actionNext.setEnabled(enable);
}

SchemeObliqueAction::SchemeObliqueAction()
{
    this->createActions();
}

SchemeObliqueAction::~SchemeObliqueAction()
{

}

void SchemeObliqueAction::createActions()
{
    this->createActionCreateOblique();
    this->createActionView();
    this->createActionScene();
    this->createActionSettingsOblique();
}

void SchemeObliqueAction::createActionCreateOblique()
{
    this->actionCreate.setText("Усложненная косая");
}

void SchemeObliqueAction::createActionSettingsOblique()
{
    this->menuSettings.setTitle("Усложненная косая");

    this->actionEditDirectionNewNode.setText("Изменить направление для новых узлов");
    this->actionColorMap.setText("Показывать цветовую карту открытой схемы");

    this->actionColorMap.setCheckable(true);

    this->menuSettings.addAction(&this->actionEditDirectionNewNode);
    this->menuSettings.addAction(&this->actionColorMap);
}

void SchemeObliqueAction::createActionView()
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

void SchemeObliqueAction::createActionScene()
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
