#include "schemeobliquesatelliteconnects.h"

SchemeObliqueSatelliteConnects::SchemeObliqueSatelliteConnects(SchemeObliqueChartScene *scene, QObject *parent):
    QObject{parent},
    scene(scene)
{

}

SchemeObliqueSatelliteConnects::~SchemeObliqueSatelliteConnects()
{

}

void SchemeObliqueSatelliteConnects::createConnects(const bool isNode1_2, const QList<SchemeObliqueObjectNode *> &listNodes)
{
    if (isNode1_2) {
        listNodes.front()->partLeftTop->nodeBottom = listNodes.front();
        listNodes.front()->partLeftBottom->nodeTop = listNodes.front();
        listNodes.front()->partRightTop->nodeBottom = listNodes.front();
        listNodes.front()->partRightBottom->nodeTop = listNodes.front();

        listNodes.back()->partLeftTop->nodeBottom = listNodes.back();
        listNodes.back()->partLeftBottom->nodeTop = listNodes.back();
        listNodes.back()->partRightTop->nodeBottom = listNodes.back();
        listNodes.back()->partRightBottom->nodeTop = listNodes.back();
    } else {
        listNodes.front()->partLeftTop->nodeBottom = listNodes.front();
        listNodes.front()->partLeftBottom->nodeTop = listNodes.front();
        listNodes.front()->partRightTop->nodeBottom = listNodes.front();
        listNodes.front()->partRightBottom->nodeTop = listNodes.front();

        listNodes.back()->partLeftTop->nodeBottom = listNodes.back();
        listNodes.back()->partLeftBottom->nodeTop = listNodes.back();
        listNodes.back()->partRightTop->nodeBottom = listNodes.back();
        listNodes.back()->partRightBottom->nodeTop = listNodes.back();
    }
}

void SchemeObliqueSatelliteConnects::createConnectsLeft(const QList<SchemeObliqueObjectNode *> &nodes)
{
    if (nodes.front()->nodeRightTop) {
        nodes.front()->nodeRightTop->partLeftBottom->nodeTop = nodes.front()->nodeRightTop;
        nodes.front()->partRightTop->nodeBottom = nodes.front();

        nodes.front()->partLeftTop->nodeBottom = nodes.front();

        if (nodes.front() == nodes.back()) {
            if (nodes.front()->nodeRightBottom) {
                nodes.front()->partRightBottom->nodeTop = nodes.front();
                nodes.front()->nodeRightBottom->partLeftTop->nodeBottom = nodes.front()->nodeRightBottom;

                nodes.front()->partLeftBottom->nodeTop = nodes.front();
            } else {
                nodes.front()->partRightBottom->nodeTop = nodes.front();
                nodes.front()->partLeftBottom->nodeTop = nodes.front();
            }
        } else {
            nodes.front()->partRightBottom->nodeTop = nodes.front();
            nodes.front()->nodeRightBottom->partLeftTop->nodeBottom = nodes.front()->nodeRightBottom;

            nodes.front()->partLeftBottom->nodeTop = nodes.front();
        }
    } else {
        nodes.front()->partRightTop->nodeBottom = nodes.front();
        nodes.front()->partLeftTop->nodeBottom = nodes.front();

        nodes.front()->nodeRightBottom->partLeftTop->nodeBottom = nodes.front()->nodeRightBottom;
        nodes.front()->partRightBottom->nodeTop = nodes.front();

        if (nodes.front() == nodes.back()) {
            nodes.front()->partLeftBottom->nodeTop = nodes.front();
        } else {
            nodes.front()->partLeftBottom->nodeTop = nodes.front();
        }
    }

    for (int i = 1; i < nodes.size() - 1; ++i) {
        nodes[i]->nodeRightTop->partLeftBottom->nodeTop = nodes[i]->nodeRightTop;
        nodes[i]->partRightTop->nodeBottom = nodes[i];

        nodes[i]->partLeftTop->nodeBottom = nodes[i];

        nodes[i]->partRightBottom->nodeTop = nodes[i];
        nodes[i]->nodeRightBottom->partLeftTop->nodeBottom = nodes[i]->nodeRightBottom;

        nodes[i]->partLeftBottom->nodeTop = nodes[i];
    }

    if (nodes.front() != nodes.back()) {
        nodes.back()->nodeRightTop->partLeftBottom->nodeTop = nodes.back()->nodeRightTop;
        nodes.back()->partRightTop->nodeBottom = nodes.back();

        nodes.back()->partLeftTop->nodeBottom = nodes.back();

        if (nodes.back()->nodeRightBottom) {
            nodes.back()->partRightBottom->nodeTop = nodes.back();
            nodes.back()->nodeRightBottom->partLeftTop->nodeBottom = nodes.back()->nodeRightBottom;

            nodes.back()->partLeftBottom->nodeTop = nodes.back();
        } else {
            nodes.back()->partRightBottom->nodeTop = nodes.back();
            nodes.back()->partLeftBottom->nodeTop = nodes.back();
        }
    }
}

