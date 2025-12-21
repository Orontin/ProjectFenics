#ifndef SCHEMEOBLIQUEWIDGETCOLORMAPWINDOW_H
#define SCHEMEOBLIQUEWIDGETCOLORMAPWINDOW_H

#include <QWidget>
#include <QMenuBar>
#include <QMoveEvent>
#include <QGridLayout>

#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"

class SchemeObliqueWidgetColorMapWindow : public QWidget
{
    Q_OBJECT

public:
    static SchemeObliqueWidgetColorMapWindow &getInstance();

    void onUpdateShortcutView();

    void visibleSchemeObliqueChartScene(SchemeObliqueChartScene *scene);
    void visible(const bool &visible);

protected:
    void moveEvent(QMoveEvent *event) override final;
    void resizeEvent(QResizeEvent *event) override final;

private:
    explicit SchemeObliqueWidgetColorMapWindow(QWidget *parent = nullptr);
    ~SchemeObliqueWidgetColorMapWindow();

    void setVisibleWidget(const bool &visible);
    void setPosition();

    QGridLayout gridLayout;

    QMenuBar menuBar;

    QMenu view;

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

    static SchemeObliqueWidgetColorMapWindow *schemeObliqueWidgetColorMapWindow;
};

#endif // SCHEMEOBLIQUEWIDGETCOLORMAPWINDOW_H
