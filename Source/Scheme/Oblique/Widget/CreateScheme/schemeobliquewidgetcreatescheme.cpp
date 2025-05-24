#include "schemeobliquewidgetcreatescheme.h"
#include "ui_schemeobliquewidgetcreatescheme.h"

#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"
#include "Scheme/Oblique/Chart/schemeobliquechartview.h"

SchemeObliqueWidgetCreateScheme::SchemeObliqueWidgetCreateScheme() :
    AbstractSchemeWidgetCreateScheme(nullptr),
    ui(new Ui::SchemeObliqueWidgetCreateScheme)
{
    this->ui->setupUi(this);

    this->setWindowTitle("Создать схему");

    this->ui->countHalfrow->setMinimum(SchemeObliqueChartScene::defaultCountHalfrow);
    this->ui->countHalfrow->setMaximum(SchemeObliqueChartScene::maximumCount);
    this->ui->countThreads->setMinimum(SchemeObliqueChartScene::defaultCountThread);
    this->ui->countThreads->setMaximum(SchemeObliqueChartScene::maximumCount);
}

SchemeObliqueWidgetCreateScheme::~SchemeObliqueWidgetCreateScheme()
{
    delete this->ui;
}

void SchemeObliqueWidgetCreateScheme::createIn()
{
    this->ui->name->setText(SchemeObliqueChartScene::defaultNameScheme);
    this->show();
}

void SchemeObliqueWidgetCreateScheme::on_cancel_clicked()
{
    this->close();
}

void SchemeObliqueWidgetCreateScheme::on_create_clicked()
{
    emit this->createOut(*(new SchemeObliqueChartView(this->ui->countThreads->value(), this->ui->countHalfrow->value(), this->ui->nodeOf1_2->isChecked(), this->ui->name->text())));
    on_cancel_clicked();
}
