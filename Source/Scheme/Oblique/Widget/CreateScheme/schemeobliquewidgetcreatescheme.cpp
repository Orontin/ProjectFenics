#include "schemeobliquewidgetcreatescheme.h"

#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"
#include "Scheme/Oblique/Chart/schemeobliquechartview.h"

SchemeObliqueWidgetCreateScheme *SchemeObliqueWidgetCreateScheme::schemeObliqueWidgetCreateScheme{nullptr};

SchemeObliqueWidgetCreateScheme &SchemeObliqueWidgetCreateScheme::getInstance()
{
    if (!SchemeObliqueWidgetCreateScheme::schemeObliqueWidgetCreateScheme) {
        SchemeObliqueWidgetCreateScheme::schemeObliqueWidgetCreateScheme = new SchemeObliqueWidgetCreateScheme;
    }
    return *SchemeObliqueWidgetCreateScheme::schemeObliqueWidgetCreateScheme;
}

void SchemeObliqueWidgetCreateScheme::createIn()
{
    this->name.setText(SchemeObliqueChartScene::defaultNameScheme);
    this->show();
}

void SchemeObliqueWidgetCreateScheme::onCancelClicked()
{
    this->close();
}

void SchemeObliqueWidgetCreateScheme::onCreateClicked()
{
    emit this->createOut(*(new SchemeObliqueChartView(this->countThreads.value(), this->countHalfrow.value(), this->nodeOf1_2.isChecked(), this->name.text())));
    this->onCancelClicked();
}

SchemeObliqueWidgetCreateScheme::SchemeObliqueWidgetCreateScheme()
{
    this->setupUi();

    this->setWindowTitle("Создать схему");
    this->resize(300, 250);
    this->setMinimumSize(300, 250);
    this->setMaximumSize(300, 250);

    this->setWindowModality(Qt::ApplicationModal);

    this->countHalfrow.setMinimum(SchemeObliqueChartScene::defaultCountHalfrow);
    this->countHalfrow.setMaximum(SchemeObliqueChartScene::maximumCount);
    this->countThreads.setMinimum(SchemeObliqueChartScene::defaultCountThread);
    this->countThreads.setMaximum(SchemeObliqueChartScene::maximumCount);

    connect(&this->create, &QPushButton::clicked, this, &SchemeObliqueWidgetCreateScheme::onCreateClicked);
    connect(&this->cancel, &QPushButton::clicked, this, &SchemeObliqueWidgetCreateScheme::onCancelClicked);
}

SchemeObliqueWidgetCreateScheme::~SchemeObliqueWidgetCreateScheme()
{

}
