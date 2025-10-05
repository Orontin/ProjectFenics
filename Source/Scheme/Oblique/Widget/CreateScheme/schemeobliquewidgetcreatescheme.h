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

    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QGroupBox *groupBoxFirstNode;
    QGridLayout *gridLayout_2;
    QRadioButton *nodeOf2_3;
    QRadioButton *nodeOf1_2;
    QHBoxLayout *horizontalLayoutCount;
    QVBoxLayout *verticalLayoutLabel;
    QLabel *labelCountThread;
    QLabel *labelCountRow;
    QVBoxLayout *verticalLayoutBox;
    QSpinBox *countThreads;
    QSpinBox *countHalfrow;
    QHBoxLayout *horizontalLayoutName;
    QLabel *label_name;
    QLineEdit *name;
    QHBoxLayout *horizontalLayoutButton;
    QPushButton *create;
    QPushButton *cancel;

    void setupUi()
    {
        gridLayout_3 = new QGridLayout(this);
        gridLayout_3->setObjectName("gridLayout_3");
        groupBox = new QGroupBox(this);
        groupBox->setObjectName("groupBox");
        groupBox->setEnabled(true);
        groupBox->setCheckable(false);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        groupBoxFirstNode = new QGroupBox(groupBox);
        groupBoxFirstNode->setObjectName("groupBoxFirstNode");
        gridLayout_2 = new QGridLayout(groupBoxFirstNode);
        gridLayout_2->setObjectName("gridLayout_2");
        nodeOf2_3 = new QRadioButton(groupBoxFirstNode);
        nodeOf2_3->setObjectName("nodeOf2_3");

        gridLayout_2->addWidget(nodeOf2_3, 1, 0, 1, 1);

        nodeOf1_2 = new QRadioButton(groupBoxFirstNode);
        nodeOf1_2->setObjectName("nodeOf1_2");
        nodeOf1_2->setChecked(true);

        gridLayout_2->addWidget(nodeOf1_2, 0, 0, 1, 1);


        gridLayout->addWidget(groupBoxFirstNode, 1, 0, 1, 1);

        horizontalLayoutCount = new QHBoxLayout();
        horizontalLayoutCount->setObjectName("horizontalLayoutCount");
        verticalLayoutLabel = new QVBoxLayout();
        verticalLayoutLabel->setObjectName("verticalLayoutLabel");
        labelCountThread = new QLabel(groupBox);
        labelCountThread->setObjectName("labelCountThread");

        verticalLayoutLabel->addWidget(labelCountThread);

        labelCountRow = new QLabel(groupBox);
        labelCountRow->setObjectName("labelCountRow");

        verticalLayoutLabel->addWidget(labelCountRow);


        horizontalLayoutCount->addLayout(verticalLayoutLabel);

        verticalLayoutBox = new QVBoxLayout();
        verticalLayoutBox->setObjectName("verticalLayoutBox");
        countThreads = new QSpinBox(groupBox);
        countThreads->setObjectName("countThreads");
        countThreads->setMinimum(3);
        countThreads->setMaximum(2147483647);

        verticalLayoutBox->addWidget(countThreads);

        countHalfrow = new QSpinBox(groupBox);
        countHalfrow->setObjectName("countHalfrow");
        countHalfrow->setMinimum(2);
        countHalfrow->setMaximum(2147483647);

        verticalLayoutBox->addWidget(countHalfrow);


        horizontalLayoutCount->addLayout(verticalLayoutBox);


        gridLayout->addLayout(horizontalLayoutCount, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        horizontalLayoutName = new QHBoxLayout();
        horizontalLayoutName->setObjectName("horizontalLayoutName");
        label_name = new QLabel(this);
        label_name->setObjectName("label_name");

        horizontalLayoutName->addWidget(label_name);

        name = new QLineEdit(this);
        name->setObjectName("name");

        horizontalLayoutName->addWidget(name);


        gridLayout_3->addLayout(horizontalLayoutName, 1, 0, 1, 1);

        horizontalLayoutButton = new QHBoxLayout();
        horizontalLayoutButton->setObjectName("horizontalLayoutButton");
        create = new QPushButton(this);
        create->setObjectName("create");

        horizontalLayoutButton->addWidget(create);

        cancel = new QPushButton(this);
        cancel->setObjectName("cancel");

        horizontalLayoutButton->addWidget(cancel);

        gridLayout_3->addLayout(horizontalLayoutButton, 2, 0, 1, 1);

        this->groupBox->setTitle(QString());
        this->groupBoxFirstNode->setTitle("Первый узел");
        this->nodeOf2_3->setText("Нити 2 - 3");
        this->nodeOf1_2->setText("Нити 1 - 2");
        this->labelCountThread->setText("Количество нитей");
        this->labelCountRow->setText("Количество строк");
        this->label_name->setText("Имя");
        this->create->setText("Создать");
        this->cancel->setText("Отменить");
    }
};

#endif // SCHEMEOBLIQUEWIDGETCREATESCHEME_H
