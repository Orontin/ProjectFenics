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

    AbstractSchemeChartView &getCurrentScheme();

public slots:
    void addScheme(const QString &typeScheme);
    void deleteScheme();

public slots:
    void createOut(AbstractSchemeChartView &view);

signals:
    void enabledRemoveHalfrow(const bool &enabled);
    void enabledRemoveThread(const bool &enabled);
    void enabledAddedThread(const bool &enabled);
    void enabledAddedHalfrow(const bool &enabled);

    void enabledHistoryBack(const bool &enabled);
    void enabledHistoryNext(const bool &enabled);

private:
    QList<AbstractScheme*> &schemes;
    QMap<const AbstractSchemeChartView*, const QString*> mapViewType;
};

#endif // TABWIDGET_H
