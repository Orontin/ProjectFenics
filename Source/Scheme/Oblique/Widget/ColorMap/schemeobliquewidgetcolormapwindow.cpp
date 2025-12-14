#include "schemeobliquewidgetcolormapwindow.h"

#include "Scheme/Oblique/Widget/ColorMap/Chart/schemeobliquewidgetcolormapchartview.h"

SchemeObliqueWidgetColorMapWindow *SchemeObliqueWidgetColorMapWindow::schemeObliqueWidgetColorMapWindow{nullptr};

SchemeObliqueWidgetColorMapWindow &SchemeObliqueWidgetColorMapWindow::getInstance()
{
    if (!SchemeObliqueWidgetColorMapWindow::schemeObliqueWidgetColorMapWindow) {
        SchemeObliqueWidgetColorMapWindow::schemeObliqueWidgetColorMapWindow = new SchemeObliqueWidgetColorMapWindow;
    }
    return *SchemeObliqueWidgetColorMapWindow::schemeObliqueWidgetColorMapWindow;
}

void SchemeObliqueWidgetColorMapWindow::visible(const bool &isVisible)
{
    if (isVisible) {
        this->show();
    } else {
        this->close();
    }
}

void SchemeObliqueWidgetColorMapWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event)
    emit this->closed();
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
