#ifndef SCHEMEOBLIQUEWIDGETCREATESCHEME_H
#define SCHEMEOBLIQUEWIDGETCREATESCHEME_H

#include <QWidget>

#include "Abstract/abstractschemechartview.h"

namespace Ui {
class SchemeObliqueWidgetCreateScheme;
}

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

    Ui::SchemeObliqueWidgetCreateScheme *ui;
};

#endif // SCHEMEOBLIQUEWIDGETCREATESCHEME_H
