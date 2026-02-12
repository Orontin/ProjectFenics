#include "schemeobliqueobjectnode.h"

#include <QPainter>

#include "Scheme/Oblique/Widget/ColorMap/Chart/schemeobliquewidgetcolormapchartview.h"

QPolygon SchemeObliqueObjectNode::POLYGON_ROMB_BIG{QPoint(0, -68), QPoint(68, 0), QPoint(0, 68), QPoint(-68, 0), QPoint(0, -68)};
QPolygon SchemeObliqueObjectNode::POLYGON_ROMB_SMALL{QPoint(0, -40), QPoint(40, 0), QPoint(0, 40), QPoint(-40, 0), QPoint(0, -40)};

QPolygon SchemeObliqueObjectNode::POLYGON_PARALLEL_LEFT_PART{QPoint(-24, 12), QPoint(-24, -12), QPoint(-12, -24), QPoint(-6, -18), QPoint(-6, 18), QPoint(-12, 24)};
QPolygon SchemeObliqueObjectNode::POLYGON_PARALLEL_RIGHT_PART{QPoint(24, 12), QPoint(24, -12), QPoint(12, -24), QPoint(6, -18), QPoint(6, 18), QPoint(12, 24)};
QList<QLine> SchemeObliqueObjectNode::LINES_PARALLEL_LEFT{{QPoint(-24, 12), QPoint(-24, -12)}, {QPoint(-12, -24), QPoint(-6, -18)}, {QPoint(-6, -18), QPoint(-6, 18)}, {QPoint(-6, 18), QPoint(-12, 24)}};
QList<QLine> SchemeObliqueObjectNode::LINES_PARALLEL_RIGHT{{QPoint(24, 12), QPoint(24, -12)}, {QPoint(12, -24), QPoint(6, -18)}, {QPoint(6, -18), QPoint(6, 18)}, {QPoint(6, 18), QPoint(12, 24)}};

QPolygon SchemeObliqueObjectNode::POLYGON_LEFT_UP__IN__LEFT_BOTTOM{QPoint(0, -36), QPoint(36, 0), QPoint(0, 36), QPoint(-36, 0), QPoint(0, -36)};
QPolygon SchemeObliqueObjectNode::POLYGON_RIGHT_UP__IN__RIGHT_BOTTOM{QPoint(0, -36), QPoint(36, 0), QPoint(0, 36), QPoint(-36, 0), QPoint(0, -36)};
QPolygon SchemeObliqueObjectNode::POLYGON_LEFT_UP__IN__RIGHT_BOTTOM{QPoint(0, -36), QPoint(36, 0), QPoint(0, 36), QPoint(-36, 0), QPoint(0, -36)};
QPolygon SchemeObliqueObjectNode::POLYGON_RIGHT_UP__IN__LEFT_BOTTOM{QPoint(0, -36), QPoint(36, 0), QPoint(0, 36), QPoint(-36, 0), QPoint(0, -36)};
QList<QLine> SchemeObliqueObjectNode::LINES_LEFT_UP__IN__LEFT_BOTTOM{{QPoint(-12, -24), QPoint(0, -36)}, {QPoint(0, -36), QPoint(36, 0)}, {QPoint(36, 0), QPoint(0, 36)}, {QPoint(0, 36), QPoint(-12, 24)}, {QPoint(-24, 12), QPoint(-36, 0)}, {QPoint(-36, 0), QPoint(-24, -12)}};
QList<QLine> SchemeObliqueObjectNode::LINES_RIGHT_UP__IN__RIGHT_BOTTOM{{QPoint(-36, 0), QPoint(0, -36)}, {QPoint(0, -36), QPoint(12, -24)}, {QPoint(24, -12), QPoint(36, 0)}, {QPoint(36, 0), QPoint(24, 12)}, {QPoint(12, 24), QPoint(0, 36)}, {QPoint(0, 36), QPoint(-36, 0)}};
QList<QLine> SchemeObliqueObjectNode::LINES_LEFT_UP__IN__RIGHT_BOTTOM{{QPoint(12, 24), QPoint(0, 36)}, {QPoint(0, 36), QPoint(-36, 0)}, {QPoint(-36, 0), QPoint(-24, -12)}, {QPoint(-12, -24), QPoint(0, -36)}, {QPoint(0, -36), QPoint(36, 0)}, {QPoint(36, 0), QPoint(24, 12)}};
QList<QLine> SchemeObliqueObjectNode::LINES_RIGHT_UP__IN__LEFT_BOTTOM{{QPoint(-36, 0), QPoint(0, -36)}, {QPoint(0, -36), QPoint(12, -24)}, {QPoint(-24, 12), QPoint(-36, 0)}, {QPoint(24, -12), QPoint(36, 0)}, {QPoint(36, 0), QPoint(0, 36)}, {QPoint(0, 36), QPoint(-12, 24)}};

