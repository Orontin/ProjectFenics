#include "schemeobliquewidgeteditdirectionfornewnodechartview.h"

#include "Scheme/Oblique/Widget/EditDirectionForNewNode/Chart/schemeobliquewidgeteditdirectionfornewnodechartscene.h"

SchemeObliqueWidgetEditDirectionForNewNodeChartView::SchemeObliqueWidgetEditDirectionForNewNodeChartView()
{
    this->setScene(new SchemeObliqueWidgetEditDirectionForNewNodeChartScene());

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

SchemeObliqueWidgetEditDirectionForNewNodeChartView::~SchemeObliqueWidgetEditDirectionForNewNodeChartView()
{
    delete this->scene();
}
