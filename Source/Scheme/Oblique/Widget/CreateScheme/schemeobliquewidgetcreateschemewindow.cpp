#include "schemeobliquewidgetcreateschemewindow.h"

#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"
#include "Scheme/Oblique/Chart/schemeobliquechartview.h"

#include "Scheme/Oblique/File/Setting/schemeobliquefilesettings.h"

#include <QScreen>

SchemeObliqueWidgetCreateSchemeWindow *SchemeObliqueWidgetCreateSchemeWindow::schemeObliqueWidgetCreateSchemeWindow{nullptr};

SchemeObliqueWidgetCreateSchemeWindow &SchemeObliqueWidgetCreateSchemeWindow::getInstance(AbstractScheme &scheme)
{
    if (!SchemeObliqueWidgetCreateSchemeWindow::schemeObliqueWidgetCreateSchemeWindow) {
        SchemeObliqueWidgetCreateSchemeWindow::schemeObliqueWidgetCreateSchemeWindow = new SchemeObliqueWidgetCreateSchemeWindow(scheme);
    }
    return *SchemeObliqueWidgetCreateSchemeWindow::schemeObliqueWidgetCreateSchemeWindow;
}

void SchemeObliqueWidgetCreateSchemeWindow::createIn()
{
    this->name.setText(SchemeObliqueChartScene::defaultNameScheme);
    this->visible();
}

void SchemeObliqueWidgetCreateSchemeWindow::moveEvent(QMoveEvent *event)
{
    Q_UNUSED(event)

    SchemeObliqueFileSettings::setCreateSchemeWindowX(this->geometry().x());
    SchemeObliqueFileSettings::setCreateSchemeWindowY(this->geometry().y());

    SchemeObliqueFileSettings::setCreateSchemeWindowScreenWidth(this->screen()->geometry().width());
    SchemeObliqueFileSettings::setCreateSchemeWindowScreenHeight(this->screen()->geometry().height());
}

void SchemeObliqueWidgetCreateSchemeWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)

    SchemeObliqueFileSettings::setCreateSchemeWindowWidth(this->geometry().width());
    SchemeObliqueFileSettings::setCreateSchemeWindowHeight(this->geometry().height());

    SchemeObliqueFileSettings::setCreateSchemeWindowScreenWidth(this->screen()->geometry().width());
    SchemeObliqueFileSettings::setCreateSchemeWindowScreenHeight(this->screen()->geometry().height());
}

void SchemeObliqueWidgetCreateSchemeWindow::onCancelClicked()
{
    this->close();
}

void SchemeObliqueWidgetCreateSchemeWindow::onCreateClicked()
{
    emit this->createOut(*(new SchemeObliqueChartView(this->countThreads.value(), this->countHalfrow.value(), this->nodeOf1_2.isChecked(), this->name.text(), scheme)));
    this->onCancelClicked();
}

SchemeObliqueWidgetCreateSchemeWindow::SchemeObliqueWidgetCreateSchemeWindow(AbstractScheme &scheme): scheme(scheme)
{
    this->setWindowTitle("Создать схему");
    this->setWindowModality(Qt::ApplicationModal);
    this->setPosition();

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

    this->countHalfrow.setMinimum(SchemeObliqueChartScene::defaultCountHalfrow);
    this->countHalfrow.setMaximum(SchemeObliqueChartScene::maximumCount);
    this->countThreads.setMinimum(SchemeObliqueChartScene::defaultCountThread);
    this->countThreads.setMaximum(SchemeObliqueChartScene::maximumCount);

    connect(&this->create, &QPushButton::clicked, this, &SchemeObliqueWidgetCreateSchemeWindow::onCreateClicked);
    connect(&this->cancel, &QPushButton::clicked, this, &SchemeObliqueWidgetCreateSchemeWindow::onCancelClicked);
}

SchemeObliqueWidgetCreateSchemeWindow::~SchemeObliqueWidgetCreateSchemeWindow()
{

}

void SchemeObliqueWidgetCreateSchemeWindow::visible()
{
    this->show();
    this->setPosition();
}

void SchemeObliqueWidgetCreateSchemeWindow::setPosition()
{
    int screenWidth = this->screen()->geometry().width();
    int screenHeight = this->screen()->geometry().height();

    int colorMapWindowScreenWidth = SchemeObliqueFileSettings::getCreateSchemeWindowScreenWidth(screenWidth);
    int colorMapWindowScreenHeight = SchemeObliqueFileSettings::getCreateSchemeWindowScreenHeight(screenHeight);

    this->setGeometry(
        ((SchemeObliqueFileSettings::getCreateSchemeWindowX(screenWidth) * screenWidth) / colorMapWindowScreenWidth),
        ((SchemeObliqueFileSettings::getCreateSchemeWindowY(screenHeight) * screenHeight) / colorMapWindowScreenHeight),
        ((SchemeObliqueFileSettings::getCreateSchemeWindowWidth() * screenWidth) / colorMapWindowScreenWidth),
        ((SchemeObliqueFileSettings::getCreateSchemeWindowHeight() * screenHeight) / colorMapWindowScreenHeight)
    );
    this->setMinimumSize(this->geometry().width(), this->geometry().height());
    this->setMaximumSize(this->geometry().width(), this->geometry().height());
}
