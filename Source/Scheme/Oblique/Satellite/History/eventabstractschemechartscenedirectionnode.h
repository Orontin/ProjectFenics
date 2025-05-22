#ifndef EVENTABSTRACTSCHEMECHARTSCENEDIRECTIONNODE_H
#define EVENTABSTRACTSCHEMECHARTSCENEDIRECTIONNODE_H

#include "event.h"

#include "Scheme/Oblique/Object/schemeobliqueobjectnode.h"

class SchemeObliqueChartScene;

class EventAbstractSchemeChartSceneDirectionNode: public Event
{
public:
    EventAbstractSchemeChartSceneDirectionNode(SchemeObliqueChartScene &scene,
                                               const int &numberRow,
                                               const int &numberColumn,
                                               const SchemeObliqueObjectNode::DirectionsNode &directionsNodeNext,
                                               const SchemeObliqueObjectNode::DirectionsNode &directionsNodeBack);
    ~EventAbstractSchemeChartSceneDirectionNode();

    void next();
    void back();

private:
    const int numberRow;
    const int numberColumn;
    const SchemeObliqueObjectNode::DirectionsNode directionsNodeNext;
    const SchemeObliqueObjectNode::DirectionsNode directionsNodeBack;
};

#endif // EVENTABSTRACTSCHEMECHARTSCENEDIRECTIONNODE_H
