#ifndef ABSTRACTSCHEMECHARTVIEW_H
#define ABSTRACTSCHEMECHARTVIEW_H

#include <QGraphicsView>
#include <QMenu>

class AbstractSchemeChartView : public QGraphicsView
{
    Q_OBJECT

public:
    AbstractSchemeChartView(const QString &name): name(name) {};
    ~AbstractSchemeChartView() {};

    virtual QMenu &getMenuView() = 0;

    QString name;

protected:
    QMenu menuView;
};

#endif // ABSTRACTSCHEMECHARTVIEW_H
