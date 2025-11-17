#include "eventabstractschemechartscenedirections.h"

#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"

EventAbstractSchemeChartSceneDirections::EventAbstractSchemeChartSceneDirections(SchemeObliqueChartScene &scene, const SchemeOblique::Directions &direction, const QBrush &brush, const QList<SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode> &directionNode):
    Event(scene),
    direction(direction),
    brush(brush),
    directionNode(directionNode)
{

}

EventAbstractSchemeChartSceneDirections::~EventAbstractSchemeChartSceneDirections()
{

}

void EventAbstractSchemeChartSceneDirections::next()
{
    scene.editFromHistory(direction, directionNode, brush);
}

void EventAbstractSchemeChartSceneDirections::back()
{
    SchemeOblique::Directions directionReverse;
    switch (direction) {
    case SchemeOblique::Directions::ADD_TOP:
        directionReverse = SchemeOblique::Directions::REMOVE_TOP;
        break;
    case SchemeOblique::Directions::ADD_BOTTOM:
        directionReverse = SchemeOblique::Directions::REMOVE_BOTTOM;
        break;
    case SchemeOblique::Directions::ADD_LEFT:
        directionReverse = SchemeOblique::Directions::REMOVE_LEFT;
        break;
    case SchemeOblique::Directions::ADD_RIGHT:
        directionReverse = SchemeOblique::Directions::REMOVE_RIGHT;
        break;
    case SchemeOblique::Directions::REMOVE_TOP:
        directionReverse = SchemeOblique::Directions::ADD_TOP;
        break;
    case SchemeOblique::Directions::REMOVE_BOTTOM:
        directionReverse = SchemeOblique::Directions::ADD_BOTTOM;
        break;
    case SchemeOblique::Directions::REMOVE_LEFT:
        directionReverse = SchemeOblique::Directions::ADD_LEFT;
        break;
    case SchemeOblique::Directions::REMOVE_RIGHT:
        directionReverse = SchemeOblique::Directions::ADD_RIGHT;
        break;
    }
    scene.editFromHistory(directionReverse, directionNode, brush);
}
