#include "schemeobliquewidgeteditdirectionfornewnodechartscene.h"

#include "Scheme/Oblique/File/Setting/schemeobliquefilesettings.h"
#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"

SchemeObliqueWidgetEditDirectionForNewNodeChartScene *SchemeObliqueWidgetEditDirectionForNewNodeChartScene::schemeObliqueWidgetEditDirectionForNewNodeChartScene{nullptr};

SchemeObliqueWidgetEditDirectionForNewNodeChartScene &SchemeObliqueWidgetEditDirectionForNewNodeChartScene::getInstance()
{
    if (!SchemeObliqueWidgetEditDirectionForNewNodeChartScene::schemeObliqueWidgetEditDirectionForNewNodeChartScene) {
        SchemeObliqueWidgetEditDirectionForNewNodeChartScene::schemeObliqueWidgetEditDirectionForNewNodeChartScene = new SchemeObliqueWidgetEditDirectionForNewNodeChartScene;
    }
    return *schemeObliqueWidgetEditDirectionForNewNodeChartScene;
}

void SchemeObliqueWidgetEditDirectionForNewNodeChartScene::setStandartDirectionObliqueNode(const SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode &directionNode)
{
    SchemeObliqueWidgetEditDirectionForNewNodeChartScene::standartDirectionObliqueNode = directionNode;
}

SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode SchemeObliqueWidgetEditDirectionForNewNodeChartScene::getStandartDirectionObliqueNode()
{
    return SchemeObliqueWidgetEditDirectionForNewNodeChartScene::standartDirectionObliqueNode;
}

SchemeObliqueWidgetEditDirectionForNewNodeChartScene::SchemeObliqueWidgetEditDirectionForNewNodeChartScene():
    standartDirectionObliqueNode(SchemeObliqueFileSettings::getStandartDirectionObliqueNode()),
    node(new SchemeObliqueObjectNode(QPoint(0, 0), this->getStandartDirectionObliqueNode())),
    partLeftTop(new SchemeObliqueObjectPart(this->node->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_LEFT)),
    partLeftBottom(new SchemeObliqueObjectPart(this->node->pos, SchemeObliqueObjectPart::DirectionsPart::END_CORNER_LEFT)),
    partRightTop(new SchemeObliqueObjectPart(this->node->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_RIGHT)),
    partRightBottom(new SchemeObliqueObjectPart(this->node->pos, SchemeObliqueObjectPart::DirectionsPart::END_CORNER_RIGHT))
{
    this->setBackgroundBrush(SchemeObliqueChartScene::defaultBrush);
    this->setItemIndexMethod(NoIndex);

    this->node->partLeftTop = partLeftTop;
    this->node->partLeftBottom = partLeftBottom;
    this->node->partRightTop = partRightTop;
    this->node->partRightBottom = partRightBottom;

    this->partLeftTop->nodeBottom = node;
    this->partRightTop->nodeBottom = node;
    this->partLeftBottom->nodeTop = node;
    this->partRightBottom->nodeTop = node;

    this->addItem(this->node);

    this->addItem(this->partLeftTop);
    this->addItem(this->partLeftBottom);
    this->addItem(this->partRightTop);
    this->addItem(this->partRightBottom);
}

SchemeObliqueWidgetEditDirectionForNewNodeChartScene::~SchemeObliqueWidgetEditDirectionForNewNodeChartScene()
{
    delete this->partLeftTop;
    delete this->partLeftBottom;
    delete this->partRightTop;
    delete this->partRightBottom;

    delete this->node;
}

void SchemeObliqueWidgetEditDirectionForNewNodeChartScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem *item = this->itemAt(event->scenePos(), QTransform());
    SchemeObliqueObjectNode *node = dynamic_cast<SchemeObliqueObjectNode *>(item);
    if (node) {
        node->click();
        this->setStandartDirectionObliqueNode(node->directionNode);
        SchemeObliqueFileSettings::setStandartDirectionObliqueNode(this->getStandartDirectionObliqueNode());
    }
}
