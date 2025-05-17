#ifndef ABSTRACTSCHEMECHARTVIEW_H
#define ABSTRACTSCHEMECHARTVIEW_H

#include <QGraphicsView>

class AbstractSchemeChartView : public QGraphicsView
{
    Q_OBJECT

public:
    AbstractSchemeChartView(const QString &name): name(name) {};
    ~AbstractSchemeChartView() {};

    virtual const QString &getTypeScheme() = 0;

    virtual void toRight() = 0;
    virtual void toLeft() = 0;
    virtual void toTop() = 0;
    virtual void toBottom() = 0;

    virtual void zoomIn() = 0;
    virtual void zoomOut() = 0;

    virtual void rotateRight() = 0;
    virtual void rotateLeft() = 0;

    QString name;
};

#endif // ABSTRACTSCHEMECHARTVIEW_H
