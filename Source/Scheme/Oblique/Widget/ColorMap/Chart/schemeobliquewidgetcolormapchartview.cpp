#include "schemeobliquewidgetcolormapchartview.h"

#include <QSurfaceFormat>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QScrollBar>
#include <QtMath>

#include "Scheme/Oblique/File/Setting/schemeobliquefilesettings.h"

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
    tryZoom(1, nullptr);
}

void SchemeObliqueWidgetColorMapChartView::zoomOut()
{
    tryZoom(-1, nullptr);
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
        if (angle > 0) {
            tryZoom(1, event);
        } else if (angle < 0) {
            tryZoom(-1, event);
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
    }
}

void SchemeObliqueWidgetColorMapChartView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && this->isMovements) {
        this->isMovements = false;
    }
}

void SchemeObliqueWidgetColorMapChartView::commonCreate()
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->setMouseTracking(true);
}

void SchemeObliqueWidgetColorMapChartView::tryZoom(const int &direction, const QWheelEvent *targetViewportPos)
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
    this->scale(factor, factor);

    if (targetViewportPos) {
        // Центрирование по позиции курсора
        QPoint targetScenePos = this->mapToScene(targetViewportPos->position().toPoint()).toPoint();
        QPoint deltaViewportPos = targetViewportPos->position().toPoint() - QPoint(this->viewport()->width() / 2, this->viewport()->height() / 2);
        QPoint viewportCenter = this->mapFromScene(targetScenePos) - deltaViewportPos;
        this->centerOn(this->mapToScene(viewportCenter));
    } else {
        // Центрирование по центру всей сцены
        this->centerOn(this->mapToScene(this->viewport()->geometry()).boundingRect().center());
    }

    SchemeObliqueFileSettings::setColorMapScroll(this->scroll);
}

SchemeObliqueWidgetColorMapChartView::SchemeObliqueWidgetColorMapChartView():
    isMovements(false),
    scroll(SchemeObliqueFileSettings::getColorMapScroll())
{

}

SchemeObliqueWidgetColorMapChartView::~SchemeObliqueWidgetColorMapChartView()
{

}
