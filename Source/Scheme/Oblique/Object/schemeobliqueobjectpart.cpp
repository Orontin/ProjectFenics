#include "schemeobliqueobjectpart.h"

#include <QPainter>
#include <QColorDialog>

#include "Scheme/Oblique/Object/schemeobliqueobjectnode.h"

QPolygon SchemeObliqueObjectPart::POLYGON_BRUSH_BEGGINING_CORNER_LEFT{{QPoint(-12, -24), QPoint(-56, -68), QPoint(-22, -102), QPoint(-22, -148), QPoint(-39, -148), QPoint(-39, -109), QPoint(-80, -68), QPoint(-24, -12), QPoint(-12, -24)}};
QPolygon SchemeObliqueObjectPart::POLYGON_BRUSH_BEGGINING_CORNER_RIGHT{{QPoint(12, -24), QPoint(56, -68), QPoint(22, -102), QPoint(22, -148), QPoint(39, -148), QPoint(39, -109), QPoint(80, -68), QPoint(24, -12), QPoint(12, -24)}};
QPolygon SchemeObliqueObjectPart::POLYGON_BRUSH_BEGGINING_LEFT{{QPoint(-24, -12), QPoint(-46, -34), QPoint(-46, -80), QPoint(-29, -80), QPoint(-29, -41), QPoint(-12, -24), QPoint(-24, -12)}};
QPolygon SchemeObliqueObjectPart::POLYGON_BRUSH_BEGGINING_RIGHT{{QPoint(24, -12), QPoint(46, -34), QPoint(46, -80), QPoint(29, -80), QPoint(29, -41), QPoint(12, -24), QPoint(24, -12)}};
QPolygon SchemeObliqueObjectPart::POLYGON_BRUSH_CENTR_LEFT{{QPoint(-12, 24), QPoint(-44, 56), QPoint(-56, 44), QPoint(-24, 12), QPoint(-12, 24)}};
QPolygon SchemeObliqueObjectPart::POLYGON_BRUSH_CENTR_RIGHT{{QPoint(12, 24), QPoint(44, 56), QPoint(56, 44), QPoint(24, 12), QPoint(12, 24)}};
QPolygon SchemeObliqueObjectPart::POLYGON_BRUSH_CORNER_LEFT{{QPoint(-12, 24), QPoint(-56, 68), QPoint(-12, 112), QPoint(-24, 124), QPoint(-80, 68), QPoint(-24, 12), QPoint(-12, 24)}};
QPolygon SchemeObliqueObjectPart::POLYGON_BRUSH_CORNER_RIGHT{{QPoint(12, 24), QPoint(56, 68), QPoint(12, 112), QPoint(24, 124), QPoint(80, 68), QPoint(24, 12), QPoint(12, 24)}};
QPolygon SchemeObliqueObjectPart::POLYGON_BRUSH_END_CORNER_LEFT{{QPoint(-12, 24), QPoint(-56, 68), QPoint(-22, 102), QPoint(-22, 148), QPoint(-39, 148), QPoint(-39, 109), QPoint(-80, 68), QPoint(-24, 12), QPoint(-12, 24)}};
QPolygon SchemeObliqueObjectPart::POLYGON_BRUSH_END_CORNER_RIGHT{{QPoint(12, 24), QPoint(56, 68), QPoint(22, 102), QPoint(22, 148), QPoint(39, 148), QPoint(39, 109), QPoint(80, 68), QPoint(24, 12), QPoint(12, 24)}};
QPolygon SchemeObliqueObjectPart::POLYGON_BRUSH_END_LEFT{{QPoint(-24, 12), QPoint(-46, 34), QPoint(-46, 80), QPoint(-29, 80), QPoint(-29, 41), QPoint(-12, 24), QPoint(-24, 12)}};
QPolygon SchemeObliqueObjectPart::POLYGON_BRUSH_END_RIGHT{{QPoint(24, 12), QPoint(46, 34), QPoint(46, 80), QPoint(29, 80), QPoint(29, 41), QPoint(12, 24), QPoint(24, 12)}};