QPolygon SchemeObliqueObjectNode::POLYGON_LEFT_UP__IN__LEFT_BOTTOM_ARROW{QPoint(-10, -14), QPoint(-14, -10), QPoint(-4, 0), QPoint(-8, 4), QPoint(-12, 0), QPoint(-12, 12), QPoint(0, 12), QPoint(-4, 8), QPoint(4, 0), QPoint(-10, -14)};
QPolygon SchemeObliqueObjectNode::POLYGON_RIGHT_UP__IN__RIGHT_BOTTOM_ARROW{QPoint(10, -14), QPoint(14, -10), QPoint(4, 0), QPoint(8, 4), QPoint(12, 0), QPoint(12, 12), QPoint(0, 12), QPoint(4, 8), QPoint(-4, 0), QPoint(10, -14)};
QPolygon SchemeObliqueObjectNode::POLYGON_LEFT_UP__IN__RIGHT_BOTTOM_ARROW{QPoint(-10, -14), QPoint(-14, -10), QPoint(4, 8), QPoint(0, 12), QPoint(12, 12), QPoint(12, 0), QPoint(8, 4), QPoint(-10, -14)};
QPolygon SchemeObliqueObjectNode::POLYGON_RIGHT_UP__IN__LEFT_BOTTOM_ARROW{QPoint(10, -14), QPoint(14, -10), QPoint(-4, 8), QPoint(0, 12), QPoint(-12, 12), QPoint(-12, 0), QPoint(-8, 4), QPoint(10, -14)};

QPolygon SchemeObliqueObjectNode::POLYGON_LEFT_UP__IN__RIGHT_BOTTOM_NO_NODE_LEFT{QPoint(-12, -24), QPoint(24, 12), QPoint(12, 24), QPoint(-24, -12)};
QPolygon SchemeObliqueObjectNode::POLYGON_LEFT_UP__IN__RIGHT_BOTTOM_NO_NODE_RIGHT{QPoint(12, -24), QPoint(-24, 12), QPoint(-12, 24), QPoint(24, -12)};
QList<QLine> SchemeObliqueObjectNode::LINES_LEFT_UP__IN__RIGHT_BOTTOM_NO_NODE_LEFT{{QPoint(-12, -24), QPoint(24, 12)}, {QPoint(-24, -12), QPoint(12, 24)}};
QList<QLine> SchemeObliqueObjectNode::LINES_LEFT_UP__IN__RIGHT_BOTTOM_NO_NODE_RIGHT{{QPoint(12, -24), QPoint(0, -12)}, {QPoint(24, -12), QPoint(12, 0)}, {QPoint(0, 12), QPoint(-12, 24)}, {QPoint(-12, 0), QPoint(-24, 12)}};

QPolygon SchemeObliqueObjectNode::POLYGON_RIGHT_UP__IN__LEFT_BOTTOM_NO_NODE_LEFT{QPoint(-12, -24), QPoint(24, 12), QPoint(12, 24), QPoint(-24, -12)};
QPolygon SchemeObliqueObjectNode::POLYGON_RIGHT_UP__IN__LEFT_BOTTOM_NO_NODE_RIGHT{QPoint(12, -24), QPoint(-24, 12), QPoint(-12, 24), QPoint(24, -12)};
QList<QLine> SchemeObliqueObjectNode::LINES_RIGHT_UP__IN__LEFT_BOTTOM_NO_NODE_LEFT{{QPoint(-12, -24), QPoint(0, -12)}, {QPoint(-24, -12), QPoint(-12, 0)}, {QPoint(0, 12), QPoint(12, 24)}, {QPoint(12, 0), QPoint(24, 12)}};
QList<QLine> SchemeObliqueObjectNode::LINES_RIGHT_UP__IN__LEFT_BOTTOM_NO_NODE_RIGHT{{QPoint(12, -24), QPoint(-24, 12)}, {QPoint(24, -12), QPoint(-12, 24)}};

