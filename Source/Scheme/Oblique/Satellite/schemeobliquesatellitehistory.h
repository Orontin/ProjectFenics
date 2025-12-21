#ifndef SCHEMEOBLIQUESATELLITEHISTORY_H
#define SCHEMEOBLIQUESATELLITEHISTORY_H

#include <QObject>

#include "Scheme/Oblique/schemeoblique.h"

#include "Scheme/Oblique/Satellite/History/event.h"
#include "Scheme/Oblique/Satellite/History/eventabstractschemechartscenedirectionnode.h"
#include "Scheme/Oblique/Satellite/History/eventabstractschemechartscenedirections.h"
#include "Scheme/Oblique/Satellite/History/eventabstractschemechartscenesetcolorthread.h"

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

    void addHistory(const int &numberRow, const int &numberColumn, const SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode &directionsNodeNext, const SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode &directionsNodeBack);
    void addHistory(const int &numberThread, const QBrush &brushNext, const QBrush &brushBack);
    void addHistory(const SchemeOblique::Directions &direction, const QBrush &brush, const QList<SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode> &directionNode);

    void back();
    void next();

private:
    SchemeObliqueChartScene *scene;

    QList<Event*> events;
    int iterator;
};

#endif // SCHEMEOBLIQUESATELLITEHISTORY_H