void SchemeObliqueSatelliteConnects::createConnectsRight(const QList<SchemeObliqueObjectNode *> &nodes)
{
    if (nodes.front()->nodeLeftTop) {
        nodes.front()->nodeLeftTop->partRightBottom->nodeTop = nodes.front()->nodeLeftTop;
        nodes.front()->partLeftTop->nodeBottom = nodes.front();

        nodes.front()->partRightTop->nodeBottom = nodes.front();

        if (nodes.front() == nodes.back()) {
            if (nodes.front()->nodeLeftBottom) {
                nodes.front()->partLeftBottom->nodeTop = nodes.front();
                nodes.front()->nodeLeftBottom->partRightTop->nodeBottom = nodes.front()->nodeLeftBottom;

                nodes.front()->partRightBottom->nodeTop = nodes.front();
            } else {
                nodes.front()->partLeftBottom->nodeTop = nodes.front();
                nodes.front()->partRightBottom->nodeTop = nodes.front();
            }
        } else {
            nodes.front()->partLeftBottom->nodeTop = nodes.front();
            nodes.front()->nodeLeftBottom->partRightTop->nodeBottom = nodes.front()->nodeLeftBottom;

            nodes.front()->partRightBottom->nodeTop = nodes.front();
        }
    } else {
        nodes.front()->partLeftTop->nodeBottom = nodes.front();
        nodes.front()->partRightTop->nodeBottom = nodes.front();

        nodes.front()->nodeLeftBottom->partRightTop->nodeBottom = nodes.front()->nodeLeftBottom;
        nodes.front()->partLeftBottom->nodeTop = nodes.front();

        if (nodes.front() == nodes.back()) {
            nodes.front()->partRightBottom->nodeTop = nodes.front();
        } else {
            nodes.front()->partRightBottom->nodeTop = nodes.front();
        }
    }

    for (int i = 1; i < nodes.size() - 1; ++i) {
        nodes[i]->nodeLeftTop->partRightBottom->nodeTop = nodes[i]->nodeLeftTop;
        nodes[i]->partLeftTop->nodeBottom = nodes[i];

        nodes[i]->partRightTop->nodeBottom = nodes[i];

        nodes[i]->partLeftBottom->nodeTop = nodes[i];
        nodes[i]->nodeLeftBottom->partRightTop->nodeBottom = nodes[i]->nodeLeftBottom;

        nodes[i]->partRightBottom->nodeTop = nodes[i];
    }

    if (nodes.front() != nodes.back()) {
        nodes.back()->nodeLeftTop->partRightBottom->nodeTop = nodes.back()->nodeLeftTop;
        nodes.back()->partLeftTop->nodeBottom = nodes.back();

        nodes.back()->partRightTop->nodeBottom = nodes.back();

        if (nodes.back()->nodeLeftBottom) {
            nodes.back()->partLeftBottom->nodeTop = nodes.back();
            nodes.back()->nodeLeftBottom->partRightTop->nodeBottom = nodes.back()->nodeLeftBottom;

            nodes.back()->partRightBottom->nodeTop = nodes.back();
        } else {
            nodes.back()->partLeftBottom->nodeTop = nodes.back();
            nodes.back()->partRightBottom->nodeTop = nodes.back();
        }
    }
}

