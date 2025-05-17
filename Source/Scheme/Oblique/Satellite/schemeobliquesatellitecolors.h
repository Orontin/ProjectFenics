#ifndef SCHEMEOBLIQUESATELLITECOLORS_H
#define SCHEMEOBLIQUESATELLITECOLORS_H

#include <QObject>

#include "Scheme/Oblique/Object/schemeobliqueobjectnode.h"

class SchemeObliqueChartScene;

class SchemeObliqueSatelliteColors : public QObject
{
    Q_OBJECT
public:
    SchemeObliqueSatelliteColors(SchemeObliqueChartScene *scene, QObject *parent = nullptr);
    ~SchemeObliqueSatelliteColors();

    void createColorsLeft(const QList<SchemeObliqueObjectNode *> &nodes);
    void createColorsRight(const QList<SchemeObliqueObjectNode *> &nodes);
    void createColorsTop(const QList<SchemeObliqueObjectNode *> &nodes);
    void createColorsBottom(const QList<SchemeObliqueObjectNode *> &nodes);

    void removeColorsLeft(const QList<SchemeObliqueObjectNode *> &nodes);
    void removeColorsRight(const QList<SchemeObliqueObjectNode *> &nodes);
    void removeColorsTop(const QList<SchemeObliqueObjectNode *> &nodes);
    void removeColorsBottom(const QList<SchemeObliqueObjectNode *> &nodes);

private:
    SchemeObliqueChartScene *scene;
};

#endif // SCHEMEOBLIQUESATELLITECOLORS_H
