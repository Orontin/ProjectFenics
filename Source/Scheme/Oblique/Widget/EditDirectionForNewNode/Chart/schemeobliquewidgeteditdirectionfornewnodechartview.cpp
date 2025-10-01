#include "schemeobliquewidgeteditdirectionfornewnodechartview.h"

#include "Scheme/Oblique/Widget/EditDirectionForNewNode/Chart/schemeobliquewidgeteditdirectionfornewnodechartscene.h"

SchemeObliqueWidgetEditDirectionForNewNodeChartView *SchemeObliqueWidgetEditDirectionForNewNodeChartView::schemeObliqueWidgetEditDirectionForNewNodeChartView{nullptr};

SchemeObliqueWidgetEditDirectionForNewNodeChartView &SchemeObliqueWidgetEditDirectionForNewNodeChartView::getInstance()
{
    if (!SchemeObliqueWidgetEditDirectionForNewNodeChartView::schemeObliqueWidgetEditDirectionForNewNodeChartView) {
        SchemeObliqueWidgetEditDirectionForNewNodeChartView::schemeObliqueWidgetEditDirectionForNewNodeChartView = new SchemeObliqueWidgetEditDirectionForNewNodeChartView;
    }
    return *schemeObliqueWidgetEditDirectionForNewNodeChartView;
}

SchemeObliqueWidgetEditDirectionForNewNodeChartView::SchemeObliqueWidgetEditDirectionForNewNodeChartView()
{
    this->setScene(&SchemeObliqueWidgetEditDirectionForNewNodeChartScene::getInstance());

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

SchemeObliqueWidgetEditDirectionForNewNodeChartView::~SchemeObliqueWidgetEditDirectionForNewNodeChartView()
{
    delete this->scene();
}
