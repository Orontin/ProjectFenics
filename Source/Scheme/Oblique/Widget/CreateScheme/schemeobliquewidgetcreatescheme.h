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
    static SchemeObliqueWidgetCreateScheme &getInstance(AbstractScheme &scheme);

public slots:
    void createIn();

signals:
    void createOut(AbstractSchemeChartView &view);

private slots:
    void onCancelClicked();
    void onCreateClicked();

private:
    explicit SchemeObliqueWidgetCreateScheme(AbstractScheme &scheme);
    ~SchemeObliqueWidgetCreateScheme();

    static SchemeObliqueWidgetCreateScheme *schemeObliqueWidgetCreateScheme;
    AbstractScheme &scheme;

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
};

#endif // SCHEMEOBLIQUEWIDGETCREATESCHEME_H