void SchemeObliqueSatelliteConnects::createConnectsTop(const QList<SchemeObliqueObjectNode *> &nodes)
{
    nodes.front()->partLeftTop->nodeBottom = nodes.front();
    nodes.front()->partRightTop->nodeBottom = nodes.front();

    if (nodes.front()->nodeLeftBottom->nodeLeftTop == nodes.front()) {
        nodes.front()->nodeLeftBottom->partLeftTop->nodeBottom = nodes.front()->nodeLeftBottom;
        nodes.front()->partLeftBottom->nodeTop = nodes.front();

        nodes.front()->nodeRightBottom->partLeftTop->nodeBottom = nodes.front()->nodeRightBottom;
        nodes.front()->partRightBottom->nodeTop = nodes.front();

        if (nodes.front() == nodes.back()) {
            nodes.front()->nodeRightBottom->partRightTop->nodeBottom = nodes.front()->nodeRightBottom;
        }
    } else {
        nodes.front()->nodeLeftBottom->partRightTop->nodeBottom = nodes.front()->nodeLeftBottom;
        nodes.front()->partLeftBottom->nodeTop = nodes.front();

        nodes.front()->nodeLeftBottom->partLeftTop->nodeBottom = nodes.front()->nodeLeftBottom;

        if (nodes.front() == nodes.back()) {
            if (nodes.front()->nodeRightBottom->nodeRightTop == nodes.front()) {
                nodes.front()->nodeRightBottom->partRightTop->nodeBottom = nodes.front()->nodeRightBottom;
                nodes.front()->partRightBottom->nodeTop = nodes.front();
            } else {
                nodes.front()->nodeRightBottom->partLeftTop->nodeBottom = nodes.front()->nodeRightBottom;
                nodes.front()->partRightBottom->nodeTop = nodes.front();

                nodes.front()->nodeRightBottom->partRightTop->nodeBottom = nodes.front()->nodeRightBottom;
            }
        } else {
            nodes.front()->nodeRightBottom->partLeftTop->nodeBottom = nodes.front()->nodeRightBottom;
            nodes.front()->partRightBottom->nodeTop = nodes.front();
        }
    }

    for (int i = 1; i < nodes.size() - 1; ++i) {
        nodes[i]->partLeftTop->nodeBottom = nodes[i];
        nodes[i]->partRightTop->nodeBottom = nodes[i];

        nodes[i]->nodeLeftBottom->partRightTop->nodeBottom = nodes[i]->nodeLeftBottom;
        nodes[i]->partLeftBottom->nodeTop = nodes[i];

        nodes[i]->nodeRightBottom->partLeftTop->nodeBottom = nodes[i]->nodeRightBottom;
        nodes[i]->partRightBottom->nodeTop = nodes[i];
    }

    if (nodes.front() != nodes.back()) {
        nodes.back()->partLeftTop->nodeBottom = nodes.back();
        nodes.back()->partRightTop->nodeBottom = nodes.back();

        nodes.back()->nodeLeftBottom->partRightTop->nodeBottom = nodes.back()->nodeLeftBottom;
        nodes.back()->partLeftBottom->nodeTop = nodes.back();

        if (nodes.back()->nodeRightBottom->nodeRightTop == nodes.back()) {
            nodes.back()->nodeRightBottom->partRightTop->nodeBottom = nodes.back()->nodeRightBottom;
            nodes.back()->partRightBottom->nodeTop = nodes.back();
        } else {
            nodes.back()->nodeRightBottom->partLeftTop->nodeBottom = nodes.back()->nodeRightBottom;
            nodes.back()->partRightBottom->nodeTop = nodes.back();

            nodes.back()->nodeRightBottom->partRightTop->nodeBottom = nodes.back()->nodeRightBottom;
        }
    }
}

