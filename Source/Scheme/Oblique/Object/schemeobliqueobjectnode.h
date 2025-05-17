#ifndef SCHEMEOBLIQUEOBJECTNODE_H
#define SCHEMEOBLIQUEOBJECTNODE_H

#include <QList>
#include <QBrush>

#include "Scheme/Oblique/Object/schemeobliqueobjectpart.h"

class SchemeObliqueObjectPart;

class SchemeObliqueObjectNode: public QGraphicsObject
{
    Q_OBJECT

public:
    enum DirectionsNode {
        GAP                                 = 0,
        PARALLEL                            = 1,
        LEFT_UP__IN__RIGHT_BOTTOM_NO_NODE   = 2,
        RIGHT_UP__IN__LEFT_BOTTOM_NO_NODE   = 3,
        LEFT_UP__IN__LEFT_BOTTOM            = 4,
        RIGHT_UP__IN__RIGHT_BOTTOM          = 5,
        LEFT_UP__IN__RIGHT_BOTTOM           = 6,
        RIGHT_UP__IN__LEFT_BOTTOM           = 7,
    };

    static DirectionsNode standartDirectionObliqueNode;

    SchemeObliqueObjectNode(const QPoint &pos, const SchemeObliqueObjectNode::DirectionsNode &directionNode);
    ~SchemeObliqueObjectNode();

    void editNode();
    void editNode(const SchemeObliqueObjectNode::DirectionsNode &directionNode);
    void setDirectionNode(const SchemeObliqueObjectNode::DirectionsNode &directionNode);

    void click();

    SchemeObliqueObjectPart *searhBegginingPart(const SchemeObliqueObjectPart *part);
    SchemeObliqueObjectPart *searhPart(const SchemeObliqueObjectPart *part);

    SchemeObliqueObjectNode *nodeLeftTop = nullptr;
    SchemeObliqueObjectNode *nodeLeftBottom = nullptr;
    SchemeObliqueObjectNode *nodeRightTop = nullptr;
    SchemeObliqueObjectNode *nodeRightBottom = nullptr;

    SchemeObliqueObjectPart *partLeftTop = nullptr;
    SchemeObliqueObjectPart *partLeftBottom = nullptr;
    SchemeObliqueObjectPart *partRightTop = nullptr;
    SchemeObliqueObjectPart *partRightBottom = nullptr;

    QPoint pos;

    SchemeObliqueObjectNode::DirectionsNode directionNode;

private:
    QRectF boundingRect() const;
    QPainterPath shape() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPainterPath graphicObjectNode;

    QPainterPath graphicObjectArrow;

    QPainterPath graphicObjectNodeLeftBrush;
    QPainterPath graphicObjectNodeRightBrush;

    QList<QLine> graphicObjectNodeLeftUpPen;
    QList<QLine> graphicObjectNodeLeftBottomPen;

    QList<QLine> graphicObjectNodeRightUpPen;
    QList<QLine> graphicObjectNodeRightBottomPen;

    static QPolygon POLYGON_ROMB;

    static QPolygon POLYGON_PARALLEL_LEFT_PART;
    static QPolygon POLYGON_PARALLEL_RIGHT_PART;
    static QList<QLine> LINES_PARALLEL_LEFT;
    static QList<QLine> LINES_PARALLEL_RIGHT;

    static QPolygon POLYGON_LEFT_UP__IN__LEFT_BOTTOM;
    static QPolygon POLYGON_RIGHT_UP__IN__RIGHT_BOTTOM;
    static QPolygon POLYGON_LEFT_UP__IN__RIGHT_BOTTOM;
    static QPolygon POLYGON_RIGHT_UP__IN__LEFT_BOTTOM;
    static QList<QLine> LINES_LEFT_UP__IN__LEFT_BOTTOM;
    static QList<QLine> LINES_RIGHT_UP__IN__RIGHT_BOTTOM;
    static QList<QLine> LINES_LEFT_UP__IN__RIGHT_BOTTOM;
    static QList<QLine> LINES_RIGHT_UP__IN__LEFT_BOTTOM;

    static QPolygon POLYGON_LEFT_UP__IN__LEFT_BOTTOM_ARROW;
    static QPolygon POLYGON_RIGHT_UP__IN__RIGHT_BOTTOM_ARROW;
    static QPolygon POLYGON_LEFT_UP__IN__RIGHT_BOTTOM_ARROW;
    static QPolygon POLYGON_RIGHT_UP__IN__LEFT_BOTTOM_ARROW;

    static QPolygon POLYGON_LEFT_UP__IN__RIGHT_BOTTOM_NO_NODE_LEFT;
    static QPolygon POLYGON_LEFT_UP__IN__RIGHT_BOTTOM_NO_NODE_RIGHT;
    static QList<QLine> LINES_LEFT_UP__IN__RIGHT_BOTTOM_NO_NODE_LEFT;
    static QList<QLine> LINES_LEFT_UP__IN__RIGHT_BOTTOM_NO_NODE_RIGHT;

    static QPolygon POLYGON_RIGHT_UP__IN__LEFT_BOTTOM_NO_NODE_LEFT;
    static QPolygon POLYGON_RIGHT_UP__IN__LEFT_BOTTOM_NO_NODE_RIGHT;
    static QList<QLine> LINES_RIGHT_UP__IN__LEFT_BOTTOM_NO_NODE_LEFT;
    static QList<QLine> LINES_RIGHT_UP__IN__LEFT_BOTTOM_NO_NODE_RIGHT;

    static QList<QLine> LINES_GAP_LEFT_UP;
    static QList<QLine> LINES_GAP_LEFT_BOTTOM;
    static QList<QLine> LINES_GAP_RIGHT_UP;
    static QList<QLine> LINES_GAP_RIGHT_BOTTOM;
};

#endif // SCHEMEOBLIQUEOBJECTNODE_H
