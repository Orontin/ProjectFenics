#include "schemeobliquewidgetcreateoreditscheme.h"
#include "ui_schemeobliquewidgetcreateoreditscheme.h"

#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"
#include "Scheme/Oblique/Chart/schemeobliquechartview.h"

SchemeObliqueWidgetCreateOrEditScheme::SchemeObliqueWidgetCreateOrEditScheme() :
    AbstractSchemeWidgetCreateOrEditScheme(nullptr),
    ui(new Ui::SchemeObliqueWidgetCreateOrEditScheme)
{
    this->ui->setupUi(this);

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
    this->setWindowTitle("Создать схему");
    this->ui->createOrEdit->setText("Создать");
    this->ui->groupBox_2->setCheckable(false);
    this->ui->groupBox_2->setTitle("");

    this->ui->name->setText(SchemeObliqueChartScene::defaultNameScheme);

    this->show();
}

void SchemeObliqueWidgetCreateOrEditScheme::editIn(AbstractSchemeChartView &view)
{
    this->ui->countThreads->setValue(static_cast<SchemeObliqueChartScene&>(*view.scene()).getSizeThread());
    this->ui->countHalfrow->setValue(static_cast<SchemeObliqueChartScene&>(*view.scene()).getSizeHalfrow());
    this->ui->nodeOf1_2->setChecked(static_cast<SchemeObliqueChartScene&>(*view.scene()).getIsNode1_2());
    this->ui->nodeOf2_3->setChecked(!static_cast<SchemeObliqueChartScene&>(*view.scene()).getIsNode1_2());

    this->setWindowTitle("Изменить схему");
    this->ui->createOrEdit->setText("Изменить");
    this->ui->groupBox_2->setCheckable(true);
    this->ui->groupBox_2->setTitle("Изменить всю схему");

    this->ui->name->setText(view.name);

    this->view = &view;

    this->show();
}

void SchemeObliqueWidgetCreateOrEditScheme::on_createOrEdit_clicked()
{
    if (this->ui->groupBox_2->isCheckable()) {
        this->view->name = this->ui->name->text();
        if (this->ui->groupBox_2->isChecked()) {
            static_cast<SchemeObliqueChartScene&>(*view->scene()).editScene(this->ui->countThreads->value(), this->ui->countHalfrow->value(), this->ui->nodeOf1_2->isChecked());
        }
        emit this->editOut(*this->view);
    } else {
        emit this->createOut(*(new SchemeObliqueChartView(this->ui->countThreads->value(), this->ui->countHalfrow->value(), this->ui->nodeOf1_2->isChecked(), this->ui->name->text())));
    }
    on_cancel_clicked();
}

void SchemeObliqueWidgetCreateOrEditScheme::on_cancel_clicked()
{
    this->view = nullptr;
    this->close();
}
