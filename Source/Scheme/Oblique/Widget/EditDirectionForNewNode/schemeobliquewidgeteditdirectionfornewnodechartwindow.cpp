#include "schemeobliquewidgeteditdirectionfornewnodechartwindow.h"
#include "ui_schemeobliquewidgeteditdirectionfornewnodechartwindow.h"

SchemeObliqueWidgetEditDirectionForNewNodeWindow::SchemeObliqueWidgetEditDirectionForNewNodeWindow(QWidget *parent):
    QWidget(parent),
    ui(new Ui::SchemeObliqueWidgetEditDirectionForNewNodeWindow),
    schemeObliqueWidgetEditDirectionForNewNodeChartView(*(new SchemeObliqueWidgetEditDirectionForNewNodeChartView))
{
    ui->setupUi(this);

    this->setWindowModality(Qt::ApplicationModal);

    this->ui->centralWidget->addWidget(&schemeObliqueWidgetEditDirectionForNewNodeChartView);

    this->setWindowTitle("Изменить направление новых узлов");
}

SchemeObliqueWidgetEditDirectionForNewNodeWindow::~SchemeObliqueWidgetEditDirectionForNewNodeWindow()
{
    delete this->ui;
}

void SchemeObliqueWidgetEditDirectionForNewNodeWindow::open()
{
    this->show();
}