QList<QLine> SchemeObliqueObjectNode::LINES_GAP_LEFT_UP{{QPoint(-12, -24), QPoint(-24, -12)}};
QList<QLine> SchemeObliqueObjectNode::LINES_GAP_LEFT_BOTTOM{{QPoint(-12, 24), QPoint(-24, 12)}};
QList<QLine> SchemeObliqueObjectNode::LINES_GAP_RIGHT_UP{{QPoint(12, -24), QPoint(24, -12)}};
QList<QLine> SchemeObliqueObjectNode::LINES_GAP_RIGHT_BOTTOM{{QPoint(12, 24), QPoint(24, 12)}};

SchemeObliqueObjectNode::SchemeObliqueObjectNode(const QPoint &pos, const SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode &directionNode):
    pos(pos),
    directionNode(directionNode)
{
    this->setZValue(1);
    this->graphicObjectNode.addPolygon(SchemeObliqueObjectNode::POLYGON_ROMB_SMALL.translated(pos));
    this->graphicObjectNodeMapColor.addPolygon(SchemeObliqueObjectNode::POLYGON_ROMB_BIG.translated(pos));
    editNode(directionNode);
}

SchemeObliqueObjectNode::~SchemeObliqueObjectNode()
{

}

int SchemeObliqueObjectNode::getNumberRow()
{
    int numberRow = 0;

    SchemeObliqueObjectNode *node = this;
    while (true) {
        if (node->nodeLeftTop && node->nodeLeftTop->nodeLeftBottom != node) {
            node = node->nodeLeftTop;
            numberRow++;
        } else if (node->nodeRightTop && node->nodeRightTop->nodeRightBottom != node) {
            node = node->nodeRightTop;
            numberRow++;
        } else {
            break;
        }
    }

    return numberRow;
}

int SchemeObliqueObjectNode::getNumberColumn()
{
    int numberColumn = 0;

    SchemeObliqueObjectNode *node = this;
    while (true) {
        if (node->nodeLeftBottom && node->nodeLeftBottom->nodeLeftTop && node->nodeLeftBottom->nodeLeftTop != node && node->nodeLeftBottom->nodeLeftTop != node->nodeLeftTop) {
            node = node->nodeLeftBottom->nodeLeftTop;
            numberColumn++;
        } else if (node->nodeLeftTop && node->nodeLeftTop->nodeLeftBottom && node->nodeLeftTop->nodeLeftBottom != node && node->nodeLeftTop->nodeLeftBottom != node->nodeLeftBottom) {
            node = node->nodeLeftTop->nodeLeftBottom;
            numberColumn++;
        } else {
            break;
        }
    }

    return numberColumn;
}

void SchemeObliqueObjectNode::editNode()
{
    SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode directionsNode = SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::GAP;

    switch (this->directionNode) {
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::PARALLEL:
            directionsNode = SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::LEFT_UP__IN__RIGHT_BOTTOM;
            break;
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::LEFT_UP__IN__RIGHT_BOTTOM:
            directionsNode = SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::RIGHT_UP__IN__LEFT_BOTTOM;
            break;
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::RIGHT_UP__IN__LEFT_BOTTOM:
            directionsNode = SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::LEFT_UP__IN__LEFT_BOTTOM;
            break;
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::LEFT_UP__IN__LEFT_BOTTOM:
            directionsNode = SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::RIGHT_UP__IN__RIGHT_BOTTOM;
            break;
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::RIGHT_UP__IN__RIGHT_BOTTOM:
            directionsNode = SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::LEFT_UP__IN__RIGHT_BOTTOM_NO_NODE;
            break;
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::LEFT_UP__IN__RIGHT_BOTTOM_NO_NODE:
            directionsNode = SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::RIGHT_UP__IN__LEFT_BOTTOM_NO_NODE;
            break;
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::RIGHT_UP__IN__LEFT_BOTTOM_NO_NODE:
            directionsNode = SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::GAP;
            break;
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::GAP:
            directionsNode = SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::PARALLEL;
            break;
    }

    this->editNode(directionsNode);
}

