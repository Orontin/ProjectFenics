#ifndef SCHEMEOBLIQUEWIDGETCREATESCHEME_H
#define SCHEMEOBLIQUEWIDGETCREATESCHEME_H

#include <QWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QSpinBox>
#include <QVBoxLayout>

#include "Abstract/abstractschemechartview.h"

class SchemeObliqueWidgetCreateScheme: public QWidget
{
    Q_OBJECT

public:
    static SchemeObliqueWidgetCreateScheme &getInstance();

public slots:
    void createIn();

signals:
    void createOut(AbstractSchemeChartView &view);

private slots:
    void onCancelClicked();
    void onCreateClicked();

private:
    explicit SchemeObliqueWidgetCreateScheme();
    ~SchemeObliqueWidgetCreateScheme();

    static SchemeObliqueWidgetCreateScheme *schemeObliqueWidgetCreateScheme;

    QGridLayout gridLayout;
    QGroupBox groupBox;
    QGridLayout gridLayoutGroupBox;
    QGroupBox groupBoxFirstNode;
    QGridLayout gridLayoutFirstName;
    QRadioButton nodeOf2_3;
    QRadioButton nodeOf1_2;
    QHBoxLayout horizontalLayoutCount;
    QVBoxLayout verticalLayoutLabel;
    QLabel labelCountThread;
    QLabel labelCountRow;
    QVBoxLayout verticalLayoutSpinBox;
    QSpinBox countThreads;
    QSpinBox countHalfrow;
    QHBoxLayout horizontalLayoutName;
    QLabel labelName;
    QLineEdit name;
    QHBoxLayout horizontalLayoutButton;
    QPushButton create;
    QPushButton cancel;

    void setupUi()
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
    }
};

#endif // SCHEMEOBLIQUEWIDGETCREATESCHEME_H