QList<QLine> SchemeObliqueObjectPart::LINES_PEN_BEGGINING_CORNER_LEFT{{QPoint(-12, -24), QPoint(-56, -68)}, {QPoint(-56, -68), QPoint(-22, -102)}, {QPoint(-22, -102), QPoint(-22, -148)}, {QPoint(-22, -148), QPoint(-39, -148)}, {QPoint(-39, -148), QPoint(-39, -109)}, {QPoint(-39, -109), QPoint(-80, -68)}, {QPoint(-80, -68), QPoint(-24, -12)}};
QList<QLine> SchemeObliqueObjectPart::LINES_PEN_BEGGINING_CORNER_RIGHT{{QPoint(12, -24), QPoint(56, -68)}, {QPoint(12, -24), QPoint(56, -68)}, {QPoint(56, -68), QPoint(22, -102)}, {QPoint(22, -102), QPoint(22, -148)}, {QPoint(22, -148), QPoint(39, -148)}, {QPoint(39, -148), QPoint(39, -109)}, {QPoint(39, -109), QPoint(80, -68)}, {QPoint(80, -68), QPoint(24, -12)}};
QList<QLine> SchemeObliqueObjectPart::LINES_PEN_BEGGINING_LEFT{{QPoint(-24, -12), QPoint(-46, -34)}, {QPoint(-46, -34), QPoint(-46, -80)}, {QPoint(-46, -80), QPoint(-29, -80)}, {QPoint(-29, -80), QPoint(-29, -41)}, {QPoint(-29, -41), QPoint(-12, -24)}};
QList<QLine> SchemeObliqueObjectPart::LINES_PEN_BEGGINING_RIGHT{{QPoint(24, -12), QPoint(46, -34)}, {QPoint(46, -34), QPoint(46, -80)}, {QPoint(46, -80), QPoint(29, -80)}, {QPoint(29, -80), QPoint(29, -41)}, {QPoint(29, -41), QPoint(12, -24)}};
QList<QLine> SchemeObliqueObjectPart::LINES_PEN_CENTR_LEFT{{QPoint(-12, 24), QPoint(-44, 56)}, {QPoint(-56, 44), QPoint(-24, 12)}};
QList<QLine> SchemeObliqueObjectPart::LINES_PEN_CENTR_RIGHT{{QPoint(12, 24), QPoint(44, 56)}, {QPoint(56, 44), QPoint(24, 12)}};
QList<QLine> SchemeObliqueObjectPart::LINES_PEN_CORNER_LEFT{{QPoint(-12, 24), QPoint(-56, 68)}, {QPoint(-56, 68), QPoint(-12, 112)}, {QPoint(-24, 124), QPoint(-80, 68)}, {QPoint(-80, 68), QPoint(-24, 12)}};
QList<QLine> SchemeObliqueObjectPart::LINES_PEN_CORNER_RIGHT{{QPoint(12, 24), QPoint(56, 68)}, {QPoint(56, 68), QPoint(12, 112)}, {QPoint(24, 124), QPoint(80, 68)}, {QPoint(80, 68), QPoint(24, 12)}};
QList<QLine> SchemeObliqueObjectPart::LINES_PEN_END_CORNER_LEFT{{QPoint(-12, 24), QPoint(-56, 68)}, {QPoint(-56, 68), QPoint(-22, 102)}, {QPoint(-22, 102), QPoint(-22, 148)}, {QPoint(-22, 148), QPoint(-39, 148)}, {QPoint(-39, 148), QPoint(-39, 109)}, {QPoint(-39, 109), QPoint(-80, 68)}, {QPoint(-80, 68), QPoint(-24, 12)}};
QList<QLine> SchemeObliqueObjectPart::LINES_PEN_END_CORNER_RIGHT{{QPoint(12, 24), QPoint(56, 68)}, {QPoint(56, 68), QPoint(22, 102)}, {QPoint(22, 102), QPoint(22, 148)}, {QPoint(22, 148), QPoint(39, 148)}, {QPoint(39, 148), QPoint(39, 109)}, {QPoint(39, 109), QPoint(80, 68)}, {QPoint(80, 68), QPoint(24, 12)}};
QList<QLine> SchemeObliqueObjectPart::LINES_PEN_END_LEFT{{QPoint(-24, 12), QPoint(-46, 34)}, {QPoint(-46, 34), QPoint(-46, 80)}, {QPoint(-46, 80), QPoint(-29, 80)}, {QPoint(-29, 80), QPoint(-29, 41)}, {QPoint(-29, 41), QPoint(-12, 24)}};
QList<QLine> SchemeObliqueObjectPart::LINES_PEN_END_RIGHT{{QPoint(24, 12), QPoint(46, 34)}, {QPoint(46, 34), QPoint(46, 80)}, {QPoint(46, 80), QPoint(29, 80)}, {QPoint(29, 80), QPoint(29, 41)}, {QPoint(29, 41), QPoint(12, 24)}};