void SchemeObliqueObjectNode::editNode(const SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode &directionNode)
{
    setDirectionNode(directionNode);

    this->graphicObjectArrow.clear();
    this->graphicObjectNodeLeftBrush.clear();
    this->graphicObjectNodeRightBrush.clear();
    this->graphicObjectNodeLeftUpPen.clear();
    this->graphicObjectNodeLeftBottomPen.clear();
    this->graphicObjectNodeRightUpPen.clear();
    this->graphicObjectNodeRightBottomPen.clear();

    switch (this->directionNode) {
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::PARALLEL:
            this->graphicObjectNodeLeftBrush.addPolygon(SchemeObliqueObjectNode::POLYGON_PARALLEL_LEFT_PART.translated(pos));
            for (QLine &line : SchemeObliqueObjectNode::LINES_PARALLEL_LEFT) {
                this->graphicObjectNodeLeftUpPen.push_back(line.translated(pos));
            }
            this->graphicObjectNodeRightBrush.addPolygon(SchemeObliqueObjectNode::POLYGON_PARALLEL_RIGHT_PART.translated(pos));
            for (QLine &line : SchemeObliqueObjectNode::LINES_PARALLEL_RIGHT) {
                this->graphicObjectNodeRightUpPen.push_back(line.translated(pos));
            }
            break;
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::LEFT_UP__IN__LEFT_BOTTOM:
            this->graphicObjectArrow.addPolygon(SchemeObliqueObjectNode::POLYGON_LEFT_UP__IN__LEFT_BOTTOM_ARROW.translated(pos));
            this->graphicObjectNodeLeftBrush.addPolygon(SchemeObliqueObjectNode::POLYGON_LEFT_UP__IN__LEFT_BOTTOM.translated(pos));
            for (QLine &line : SchemeObliqueObjectNode::LINES_LEFT_UP__IN__LEFT_BOTTOM) {
                this->graphicObjectNodeLeftUpPen.push_back(line.translated(pos));
            }
            break;
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::RIGHT_UP__IN__RIGHT_BOTTOM:
            this->graphicObjectArrow.addPolygon(SchemeObliqueObjectNode::POLYGON_RIGHT_UP__IN__RIGHT_BOTTOM_ARROW.translated(pos));
            this->graphicObjectNodeRightBrush.addPolygon(SchemeObliqueObjectNode::POLYGON_RIGHT_UP__IN__RIGHT_BOTTOM.translated(pos));
            for (QLine &line : SchemeObliqueObjectNode::LINES_RIGHT_UP__IN__RIGHT_BOTTOM) {
                this->graphicObjectNodeRightUpPen.push_back(line.translated(pos));
            }
            break;
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::LEFT_UP__IN__RIGHT_BOTTOM:
            this->graphicObjectArrow.addPolygon(SchemeObliqueObjectNode::POLYGON_LEFT_UP__IN__RIGHT_BOTTOM_ARROW.translated(pos));
            this->graphicObjectNodeLeftBrush.addPolygon(SchemeObliqueObjectNode::POLYGON_LEFT_UP__IN__RIGHT_BOTTOM.translated(pos));
            for (QLine &line : SchemeObliqueObjectNode::LINES_LEFT_UP__IN__RIGHT_BOTTOM) {
                this->graphicObjectNodeLeftUpPen.push_back(line.translated(pos));
            }
            break;
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::RIGHT_UP__IN__LEFT_BOTTOM:
            this->graphicObjectArrow.addPolygon(SchemeObliqueObjectNode::POLYGON_RIGHT_UP__IN__LEFT_BOTTOM_ARROW.translated(pos));
            this->graphicObjectNodeRightBrush.addPolygon(SchemeObliqueObjectNode::POLYGON_RIGHT_UP__IN__LEFT_BOTTOM.translated(pos));
            for (QLine &line : SchemeObliqueObjectNode::LINES_RIGHT_UP__IN__LEFT_BOTTOM) {
                this->graphicObjectNodeRightUpPen.push_back(line.translated(pos));
            }
            break;
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::LEFT_UP__IN__RIGHT_BOTTOM_NO_NODE:
            this->graphicObjectNodeLeftBrush.addPolygon(SchemeObliqueObjectNode::POLYGON_LEFT_UP__IN__RIGHT_BOTTOM_NO_NODE_LEFT.translated(pos));
            for (QLine &line : SchemeObliqueObjectNode::LINES_LEFT_UP__IN__RIGHT_BOTTOM_NO_NODE_LEFT) {
                this->graphicObjectNodeLeftUpPen.push_back(line.translated(pos));
            }
            this->graphicObjectNodeRightBrush.addPolygon(SchemeObliqueObjectNode::POLYGON_LEFT_UP__IN__RIGHT_BOTTOM_NO_NODE_RIGHT.translated(pos));
            for (QLine &line : SchemeObliqueObjectNode::LINES_LEFT_UP__IN__RIGHT_BOTTOM_NO_NODE_RIGHT) {
                this->graphicObjectNodeRightUpPen.push_back(line.translated(pos));
            }
            break;
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::RIGHT_UP__IN__LEFT_BOTTOM_NO_NODE:
            this->graphicObjectNodeLeftBrush.addPolygon(SchemeObliqueObjectNode::POLYGON_RIGHT_UP__IN__LEFT_BOTTOM_NO_NODE_LEFT.translated(pos));
            for (QLine &line : SchemeObliqueObjectNode::LINES_RIGHT_UP__IN__LEFT_BOTTOM_NO_NODE_LEFT) {
                this->graphicObjectNodeLeftUpPen.push_back(line.translated(pos));
            }
            this->graphicObjectNodeRightBrush.addPolygon(SchemeObliqueObjectNode::POLYGON_RIGHT_UP__IN__LEFT_BOTTOM_NO_NODE_RIGHT.translated(pos));
            for (QLine &line : SchemeObliqueObjectNode::LINES_RIGHT_UP__IN__LEFT_BOTTOM_NO_NODE_RIGHT) {
                this->graphicObjectNodeRightUpPen.push_back(line.translated(pos));
            }
            break;
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::GAP:
            for (QLine &line : SchemeObliqueObjectNode::LINES_GAP_LEFT_UP) {
                this->graphicObjectNodeLeftUpPen.push_back(line.translated(pos));
            }
            for (QLine &line : SchemeObliqueObjectNode::LINES_GAP_LEFT_BOTTOM) {
                this->graphicObjectNodeLeftBottomPen.push_back(line.translated(pos));
            }
            for (QLine &line : SchemeObliqueObjectNode::LINES_GAP_RIGHT_UP) {
                this->graphicObjectNodeRightUpPen.push_back(line.translated(pos));
            }
            for (QLine &line : SchemeObliqueObjectNode::LINES_GAP_RIGHT_BOTTOM) {
                this->graphicObjectNodeRightBottomPen.push_back(line.translated(pos));
            }
            break;
    }
}

