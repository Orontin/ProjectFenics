#ifndef SCHEMEOBLIQUESATELLITECONNECTS_H
#define SCHEMEOBLIQUESATELLITECONNECTS_H

#include <QObject>

#include "Scheme/Oblique/Object/schemeobliqueobjectnode.h"

class SchemeObliqueChartScene;

class SchemeObliqueSatelliteConnects : public QObject
{
    Q_OBJECT
public:
    SchemeObliqueSatelliteConnects(SchemeObliqueChartScene *scene, QObject *parent = nullptr);
    ~SchemeObliqueSatelliteConnects();

    void createConnects(const bool isNode1_2, const QList<SchemeObliqueObjectNode*> &listNodes);

    void createConnectsLeft(const QList<SchemeObliqueObjectNode *> &nodes);
    void createConnectsRight(const QList<SchemeObliqueObjectNode *> &nodes);
    void createConnectsTop(const QList<SchemeObliqueObjectNode *> &nodes);
    void createConnectsBottom(const QList<SchemeObliqueObjectNode *> &nodes);

    void removeConnectsLeft(const QList<SchemeObliqueObjectNode *> &nodes);
    void removeConnectsRight(const QList<SchemeObliqueObjectNode *> &nodes);
    void removeConnectsTop(const QList<SchemeObliqueObjectNode *> &nodes);
    void removeConnectsBottom(const QList<SchemeObliqueObjectNode *> &nodes);

private:
    SchemeObliqueChartScene *scene;
};

#endif // SCHEMEOBLIQUESATELLITECONNECTS_H
