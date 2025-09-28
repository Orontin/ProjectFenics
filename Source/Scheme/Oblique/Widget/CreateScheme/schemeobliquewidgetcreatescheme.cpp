#include "schemeobliquewidgetcreatescheme.h"
#include "ui_schemeobliquewidgetcreatescheme.h"

#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"
#include "Scheme/Oblique/Chart/schemeobliquechartview.h"

SchemeObliqueWidgetCreateScheme::SchemeObliqueWidgetCreateScheme():
    ui(new Ui::SchemeObliqueWidgetCreateScheme)
{
    this->ui->setupUi(this);

    this->setWindowTitle("Создать схему");

    this->setWindowModality(Qt::ApplicationModal);

    this->ui->countHalfrow->setMinimum(SchemeObliqueChartScene::defaultCountHalfrow);
    this->ui->countHalfrow->setMaximum(SchemeObliqueChartScene::maximumCount);
    this->ui->countThreads->setMinimum(SchemeObliqueChartScene::defaultCountThread);
    this->ui->countThreads->setMaximum(SchemeObliqueChartScene::maximumCount);

    connect(this->ui->create, &QPushButton::clicked, this, &SchemeObliqueWidgetCreateScheme::onCreateClicked);
    connect(this->ui->cancel, &QPushButton::clicked, this, &SchemeObliqueWidgetCreateScheme::onCancelClicked);
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

void SchemeObliqueWidgetCreateScheme::onCancelClicked()
{
    this->close();
}

void SchemeObliqueWidgetCreateScheme::onCreateClicked()
{
    emit this->createOut(*(new SchemeObliqueChartView(this->ui->countThreads->value(), this->ui->countHalfrow->value(), this->ui->nodeOf1_2->isChecked(), this->ui->name->text())));
    this->onCancelClicked();
}
