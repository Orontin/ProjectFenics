#include "schemeobliquewidgetcolormapchartview.h"

#include <QSurfaceFormat>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QScrollBar>
#include <QtMath>

SchemeObliqueWidgetColorMapChartView *SchemeObliqueWidgetColorMapChartView::schemeObliqueWidgetColorMapChartView{nullptr};

SchemeObliqueWidgetColorMapChartView &SchemeObliqueWidgetColorMapChartView::getInstance()
{
    if (!SchemeObliqueWidgetColorMapChartView::schemeObliqueWidgetColorMapChartView) {
        SchemeObliqueWidgetColorMapChartView::schemeObliqueWidgetColorMapChartView = new SchemeObliqueWidgetColorMapChartView;
    }
    return *schemeObliqueWidgetColorMapChartView;
}

void SchemeObliqueWidgetColorMapChartView::toRight()
{
    const int step = abs(this->horizontalScrollBar()->minimum());
    this->horizontalScrollBar()->setValue(this->horizontalScrollBar()->value() + step);
}

void SchemeObliqueWidgetColorMapChartView::toLeft()
{
    const int step = abs(this->horizontalScrollBar()->minimum());
    this->horizontalScrollBar()->setValue(this->horizontalScrollBar()->value() - step);
}

void SchemeObliqueWidgetColorMapChartView::toTop()
{
    const int step = abs(this->verticalScrollBar()->minimum());
    this->verticalScrollBar()->setValue(this->verticalScrollBar()->value() - step);
}

void SchemeObliqueWidgetColorMapChartView::toBottom()
{
    const int step = abs(this->verticalScrollBar()->minimum());
    this->verticalScrollBar()->setValue(this->verticalScrollBar()->value() + step);
}

void SchemeObliqueWidgetColorMapChartView::zoomIn()
{
    if (this->skrooll > -25) {
        double angle = 120;
        this->skrooll--;
        double factor = qPow(1.0015, angle);
        this->scale(factor, factor);
        this->centerOn(this->mapToScene(this->viewport()->geometry()).boundingRect().center());
    }
}

void SchemeObliqueWidgetColorMapChartView::zoomOut()
{
    if (this->skrooll < 25) {
        double angle = -120;
        this->skrooll++;
        double factor = qPow(1.0015, angle);
        this->scale(factor, factor);
        this->centerOn(this->mapToScene(this->viewport()->geometry()).boundingRect().center());
    }
}

void SchemeObliqueWidgetColorMapChartView::rotateRight()
{
    this->rotate(45);
}

void SchemeObliqueWidgetColorMapChartView::rotateLeft()
{
    this->rotate(-45);
}

void SchemeObliqueWidgetColorMapChartView::setSchemeObliqueChartScene(SchemeObliqueChartScene *scene)
{
    this->setScene(scene);
}

void SchemeObliqueWidgetColorMapChartView::wheelEvent(QWheelEvent *event)
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

void SchemeObliqueWidgetColorMapChartView::mousePressEvent(QMouseEvent *event)
{
    if (event->modifiers() & Qt::ControlModifier && event->button() == Qt::LeftButton && !this->isMovements) {
        this->setTransformationAnchor(QGraphicsView::NoAnchor);
        this->isMovements = true;
        this->lastPos = event->pos();
    } else {
        QGraphicsView::mousePressEvent(event);
    }
}

void SchemeObliqueWidgetColorMapChartView::mouseMoveEvent(QMouseEvent *event)
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

void SchemeObliqueWidgetColorMapChartView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && this->isMovements) {
        this->isMovements = false;
    } else {
        QGraphicsView::mouseReleaseEvent(event);
    }
}

void SchemeObliqueWidgetColorMapChartView::commonCreate()
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->setMouseTracking(true);
}

SchemeObliqueWidgetColorMapChartView::SchemeObliqueWidgetColorMapChartView()
{

}

SchemeObliqueWidgetColorMapChartView::~SchemeObliqueWidgetColorMapChartView()
{

}
