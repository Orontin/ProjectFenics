#ifndef SCHEMEOBLIQUEWIDGETCREATESCHEMEWINDOW_H
#define SCHEMEOBLIQUEWIDGETCREATESCHEMEWINDOW_H

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

class SchemeObliqueWidgetCreateSchemeWindow: public QWidget
{
    Q_OBJECT

public:
    static SchemeObliqueWidgetCreateSchemeWindow &getInstance(AbstractScheme &scheme);

public slots:
    void createIn();

signals:
    void createOut(AbstractSchemeChartView &view);

protected:
    void moveEvent(QMoveEvent *event) override final;
    void resizeEvent(QResizeEvent *event) override final;

private slots:
    void onCancelClicked();
    void onCreateClicked();

private:
    explicit SchemeObliqueWidgetCreateSchemeWindow(AbstractScheme &scheme);
    ~SchemeObliqueWidgetCreateSchemeWindow();

    void visible();
    void setPosition();

    static SchemeObliqueWidgetCreateSchemeWindow *schemeObliqueWidgetCreateSchemeWindow;
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

#endif // SCHEMEOBLIQUEWIDGETCREATESCHEMEWINDOW_H
