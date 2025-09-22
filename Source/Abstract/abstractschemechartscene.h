#ifndef ABSTRACTSCHEMECHARTSCENE_H
#define ABSTRACTSCHEMECHARTSCENE_H

#include <QGraphicsScene>
#include <QMenu>

class AbstractSchemeChartScene : public QGraphicsScene
{
    Q_OBJECT

public:
    virtual void updateScene() = 0;
    virtual void backHistory() = 0;
    virtual void nextHistory() = 0;

    virtual QMenu &getMenuHistory() = 0;
    virtual QMenu &getMenuManagment() = 0;
    virtual QMenu &getMenuSettings() = 0;

protected:
    QMenu menuHistory;
    QMenu menuManagment;
    QMenu menuSettings;
};

#endif // ABSTRACTSCHEMECHARTSCENE_H
