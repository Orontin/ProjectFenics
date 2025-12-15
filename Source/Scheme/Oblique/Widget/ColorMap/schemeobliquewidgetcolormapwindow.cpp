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

SchemeObliqueWidgetColorMapWindow::SchemeObliqueWidgetColorMapWindow(QWidget *parent): QWidget(parent)
{
    this->setWindowTitle("Карта цветов");
    this->resize(300, 600);

    this->setLayout(&this->gridLayout);
    this->gridLayout.setSpacing(0);
    this->gridLayout.setContentsMargins(0, 0, 0, 0);

    this->gridLayout.addWidget(&SchemeObliqueWidgetColorMapChartView::getInstance());
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
