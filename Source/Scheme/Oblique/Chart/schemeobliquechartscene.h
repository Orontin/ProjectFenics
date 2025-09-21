#ifndef SCHEMEOBLIQUECHARTSCENE_H
#define SCHEMEOBLIQUECHARTSCENE_H

#include <QElapsedTimer>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include "Abstract/abstractschemechartscene.h"

#include "Scheme/Oblique/schemeoblique.h"

#include "Scheme/Oblique/Widget/EditDirectionForNewNode/schemeobliquewidgeteditdirectionfornewnodechartwindow.h"

#include "Scheme/Oblique/Satellite/schemeobliquesatelliteinfos.h"
#include "Scheme/Oblique/Satellite/schemeobliquesatellitenodes.h"
#include "Scheme/Oblique/Satellite/schemeobliquesatelliteparts.h"
#include "Scheme/Oblique/Satellite/schemeobliquesatelliteconnects.h"
#include "Scheme/Oblique/Satellite/schemeobliquesatellitecolors.h"
#include "Scheme/Oblique/Satellite/schemeobliquesatellitehistory.h"

class SchemeObliqueChartScene : public AbstractSchemeChartScene
{
    Q_OBJECT

public:
    static int spaceBetweenNodeOne;
    static int spaceBetweenNodeTwo;
    static int spaceBetweenNodeThree;
    static int spaceBetweenNodeFour;
    static int spaceBetweenNodeFive;
    static int spaceBetweenNodeSix;

    static int maximumCount;
    static int defaultCountThread;
    static int defaultCountHalfrow;
    static bool defaultIsNode1_2;
    static QString defaultNameScheme;
    static QBrush defaultBrush;

    SchemeObliqueChartScene(const int &countThreads, const int &countHalfrow, const bool &isNode1_2);
    SchemeObliqueChartScene(const int &countThreads, const int &countHalfrow, const bool &isNode1_2, const QList<int> &nodeDirections, const QList<QBrush> &colorThreads);
    ~SchemeObliqueChartScene();

    QMenu &getMenuHistory();
    QMenu &getMenuManagment();
    QMenu &getMenuSettings();

    void editFromHistory(const int &numberRow, const int &numberColumn, const SchemeObliqueObjectNode::DirectionsNode &directionsNode);
    void editFromHistory(const int &numberThread, const QBrush &brush);
    void editFromHistory(const SchemeOblique::Directions &direction, const QList<SchemeObliqueObjectNode::DirectionsNode> &directionNode, const QBrush &brush);

    void updateScene() final;
    void backHistory() final;
    void nextHistory() final;

    SchemeObliqueSatelliteInfos info;
    SchemeObliqueSatelliteNodes nodes;
    SchemeObliqueSatelliteParts parts;
    SchemeObliqueSatelliteConnects connects;
    SchemeObliqueSatelliteColors colors;
    SchemeObliqueSatelliteHistory history;

protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    void commonCreate();

    void editNodes(const SchemeOblique::Directions &direction, const bool &isUpdate, const bool &isSetHistory);
    void editScene(const int &countThreads, const int &countHalfrow, const bool &isNode1_2);
    void editScene(const int &countThreads, const int &countHalfrow, const bool &isNode1_2, const QList<int> &nodeDirections, const QList<QBrush> &colorThreads);
    void removeScene();

    void updateRectScene();
    void updateEnabledEditNodeAndThread();
    void updateEnabledHistory();

    QMenu menuThread;
    QMenu menuHalfrow;
    QAction actionBack;
    QAction actionNext;
    QAction actionRemoveThreadLeft;
    QAction actionRemoveThreadRight;
    QAction actionAddThreadLeft;
    QAction actionAddThreadRight;
    QAction actionRemoveHalfrowDown;
    QAction actionRemoveHalfrowTop;
    QAction actionAddHalfrowDown;
    QAction actionAddHalfrowTop;
    QAction actionEditDirectionNewNode;

    SchemeObliqueWidgetEditDirectionForNewNodeWindow schemeObliqueWidgetEditDirectionForNewNodeWindow;
};

#endif // SCHEMEOBLIQUECHARTSCENE_H
