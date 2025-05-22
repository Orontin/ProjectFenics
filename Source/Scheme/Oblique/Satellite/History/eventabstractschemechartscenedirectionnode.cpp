#include "eventabstractschemechartscenedirectionnode.h"

#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"

EventAbstractSchemeChartSceneDirectionNode::EventAbstractSchemeChartSceneDirectionNode(SchemeObliqueChartScene &scene,
                                                                                       const int &numberRow,
                                                                                       const int &numberColumn,
                                                                                       const SchemeObliqueObjectNode::DirectionsNode &directionsNodeNext,
                                                                                       const SchemeObliqueObjectNode::DirectionsNode &directionsNodeBack):
    Event(scene),
    numberRow(numberRow),
    numberColumn(numberColumn),
    directionsNodeNext(directionsNodeNext),
    directionsNodeBack(directionsNodeBack)
{

}

EventAbstractSchemeChartSceneDirectionNode::~EventAbstractSchemeChartSceneDirectionNode()
{

}

void EventAbstractSchemeChartSceneDirectionNode::next()
{
    scene.editFromHistory(numberRow, numberColumn, directionsNodeNext);
}

void EventAbstractSchemeChartSceneDirectionNode::back()
{
    scene.editFromHistory(numberRow, numberColumn, directionsNodeBack);
}
