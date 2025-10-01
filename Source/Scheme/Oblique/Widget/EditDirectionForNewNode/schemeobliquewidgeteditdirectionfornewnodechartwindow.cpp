#include "schemeobliquewidgeteditdirectionfornewnodechartwindow.h"
#include "ui_schemeobliquewidgeteditdirectionfornewnodechartwindow.h"

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

SchemeObliqueWidgetEditDirectionForNewNodeWindow::SchemeObliqueWidgetEditDirectionForNewNodeWindow(QWidget *parent):
    QWidget(parent),
    ui(new Ui::SchemeObliqueWidgetEditDirectionForNewNodeWindow)
{
    ui->setupUi(this);

    this->setWindowModality(Qt::ApplicationModal);

    this->ui->centralWidget->addWidget(&SchemeObliqueWidgetEditDirectionForNewNodeChartView::getInstance());

    this->setWindowTitle("Изменить направление новых узлов");
}

SchemeObliqueWidgetEditDirectionForNewNodeWindow::~SchemeObliqueWidgetEditDirectionForNewNodeWindow()
{
    delete this->ui;
}
