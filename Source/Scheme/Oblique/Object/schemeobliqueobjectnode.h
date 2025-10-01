#ifndef SCHEMEOBLIQUEOBJECTNODE_H
#define SCHEMEOBLIQUEOBJECTNODE_H

#include <QList>
#include <QBrush>

#include "Scheme/Oblique/Object/schemeobliqueobjectpart.h"
#include "Scheme/Oblique/Widget/EditDirectionForNewNode/Chart/schemeobliquewidgeteditdirectionfornewnodechartscene.h"

class SchemeObliqueObjectPart;

class SchemeObliqueObjectNode: public QGraphicsObject
{
    Q_OBJECT

public:
    SchemeObliqueObjectNode(const QPoint &pos, const SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode &directionNode);
    ~SchemeObliqueObjectNode();

    int getNumberRow();
    int getNumberColumn();

    void editNode();
    void editNode(const SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode &directionNode);
    void setDirectionNode(const SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode &directionNode);

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

    SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode directionNode;

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
