#ifndef SCHEMEOBLIQUESATELLITEHISTORY_H
#define SCHEMEOBLIQUESATELLITEHISTORY_H

#include <QObject>

#include "Abstract/abstractschemechartscene.h"

class Event
{
public:
    Event(AbstractSchemeChartScene &scene): scene(scene) {};

    virtual void next() = 0;
    virtual void back() = 0;

protected:
    AbstractSchemeChartScene &scene;
};

class EventAbstractSchemeChartSceneDirections: public Event
{
public:
    EventAbstractSchemeChartSceneDirections(AbstractSchemeChartScene &scene, const AbstractSchemeChartScene::Directions &direction): Event(scene), direction(direction) {};

    void next() {
        scene.editNodes(direction, true, false);
    };
    void back() {
        AbstractSchemeChartScene::Directions directionReverse;
        switch (direction) {
        case AbstractSchemeChartScene::Directions::ADD_TOP:
            directionReverse = AbstractSchemeChartScene::Directions::REMOVE_TOP;
            break;
        case AbstractSchemeChartScene::Directions::ADD_BOTTOM:
            directionReverse = AbstractSchemeChartScene::Directions::REMOVE_TOP;
            break;
        case AbstractSchemeChartScene::Directions::ADD_LEFT:
            directionReverse = AbstractSchemeChartScene::Directions::REMOVE_LEFT;
            break;
        case AbstractSchemeChartScene::Directions::ADD_RIGHT:
            directionReverse = AbstractSchemeChartScene::Directions::REMOVE_RIGHT;
            break;
        case AbstractSchemeChartScene::Directions::REMOVE_TOP:
            directionReverse = AbstractSchemeChartScene::Directions::ADD_TOP;
            break;
        case AbstractSchemeChartScene::Directions::REMOVE_BOTTOM:
            directionReverse = AbstractSchemeChartScene::Directions::ADD_BOTTOM;
            break;
        case AbstractSchemeChartScene::Directions::REMOVE_LEFT:
            directionReverse = AbstractSchemeChartScene::Directions::ADD_LEFT;
            break;
        case AbstractSchemeChartScene::Directions::REMOVE_RIGHT:
            directionReverse = AbstractSchemeChartScene::Directions::ADD_RIGHT;
            break;
        }
        scene.editNodes(directionReverse, true, false);
    };

private:
    const AbstractSchemeChartScene::Directions direction;
};

class SchemeObliqueChartScene;

class SchemeObliqueSatelliteHistory: public QObject
{
    Q_OBJECT
public:
    SchemeObliqueSatelliteHistory(SchemeObliqueChartScene *scene, QObject *parent = nullptr);
    ~SchemeObliqueSatelliteHistory();

    void addHistory(const AbstractSchemeChartScene::Directions &direction);
    void back();
    void next();

private:
    SchemeObliqueChartScene *scene;

    QList<Event*> events;
    int iterator;
};

#endif // SCHEMEOBLIQUESATELLITEHISTORY_H
