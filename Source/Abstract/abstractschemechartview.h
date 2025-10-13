#ifndef ABSTRACTSCHEMECHARTVIEW_H
#define ABSTRACTSCHEMECHARTVIEW_H

#include <QGraphicsView>
#include <QMenu>

class AbstractScheme;

class AbstractSchemeChartView : public QGraphicsView
{
    Q_OBJECT

public:
    AbstractSchemeChartView(const QString &name): name(name) {};
    ~AbstractSchemeChartView() {};

    virtual void setMenuView(QMenu &menuView) = 0;
    virtual void onUpdateShortcut() = 0;
    virtual const QString &getTypeScheme() = 0;

    const QString name;
};

#endif // ABSTRACTSCHEMECHARTVIEW_H
