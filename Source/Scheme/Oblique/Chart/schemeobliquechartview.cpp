#include "schemeobliquechartview.h"

#include <QSurfaceFormat>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QScrollBar>
#include <QtMath>

#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"

const QString &SchemeObliqueChartView::typeScheme = "Усложенная косая";

SchemeObliqueChartView::SchemeObliqueChartView():
    AbstractSchemeChartView("")
{
}

SchemeObliqueChartView::SchemeObliqueChartView(const int &countThreads,
                                               const int &countHalfrow,
                                               const bool &isNode1_2,
                                               const QString &name):
    AbstractSchemeChartView(name)
{
    this->setScene(new SchemeObliqueChartScene(countThreads, countHalfrow, isNode1_2));

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->setMouseTracking(true);
}

SchemeObliqueChartView::SchemeObliqueChartView(const int &countThreads,
                                               const int &countHalfrow,
                                               const bool &isNode1_2,
                                               const QList<int> &nodeDirections,
                                               const QList<QBrush> &colorThreads,
                                               const QString &name):
    AbstractSchemeChartView(name)
{
    this->setScene(new SchemeObliqueChartScene(countThreads, countHalfrow, isNode1_2, nodeDirections, colorThreads));

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->setMouseTracking(true);
}

SchemeObliqueChartView::~SchemeObliqueChartView()
{
    delete this->scene();
}

const QString &SchemeObliqueChartView::getTypeScheme() {
    return SchemeObliqueChartView::typeScheme;
}

void SchemeObliqueChartView::toRight()
{
    const int step = abs(this->horizontalScrollBar()->minimum());
    this->horizontalScrollBar()->setValue(this->horizontalScrollBar()->value() + step);
}

void SchemeObliqueChartView::toLeft()
{
    const int step = abs(this->horizontalScrollBar()->minimum());
    this->horizontalScrollBar()->setValue(this->horizontalScrollBar()->value() - step);
}

void SchemeObliqueChartView::toTop()
{
    const int step = abs(this->verticalScrollBar()->minimum());
    this->verticalScrollBar()->setValue(this->verticalScrollBar()->value() - step);
}

void SchemeObliqueChartView::toBottom()
{
    const int step = abs(this->verticalScrollBar()->minimum());
    this->verticalScrollBar()->setValue(this->verticalScrollBar()->value() + step);
}

void SchemeObliqueChartView::zoomIn()
{
    if (this->skrooll > -25) {
        double angle = 120;
        this->skrooll--;
        double factor = qPow(1.0015, angle);
        this->scale(factor, factor);
        this->centerOn(this->mapToScene(this->viewport()->geometry()).boundingRect().center());
    }
}

void SchemeObliqueChartView::zoomOut()
{
    if (this->skrooll < 25) {
        double angle = -120;
        this->skrooll++;
        double factor = qPow(1.0015, angle);
        this->scale(factor, factor);
        this->centerOn(this->mapToScene(this->viewport()->geometry()).boundingRect().center());
    }
}

void SchemeObliqueChartView::rotateRight()
{
    this->rotate(45);
}

void SchemeObliqueChartView::rotateLeft()
{
    this->rotate(-45);
}

void SchemeObliqueChartView::wheelEvent(QWheelEvent *event)
{
    if (event->modifiers() & Qt::ControlModifier) {
        double angle = event->angleDelta().y();

        if (angle > 0 && this->skrooll > -25) {
            angle = 120;
            this->skrooll--;
            double factor = qPow(1.0015, angle);

            QPoint targetViewportPos = event->position().toPoint();
            QPoint targetScenePos = this->mapToScene(event->position().x(),event->position().y()).toPoint();

            this->scale(factor, factor);
            this->centerOn(targetScenePos);
            QPoint deltaViewportPos = targetViewportPos - QPoint(this->viewport()->width() / 2.0, this->viewport()->height() / 2.0);
            QPoint viewportCenter = this->mapFromScene(targetScenePos) - deltaViewportPos;
            this->centerOn(this->mapToScene(viewportCenter));
        } else if (angle < 0 && this->skrooll < 25) {
            angle = -120;
            this->skrooll++;
            double factor = qPow(1.0015, angle);

            QPoint targetViewportPos = event->position().toPoint();
            QPoint targetScenePos = this->mapToScene(event->position().x(),event->position().y()).toPoint();

            this->scale(factor, factor);
            this->centerOn(targetScenePos);
            QPoint deltaViewportPos = targetViewportPos - QPoint(this->viewport()->width() / 2.0, this->viewport()->height() / 2.0);
            QPoint viewportCenter = this->mapFromScene(targetScenePos) - deltaViewportPos;
            this->centerOn(this->mapToScene(viewportCenter));
        }
    } else {
        QGraphicsView::wheelEvent(event);
    }
}

void SchemeObliqueChartView::mousePressEvent(QMouseEvent *event)
{
    if (event->modifiers() & Qt::ControlModifier && event->button() == Qt::LeftButton && this->isMovements == false) {
        this->setTransformationAnchor(QGraphicsView::NoAnchor);
        this->isMovements = true;
        this->originX = event->position().x();
        this->originY = event->position().y();
    } else {
        QGraphicsView::mousePressEvent(event);
    }
}

void SchemeObliqueChartView::mouseMoveEvent(QMouseEvent *event)
{
    if (event->modifiers() & Qt::ControlModifier && event->buttons().testFlag(Qt::LeftButton) && this->isMovements == true) {
        QPoint oldP = this->mapToScene(this->originX, this->originY).toPoint();
        QPoint newP = this->mapToScene(event->pos()).toPoint();
        QPoint translation = newP - oldP;

        this->translate(translation.x(), translation.y());

        this->originX = event->position().x();
        this->originY = event->position().y();
    } else {
        QGraphicsView::mouseMoveEvent(event);
    }
}

void SchemeObliqueChartView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->modifiers() & Qt::ControlModifier && event->button() == Qt::LeftButton && this->isMovements == true) {
        this->isMovements = false;
    } else {
        QGraphicsView::mouseReleaseEvent(event);
    }
}
