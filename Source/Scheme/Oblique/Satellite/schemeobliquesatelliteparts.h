#ifndef SCHEMEOBLIQUESATELLITEPARTS_H
#define SCHEMEOBLIQUESATELLITEPARTS_H

#include <QObject>

#include "Scheme/Oblique/Object/schemeobliqueobjectnode.h"
#include "Scheme/Oblique/Object/schemeobliqueobjectpart.h"

class SchemeObliqueChartScene;

class SchemeObliqueSatelliteParts : public QObject
{
    Q_OBJECT

public:
    SchemeObliqueSatelliteParts(SchemeObliqueChartScene *scene, QObject *parent = nullptr);
    ~SchemeObliqueSatelliteParts();

    void setThreadColorsLeft(const SchemeObliqueObjectNode *leftNode, const QBrush &colorThread);
    void setThreadColorsRight(const SchemeObliqueObjectNode *rightNode, const QBrush &colorThread);
    QBrush getThreadColorsLeft(const SchemeObliqueObjectNode *leftNode);
    QBrush getThreadColorsRight(const SchemeObliqueObjectNode *rightNode);

    void setThreadColors(const QList<SchemeObliqueObjectNode*> &topNodes, const QList<QBrush> &colorThreads);
    QList<QBrush> getThreadColors(const QList<SchemeObliqueObjectNode*> &topNodes);

    QList<SchemeObliqueObjectPart*> getThreadBeggining(const QList<SchemeObliqueObjectNode*> &topNodes);

    void createParts(const bool isNode1_2, const QList<SchemeObliqueObjectNode*> &listNodes);
    void removeParts(const SchemeObliqueObjectNode &topNodes, const SchemeObliqueObjectNode &bottom);

    void createPartsLeft(const QList<SchemeObliqueObjectNode *> &nodes);
    void createPartsRight(const QList<SchemeObliqueObjectNode *> &nodes);
    void createPartsTop(const QList<SchemeObliqueObjectNode *> &nodes);
    void createPartsBottom(const QList<SchemeObliqueObjectNode *> &nodes);

    void removePartsLeft(const QList<SchemeObliqueObjectNode *> &nodes);
    void removePartsRight(const QList<SchemeObliqueObjectNode *> &nodes);
    void removePartsTop(const QList<SchemeObliqueObjectNode *> &nodes);
    void removePartsBottom(const QList<SchemeObliqueObjectNode *> &nodes);

private:
    SchemeObliqueObjectPart *createPart(SchemeObliqueObjectNode &pos, const SchemeObliqueObjectPart::DirectionsPart &type);

    SchemeObliqueChartScene *scene;
};

#endif // SCHEMEOBLIQUESATELLITEPARTS_H