QBrush SchemeObliqueObjectPart::defaultBrush{QBrush(Qt::white)};

SchemeObliqueObjectPart::SchemeObliqueObjectPart(const QPoint &pos, const SchemeObliqueObjectPart::DirectionsPart &directionPart):
    brush(SchemeObliqueObjectPart::defaultBrush),
    pen(QPen(getContrastColor(this->brush.color()), 0))
{
    this->setZValue(0);
    this->editPart(pos, directionPart);
}

SchemeObliqueObjectPart::~SchemeObliqueObjectPart()
{

}

void SchemeObliqueObjectPart::editPart(const QPoint &pos, const SchemeObliqueObjectPart::DirectionsPart &directionPart)
{
    this->setDirectionPart(directionPart);

    this->partBrush.clear();
    this->partPen.clear();

    switch (directionPart) {
        case SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_LEFT:
            this->partBrush.addPolygon(SchemeObliqueObjectPart::POLYGON_BRUSH_BEGGINING_CORNER_LEFT.translated(pos));
            for (QLine &line : SchemeObliqueObjectPart::LINES_PEN_BEGGINING_CORNER_LEFT) {
                this->partPen.push_back(line.translated(pos));
            }
            break;
        case SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_RIGHT:
            this->partBrush.addPolygon(SchemeObliqueObjectPart::POLYGON_BRUSH_BEGGINING_CORNER_RIGHT.translated(pos));
            for (QLine &line : SchemeObliqueObjectPart::LINES_PEN_BEGGINING_CORNER_RIGHT) {
                this->partPen.push_back(line.translated(pos));
            }
            break;
        case SchemeObliqueObjectPart::DirectionsPart::BEGGINING_LEFT:
            this->partBrush.addPolygon(SchemeObliqueObjectPart::POLYGON_BRUSH_BEGGINING_LEFT.translated(pos));
            for (QLine &line : SchemeObliqueObjectPart::LINES_PEN_BEGGINING_LEFT) {
                this->partPen.push_back(line.translated(pos));
            }
            break;
        case SchemeObliqueObjectPart::DirectionsPart::BEGGINING_RIGHT:
            this->partBrush.addPolygon(SchemeObliqueObjectPart::POLYGON_BRUSH_BEGGINING_RIGHT.translated(pos));
            for (QLine &line : SchemeObliqueObjectPart::LINES_PEN_BEGGINING_RIGHT) {
                this->partPen.push_back(line.translated(pos));
            }
            break;
        case SchemeObliqueObjectPart::DirectionsPart::CENTR_LEFT:
            this->partBrush.addPolygon(SchemeObliqueObjectPart::POLYGON_BRUSH_CENTR_LEFT.translated(pos));
            for (QLine &line : SchemeObliqueObjectPart::LINES_PEN_CENTR_LEFT) {
                this->partPen.push_back(line.translated(pos));
            }
            break;
        case SchemeObliqueObjectPart::DirectionsPart::CENTR_RIGHT:
            this->partBrush.addPolygon(SchemeObliqueObjectPart::POLYGON_BRUSH_CENTR_RIGHT.translated(pos));
            for (QLine &line : SchemeObliqueObjectPart::LINES_PEN_CENTR_RIGHT) {
                this->partPen.push_back(line.translated(pos));
            }
            break;
        case SchemeObliqueObjectPart::DirectionsPart::CORNER_LEFT:
            this->partBrush.addPolygon(SchemeObliqueObjectPart::POLYGON_BRUSH_CORNER_LEFT.translated(pos));
            for (QLine &line : SchemeObliqueObjectPart::LINES_PEN_CORNER_LEFT) {
                this->partPen.push_back(line.translated(pos));
            }
            break;
        case SchemeObliqueObjectPart::DirectionsPart::CORNER_RIGHT:
            this->partBrush.addPolygon(SchemeObliqueObjectPart::POLYGON_BRUSH_CORNER_RIGHT.translated(pos));
            for (QLine &line : SchemeObliqueObjectPart::LINES_PEN_CORNER_RIGHT) {
                this->partPen.push_back(line.translated(pos));
            }
            break;
        case SchemeObliqueObjectPart::DirectionsPart::END_CORNER_LEFT:
            this->partBrush.addPolygon(SchemeObliqueObjectPart::POLYGON_BRUSH_END_CORNER_LEFT.translated(pos));
            for (QLine &line : SchemeObliqueObjectPart::LINES_PEN_END_CORNER_LEFT) {
                this->partPen.push_back(line.translated(pos));
            }
            break;
        case SchemeObliqueObjectPart::DirectionsPart::END_CORNER_RIGHT:
            this->partBrush.addPolygon(SchemeObliqueObjectPart::POLYGON_BRUSH_END_CORNER_RIGHT.translated(pos));
            for (QLine &line : SchemeObliqueObjectPart::LINES_PEN_END_CORNER_RIGHT) {
                this->partPen.push_back(line.translated(pos));
            }
            break;
        case SchemeObliqueObjectPart::DirectionsPart::END_LEFT:
            this->partBrush.addPolygon(SchemeObliqueObjectPart::POLYGON_BRUSH_END_LEFT.translated(pos));
            for (QLine &line : SchemeObliqueObjectPart::LINES_PEN_END_LEFT) {
                this->partPen.push_back(line.translated(pos));
            }
            break;
        case SchemeObliqueObjectPart::DirectionsPart::END_RIGHT:
            this->partBrush.addPolygon(SchemeObliqueObjectPart::POLYGON_BRUSH_END_RIGHT.translated(pos));
            for (QLine &line : SchemeObliqueObjectPart::LINES_PEN_END_RIGHT) {
                this->partPen.push_back(line.translated(pos));
            }
            break;
    }
}

