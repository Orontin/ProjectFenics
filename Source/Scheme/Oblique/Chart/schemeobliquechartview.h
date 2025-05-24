#ifndef SCHEMEOBLIQUECHARTVIEW_H
#define SCHEMEOBLIQUECHARTVIEW_H

#include "Abstract/abstractschemechartview.h"

class SchemeObliqueChartView : public AbstractSchemeChartView
{
    Q_OBJECT

public:
    SchemeObliqueChartView();
    SchemeObliqueChartView(const int &countThreads, const int &countHalfrow, const bool &isNode1_2, const QString &name);
    SchemeObliqueChartView(const int &countThreads, const int &countHalfrow, const bool &isNode1_2, const QList<int> &nodeDirections, const QList<QBrush> &colorThreads, const QString &name);
    ~SchemeObliqueChartView();

    const QString &getTypeScheme();

    void toRight();
    void toLeft();
    void toTop();
    void toBottom();

    void zoomIn();
    void zoomOut();

    void rotateRight();
    void rotateLeft();

protected:
    void wheelEvent(QWheelEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    qreal originX;
    qreal originY;
    bool isMovements = false;
    int skrooll = 5;

    static const QString &typeScheme;
};

#endif // SCHEMEOBLIQUECHARTVIEW_H
