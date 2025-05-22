#include "eventabstractschemechartscenedirections.h"

#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"

EventAbstractSchemeChartSceneDirections::EventAbstractSchemeChartSceneDirections(SchemeObliqueChartScene &scene, const AbstractSchemeChartScene::Directions &direction, const QBrush &brush, const QList<SchemeObliqueObjectNode::DirectionsNode> &directionNode):
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
    AbstractSchemeChartScene::Directions directionReverse;
    switch (direction) {
    case AbstractSchemeChartScene::Directions::ADD_TOP:
        directionReverse = AbstractSchemeChartScene::Directions::REMOVE_TOP;
        break;
    case AbstractSchemeChartScene::Directions::ADD_BOTTOM:
        directionReverse = AbstractSchemeChartScene::Directions::REMOVE_BOTTOM;
        break;
    case AbstractSchemeChartScene::Directions::ADD_LEFT:
        directionReverse = AbstractSchemeChartScene::Directions::REMOVE_LEFT;
        break;
    case AbstractSchemeChartScene::Directions::ADD_RIGHT:
        directionReverse = AbstractSchemeChartScene::Directions::REMOVE_RIGHT;
        break;
    case AbstractSchemeChartScene::Directions::REMOVE_TOP:
        directionReverse = AbstractSchemeChartScene::Directions::ADD_TOP;
        break;
    case AbstractSchemeChartScene::Directions::REMOVE_BOTTOM:
        directionReverse = AbstractSchemeChartScene::Directions::ADD_BOTTOM;
        break;
    case AbstractSchemeChartScene::Directions::REMOVE_LEFT:
        directionReverse = AbstractSchemeChartScene::Directions::ADD_LEFT;
        break;
    case AbstractSchemeChartScene::Directions::REMOVE_RIGHT:
        directionReverse = AbstractSchemeChartScene::Directions::ADD_RIGHT;
        break;
    }
    scene.editFromHistory(directionReverse, directionNode, brush);
}
