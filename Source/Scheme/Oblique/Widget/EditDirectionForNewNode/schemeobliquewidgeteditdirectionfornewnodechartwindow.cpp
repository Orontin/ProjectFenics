#include "schemeobliquewidgeteditdirectionfornewnodechartwindow.h"

#include "Scheme/Oblique/Widget/EditDirectionForNewNode/Chart/schemeobliquewidgeteditdirectionfornewnodechartview.h"

SchemeObliqueWidgetEditDirectionForNewNodeWindow *SchemeObliqueWidgetEditDirectionForNewNodeWindow::schemeObliqueWidgetEditDirectionForNewNodeWindow{nullptr};

SchemeObliqueWidgetEditDirectionForNewNodeWindow &SchemeObliqueWidgetEditDirectionForNewNodeWindow::getInstance()
{
    if (!SchemeObliqueWidgetEditDirectionForNewNodeWindow::schemeObliqueWidgetEditDirectionForNewNodeWindow) {
        SchemeObliqueWidgetEditDirectionForNewNodeWindow::schemeObliqueWidgetEditDirectionForNewNodeWindow = new SchemeObliqueWidgetEditDirectionForNewNodeWindow;
    }
    return *SchemeObliqueWidgetEditDirectionForNewNodeWindow::schemeObliqueWidgetEditDirectionForNewNodeWindow;
}

void SchemeObliqueWidgetEditDirectionForNewNodeWindow::open()
{
    this->show();
}

SchemeObliqueWidgetEditDirectionForNewNodeWindow::SchemeObliqueWidgetEditDirectionForNewNodeWindow(QWidget *parent): QWidget(parent)
{
    this->setWindowTitle("Изменить направление новых узлов");
    this->resize(380, 450);
    this->setMinimumSize(380, 450);
    this->setMaximumSize(380, 450);

    this->setWindowModality(Qt::ApplicationModal);

    this->setLayout(&this->gridLayout);
    this->gridLayout.setSpacing(0);
    this->gridLayout.setContentsMargins(0, 0, 0, 0);

    this->gridLayout.addWidget(&SchemeObliqueWidgetEditDirectionForNewNodeChartView::getInstance());
}

SchemeObliqueWidgetEditDirectionForNewNodeWindow::~SchemeObliqueWidgetEditDirectionForNewNodeWindow()
{

}