void SchemeObliqueSatelliteConnects::createConnectsBottom(const QList<SchemeObliqueObjectNode *> &nodes)
{
    nodes.front()->partLeftBottom->nodeTop = nodes.front();
    nodes.front()->partRightBottom->nodeTop = nodes.front();

    if (nodes.front()->nodeLeftTop->nodeLeftBottom == nodes.front()) {
        nodes.front()->nodeLeftTop->partLeftBottom->nodeTop = nodes.front()->nodeLeftTop;
        nodes.front()->partLeftTop->nodeBottom = nodes.front();

        nodes.front()->nodeRightTop->partLeftBottom->nodeTop = nodes.front()->nodeRightTop;
        nodes.front()->partRightTop->nodeBottom = nodes.front();

        if (nodes.front() == nodes.back()) {
            nodes.front()->nodeRightTop->partRightBottom->nodeTop = nodes.front()->nodeRightTop;
        }
    } else {
        nodes.front()->nodeLeftTop->partRightBottom->nodeTop = nodes.front()->nodeLeftTop;
        nodes.front()->partLeftTop->nodeBottom = nodes.front();

        nodes.front()->nodeLeftTop->partLeftBottom->nodeTop = nodes.front()->nodeLeftTop;

        if (nodes.front() == nodes.back()) {
            if (nodes.front()->nodeRightTop->nodeRightBottom == nodes.front()) {
                nodes.front()->nodeRightTop->partRightBottom->nodeTop = nodes.front()->nodeRightTop;
                nodes.front()->partRightTop->nodeBottom = nodes.front();
            } else {
                nodes.front()->nodeRightTop->partLeftBottom->nodeTop = nodes.front()->nodeRightTop;
                nodes.front()->partRightTop->nodeBottom = nodes.front();

                nodes.front()->nodeRightTop->partRightBottom->nodeTop = nodes.front()->nodeRightTop;
            }
        } else {
            nodes.front()->nodeRightTop->partLeftBottom->nodeTop = nodes.front()->nodeRightTop;
            nodes.front()->partRightTop->nodeBottom = nodes.front();
        }
    }

    for (int i = 1; i < nodes.size() - 1; ++i) {
        nodes[i]->partLeftBottom->nodeTop = nodes[i];
        nodes[i]->partRightBottom->nodeTop = nodes[i];

        nodes[i]->nodeLeftTop->partRightBottom->nodeTop = nodes[i]->nodeLeftTop;
        nodes[i]->partLeftTop->nodeBottom = nodes[i];

        nodes[i]->nodeRightTop->partLeftBottom->nodeTop = nodes[i]->nodeRightTop;
        nodes[i]->partRightTop->nodeBottom = nodes[i];
    }

    if (nodes.front() != nodes.back()) {
        nodes.back()->partLeftBottom->nodeTop = nodes.back();
        nodes.back()->partRightBottom->nodeTop = nodes.back();

        nodes.back()->nodeLeftTop->partRightBottom->nodeTop = nodes.back()->nodeLeftTop;
        nodes.back()->partLeftTop->nodeBottom = nodes.back();

        if (nodes.back()->nodeRightTop->nodeRightBottom == nodes.back()) {
            nodes.back()->nodeRightTop->partRightBottom->nodeTop = nodes.back()->nodeRightTop;
            nodes.back()->partRightTop->nodeBottom = nodes.back();
        } else {
            nodes.back()->nodeRightTop->partLeftBottom->nodeTop = nodes.back()->nodeRightTop;
            nodes.back()->partRightTop->nodeBottom = nodes.back();

            nodes.back()->nodeRightTop->partRightBottom->nodeTop = nodes.back()->nodeRightTop;
        }
    }
}

