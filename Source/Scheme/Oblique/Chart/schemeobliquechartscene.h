#ifndef SCHEMEOBLIQUECHARTSCENE_H
#define SCHEMEOBLIQUECHARTSCENE_H

#include <QElapsedTimer>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include "Abstract/abstractschemechartscene.h"

#include "Scheme/Oblique/schemeoblique.h"

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

    void setMenuHistory(QMenu &menuHistory) override final;
    void setMenuManagment(QMenu &menuManagment) override final;
    void setMenuSettingsOpenScheme(QMenu &menuSettingsOpenScheme) override final;
    void updateShortcut() override final;
    void updateScene() override final;
    void backHistory() override final;
    void nextHistory() override final;

    void editFromHistory(const int &numberRow, const int &numberColumn, const SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode &directionsNode);
    void editFromHistory(const int &numberThread, const QBrush &brush);
    void editFromHistory(const SchemeOblique::Directions &direction, const QList<SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode> &directionNode, const QBrush &brush);

    SchemeObliqueSatelliteInfos info;
    SchemeObliqueSatelliteNodes nodes;
    SchemeObliqueSatelliteParts parts;
    SchemeObliqueSatelliteConnects connects;
    SchemeObliqueSatelliteColors colors;
    SchemeObliqueSatelliteHistory history;

protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override final;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override final;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override final;

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
};

#endif // SCHEMEOBLIQUECHARTSCENE_H
