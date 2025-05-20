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

}

void SchemeObliqueSatelliteHistory::addHistory(const AbstractSchemeChartScene::Directions &direction)
{
    qCritical() << 1;
    events.push_back(new EventAbstractSchemeChartSceneDirections(*scene, direction));
    iterator = events.size() - 1;
    qCritical() << "e" << iterator;
}

void SchemeObliqueSatelliteHistory::back()
{
    qCritical() << 2;
    if (iterator > -1) {
        events[iterator]->back();
        iterator = iterator - 1;
    } else {
        //
    }
    qCritical() << "e" << iterator;
}

void SchemeObliqueSatelliteHistory::next()
{
    qCritical() << 3;
    qCritical() << "e" << iterator;
    if (iterator < events.size() - 1) {
        iterator = iterator + 1;
        qCritical() << "e" << iterator;
        events[iterator]->next();
    } else {
        //
    }
    qCritical() << "e" << iterator;
}
