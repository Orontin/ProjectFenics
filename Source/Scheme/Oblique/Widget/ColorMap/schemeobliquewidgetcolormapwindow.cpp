#include "schemeobliquewidgetcolormapwindow.h"

#include "Scheme/Oblique/Widget/ColorMap/Chart/schemeobliquewidgetcolormapchartview.h"

#include "Scheme/Oblique/File/Setting/schemeobliquefilesetting.h"

SchemeObliqueWidgetColorMapWindow *SchemeObliqueWidgetColorMapWindow::schemeObliqueWidgetColorMapWindow{nullptr};

SchemeObliqueWidgetColorMapWindow &SchemeObliqueWidgetColorMapWindow::getInstance()
{
    if (!SchemeObliqueWidgetColorMapWindow::schemeObliqueWidgetColorMapWindow) {
        SchemeObliqueWidgetColorMapWindow::schemeObliqueWidgetColorMapWindow = new SchemeObliqueWidgetColorMapWindow;
    }
    return *SchemeObliqueWidgetColorMapWindow::schemeObliqueWidgetColorMapWindow;
}

void SchemeObliqueWidgetColorMapWindow::visibleSchemeObliqueChartScene(SchemeObliqueChartScene *scene)
{
    SchemeObliqueWidgetColorMapChartView::getInstance().setSchemeObliqueChartScene(scene);
    setVisibleWidget(SchemeObliqueFileSetting::getVisibleColorMap());
}

void SchemeObliqueWidgetColorMapWindow::visible(const bool &isVisible)
{
    SchemeObliqueFileSetting::setVisibleColorMap(isVisible);
    setVisibleWidget(isVisible);
}

void SchemeObliqueWidgetColorMapWindow::onUpdateShortcutView()
{
    actionZoomOut.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutViewZoomOut());
    actionZoomIn.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutViewZoomIn());
    actionToBottom.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutViewToBottom());
    actionToTop.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutViewToTop());
    actionToLeft.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutViewToLeft());
    actionToRight.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutViewToRight());
    actionRotateLeft.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutViewRotateLeft());
    actionRotateRight.setShortcuts(SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutViewRotateRight());
}

SchemeObliqueWidgetColorMapWindow::SchemeObliqueWidgetColorMapWindow(QWidget *parent): QWidget(parent)
{
    this->setWindowTitle("Карта цветов");
    this->resize(300, 600);

    this->setLayout(&this->gridLayout);
    this->gridLayout.setSpacing(0);
    this->gridLayout.setContentsMargins(0, 0, 0, 0);

    this->view.setTitle("Вид");

    this->createActionView();
    this->setMenuView();

    this->menuBar.addMenu(&this->view);
    this->gridLayout.setMenuBar(&this->menuBar);

    this->gridLayout.addWidget(&SchemeObliqueWidgetColorMapChartView::getInstance());

    this->connects();
}

SchemeObliqueWidgetColorMapWindow::~SchemeObliqueWidgetColorMapWindow()
{

}

void SchemeObliqueWidgetColorMapWindow::setVisibleWidget(const bool &isVisible)
{
    if (SchemeObliqueWidgetColorMapChartView::getInstance().scene() && isVisible) {
        this->show();
    } else {
        this->close();
    }
}

void SchemeObliqueWidgetColorMapWindow::createActionView()
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

void SchemeObliqueWidgetColorMapWindow::setMenuView()
{
    this->view.addMenu(&this->menuZoom);
    this->view.addMenu(&this->menuTo);
    this->view.addMenu(&this->menuRotate);
}

void SchemeObliqueWidgetColorMapWindow::connects()
{
    connect(&this->actionZoomOut, &QAction::triggered, &SchemeObliqueWidgetColorMapChartView::getInstance(), &SchemeObliqueWidgetColorMapChartView::zoomOut);
    connect(&this->actionZoomIn, &QAction::triggered, &SchemeObliqueWidgetColorMapChartView::getInstance(), &SchemeObliqueWidgetColorMapChartView::zoomIn);
    connect(&this->actionToBottom, &QAction::triggered, &SchemeObliqueWidgetColorMapChartView::getInstance(), &SchemeObliqueWidgetColorMapChartView::toBottom);
    connect(&this->actionToTop, &QAction::triggered, &SchemeObliqueWidgetColorMapChartView::getInstance(), &SchemeObliqueWidgetColorMapChartView::toTop);
    connect(&this->actionToLeft, &QAction::triggered, &SchemeObliqueWidgetColorMapChartView::getInstance(), &SchemeObliqueWidgetColorMapChartView::toLeft);
    connect(&this->actionToRight, &QAction::triggered, &SchemeObliqueWidgetColorMapChartView::getInstance(), &SchemeObliqueWidgetColorMapChartView::toRight);
    connect(&this->actionRotateLeft, &QAction::triggered, &SchemeObliqueWidgetColorMapChartView::getInstance(), &SchemeObliqueWidgetColorMapChartView::rotateLeft);
    connect(&this->actionRotateRight, &QAction::triggered, &SchemeObliqueWidgetColorMapChartView::getInstance(), &SchemeObliqueWidgetColorMapChartView::rotateRight);
}
