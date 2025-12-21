#include "schemeobliquewidgetcolormapwindow.h"

#include "Scheme/Oblique/Widget/ColorMap/Chart/schemeobliquewidgetcolormapchartview.h"

#include "Scheme/Oblique/File/Setting/schemeobliquefilesettings.h"

SchemeObliqueWidgetColorMapWindow *SchemeObliqueWidgetColorMapWindow::schemeObliqueWidgetColorMapWindow{nullptr};

SchemeObliqueWidgetColorMapWindow &SchemeObliqueWidgetColorMapWindow::getInstance()
{
    if (!SchemeObliqueWidgetColorMapWindow::schemeObliqueWidgetColorMapWindow) {
        SchemeObliqueWidgetColorMapWindow::schemeObliqueWidgetColorMapWindow = new SchemeObliqueWidgetColorMapWindow;
    }
    return *SchemeObliqueWidgetColorMapWindow::schemeObliqueWidgetColorMapWindow;
}

void SchemeObliqueWidgetColorMapWindow::onUpdateShortcutView()
{
    actionZoomOut.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutViewZoomOut());
    actionZoomIn.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutViewZoomIn());
    actionToBottom.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutViewToBottom());
    actionToTop.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutViewToTop());
    actionToLeft.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutViewToLeft());
    actionToRight.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutViewToRight());
    actionRotateLeft.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutViewRotateLeft());
    actionRotateRight.setShortcuts(SchemeObliqueFileSettings::getListShortcutActionSchemeObliqueShortcutViewRotateRight());
}

void SchemeObliqueWidgetColorMapWindow::visibleSchemeObliqueChartScene(SchemeObliqueChartScene *scene)
{
    SchemeObliqueWidgetColorMapChartView::getInstance().setSchemeObliqueChartScene(scene);
    setVisibleWidget(SchemeObliqueFileSettings::getColorMapVisible());
}

void SchemeObliqueWidgetColorMapWindow::visible(const bool &visible)
{
    SchemeObliqueFileSettings::setColorMapVisible(visible);
    setVisibleWidget(visible);
}

void SchemeObliqueWidgetColorMapWindow::moveEvent(QMoveEvent *event)
{
    Q_UNUSED(event)

    SchemeObliqueFileSettings::setColorMapWindowX(this->geometry().x());
    SchemeObliqueFileSettings::setColorMapWindowY(this->geometry().y());

    SchemeObliqueFileSettings::setColorMapWindowScreenWidth(this->screen()->geometry().width());
    SchemeObliqueFileSettings::setColorMapWindowScreenHeight(this->screen()->geometry().height());
}

void SchemeObliqueWidgetColorMapWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)

    SchemeObliqueFileSettings::setColorMapWindowWidth(this->geometry().width());
    SchemeObliqueFileSettings::setColorMapWindowHeight(this->geometry().height());

    SchemeObliqueFileSettings::setColorMapWindowScreenWidth(this->screen()->geometry().width());
    SchemeObliqueFileSettings::setColorMapWindowScreenHeight(this->screen()->geometry().height());
}

SchemeObliqueWidgetColorMapWindow::SchemeObliqueWidgetColorMapWindow(QWidget *parent): QWidget(parent)
{
    this->setWindowTitle("Карта цветов");
    this->setWindowFlag(Qt::Window);
    this->setWindowFlag(Qt::WindowCloseButtonHint, false);
    this->setWindowFlag(Qt::WindowMinimizeButtonHint, false);
    this->setWindowFlag(Qt::WindowMaximizeButtonHint, true);
    this->setAttribute(Qt::WA_QuitOnClose, false);
    this->setPosition();

    this->gridLayout.setSpacing(0);
    this->gridLayout.setContentsMargins(0, 0, 0, 0);
    this->gridLayout.setMenuBar(&this->menuBar);
    this->gridLayout.addWidget(&SchemeObliqueWidgetColorMapChartView::getInstance());
    this->setLayout(&this->gridLayout);

    this->view.setTitle("Вид");
    this->menuBar.addMenu(&this->view);

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

    this->view.addMenu(&this->menuZoom);
    this->view.addMenu(&this->menuTo);
    this->view.addMenu(&this->menuRotate);

    connect(&this->actionZoomOut, &QAction::triggered, &SchemeObliqueWidgetColorMapChartView::getInstance(), &SchemeObliqueWidgetColorMapChartView::zoomOut);
    connect(&this->actionZoomIn, &QAction::triggered, &SchemeObliqueWidgetColorMapChartView::getInstance(), &SchemeObliqueWidgetColorMapChartView::zoomIn);
    connect(&this->actionToBottom, &QAction::triggered, &SchemeObliqueWidgetColorMapChartView::getInstance(), &SchemeObliqueWidgetColorMapChartView::toBottom);
    connect(&this->actionToTop, &QAction::triggered, &SchemeObliqueWidgetColorMapChartView::getInstance(), &SchemeObliqueWidgetColorMapChartView::toTop);
    connect(&this->actionToLeft, &QAction::triggered, &SchemeObliqueWidgetColorMapChartView::getInstance(), &SchemeObliqueWidgetColorMapChartView::toLeft);
    connect(&this->actionToRight, &QAction::triggered, &SchemeObliqueWidgetColorMapChartView::getInstance(), &SchemeObliqueWidgetColorMapChartView::toRight);
    connect(&this->actionRotateLeft, &QAction::triggered, &SchemeObliqueWidgetColorMapChartView::getInstance(), &SchemeObliqueWidgetColorMapChartView::rotateLeft);
    connect(&this->actionRotateRight, &QAction::triggered, &SchemeObliqueWidgetColorMapChartView::getInstance(), &SchemeObliqueWidgetColorMapChartView::rotateRight);
}

SchemeObliqueWidgetColorMapWindow::~SchemeObliqueWidgetColorMapWindow()
{

}

void SchemeObliqueWidgetColorMapWindow::setVisibleWidget(const bool &visible)
{
    if (SchemeObliqueWidgetColorMapChartView::getInstance().scene() && visible) {
        this->show();
        this->setPosition();
    } else {
        this->close();
    }
}

void SchemeObliqueWidgetColorMapWindow::setPosition()
{
    this->setGeometry(
        ((SchemeObliqueFileSettings::getColorMapWindowX() * this->screen()->geometry().width()) / SchemeObliqueFileSettings::getColorMapWindowScreenWidth()),
        ((SchemeObliqueFileSettings::getColorMapWindowY() * this->screen()->geometry().height()) / SchemeObliqueFileSettings::getColorMapWindowScreenHeight()),
        ((SchemeObliqueFileSettings::getColorMapWindowWidth() * this->screen()->geometry().width()) / SchemeObliqueFileSettings::getColorMapWindowScreenWidth()),
        ((SchemeObliqueFileSettings::getColorMapWindowHeight() * this->screen()->geometry().height()) / SchemeObliqueFileSettings::getColorMapWindowScreenHeight())
    );
}
