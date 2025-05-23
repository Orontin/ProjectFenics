#ifndef SCHEMEOBLIQUESATELLITENODES_H
#define SCHEMEOBLIQUESATELLITENODES_H

#include <QObject>

#include "Scheme/Oblique/Object/schemeobliqueobjectnode.h"

class SchemeObliqueChartScene;

class SchemeObliqueSatelliteNodes : public QObject
{
    Q_OBJECT

public:
    SchemeObliqueSatelliteNodes(SchemeObliqueChartScene *scene, QObject *parent = nullptr);
    ~SchemeObliqueSatelliteNodes();

    void setNodeDirection(const int &numberRow, const int &numberColumn, const SchemeObliqueObjectNode::DirectionsNode &directionsNode);
    void setNodeDirections(const QList<int> &nodeDirections);
    QStringList getNodeDirections();

    QList<SchemeObliqueObjectNode::DirectionsNode> getNodeDirectionLeft();
    QList<SchemeObliqueObjectNode::DirectionsNode> getNodeDirectionRight();
    QList<SchemeObliqueObjectNode::DirectionsNode> getNodeDirectionTop();
    QList<SchemeObliqueObjectNode::DirectionsNode> getNodeDirectionBottom();

    void setNodeDirectionLeft(const QList<SchemeObliqueObjectNode::DirectionsNode> &directionLeft);
    void setNodeDirectionRight(const QList<SchemeObliqueObjectNode::DirectionsNode> &directionRight);
    void setNodeDirectionTop(const QList<SchemeObliqueObjectNode::DirectionsNode> &directionTop);
    void setNodeDirectionBottom(const QList<SchemeObliqueObjectNode::DirectionsNode> &directionBottom);

    QList<SchemeObliqueObjectNode*> createNodes(const bool &isNode1_2);
    void removeNodes();

    void createNodeRight();
    void createNodeLeft();
    void createNodeTop();
    void createNodeBottom();

    void removeNodeRight();
    void removeNodeLeft();
    void removeNodeTop();
    void removeNodeBottom();

    SchemeObliqueObjectNode *getTopFront();
    SchemeObliqueObjectNode *getTopBack();
    SchemeObliqueObjectNode *getBottomFront();
    SchemeObliqueObjectNode *getBottomBack();
    SchemeObliqueObjectNode *getRightFront();
    SchemeObliqueObjectNode *getRightBack();
    SchemeObliqueObjectNode *getLeftFront();
    SchemeObliqueObjectNode *getLeftBack();

    int getSizeTop();
    int getSizeBottom();
    int getSizeLeft();
    int getSizeRight();

    QList<SchemeObliqueObjectNode*> right;
    QList<SchemeObliqueObjectNode*> left;
    QList<SchemeObliqueObjectNode*> top;
    QList<SchemeObliqueObjectNode*> bottom;

private:
    SchemeObliqueObjectNode *createNode(const QPoint &pos);

    SchemeObliqueChartScene *scene = nullptr;
};

#endif // SCHEMEOBLIQUESATELLITENODES_H
