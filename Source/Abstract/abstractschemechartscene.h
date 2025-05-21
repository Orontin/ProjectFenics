#ifndef ABSTRACTSCHEMECHARTSCENE_H
#define ABSTRACTSCHEMECHARTSCENE_H

#include <QGraphicsScene>

class AbstractSchemeChartScene : public QGraphicsScene
{
    Q_OBJECT

public:
    enum Directions {
        ADD_TOP       = 0,
        ADD_BOTTOM    = 1,
        ADD_LEFT      = 2,
        ADD_RIGHT     = 3,
        REMOVE_TOP    = 4,
        REMOVE_BOTTOM = 5,
        REMOVE_LEFT   = 6,
        REMOVE_RIGHT  = 7
    };

    virtual void updateScene() = 0;
    virtual void editNodes(const AbstractSchemeChartScene::Directions &direction, const bool &isUpdate, const bool &isSetHistory) = 0;
    virtual void backHistory() = 0;
    virtual void nextHistory() = 0;

signals:
    void enabledRemoveThread(const bool &enabled);
    void enabledRemoveNode(const bool &enabled);
    void enabledAddedThread(const bool &enabled);
    void enabledAddedNode(const bool &enabled);

    void enabledHistoryNext(const bool &enabled);
    void enabledHistoryBack(const bool &enabled);
};

#endif // ABSTRACTSCHEMECHARTSCENE_H
