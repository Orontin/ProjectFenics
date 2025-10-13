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
    virtual void setMenuHistory(QMenu &menuHistory) = 0;
    virtual void setMenuManagment(QMenu &menuManagment) = 0;
    virtual void setMenuSettingsOpenScheme(QMenu &menuSettingsOpenScheme) = 0;
    virtual void onUpdateShortcut() = 0;
};

#endif // ABSTRACTSCHEMECHARTSCENE_H
