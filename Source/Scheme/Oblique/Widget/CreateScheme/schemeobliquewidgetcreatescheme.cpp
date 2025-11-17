#include "schemeobliquewidgetcreatescheme.h"

#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"
#include "Scheme/Oblique/Chart/schemeobliquechartview.h"

SchemeObliqueWidgetCreateScheme *SchemeObliqueWidgetCreateScheme::schemeObliqueWidgetCreateScheme{nullptr};

SchemeObliqueWidgetCreateScheme &SchemeObliqueWidgetCreateScheme::getInstance(AbstractScheme &scheme)
{
    if (!SchemeObliqueWidgetCreateScheme::schemeObliqueWidgetCreateScheme) {
        SchemeObliqueWidgetCreateScheme::schemeObliqueWidgetCreateScheme = new SchemeObliqueWidgetCreateScheme(scheme);
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
    emit this->createOut(*(new SchemeObliqueChartView(this->countThreads.value(), this->countHalfrow.value(), this->nodeOf1_2.isChecked(), this->name.text(), scheme)));
    this->onCancelClicked();
}

SchemeObliqueWidgetCreateScheme::SchemeObliqueWidgetCreateScheme(AbstractScheme &scheme): scheme(scheme)
{
    this->labelCountThread.setText("Количество нитей");
    this->verticalLayoutLabel.addWidget(&this->labelCountThread);
    this->labelCountRow.setText("Количество строк");
    this->verticalLayoutLabel.addWidget(&this->labelCountRow);

    this->horizontalLayoutCount.addLayout(&this->verticalLayoutLabel);

    this->countThreads.setMinimum(3);
    this->countThreads.setMaximum(2147483647);
    this->verticalLayoutSpinBox.addWidget(&this->countThreads);

    this->countHalfrow.setMinimum(2);
    this->countHalfrow.setMaximum(2147483647);
    this->verticalLayoutSpinBox.addWidget(&this->countHalfrow);

    this->horizontalLayoutCount.addLayout(&this->verticalLayoutSpinBox);

    this->nodeOf2_3.setText("Нити 2 - 3");
    this->gridLayoutFirstName.addWidget(&this->nodeOf2_3, 1, 0, 1, 1);

    this->nodeOf1_2.setChecked(true);
    this->nodeOf1_2.setText("Нити 1 - 2");
    this->gridLayoutFirstName.addWidget(&this->nodeOf1_2, 0, 0, 1, 1);

    this->groupBoxFirstNode.setTitle("Первый узел");
    this->groupBoxFirstNode.setLayout(&this->gridLayoutFirstName);

    this->gridLayout.addWidget(&this->groupBoxFirstNode, 1, 0, 1, 1);

    this->gridLayout.addLayout(&this->horizontalLayoutCount, 0, 0, 1, 1);

    this->groupBox.setTitle(QString());
    this->groupBox.setEnabled(true);
    this->groupBox.setCheckable(false);

    this->groupBox.setLayout(&this->gridLayout);

    this->gridLayoutGroupBox.addWidget(&this->groupBox, 0, 0, 1, 1);

    this->labelName.setText("Имя");
    this->horizontalLayoutName.addWidget(&this->labelName);
    this->horizontalLayoutName.addWidget(&this->name);
    this->gridLayoutGroupBox.addLayout(&this->horizontalLayoutName, 1, 0, 1, 1);

    this->create.setText("Создать");
    this->horizontalLayoutButton.addWidget(&this->create);
    this->cancel.setText("Отменить");
    this->horizontalLayoutButton.addWidget(&this->cancel);
    this->gridLayoutGroupBox.addLayout(&this->horizontalLayoutButton, 2, 0, 1, 1);

    this->setLayout(&this->gridLayoutGroupBox);

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
