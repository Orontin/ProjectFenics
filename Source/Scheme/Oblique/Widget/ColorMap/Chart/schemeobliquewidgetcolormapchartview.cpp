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

SchemeObliqueWidgetColorMapChartView::SchemeObliqueWidgetColorMapChartView():
    isMovements(false),
    scroll(0)
{
    this->commonCreate();
    this->setSaveZoom();
}

SchemeObliqueWidgetColorMapChartView::~SchemeObliqueWidgetColorMapChartView()
{

}

void SchemeObliqueWidgetColorMapChartView::commonCreate()
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->setMouseTracking(true);
}

void SchemeObliqueWidgetColorMapChartView::setSaveZoom()
{
    int scroll = SchemeObliqueFileSettings::getColorMapScroll();
    int scrollModule = (scroll < 0 ? scroll * -1 : scroll);

    for (int i = 0; i < scrollModule; i++) {
        if (scroll < 0) {
            this->tryZoom(1, nullptr);
        } else {
            this->tryZoom(-1, nullptr);
        }
    }
    this->scroll = scroll;
}

void SchemeObliqueWidgetColorMapChartView::tryZoom(const int &direction, const QWheelEvent *event)
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

    qCritical() << this->scroll;

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

    SchemeObliqueFileSettings::setColorMapScroll(this->scroll);
}
