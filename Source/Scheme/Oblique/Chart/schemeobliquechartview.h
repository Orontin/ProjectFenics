#ifndef SCHEMEOBLIQUECHARTVIEW_H
#define SCHEMEOBLIQUECHARTVIEW_H

#include "Abstract/abstractschemechartview.h"

class SchemeObliqueChartView : public AbstractSchemeChartView
{
    Q_OBJECT

public:
    SchemeObliqueChartView(const int &countThreads, const int &countHalfrow, const bool &isNode1_2, const QString &name);
    SchemeObliqueChartView(const int &countThreads, const int &countHalfrow, const bool &isNode1_2, const QList<int> &nodeDirections, const QList<QBrush> &colorThreads, const QString &name);
    ~SchemeObliqueChartView();

    void setMenuView(QMenu &menuView) override final;
    void onUpdateShortcut() override final;
    const QString &getTypeScheme() override final;

    static const QString &getTypeSchemeStatic();

protected:
    void wheelEvent(QWheelEvent *event) override final;
    void mousePressEvent(QMouseEvent *event) override final;
    void mouseMoveEvent(QMouseEvent *event) override final;
    void mouseReleaseEvent(QMouseEvent *event) override final;

private slots:
    void toRight();
    void toLeft();
    void toTop();
    void toBottom();

    void zoomIn();
    void zoomOut();

    void rotateRight();
    void rotateLeft();

private:
    void commonCreate();

    QPoint lastPos;
    bool isMovements = false;
    int skrooll = 5;

    QMenu menuZoom;
    QMenu menuTo;
    QMenu menuRotate;
    QAction actionZoomOut;
    QAction actionZoomIn;
    QAction actionToBottom;
    QAction actionToTop;
    QAction actionToLeft;
    QAction actionToRight;
    QAction actionRotateLeft;
    QAction actionRotateRight;

    static const QString &typeScheme;
};

#endif // SCHEMEOBLIQUECHARTVIEW_H
