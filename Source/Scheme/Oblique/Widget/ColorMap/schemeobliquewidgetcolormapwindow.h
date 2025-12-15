#ifndef SCHEMEOBLIQUEWIDGETCOLORMAPWINDOW_H
#define SCHEMEOBLIQUEWIDGETCOLORMAPWINDOW_H

#include <QWidget>
#include <QGridLayout>

#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"

class SchemeObliqueWidgetColorMapWindow : public QWidget
{
    Q_OBJECT

public:
    static SchemeObliqueWidgetColorMapWindow &getInstance();

    void visibleSchemeObliqueChartScene(SchemeObliqueChartScene *scene);
    void visible(const bool &isVisible);

private:
    explicit SchemeObliqueWidgetColorMapWindow(QWidget *parent = nullptr);
    ~SchemeObliqueWidgetColorMapWindow();

    void setVisibleWidget(const bool &isVisible);

    static SchemeObliqueWidgetColorMapWindow *schemeObliqueWidgetColorMapWindow;

    QGridLayout gridLayout;
};

#endif // SCHEMEOBLIQUEWIDGETCOLORMAPWINDOW_H
