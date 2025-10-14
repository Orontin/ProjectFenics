#include "tabwidget.h"

TabWidget::TabWidget(QList<AbstractScheme*> &schemes): schemes(schemes)
{
    for (AbstractScheme *scheme : schemes) {
        this->connect(scheme, &AbstractScheme::createOut, this, &TabWidget::createOut);
    }
}

TabWidget::~TabWidget()
{
    while (this->count()) {
        deleteView();
    }
}

AbstractSchemeChartView &TabWidget::getCurrentView()
{
    return *static_cast<AbstractSchemeChartView*>(this->currentWidget());
}

void TabWidget::deleteView()
{
    delete this->currentWidget();
}

void TabWidget::createOut(AbstractSchemeChartView &view)
{
    this->addTab(&view, view.name);
    this->setCurrentWidget(&view);
}