void SchemeObliqueObjectNode::setDirectionNode(const SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode &directionNode)
{
    this->directionNode = directionNode;
}

void SchemeObliqueObjectNode::click()
{
    editNode();
    this->partLeftTop->updateColor();
    this->partRightTop->updateColor();
}

SchemeObliqueObjectPart *SchemeObliqueObjectNode::searhBegginingPart(const SchemeObliqueObjectPart *part)
{
    SchemeObliqueObjectPart *returnPart = searhPart(part);

    if (returnPart) {
        return returnPart->searhBegginingPart();
    } else {
        return returnPart;
    }
}

SchemeObliqueObjectPart *SchemeObliqueObjectNode::searhPart(const SchemeObliqueObjectPart *part)
{
    SchemeObliqueObjectPart *returnPart = nullptr;

    switch (this->directionNode) {
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::PARALLEL:
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::LEFT_UP__IN__LEFT_BOTTOM:
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::RIGHT_UP__IN__RIGHT_BOTTOM:
            if (part == this->partLeftBottom) {
                returnPart = this->partLeftTop;
            } else if (part == this->partRightBottom) {
                returnPart = this->partRightTop;
            } else if (part == this->partLeftTop) {
                returnPart = this->partLeftBottom;
            } else if (part == this->partRightTop) {
                returnPart = this->partRightBottom;
            }
            break;
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::LEFT_UP__IN__RIGHT_BOTTOM:
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::RIGHT_UP__IN__LEFT_BOTTOM:
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::LEFT_UP__IN__RIGHT_BOTTOM_NO_NODE:
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::RIGHT_UP__IN__LEFT_BOTTOM_NO_NODE:
            if (part == this->partLeftBottom) {
                returnPart = this->partRightTop;
            } else if (part == this->partRightBottom) {
                returnPart = this->partLeftTop;
            } else if (part == this->partLeftTop) {
                returnPart = this->partRightBottom;
            } else if (part == this->partRightTop) {
                returnPart = this->partLeftBottom;
            }
            break;
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::GAP:
            returnPart = nullptr;
            break;
    }

    return returnPart;
}

