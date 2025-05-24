#ifndef SCHEMEOBLIQUESATELLITEHISTORY_H
#define SCHEMEOBLIQUESATELLITEHISTORY_H

#include <QObject>

#include "Abstract/abstractschemechartscene.h"
#include "Scheme/Oblique/Object/schemeobliqueobjectnode.h"

#include "Scheme/Oblique/Satellite/History/event.h"
#include "Scheme/Oblique/Satellite/History/eventabstractschemechartscenedirectionnode.h"
#include "Scheme/Oblique/Satellite/History/eventabstractschemechartscenedirections.h"
#include "Scheme/Oblique/Satellite/History/eventabstractschemechartscenesetcolorthread.h"


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

    void addHistory(const int &numberRow, const int &numberColumn, const SchemeObliqueObjectNode::DirectionsNode &directionsNodeNext, const SchemeObliqueObjectNode::DirectionsNode &directionsNodeBack);
    void addHistory(const int &numberThread, const QBrush &brushNext, const QBrush &brushBack);
    void addHistory(const AbstractSchemeChartScene::Directions &direction, const QBrush &brush, const QList<SchemeObliqueObjectNode::DirectionsNode> &directionNode);

    void back();
    void next();

private:
    SchemeObliqueChartScene *scene;

    QList<Event*> events;
    int iterator;
};

#endif // SCHEMEOBLIQUESATELLITEHISTORY_H
