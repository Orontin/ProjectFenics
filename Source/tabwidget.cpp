#include "tabwidget.h"

#include "Abstract/abstractschemechartscene.h"

TabWidget::TabWidget(QList<AbstractScheme*> &schemes): schemes(schemes)
{
    for (AbstractScheme *scheme : schemes) {
        scheme->widgetCreateScheme->setWindowModality(Qt::ApplicationModal);
        this->connect(scheme->widgetCreateScheme, &AbstractSchemeWidgetCreateScheme::createOut, this, &TabWidget::createOut);
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
            scheme->widgetCreateScheme->createIn();
        }
    }
}

void TabWidget::deleteScheme()
{
    delete this->currentWidget();
}

void TabWidget::createOut(AbstractSchemeChartView &view)
{
    this->addTab(&view, view.name);
    this->setCurrentWidget(&view);
    static_cast<AbstractSchemeChartScene&>(*view.scene()).updateScene();
}