QRectF SchemeObliqueObjectNode::boundingRect() const
{
    return this->graphicObjectNodeMapColor.boundingRect();
}

QPainterPath SchemeObliqueObjectNode::shape() const
{
    return this->graphicObjectNode;
}

void SchemeObliqueObjectNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    if (widget == SchemeObliqueWidgetColorMapChartView::getInstance().viewport()) {
        painter->setPen(QPen(QColor(), -1));

        switch (this->directionNode) {
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::LEFT_UP__IN__LEFT_BOTTOM:
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::LEFT_UP__IN__RIGHT_BOTTOM:
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::LEFT_UP__IN__RIGHT_BOTTOM_NO_NODE:
            painter->setBrush(this->partLeftTop->brush);
            painter->drawPath(this->graphicObjectNodeMapColor);
            break;
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::RIGHT_UP__IN__RIGHT_BOTTOM:
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::RIGHT_UP__IN__LEFT_BOTTOM:
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::RIGHT_UP__IN__LEFT_BOTTOM_NO_NODE:
            painter->setBrush(this->partRightTop->brush);
            painter->drawPath(this->graphicObjectNodeMapColor);
            break;
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::PARALLEL:
        case SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode::GAP:
            break;
        }
    } else {
        painter->setPen(QPen(QColor(), -1));

        if (this->graphicObjectNodeLeftUpPen.size() < this->graphicObjectNodeRightUpPen.size()) {
            painter->setBrush(this->partRightTop->brush);
            painter->drawPath(this->graphicObjectNodeRightBrush);
            painter->setBrush(this->partLeftTop->brush);
            painter->drawPath(this->graphicObjectNodeLeftBrush);

            painter->setPen(this->partRightTop->pen);
            for (QLine &line : this->graphicObjectNodeRightUpPen) {
                painter->drawLine(line);
            }
            painter->setPen(this->partLeftTop->pen);
            for (QLine &line : this->graphicObjectNodeLeftUpPen) {
                painter->drawLine(line);
            }

            painter->setBrush(this->partRightTop->pen.brush());
            painter->setPen(this->partRightTop->pen);
            painter->drawPath(this->graphicObjectArrow);
        } else {
            painter->setBrush(this->partLeftTop->brush);
            painter->drawPath(this->graphicObjectNodeLeftBrush);
            painter->setBrush(this->partRightTop->brush);
            painter->drawPath(this->graphicObjectNodeRightBrush);

            painter->setPen(this->partLeftTop->pen);
            for (QLine &line : this->graphicObjectNodeLeftUpPen) {
                painter->drawLine(line);
            }
            painter->setPen(this->partRightTop->pen);
            for (QLine &line : this->graphicObjectNodeRightUpPen) {
                painter->drawLine(line);
            }

            painter->setBrush(this->partLeftTop->pen.brush());
            painter->setPen(this->partLeftTop->pen);
            painter->drawPath(this->graphicObjectArrow);
        }

        painter->setPen(this->partLeftBottom->pen);
        for (QLine &line : this->graphicObjectNodeLeftBottomPen) {
            painter->drawLine(line);
        }
        painter->setPen(this->partRightBottom->pen);
        for (QLine &line : this->graphicObjectNodeRightBottomPen) {
            painter->drawLine(line);
        }
    }
}