void SchemeObliqueObjectPart::setDirectionPart(const SchemeObliqueObjectPart::DirectionsPart &directionPart)
{
    this->directionPart = directionPart;
}

SchemeObliqueObjectPart* SchemeObliqueObjectPart::click()
{
    SchemeObliqueObjectPart *begginingPart = searhBegginingPart();
    if (begginingPart) {
        if (begginingPart->setColor()) {
            begginingPart->updateColor();
        } else {
            begginingPart = nullptr;
        }
    }

    return begginingPart;
}

bool SchemeObliqueObjectPart::setColor()
{
    bool isSelectNewColor = false;

    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        this->brush = color;
        this->pen = QPen(getContrastColor(this->brush.color()), 0);

        isSelectNewColor = true;
    }

    return isSelectNewColor;
}

void SchemeObliqueObjectPart::setColor(const QBrush &brush)
{
    this->brush = brush;
    this->pen = QPen(getContrastColor(this->brush.color()), 0);
}

void SchemeObliqueObjectPart::updateColor()
{
    this->update();
    if (this->nodeBottom) {
        this->nodeBottom->update();
        SchemeObliqueObjectPart *part = this->nodeBottom->searhPart(this);
        if (part) {
            part->setColor(this->brush);
            part->updateColor();
        } else {
            switch (directionPart) {
            case SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_LEFT:
            case SchemeObliqueObjectPart::DirectionsPart::BEGGINING_LEFT:
            case SchemeObliqueObjectPart::DirectionsPart::CENTR_RIGHT:
            case SchemeObliqueObjectPart::DirectionsPart::CORNER_LEFT:
            case SchemeObliqueObjectPart::DirectionsPart::END_CORNER_LEFT:
            case SchemeObliqueObjectPart::DirectionsPart::END_LEFT:
                this->nodeBottom->partLeftBottom->setColor(SchemeObliqueObjectPart::defaultBrush);
                this->nodeBottom->partLeftBottom->updateColor();
                break;
            case SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_RIGHT:
            case SchemeObliqueObjectPart::DirectionsPart::BEGGINING_RIGHT:
            case SchemeObliqueObjectPart::DirectionsPart::CENTR_LEFT:
            case SchemeObliqueObjectPart::DirectionsPart::CORNER_RIGHT:
            case SchemeObliqueObjectPart::DirectionsPart::END_CORNER_RIGHT:
            case SchemeObliqueObjectPart::DirectionsPart::END_RIGHT:
                this->nodeBottom->partRightBottom->setColor(SchemeObliqueObjectPart::defaultBrush);
                this->nodeBottom->partRightBottom->updateColor();
                break;
            }
        }
    }
}

