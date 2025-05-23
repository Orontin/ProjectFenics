#include "tabwidget.h"

#include "Abstract/abstractschemechartscene.h"

TabWidget::TabWidget(QList<AbstractScheme*> &schemes): schemes(schemes)
{
    for (AbstractScheme *scheme : schemes) {
        scheme->widgetCreateOrEditScheme->setWindowModality(Qt::ApplicationModal);
        this->connect(scheme->widgetCreateOrEditScheme, &AbstractSchemeWidgetCreateOrEditScheme::createOut, this, &TabWidget::createOut);
    }
}

TabWidget::~TabWidget()
{
    while (this->count()) {
        deleteScheme();
    }
}

AbstractSchemeChartView &TabWidget::getCurrentScheme()
{
    return *static_cast<AbstractSchemeChartView*>(this->currentWidget());
}

void TabWidget::addScheme(const QString &typeScheme)
{
    for (AbstractScheme *scheme : schemes) {
        if (scheme->typeScheme == typeScheme) {
            scheme->widgetCreateOrEditScheme->createIn();
        }
    }
}

void TabWidget::deleteScheme()
{
    delete this->currentWidget();
}

void TabWidget::createOut(AbstractSchemeChartView &view)
{
    this->connect(&static_cast<AbstractSchemeChartScene&>(*view.scene()), &AbstractSchemeChartScene::enabledRemoveNode, this, &TabWidget::enabledRemoveHalfrow);
    this->connect(&static_cast<AbstractSchemeChartScene&>(*view.scene()), &AbstractSchemeChartScene::enabledRemoveThread, this, &TabWidget::enabledRemoveThread);
    this->connect(&static_cast<AbstractSchemeChartScene&>(*view.scene()), &AbstractSchemeChartScene::enabledAddedThread, this, &TabWidget::enabledAddedThread);
    this->connect(&static_cast<AbstractSchemeChartScene&>(*view.scene()), &AbstractSchemeChartScene::enabledAddedNode, this, &TabWidget::enabledAddedHalfrow);

    this->connect(&static_cast<AbstractSchemeChartScene&>(*view.scene()), &AbstractSchemeChartScene::enabledHistoryBack, this, &TabWidget::enabledHistoryBack);
    this->connect(&static_cast<AbstractSchemeChartScene&>(*view.scene()), &AbstractSchemeChartScene::enabledHistoryNext, this, &TabWidget::enabledHistoryNext);

    this->addTab(&view, view.name);
    this->setCurrentWidget(&view);
    static_cast<AbstractSchemeChartScene&>(*view.scene()).updateScene();
}
