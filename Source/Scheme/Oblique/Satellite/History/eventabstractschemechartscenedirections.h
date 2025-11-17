#ifndef EVENTABSTRACTSCHEMECHARTSCENEDIRECTIONS_H
#define EVENTABSTRACTSCHEMECHARTSCENEDIRECTIONS_H

#include "event.h"

#include "Scheme/Oblique/schemeoblique.h"
#include "Scheme/Oblique/Object/schemeobliqueobjectnode.h"

class SchemeObliqueChartScene;

class EventAbstractSchemeChartSceneDirections: public Event
{
public:
    EventAbstractSchemeChartSceneDirections(SchemeObliqueChartScene &scene,
                                            const SchemeOblique::Directions &direction,
                                            const QBrush &brush,
                                            const QList<SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode> &directionNode);
    ~EventAbstractSchemeChartSceneDirections();

    void next();
    void back();

private:
    const SchemeOblique::Directions direction;
    const QBrush brush;
    const QList<SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode> directionNode;
};

#endif // EVENTABSTRACTSCHEMECHARTSCENEDIRECTIONS_H
