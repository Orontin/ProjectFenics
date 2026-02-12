#include "schemeobliquechartview.h"

#include <QSurfaceFormat>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QScrollBar>
#include <QtMath>

#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"

SchemeObliqueChartView::SchemeObliqueChartView(const int &countThreads,
                                               const int &countHalfrow,
                                               const bool &isNode1_2,
                                               const QString &name,
                                               AbstractScheme &scheme):
    AbstractSchemeChartView(name, scheme),
    isMovements(false),
    scroll(0)
{
    this->setScene(new SchemeObliqueChartScene(countThreads, countHalfrow, isNode1_2));
    this->commonCreate();
}

SchemeObliqueChartView::SchemeObliqueChartView(const int &countThreads,
                                               const int &countHalfrow,
                                               const bool &isNode1_2,
                                               const QList<int> &nodeDirections,
                                               const QList<QBrush> &colorThreads,
                                               const QString &name,
                                               AbstractScheme &scheme):
    AbstractSchemeChartView(name, scheme),
    isMovements(false),
    scroll(0)
{
    this->setScene(new SchemeObliqueChartScene(countThreads, countHalfrow, isNode1_2, nodeDirections, colorThreads));
    this->commonCreate();
}

SchemeObliqueChartView::~SchemeObliqueChartView()
{
    delete this->scene();
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
    tryZoom(1, nullptr);
}

void SchemeObliqueChartView::zoomOut()
{
    tryZoom(-1, nullptr);
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
        if (angle > 0) {
            tryZoom(1, event);
        } else if (angle < 0) {
            tryZoom(-1, event);
        }
    } else {
        QGraphicsView::wheelEvent(event);
    }
}

void SchemeObliqueChartView::mousePressEvent(QMouseEvent *event)
{
    if (event->modifiers() & Qt::ControlModifier && event->button() == Qt::LeftButton && !this->isMovements) {
        this->setTransformationAnchor(QGraphicsView::NoAnchor);
        this->isMovements = true;
        this->lastPos = event->pos();
    } else {
        QGraphicsView::mousePressEvent(event);
    }
}

void SchemeObliqueChartView::mouseMoveEvent(QMouseEvent *event)
{
    if (event->modifiers() & Qt::ControlModifier && event->buttons() == Qt::LeftButton && this->isMovements) {
        QPoint delta = event->pos() - this->lastPos;

        int horizontalScrollBarValue = horizontalScrollBar()->value();
        int verticalScrollBarValue = verticalScrollBar()->value();

        horizontalScrollBar()->setValue(horizontalScrollBarValue - delta.x());
        verticalScrollBar()->setValue(verticalScrollBarValue - delta.y());

        this->lastPos = event->pos();
    } else {
        QGraphicsView::mouseMoveEvent(event);
    }
}

void SchemeObliqueChartView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && this->isMovements) {
        this->isMovements = false;
    } else {
        QGraphicsView::mouseReleaseEvent(event);
    }
}

void SchemeObliqueChartView::commonCreate()
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->setMouseTracking(true);
}

void SchemeObliqueChartView::tryZoom(const int &direction, const QWheelEvent *event)
{
    if (direction > 0) {
        if (this->scroll <= -25) {
            return;
        } else {
            this->scroll--;
        }
    } else {
        if (this->scroll >= 25) {
            return;
        } else {
            this->scroll++;
        }
    }

    double angle = 120.0 * direction;
    double factor = qPow(1.0015, angle);

    if (event) {
        // Центрирование по позиции курсора
        QPoint targetViewportPos = event->position().toPoint();
        QPoint targetScenePos = this->mapToScene(event->position().x(),event->position().y()).toPoint();
        this->scale(factor, factor);
        this->centerOn(targetScenePos);
        QPoint deltaViewportPos = targetViewportPos - QPoint(this->viewport()->width() / 2.0, this->viewport()->height() / 2.0);
        QPoint viewportCenter = this->mapFromScene(targetScenePos) - deltaViewportPos;
        this->centerOn(this->mapToScene(viewportCenter));
    } else {
        // Центрирование по центру всей сцены
        this->scale(factor, factor);
        this->centerOn(this->mapToScene(this->viewport()->geometry()).boundingRect().center());
    }
}
