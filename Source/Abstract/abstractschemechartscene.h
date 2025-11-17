#ifndef ABSTRACTSCHEMECHARTSCENE_H
#define ABSTRACTSCHEMECHARTSCENE_H

#include <QGraphicsScene>
#include <QMenu>

class AbstractSchemeChartScene : public QGraphicsScene
{
    Q_OBJECT

public:
    virtual void updateScene() = 0;
};

#endif // ABSTRACTSCHEMECHARTSCENE_H
