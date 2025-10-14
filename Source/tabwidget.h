#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>

#include "Abstract/abstractscheme.h"

class TabWidget : public QTabWidget
{
    Q_OBJECT

public:
    TabWidget(QList<AbstractScheme*> &schemes);
    ~TabWidget();

    AbstractSchemeChartView &getCurrentView();

public slots:
    void deleteView();

public slots:
    void createOut(AbstractSchemeChartView &view);

private:
    QList<AbstractScheme*> &schemes;
    QMap<const AbstractSchemeChartView*, const QString*> mapViewType;
};

#endif // TABWIDGET_H
