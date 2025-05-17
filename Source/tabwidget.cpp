#include "tabwidget.h"

#include "Abstract/abstractschemechartscene.h"

TabWidget::TabWidget(QList<AbstractScheme*> &schemes): schemes(schemes)
{
    for (AbstractScheme *scheme : schemes) {
        scheme->widgetCreateOrEditScheme->setWindowModality(Qt::ApplicationModal);

        this->connect(scheme->widgetCreateOrEditScheme, &AbstractSchemeWidgetCreateOrEditScheme::createOut, this, &TabWidget::createOut);
        this->connect(scheme->widgetCreateOrEditScheme, &AbstractSchemeWidgetCreateOrEditScheme::editOut, this, &TabWidget::editOut);
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

void TabWidget::editScheme()
{
    for (AbstractScheme *scheme : schemes) {
        if (scheme->typeScheme == static_cast<AbstractSchemeChartView&>(*this->currentWidget()).getTypeScheme()) {
            scheme->widgetCreateOrEditScheme->editIn(static_cast<AbstractSchemeChartView&>(*this->currentWidget()));
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

    this->addTab(&view, view.name);
    this->setCurrentWidget(&view);
    static_cast<AbstractSchemeChartScene&>(*view.scene()).updateScene();
}

void TabWidget::editOut(AbstractSchemeChartView &view)
{
    this->setTabText(this->currentIndex(), view.name);
}
