#ifndef SCHEMEOBLIQUESATELLITEHISTORY_H
#define SCHEMEOBLIQUESATELLITEHISTORY_H

#include <QObject>

#include "Abstract/abstractschemechartscene.h"
#include "Scheme/Oblique/Object/schemeobliqueobjectnode.h"

#include "Scheme/Oblique/Satellite/History/event.h"
#include "Scheme/Oblique/Satellite/History/eventabstractschemechartscenedirections.h"

#include <QDebug>

class SchemeObliqueChartScene;

class SchemeObliqueSatelliteHistory: public QObject
{
    Q_OBJECT
public:
    SchemeObliqueSatelliteHistory(SchemeObliqueChartScene *scene, QObject *parent = nullptr);
    ~SchemeObliqueSatelliteHistory();

    int getIterator();
    int getIteratorMaximum();
    int getIteratorMinimum();

    void addHistory(const AbstractSchemeChartScene::Directions &direction, const QList<QBrush> &brush, const QList<SchemeObliqueObjectNode::DirectionsNode> &directionNode);
    void back();
    void next();

private:
    SchemeObliqueChartScene *scene;

    QList<Event*> events;
    int iterator;
};

#endif // SCHEMEOBLIQUESATELLITEHISTORY_H
