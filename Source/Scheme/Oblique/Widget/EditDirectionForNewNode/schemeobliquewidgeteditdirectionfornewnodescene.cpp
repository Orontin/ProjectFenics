#include "schemeobliquewidgeteditdirectionfornewnodescene.h"

#include "Scheme/Oblique/File/Setting/schemeobliquefilesetting.h"
#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"

SchemeObliqueWidgetEditDirectionForNewNodeScene::SchemeObliqueWidgetEditDirectionForNewNodeScene():
    node(new SchemeObliqueObjectNode(QPoint(0, 0), SchemeObliqueObjectNode::standartDirectionObliqueNode)),
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

SchemeObliqueWidgetEditDirectionForNewNodeScene::~SchemeObliqueWidgetEditDirectionForNewNodeScene()
{
    delete this->partLeftTop;
    delete this->partLeftBottom;
    delete this->partRightTop;
    delete this->partRightBottom;

    delete this->node;
}

void SchemeObliqueWidgetEditDirectionForNewNodeScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem *item = this->itemAt(event->scenePos(), QTransform());
    SchemeObliqueObjectNode *node = dynamic_cast<SchemeObliqueObjectNode *>(item);
    if (node) {
        node->click();
        SchemeObliqueObjectNode::standartDirectionObliqueNode = node->directionNode;
        SchemeObliqueFileSetting::setStandartDirectionObliqueNode(SchemeObliqueObjectNode::standartDirectionObliqueNode);
    }
}