void SchemeObliqueSatelliteConnects::removeConnectsLeft(const QList<SchemeObliqueObjectNode *> &nodes)
{
    nodes.front()->partLeftTop->nodeTop = nullptr;
    nodes.front()->partLeftTop->nodeBottom = nodes.front();
    if (nodes.front() == nodes.back()) {
        nodes.front()->partLeftBottom->nodeTop = nodes.front();
        nodes.front()->partLeftBottom->nodeBottom = nullptr;
    } else {
        nodes.front()->partLeftBottom->nodeTop = nodes.front();
        nodes.front()->partLeftBottom->nodeBottom = nodes.front()->nodeLeftBottom;
    }

    for (int i = 1; i < nodes.size() - 1; ++i) {
        nodes[i]->partLeftBottom->nodeTop = nodes[i];
        nodes[i]->partLeftBottom->nodeBottom = nodes[i]->nodeLeftBottom;
    }

    if (nodes.front() != nodes.back()) {
        nodes.back()->partLeftBottom->nodeTop = nodes.back();
        nodes.back()->partLeftBottom->nodeBottom = nullptr;
    }
}

void SchemeObliqueSatelliteConnects::removeConnectsRight(const QList<SchemeObliqueObjectNode *> &nodes)
{
    nodes.front()->partRightTop->nodeTop = nullptr;
    nodes.front()->partRightTop->nodeBottom = nodes.front();
    if (nodes.front() == nodes.back()) {
        nodes.front()->partRightBottom->nodeTop = nodes.front();
        nodes.front()->partRightBottom->nodeBottom = nullptr;
    } else {
        nodes.front()->partRightBottom->nodeTop = nodes.front();
        nodes.front()->partRightBottom->nodeBottom = nodes.front()->nodeRightBottom;
    }

    for (int i = 1; i < nodes.size() - 1; ++i) {
        nodes[i]->partRightBottom->nodeTop = nodes[i];
        nodes[i]->partRightBottom->nodeBottom = nodes[i]->nodeRightBottom;
    }

    if (nodes.front() != nodes.back()) {
        nodes.back()->partRightBottom->nodeTop = nodes.back();
        nodes.back()->partRightBottom->nodeBottom = nullptr;
    }
}

void SchemeObliqueSatelliteConnects::removeConnectsTop(const QList<SchemeObliqueObjectNode *> &nodes)
{
    if (nodes.front()->nodeLeftBottom && nodes.front()->nodeLeftBottom->nodeRightTop == nodes.front()) {
        nodes.front()->nodeLeftBottom->partLeftTop->nodeTop = nullptr;
    }

    for (const SchemeObliqueObjectNode *node : nodes) {
        node->partLeftTop->nodeTop = nullptr;
        node->partRightTop->nodeTop = nullptr;
    }

    if (nodes.back()->nodeRightBottom && nodes.back()->nodeRightBottom->nodeLeftTop == nodes.back()) {
        nodes.back()->nodeRightBottom->partRightTop->nodeTop = nullptr;
    }
}

void SchemeObliqueSatelliteConnects::removeConnectsBottom(const QList<SchemeObliqueObjectNode *> &nodes)
{
    if (nodes.front()->nodeLeftTop && nodes.front()->nodeLeftTop->nodeRightBottom == nodes.front()) {
        nodes.front()->nodeLeftTop->partLeftBottom->nodeBottom = nullptr;
    }

    for (const SchemeObliqueObjectNode *node : nodes) {
        node->partLeftBottom->nodeBottom = nullptr;
        node->partRightBottom->nodeBottom = nullptr;
    }

    if (nodes.back()->nodeRightTop && nodes.back()->nodeRightTop->nodeLeftBottom == nodes.back()) {
        nodes.back()->nodeRightTop->partRightBottom->nodeBottom = nullptr;
    }
}
