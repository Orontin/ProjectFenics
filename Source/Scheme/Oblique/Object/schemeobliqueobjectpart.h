#ifndef SCHEMEOBLIQUEOBJECTPART_H
#define SCHEMEOBLIQUEOBJECTPART_H

#include <QPen>
#include <QBrush>
#include <QPainterPath>
#include <QGraphicsObject>

class SchemeObliqueObjectNode;

class SchemeObliqueObjectPart: public QGraphicsObject
{
    Q_OBJECT

public:
    enum DirectionsPart {
        BEGGINING_CORNER_LEFT               = 0,
        BEGGINING_CORNER_RIGHT              = 1,
        BEGGINING_LEFT                      = 2,
        BEGGINING_RIGHT                     = 3,
        CENTR_LEFT                          = 4,
        CENTR_RIGHT                         = 5,
        CORNER_LEFT                         = 6,
        CORNER_RIGHT                        = 7,
        END_CORNER_LEFT                     = 8,
        END_CORNER_RIGHT                    = 9,
        END_LEFT                            = 10,
        END_RIGHT                           = 11
    };

    SchemeObliqueObjectPart(const QPoint &pos, const SchemeObliqueObjectPart::DirectionsPart &directionPart);
    ~SchemeObliqueObjectPart();

    void editPart(const QPoint &pos, const SchemeObliqueObjectPart::DirectionsPart &directionPart);
    void setDirectionPart(const SchemeObliqueObjectPart::DirectionsPart &directionPart);

    void click();

    void setColor();
    void setColor(const QBrush &brush);
    void updateColor();

    SchemeObliqueObjectPart *searhBegginingPart();
    SchemeObliqueObjectPart *searhEndPart();

    SchemeObliqueObjectNode *nodeTop = nullptr;
    SchemeObliqueObjectNode *nodeBottom = nullptr;

    QBrush brush;
    QPen pen;

    SchemeObliqueObjectPart::DirectionsPart directionPart;

private:
    QColor getContrastColor(const QColor& color);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPainterPath partBrush;
    QList<QLine> partPen;

    static QPolygon POLYGON_BRUSH_BEGGINING_CORNER_LEFT;
    static QPolygon POLYGON_BRUSH_BEGGINING_CORNER_RIGHT;
    static QPolygon POLYGON_BRUSH_BEGGINING_LEFT;
    static QPolygon POLYGON_BRUSH_BEGGINING_RIGHT;
    static QPolygon POLYGON_BRUSH_CENTR_LEFT;
    static QPolygon POLYGON_BRUSH_CENTR_RIGHT;
    static QPolygon POLYGON_BRUSH_CORNER_LEFT;
    static QPolygon POLYGON_BRUSH_CORNER_RIGHT;
    static QPolygon POLYGON_BRUSH_END_CORNER_LEFT;
    static QPolygon POLYGON_BRUSH_END_CORNER_RIGHT;
    static QPolygon POLYGON_BRUSH_END_LEFT;
    static QPolygon POLYGON_BRUSH_END_RIGHT;

    static QList<QLine> LINES_PEN_BEGGINING_CORNER_LEFT;
    static QList<QLine> LINES_PEN_BEGGINING_CORNER_RIGHT;
    static QList<QLine> LINES_PEN_BEGGINING_LEFT;
    static QList<QLine> LINES_PEN_BEGGINING_RIGHT;
    static QList<QLine> LINES_PEN_CENTR_LEFT;
    static QList<QLine> LINES_PEN_CENTR_RIGHT;
    static QList<QLine> LINES_PEN_CORNER_LEFT;
    static QList<QLine> LINES_PEN_CORNER_RIGHT;
    static QList<QLine> LINES_PEN_END_CORNER_LEFT;
    static QList<QLine> LINES_PEN_END_CORNER_RIGHT;
    static QList<QLine> LINES_PEN_END_LEFT;
    static QList<QLine> LINES_PEN_END_RIGHT;

    static QBrush defaultBrush;
};

#endif // SCHEMEOBLIQUEOBJECTPART_H
