#include "schemeobliquesatellitehistory.h"

#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"

SchemeObliqueSatelliteHistory::SchemeObliqueSatelliteHistory(SchemeObliqueChartScene *scene, QObject *parent):
    QObject{parent},
    scene(scene),
    events(QList<Event*>()),
    iterator(-1)
{

}

SchemeObliqueSatelliteHistory::~SchemeObliqueSatelliteHistory()
{
    for (Event *event : events) {
        delete event;
    }
    events.clear();
}

int SchemeObliqueSatelliteHistory::getIterator()
{
    return iterator;
}

int SchemeObliqueSatelliteHistory::getIteratorMaximum()
{
    return events.size() - 1;
}

int SchemeObliqueSatelliteHistory::getIteratorMinimum()
{
    return -1;
}

void SchemeObliqueSatelliteHistory::addHistory(const AbstractSchemeChartScene::Directions &direction, const QList<QBrush> &brush, const QList<SchemeObliqueObjectNode::DirectionsNode> &directionNode)
{
    int eventsSize = events.size();
    for (int i = iterator + 1; i > -1 && i < eventsSize; i++) {
        delete events.back();
        events.pop_back();
    }
    events.push_back(new EventAbstractSchemeChartSceneDirections(*scene, direction, brush, directionNode));
    iterator = events.size() - 1;
}

void SchemeObliqueSatelliteHistory::back()
{
    if (iterator > -1) {
        int tmpIterator = iterator;
        iterator = iterator - 1;
        events[tmpIterator]->back();
    }
}

void SchemeObliqueSatelliteHistory::next()
{
    if (iterator < events.size() - 1) {
        iterator = iterator + 1;
        events[iterator]->next();
    }
}
