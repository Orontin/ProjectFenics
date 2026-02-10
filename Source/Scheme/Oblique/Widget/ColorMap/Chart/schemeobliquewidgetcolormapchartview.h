#ifndef SCHEMEOBLIQUEWIDGETColorMapCHARTVIEW_H
#define SCHEMEOBLIQUEWIDGETColorMapCHARTVIEW_H

#include <QGraphicsView>

#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"

class SchemeObliqueWidgetColorMapChartView : public QGraphicsView
{
    Q_OBJECT

public:
    static SchemeObliqueWidgetColorMapChartView &getInstance();

    void toRight();
    void toLeft();
    void toTop();
    void toBottom();

    void zoomIn();
    void zoomOut();

    void rotateRight();
    void rotateLeft();

    void setSchemeObliqueChartScene(SchemeObliqueChartScene *scene);

protected:
    void wheelEvent(QWheelEvent *event) override final;
    void mousePressEvent(QMouseEvent *event) override final;
    void mouseMoveEvent(QMouseEvent *event) override final;
    void mouseReleaseEvent(QMouseEvent *event) override final;

private:
    SchemeObliqueWidgetColorMapChartView();
    ~SchemeObliqueWidgetColorMapChartView();

    void commonCreate();

    QPoint lastPos;
    bool isMovements = false;
    int skrooll = 5;

    static SchemeObliqueWidgetColorMapChartView *schemeObliqueWidgetColorMapChartView;
};

#endif // SCHEMEOBLIQUEWIDGETColorMapCHARTVIEW_H
