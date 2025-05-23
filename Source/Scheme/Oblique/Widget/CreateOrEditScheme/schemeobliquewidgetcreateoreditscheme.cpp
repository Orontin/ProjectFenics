#include "schemeobliquewidgetcreateoreditscheme.h"
#include "ui_schemeobliquewidgetcreateoreditscheme.h"

#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"
#include "Scheme/Oblique/Chart/schemeobliquechartview.h"

SchemeObliqueWidgetCreateOrEditScheme::SchemeObliqueWidgetCreateOrEditScheme() :
    AbstractSchemeWidgetCreateOrEditScheme(nullptr),
    ui(new Ui::SchemeObliqueWidgetCreateOrEditScheme)
{
    this->ui->setupUi(this);

    this->setWindowTitle("Создать схему");

    this->ui->countHalfrow->setMinimum(SchemeObliqueChartScene::defaultCountHalfrow);
    this->ui->countHalfrow->setMaximum(SchemeObliqueChartScene::maximumCount);
    this->ui->countThreads->setMinimum(SchemeObliqueChartScene::defaultCountThread);
    this->ui->countThreads->setMaximum(SchemeObliqueChartScene::maximumCount);
}

SchemeObliqueWidgetCreateOrEditScheme::~SchemeObliqueWidgetCreateOrEditScheme()
{
    delete this->ui;
}

void SchemeObliqueWidgetCreateOrEditScheme::createIn()
{
    this->ui->name->setText(SchemeObliqueChartScene::defaultNameScheme);
    this->show();
}

void SchemeObliqueWidgetCreateOrEditScheme::on_cancel_clicked()
{
    this->close();
}

void SchemeObliqueWidgetCreateOrEditScheme::on_create_clicked()
{
    emit this->createOut(*(new SchemeObliqueChartView(this->ui->countThreads->value(), this->ui->countHalfrow->value(), this->ui->nodeOf1_2->isChecked(), this->ui->name->text())));
    on_cancel_clicked();
}
