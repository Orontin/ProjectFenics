#ifndef SCHEMEOBLIQUEWIDGETCOLORMAPWINDOW_H
#define SCHEMEOBLIQUEWIDGETCOLORMAPWINDOW_H

#include <QWidget>
#include <QMenuBar>
#include <QGridLayout>

#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"

class SchemeObliqueWidgetColorMapWindow : public QWidget
{
    Q_OBJECT

public:
    static SchemeObliqueWidgetColorMapWindow &getInstance();

    void visibleSchemeObliqueChartScene(SchemeObliqueChartScene *scene);
    void visible(const bool &isVisible);

    void onUpdateShortcutView();

private:
    explicit SchemeObliqueWidgetColorMapWindow(QWidget *parent = nullptr);
    ~SchemeObliqueWidgetColorMapWindow();

    void setVisibleWidget(const bool &isVisible);

    void createActionView();
    void setMenuView();

    void connects();

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