SchemeObliqueObjectPart *SchemeObliqueObjectPart::searhBegginingPart()
{
    SchemeObliqueObjectPart *returnPart = nullptr;

    switch (directionPart) {
        case SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_LEFT:
        case SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_RIGHT:
        case SchemeObliqueObjectPart::DirectionsPart::BEGGINING_LEFT:
        case SchemeObliqueObjectPart::DirectionsPart::BEGGINING_RIGHT:
            returnPart = this;
            break;
        case SchemeObliqueObjectPart::DirectionsPart::CENTR_LEFT:
        case SchemeObliqueObjectPart::DirectionsPart::CENTR_RIGHT:
        case SchemeObliqueObjectPart::DirectionsPart::CORNER_LEFT:
        case SchemeObliqueObjectPart::DirectionsPart::CORNER_RIGHT:
        case SchemeObliqueObjectPart::DirectionsPart::END_CORNER_LEFT:
        case SchemeObliqueObjectPart::DirectionsPart::END_CORNER_RIGHT:
        case SchemeObliqueObjectPart::DirectionsPart::END_LEFT:
        case SchemeObliqueObjectPart::DirectionsPart::END_RIGHT:
            returnPart = this->nodeTop->searhBegginingPart(this);
            break;
    }

    return returnPart;
}

QColor SchemeObliqueObjectPart::getContrastColor(const QColor &color)
{
    // Вычисляем относительную яркость по формуле WCAG 2.1
    double r = color.redF();
    double g = color.greenF();
    double b = color.blueF();

    r = (r <= 0.03928) ? r / 12.92 : std::pow(((r + 0.055) / 1.055), 2.4);
    g = (g <= 0.03928) ? g / 12.92 : std::pow(((g + 0.055) / 1.055), 2.4);
    b = (b <= 0.03928) ? b / 12.92 : std::pow(((b + 0.055) / 1.055), 2.4);

    double luminance = 0.2126 * r + 0.7152 * g + 0.0722 * b;

    // Выбираем черный или белый в зависимости от яркости фона
    return (luminance > 0.179) ? Qt::black : Qt::white;
}

QRectF SchemeObliqueObjectPart::boundingRect() const
{
    return this->partBrush.boundingRect();
}

QPainterPath SchemeObliqueObjectPart::shape() const
{
    return this->partBrush;
}

void SchemeObliqueObjectPart::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    switch (directionPart) {
        case SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_LEFT:
        case SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_RIGHT:
        case SchemeObliqueObjectPart::DirectionsPart::BEGGINING_LEFT:
        case SchemeObliqueObjectPart::DirectionsPart::BEGGINING_RIGHT:
            painter->setPen(QPen(QColor(), -1));
            painter->setBrush(this->brush);
            painter->drawPath(this->partBrush);

            painter->setPen(this->pen);
            for (QLine &line : this->partPen) {
                painter->drawLine(line);
            }
            break;
        case SchemeObliqueObjectPart::DirectionsPart::CENTR_LEFT:
        case SchemeObliqueObjectPart::DirectionsPart::CENTR_RIGHT:
        case SchemeObliqueObjectPart::DirectionsPart::CORNER_LEFT:
        case SchemeObliqueObjectPart::DirectionsPart::CORNER_RIGHT:
        case SchemeObliqueObjectPart::DirectionsPart::END_CORNER_LEFT:
        case SchemeObliqueObjectPart::DirectionsPart::END_CORNER_RIGHT:
        case SchemeObliqueObjectPart::DirectionsPart::END_LEFT:
        case SchemeObliqueObjectPart::DirectionsPart::END_RIGHT:
            SchemeObliqueObjectPart *part = this->nodeTop->searhPart(this);
            if (part) {
                painter->setPen(QPen(QColor(), -1));
                painter->setBrush(part->brush);
                painter->drawPath(this->partBrush);

                painter->setPen(part->pen);
                for (QLine &line : this->partPen) {
                    painter->drawLine(line);
                }
            } else {
                painter->setPen(QPen(QColor(), -1));
                painter->setBrush(this->brush);
                painter->drawPath(this->partBrush);

                painter->setPen(this->pen);
                for (QLine &line : this->partPen) {
                    painter->drawLine(line);
                }
            }
            break;
    }
}
