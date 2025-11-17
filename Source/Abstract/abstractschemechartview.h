#ifndef ABSTRACTSCHEMECHARTVIEW_H
#define ABSTRACTSCHEMECHARTVIEW_H

#include <QGraphicsView>
#include <QMenu>

class AbstractScheme;

class AbstractSchemeChartView : public QGraphicsView
{
    Q_OBJECT

public:
    AbstractSchemeChartView(const QString &name, AbstractScheme &scheme): name(name), scheme(scheme) {};
    ~AbstractSchemeChartView() {};

    AbstractScheme &getScheme() { return this->scheme; };

    const QString name;

private:
    AbstractScheme &scheme;
};

#endif // ABSTRACTSCHEMECHARTVIEW_H
