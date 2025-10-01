#ifndef SCHEMEOBLIQUEWIDGETEDITDIRECTIONFORNEWNODECHARTVIEW_H
#define SCHEMEOBLIQUEWIDGETEDITDIRECTIONFORNEWNODECHARTVIEW_H

#include <QGraphicsView>

class SchemeObliqueWidgetEditDirectionForNewNodeChartView : public QGraphicsView
{
    Q_OBJECT

public:
    static SchemeObliqueWidgetEditDirectionForNewNodeChartView &getInstance();

private:
    SchemeObliqueWidgetEditDirectionForNewNodeChartView();
    ~SchemeObliqueWidgetEditDirectionForNewNodeChartView();

    static SchemeObliqueWidgetEditDirectionForNewNodeChartView *schemeObliqueWidgetEditDirectionForNewNodeChartView;
};

#endif // SCHEMEOBLIQUEWIDGETEDITDIRECTIONFORNEWNODECHARTVIEW_H
