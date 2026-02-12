#ifndef SCHEMEOBLIQUECHARTVIEW_H
#define SCHEMEOBLIQUECHARTVIEW_H

#include "Abstract/abstractschemechartview.h"

class SchemeObliqueChartView : public AbstractSchemeChartView
{
    Q_OBJECT

public:
    SchemeObliqueChartView(const int &countThreads, const int &countHalfrow, const bool &isNode1_2, const QString &name, AbstractScheme &scheme);
    SchemeObliqueChartView(const int &countThreads, const int &countHalfrow, const bool &isNode1_2, const QList<int> &nodeDirections, const QList<QBrush> &colorThreads, const QString &name, AbstractScheme &scheme);
    ~SchemeObliqueChartView();

public slots:
    void toRight();
    void toLeft();
    void toTop();
    void toBottom();

    void zoomIn();
    void zoomOut();

    void rotateRight();
    void rotateLeft();

protected:
    void wheelEvent(QWheelEvent *event) override final;
    void mousePressEvent(QMouseEvent *event) override final;
    void mouseMoveEvent(QMouseEvent *event) override final;
    void mouseReleaseEvent(QMouseEvent *event) override final;

private:
    void commonCreate();

    void tryZoom(const int &direction, const QWheelEvent *targetViewportPos);

    QPoint lastPos;
    bool isMovements;
    int scroll;
};

#endif // SCHEMEOBLIQUECHARTVIEW_H
