#ifndef EVENTABSTRACTSCHEMECHARTSCENEDIRECTIONS_H
#define EVENTABSTRACTSCHEMECHARTSCENEDIRECTIONS_H

#include "event.h"

#include "Abstract/abstractschemechartscene.h"
#include "Scheme/Oblique/Object/schemeobliqueobjectnode.h"

class SchemeObliqueChartScene;

class EventAbstractSchemeChartSceneDirections: public Event
{
public:
    EventAbstractSchemeChartSceneDirections(SchemeObliqueChartScene &scene,
                                            const AbstractSchemeChartScene::Directions &direction,
                                            const QBrush &brush,
                                            const QList<SchemeObliqueObjectNode::DirectionsNode> &directionNode);
    ~EventAbstractSchemeChartSceneDirections();

    void next();
    void back();

private:
    const AbstractSchemeChartScene::Directions direction;
    const QBrush brush;
    const QList<SchemeObliqueObjectNode::DirectionsNode> directionNode;
};

#endif // EVENTABSTRACTSCHEMECHARTSCENEDIRECTIONS_H
