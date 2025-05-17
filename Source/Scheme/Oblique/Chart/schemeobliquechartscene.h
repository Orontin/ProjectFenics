#ifndef SCHEMEOBLIQUECHARTSCENE_H
#define SCHEMEOBLIQUECHARTSCENE_H

#include <QElapsedTimer>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include "Abstract/abstractschemechartscene.h"

#include "Scheme/Oblique/Satellite/schemeobliquesatelliteinfos.h"
#include "Scheme/Oblique/Satellite/schemeobliquesatellitenodes.h"
#include "Scheme/Oblique/Satellite/schemeobliquesatelliteparts.h"
#include "Scheme/Oblique/Satellite/schemeobliquesatelliteconnects.h"
#include "Scheme/Oblique/Satellite/schemeobliquesatellitecolors.h"

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
    SchemeObliqueChartScene(const int &countThreads, const int &countHalfrow, const bool &isNode1_2, const QList<int> &nodeDirections, QList<QBrush> &colorThreads);
    ~SchemeObliqueChartScene();

    void editScene(const int &countThreads, const int &countHalfrow, const bool &isNode1_2);
    void editScene(const int &countThreads, const int &countHalfrow, const bool &isNode1_2,const  QList<int> &nodeDirections, QList<QBrush> &colorThreads);
    void removeScene();

    void editNodes(const AbstractSchemeChartScene::Directions &direction, const bool &isUpdate);
    void updateScene() final;

    int getSizeThread();
    int getSizeHalfrow();

    bool getIsNode1_2();

    QStringList getNodeDirections();
    QStringList getThreadColors();

    SchemeObliqueSatelliteInfos info;
    SchemeObliqueSatelliteNodes nodes;
    SchemeObliqueSatelliteParts parts;
    SchemeObliqueSatelliteConnects connects;
    SchemeObliqueSatelliteColors colors;

protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    void updateRectScene();
    void updateEnabledEditNodeAndThread();
};

#endif // SCHEMEOBLIQUECHARTSCENE_H
