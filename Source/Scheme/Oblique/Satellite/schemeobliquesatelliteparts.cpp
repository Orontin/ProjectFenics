#include "schemeobliquesatelliteparts.h"

#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"

SchemeObliqueSatelliteParts::SchemeObliqueSatelliteParts(SchemeObliqueChartScene *scene, QObject *parent): QObject(parent), scene(scene)
{

}

SchemeObliqueSatelliteParts::~SchemeObliqueSatelliteParts()
{

}

void SchemeObliqueSatelliteParts::setThreadColorsLeft(const SchemeObliqueObjectNode *leftNode, const QBrush &colorThread)
{
    if (leftNode->nodeLeftBottom && !leftNode->nodeLeftBottom->nodeLeftTop) {
        leftNode->nodeLeftBottom->partLeftTop->setColor(colorThread);
        leftNode->nodeLeftBottom->partLeftTop->updateColor();
    } else {
        leftNode->partLeftTop->setColor(colorThread);
        leftNode->partLeftTop->updateColor();
    }
}

void SchemeObliqueSatelliteParts::setThreadColorsRight(const SchemeObliqueObjectNode *rightNode, const QBrush &colorThread)
{
    if (rightNode->nodeRightBottom && !rightNode->nodeRightBottom->nodeRightTop) {
        rightNode->nodeRightBottom->partRightTop->setColor(colorThread);
        rightNode->nodeRightBottom->partRightTop->updateColor();
    } else {
        rightNode->partRightTop->setColor(colorThread);
        rightNode->partRightTop->updateColor();
    }
}

QBrush SchemeObliqueSatelliteParts::getThreadColorsLeft(const SchemeObliqueObjectNode *leftNode)
{
    QBrush listColorThreads;

    if (leftNode->nodeLeftBottom && !leftNode->nodeLeftBottom->nodeLeftTop) {
        listColorThreads = leftNode->nodeLeftBottom->partLeftTop->brush;
    } else {
        listColorThreads = leftNode->partLeftTop->brush;
    }

    return listColorThreads;
}

QBrush SchemeObliqueSatelliteParts::getThreadColorsRight(const SchemeObliqueObjectNode *rightNode)
{
    QBrush listColorThreads;

    if (rightNode->nodeRightBottom && !rightNode->nodeRightBottom->nodeRightTop) {
        listColorThreads = rightNode->nodeRightBottom->partRightTop->brush;
    } else {
        listColorThreads = rightNode->partRightTop->brush;
    }

    return listColorThreads;
}

void SchemeObliqueSatelliteParts::setThreadColors(const QList<SchemeObliqueObjectNode*> &topNodes, const QList<QBrush> &colorThreads)
{
    QList<QBrush> tmpСolorThreads = colorThreads;
    if (topNodes.front()->nodeLeftBottom && !topNodes.front()->nodeLeftBottom->nodeLeftTop) {
        topNodes.front()->nodeLeftBottom->partLeftTop->setColor(tmpСolorThreads.front());
        topNodes.front()->nodeLeftBottom->partLeftTop->updateColor();
        tmpСolorThreads.pop_front();
    }

    for (const SchemeObliqueObjectNode *topNode : topNodes) {
        topNode->partLeftTop->setColor(tmpСolorThreads.front());
        topNode->partLeftTop->updateColor();
        tmpСolorThreads.pop_front();
        topNode->partRightTop->setColor(tmpСolorThreads.front());
        topNode->partRightTop->updateColor();
        tmpСolorThreads.pop_front();
    }

    if (topNodes.back()->nodeRightBottom && !topNodes.back()->nodeRightBottom->nodeRightTop) {
        topNodes.back()->nodeRightBottom->partRightTop->setColor(tmpСolorThreads.back());
        topNodes.back()->nodeRightBottom->partRightTop->updateColor();
    }
}

QList<QBrush> SchemeObliqueSatelliteParts::getThreadColors(const QList<SchemeObliqueObjectNode*> &topNodes)
{
    QList<QBrush> listColorThreads;

    if (topNodes.front()->nodeLeftBottom && !topNodes.front()->nodeLeftBottom->nodeLeftTop) {
        listColorThreads.push_back(topNodes.front()->nodeLeftBottom->partLeftTop->brush);
    }

    for (const SchemeObliqueObjectNode *topNode : topNodes) {
        listColorThreads.push_back(topNode->partLeftTop->brush);
        listColorThreads.push_back(topNode->partRightTop->brush);
    }

    if (topNodes.back()->nodeRightBottom && !topNodes.back()->nodeRightBottom->nodeRightTop) {
        listColorThreads.push_back(topNodes.back()->nodeRightBottom->partRightTop->brush);
    }

    return listColorThreads;
}

QList<SchemeObliqueObjectPart*> SchemeObliqueSatelliteParts::getThreadBeggining(const QList<SchemeObliqueObjectNode *> &topNodes)
{
    QList<SchemeObliqueObjectPart*> listThreadBeggining;

    if (topNodes.front()->nodeLeftBottom && !topNodes.front()->nodeLeftBottom->nodeLeftTop) {
        listThreadBeggining.push_back(topNodes.front()->nodeLeftBottom->partLeftTop);
    }

    for (const SchemeObliqueObjectNode *topNode : topNodes) {
        listThreadBeggining.push_back(topNode->partLeftTop);
        listThreadBeggining.push_back(topNode->partRightTop);
    }

    if (topNodes.back()->nodeRightBottom && !topNodes.back()->nodeRightBottom->nodeRightTop) {
        listThreadBeggining.push_back(topNodes.back()->nodeRightBottom->partRightTop);
    }

    return listThreadBeggining;
}

void SchemeObliqueSatelliteParts::createParts(const bool isNode1_2, const QList<SchemeObliqueObjectNode*> &listNodes)
{
    if (isNode1_2) {
        listNodes.front()->partLeftTop = createPart(*listNodes.front(), SchemeObliqueObjectPart::DirectionsPart::BEGGINING_LEFT);
        listNodes.front()->partLeftBottom = createPart(*listNodes.front(), SchemeObliqueObjectPart::DirectionsPart::END_CORNER_LEFT);
        listNodes.front()->partRightTop = createPart(*listNodes.front(), SchemeObliqueObjectPart::DirectionsPart::BEGGINING_RIGHT);
        listNodes.front()->partRightBottom = createPart(*listNodes.front(), SchemeObliqueObjectPart::DirectionsPart::CENTR_RIGHT);

        listNodes.front()->partLeftTop->nodeBottom = listNodes.front();
        listNodes.front()->partLeftBottom->nodeTop = listNodes.front();
        listNodes.front()->partRightTop->nodeBottom = listNodes.front();
        listNodes.front()->partRightBottom->nodeTop = listNodes.front();

        listNodes.back()->partLeftTop = listNodes.front()->partRightBottom;
        listNodes.back()->partLeftBottom = createPart(*listNodes.back(), SchemeObliqueObjectPart::DirectionsPart::END_LEFT);
        listNodes.back()->partRightTop = createPart(*listNodes.back(), SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_RIGHT);
        listNodes.back()->partRightBottom = createPart(*listNodes.back(), SchemeObliqueObjectPart::DirectionsPart::END_RIGHT);

        listNodes.back()->partLeftTop->nodeBottom = listNodes.back();
        listNodes.back()->partLeftBottom->nodeTop = listNodes.back();
        listNodes.back()->partRightTop->nodeBottom = listNodes.back();
        listNodes.back()->partRightBottom->nodeTop = listNodes.back();
    } else {
        listNodes.front()->partLeftTop = createPart(*listNodes.front(), SchemeObliqueObjectPart::DirectionsPart::BEGGINING_LEFT);
        listNodes.front()->partLeftBottom = createPart(*listNodes.front(), SchemeObliqueObjectPart::DirectionsPart::CENTR_LEFT);
        listNodes.front()->partRightTop = createPart(*listNodes.front(), SchemeObliqueObjectPart::DirectionsPart::BEGGINING_RIGHT);
        listNodes.front()->partRightBottom = createPart(*listNodes.front(), SchemeObliqueObjectPart::DirectionsPart::END_CORNER_RIGHT);

        listNodes.front()->partLeftTop->nodeBottom = listNodes.front();
        listNodes.front()->partLeftBottom->nodeTop = listNodes.front();
        listNodes.front()->partRightTop->nodeBottom = listNodes.front();
        listNodes.front()->partRightBottom->nodeTop = listNodes.front();

        listNodes.back()->partLeftTop = createPart(*listNodes.back(), SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_LEFT);
        listNodes.back()->partLeftBottom = createPart(*listNodes.back(), SchemeObliqueObjectPart::DirectionsPart::END_LEFT);
        listNodes.back()->partRightTop = listNodes.front()->partLeftBottom;
        listNodes.back()->partRightBottom = createPart(*listNodes.back(), SchemeObliqueObjectPart::DirectionsPart::END_RIGHT);

        listNodes.back()->partLeftTop->nodeBottom = listNodes.back();
        listNodes.back()->partLeftBottom->nodeTop = listNodes.back();
        listNodes.back()->partRightTop->nodeBottom = listNodes.back();
        listNodes.back()->partRightBottom->nodeTop = listNodes.back();
    }
}

void SchemeObliqueSatelliteParts::removeParts(const SchemeObliqueObjectNode &topNodes, const SchemeObliqueObjectNode &bottom)
{
    topNodes.partLeftTop->deleteLater();
    topNodes.partRightTop->deleteLater();

    if (topNodes.partLeftBottom == bottom.partRightTop) {
        topNodes.partRightBottom->deleteLater();
    } else {
        topNodes.partLeftBottom->deleteLater();
    }
    bottom.partLeftTop->deleteLater();
    bottom.partRightTop->deleteLater();

    bottom.partLeftBottom->deleteLater();
    bottom.partRightBottom->deleteLater();
}

void SchemeObliqueSatelliteParts::createPartsLeft(const QList<SchemeObliqueObjectNode *> &nodes)
{
    if (nodes.front()->nodeRightTop) {
        nodes.front()->nodeRightTop->partLeftBottom->editPart(nodes.front()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::CENTR_LEFT);
        nodes.front()->partRightTop = nodes.front()->nodeRightTop->partLeftBottom;

        nodes.front()->nodeRightTop->partLeftBottom->nodeTop = nodes.front()->nodeRightTop;
        nodes.front()->partRightTop->nodeBottom = nodes.front();

        nodes.front()->partLeftTop = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_LEFT);

        nodes.front()->partLeftTop->nodeBottom = nodes.front();

        if (nodes.front() == nodes.back()) {
            if (nodes.front()->nodeRightBottom) {
                nodes.front()->partRightBottom = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::CENTR_RIGHT);
                nodes.front()->nodeRightBottom->partLeftTop = nodes.front()->partRightBottom;

                nodes.front()->partRightBottom->nodeTop = nodes.front();
                nodes.front()->nodeRightBottom->partLeftTop->nodeBottom = nodes.front()->nodeRightBottom;

                nodes.front()->partLeftBottom = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::END_CORNER_LEFT);

                nodes.front()->partLeftBottom->nodeTop = nodes.front();
            } else {
                nodes.front()->partRightBottom = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::END_RIGHT);
                nodes.front()->partLeftBottom = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::END_LEFT);

                nodes.front()->partRightBottom->nodeTop = nodes.front();
                nodes.front()->partLeftBottom->nodeTop = nodes.front();
            }
        } else {
            nodes.front()->partRightBottom = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::CENTR_RIGHT);
            nodes.front()->nodeRightBottom->partLeftTop = nodes.front()->partRightBottom;

            nodes.front()->partRightBottom->nodeTop = nodes.front();
            nodes.front()->nodeRightBottom->partLeftTop->nodeBottom = nodes.front()->nodeRightBottom;

            nodes.front()->partLeftBottom = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::CORNER_LEFT);

            nodes.front()->partLeftBottom->nodeTop = nodes.front();
        }
    } else {
        nodes.front()->partRightTop = nodes.front()->nodeRightBottom->partLeftTop;

        nodes.front()->partRightTop->editPart(nodes.front()->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_RIGHT);
        nodes.front()->partLeftTop = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::BEGGINING_LEFT);

        nodes.front()->partRightTop->nodeBottom = nodes.front();
        nodes.front()->partLeftTop->nodeBottom = nodes.front();

        nodes.front()->nodeRightBottom->partLeftTop = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::CENTR_RIGHT);
        nodes.front()->partRightBottom = nodes.front()->nodeRightBottom->partLeftTop;

        nodes.front()->nodeRightBottom->partLeftTop->nodeBottom = nodes.front()->nodeRightBottom;
        nodes.front()->partRightBottom->nodeTop = nodes.front();

        if (nodes.front() == nodes.back()) {
            nodes.front()->partLeftBottom = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::END_CORNER_LEFT);

            nodes.front()->partLeftBottom->nodeTop = nodes.front();
        } else {
            nodes.front()->partLeftBottom = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::CORNER_LEFT);

            nodes.front()->partLeftBottom->nodeTop = nodes.front();
        }
    }

    for (int i = 1; i < nodes.size() - 1; ++i) {
        nodes[i]->nodeRightTop->partLeftBottom->editPart(nodes[i]->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::CENTR_LEFT);
        nodes[i]->partRightTop = nodes[i]->nodeRightTop->partLeftBottom;

        nodes[i]->nodeRightTop->partLeftBottom->nodeTop = nodes[i]->nodeRightTop;
        nodes[i]->partRightTop->nodeBottom = nodes[i];

        nodes[i]->partLeftTop = nodes[i]->nodeLeftTop->partLeftBottom;

        nodes[i]->partLeftTop->nodeBottom = nodes[i];

        nodes[i]->partRightBottom = createPart(*nodes[i], SchemeObliqueObjectPart::DirectionsPart::CENTR_RIGHT);
        nodes[i]->nodeRightBottom->partLeftTop = nodes[i]->partRightBottom;

        nodes[i]->partRightBottom->nodeTop = nodes[i];
        nodes[i]->nodeRightBottom->partLeftTop->nodeBottom = nodes[i]->nodeRightBottom;

        nodes[i]->partLeftBottom = createPart(*nodes[i], SchemeObliqueObjectPart::DirectionsPart::CORNER_LEFT);

        nodes[i]->partLeftBottom->nodeTop = nodes[i];
    }

    if (nodes.front() != nodes.back()) {
        nodes.back()->nodeRightTop->partLeftBottom->editPart(nodes.back()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::CENTR_LEFT);
        nodes.back()->partRightTop = nodes.back()->nodeRightTop->partLeftBottom;

        nodes.back()->nodeRightTop->partLeftBottom->nodeTop = nodes.back()->nodeRightTop;
        nodes.back()->partRightTop->nodeBottom = nodes.back();

        nodes.back()->partLeftTop = nodes.back()->nodeLeftTop->partLeftBottom;

        nodes.back()->partLeftTop->nodeBottom = nodes.back();

        if (nodes.back()->nodeRightBottom) {
            nodes.back()->partRightBottom = createPart(*nodes.back(), SchemeObliqueObjectPart::DirectionsPart::CENTR_RIGHT);
            nodes.back()->nodeRightBottom->partLeftTop = nodes.back()->partRightBottom;

            nodes.back()->partRightBottom->nodeTop = nodes.back();
            nodes.back()->nodeRightBottom->partLeftTop->nodeBottom = nodes.back()->nodeRightBottom;

            nodes.back()->partLeftBottom = createPart(*nodes.back(), SchemeObliqueObjectPart::DirectionsPart::END_CORNER_LEFT);

            nodes.back()->partLeftBottom->nodeTop = nodes.back();
        } else {
            nodes.back()->partRightBottom = createPart(*nodes.back(), SchemeObliqueObjectPart::DirectionsPart::END_RIGHT);
            nodes.back()->partLeftBottom = createPart(*nodes.back(), SchemeObliqueObjectPart::DirectionsPart::END_LEFT);

            nodes.back()->partRightBottom->nodeTop = nodes.back();
            nodes.back()->partLeftBottom->nodeTop = nodes.back();
        }
    }
}

void SchemeObliqueSatelliteParts::createPartsRight(const QList<SchemeObliqueObjectNode *> &nodes)
{
    if (nodes.front()->nodeLeftTop) {
        nodes.front()->nodeLeftTop->partRightBottom->editPart(nodes.front()->nodeLeftTop->pos, SchemeObliqueObjectPart::DirectionsPart::CENTR_RIGHT);
        nodes.front()->partLeftTop = nodes.front()->nodeLeftTop->partRightBottom;

        nodes.front()->nodeLeftTop->partRightBottom->nodeTop = nodes.front()->nodeLeftTop;
        nodes.front()->partLeftTop->nodeBottom = nodes.front();

        nodes.front()->partRightTop = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_RIGHT);

        nodes.front()->partRightTop->nodeBottom = nodes.front();

        if (nodes.front() == nodes.back()) {
            if (nodes.front()->nodeLeftBottom) {
                nodes.front()->partLeftBottom = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::CENTR_LEFT);
                nodes.front()->nodeLeftBottom->partRightTop = nodes.front()->partLeftBottom;

                nodes.front()->partLeftBottom->nodeTop = nodes.front();
                nodes.front()->nodeLeftBottom->partRightTop->nodeBottom = nodes.front()->nodeLeftBottom;

                nodes.front()->partRightBottom = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::END_CORNER_RIGHT);

                nodes.front()->partRightBottom->nodeTop = nodes.front();
            } else {
                nodes.front()->partLeftBottom = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::END_LEFT);
                nodes.front()->partRightBottom = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::END_RIGHT);

                nodes.front()->partLeftBottom->nodeTop = nodes.front();
                nodes.front()->partRightBottom->nodeTop = nodes.front();
            }
        } else {
            nodes.front()->partLeftBottom = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::CENTR_LEFT);
            nodes.front()->nodeLeftBottom->partRightTop = nodes.front()->partLeftBottom;

            nodes.front()->partLeftBottom->nodeTop = nodes.front();
            nodes.front()->nodeLeftBottom->partRightTop->nodeBottom = nodes.front()->nodeLeftBottom;

            nodes.front()->partRightBottom = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::CORNER_RIGHT);

            nodes.front()->partRightBottom->nodeTop = nodes.front();
        }
    } else {
        nodes.front()->partLeftTop = nodes.front()->nodeLeftBottom->partRightTop;

        nodes.front()->partLeftTop->editPart(nodes.front()->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_LEFT);
        nodes.front()->partRightTop = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::BEGGINING_RIGHT);

        nodes.front()->partLeftTop->nodeBottom = nodes.front();
        nodes.front()->partLeftTop->nodeBottom = nodes.front();

        nodes.front()->nodeLeftBottom->partRightTop = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::CENTR_LEFT);
        nodes.front()->partLeftBottom = nodes.front()->nodeLeftBottom->partRightTop;

        nodes.front()->nodeLeftBottom->partRightTop->nodeBottom = nodes.front()->nodeLeftBottom;
        nodes.front()->partLeftBottom->nodeTop = nodes.front();

        if (nodes.front() == nodes.back()) {
            nodes.front()->partRightBottom = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::END_CORNER_RIGHT);

            nodes.front()->partRightBottom->nodeTop = nodes.front();
        } else {
            nodes.front()->partRightBottom = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::CORNER_RIGHT);

            nodes.front()->partRightBottom->nodeTop = nodes.front();
        }
    }

    for (int i = 1; i < nodes.size() - 1; ++i) {
        nodes[i]->nodeLeftTop->partRightBottom->editPart(nodes[i]->nodeLeftTop->pos, SchemeObliqueObjectPart::DirectionsPart::CENTR_RIGHT);
        nodes[i]->partLeftTop = nodes[i]->nodeLeftTop->partRightBottom;

        nodes[i]->nodeLeftTop->partRightBottom->nodeTop = nodes[i]->nodeLeftTop;
        nodes[i]->partLeftTop->nodeBottom = nodes[i];

        nodes[i]->partRightTop = nodes[i]->nodeRightTop->partRightBottom;

        nodes[i]->partRightTop->nodeBottom = nodes[i];

        nodes[i]->partLeftBottom = createPart(*nodes[i], SchemeObliqueObjectPart::DirectionsPart::CENTR_LEFT);
        nodes[i]->nodeLeftBottom->partRightTop = nodes[i]->partLeftBottom;

        nodes[i]->partLeftBottom->nodeTop = nodes[i];
        nodes[i]->nodeLeftBottom->partRightTop->nodeBottom = nodes[i]->nodeLeftBottom;

        nodes[i]->partRightBottom = createPart(*nodes[i], SchemeObliqueObjectPart::DirectionsPart::CORNER_RIGHT);

        nodes[i]->partRightBottom->nodeTop = nodes[i];
    }

    if (nodes.front() != nodes.back()) {
        nodes.back()->nodeLeftTop->partRightBottom->editPart(nodes.back()->nodeLeftTop->pos, SchemeObliqueObjectPart::DirectionsPart::CENTR_RIGHT);
        nodes.back()->partLeftTop = nodes.back()->nodeLeftTop->partRightBottom;

        nodes.back()->nodeLeftTop->partRightBottom->nodeTop = nodes.back()->nodeLeftTop;
        nodes.back()->partLeftTop->nodeBottom = nodes.back();

        nodes.back()->partRightTop = nodes.back()->nodeRightTop->partRightBottom;

        nodes.back()->partRightTop->nodeBottom = nodes.back();

        if (nodes.back()->nodeLeftBottom) {
            nodes.back()->partLeftBottom = createPart(*nodes.back(), SchemeObliqueObjectPart::DirectionsPart::CENTR_LEFT);
            nodes.back()->nodeLeftBottom->partRightTop = nodes.back()->partLeftBottom;

            nodes.back()->partLeftBottom->nodeTop = nodes.back();
            nodes.back()->nodeLeftBottom->partRightTop->nodeBottom = nodes.back()->nodeLeftBottom;

            nodes.back()->partRightBottom = createPart(*nodes.back(), SchemeObliqueObjectPart::DirectionsPart::END_CORNER_RIGHT);

            nodes.back()->partRightBottom->nodeTop = nodes.back();
        } else {
            nodes.back()->partLeftBottom = createPart(*nodes.back(), SchemeObliqueObjectPart::DirectionsPart::END_LEFT);
            nodes.back()->partRightBottom = createPart(*nodes.back(), SchemeObliqueObjectPart::DirectionsPart::END_RIGHT);

            nodes.back()->partLeftBottom->nodeTop = nodes.back();
            nodes.back()->partRightBottom->nodeTop = nodes.back();
        }
    }
}

void SchemeObliqueSatelliteParts::createPartsTop(const QList<SchemeObliqueObjectNode *> &nodes)
{
    if (nodes.front()->nodeLeftBottom->nodeLeftTop == nodes.front()) {
        nodes.front()->partLeftTop = nodes.front()->nodeLeftBottom->partLeftTop;
        nodes.front()->partRightTop = nodes.front()->nodeRightBottom->partLeftTop;

        nodes.front()->partLeftTop->editPart(nodes.front()->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_LEFT);
        nodes.front()->partRightTop->editPart(nodes.front()->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_RIGHT);

        nodes.front()->partLeftTop->nodeBottom = nodes.front();
        nodes.front()->partRightTop->nodeBottom = nodes.front();

        nodes.front()->nodeLeftBottom->partLeftTop = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::CORNER_LEFT);
        nodes.front()->partLeftBottom = nodes.front()->nodeLeftBottom->partLeftTop;

        nodes.front()->nodeLeftBottom->partLeftTop->nodeBottom = nodes.front()->nodeLeftBottom;
        nodes.front()->partLeftBottom->nodeTop = nodes.front();

        nodes.front()->nodeRightBottom->partLeftTop = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::CENTR_RIGHT);
        nodes.front()->partRightBottom = nodes.front()->nodeRightBottom->partLeftTop;

        nodes.front()->nodeRightBottom->partLeftTop->nodeBottom = nodes.front()->nodeRightBottom;
        nodes.front()->partRightBottom->nodeTop = nodes.front();

        if (nodes.front() == nodes.back()) {
            nodes.front()->nodeRightBottom->partRightTop->editPart(nodes.front()->nodeRightBottom->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_RIGHT);

            nodes.front()->nodeRightBottom->partRightTop->nodeBottom = nodes.front()->nodeRightBottom;
        }
    } else {
        nodes.front()->partLeftTop = nodes.front()->nodeLeftBottom->partRightTop;

        nodes.front()->partLeftTop->editPart(nodes.front()->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_LEFT);

        nodes.front()->partLeftTop->nodeBottom = nodes.front();

        nodes.front()->nodeLeftBottom->partRightTop = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::CENTR_LEFT);
        nodes.front()->partLeftBottom = nodes.front()->nodeLeftBottom->partRightTop;

        nodes.front()->nodeLeftBottom->partRightTop->nodeBottom = nodes.front()->nodeLeftBottom;
        nodes.front()->partLeftBottom->nodeTop = nodes.front();

        nodes.front()->nodeLeftBottom->partLeftTop->editPart(nodes.front()->nodeLeftBottom->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_LEFT);

        nodes.front()->nodeLeftBottom->partLeftTop->nodeBottom = nodes.front()->nodeLeftBottom;

        if (nodes.front() == nodes.back()) {
            if (nodes.front()->nodeRightBottom->nodeRightTop == nodes.front()) {
                nodes.front()->partRightTop = nodes.front()->nodeRightBottom->partRightTop;

                nodes.front()->partRightTop->editPart(nodes.front()->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_RIGHT);

                nodes.front()->partRightTop->nodeBottom = nodes.front();

                nodes.front()->nodeRightBottom->partRightTop = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::CORNER_RIGHT);
                nodes.front()->partRightBottom = nodes.front()->nodeRightBottom->partRightTop;

                nodes.front()->nodeRightBottom->partRightTop->nodeBottom = nodes.front()->nodeRightBottom;
                nodes.front()->partRightBottom->nodeTop = nodes.front();
            } else {
                nodes.front()->partRightTop = nodes.front()->nodeRightBottom->partLeftTop;

                nodes.front()->partRightTop->editPart(nodes.front()->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_RIGHT);

                nodes.front()->partRightTop->nodeBottom = nodes.front();

                nodes.front()->nodeRightBottom->partLeftTop = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::CENTR_RIGHT);
                nodes.front()->partRightBottom = nodes.front()->nodeRightBottom->partLeftTop;

                nodes.front()->nodeRightBottom->partLeftTop->nodeBottom = nodes.front()->nodeRightBottom;
                nodes.front()->partRightBottom->nodeTop = nodes.front();

                nodes.front()->nodeRightBottom->partRightTop->editPart(nodes.front()->nodeRightBottom->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_RIGHT);

                nodes.front()->nodeRightBottom->partRightTop->nodeBottom = nodes.front()->nodeRightBottom;
            }
        } else {
            nodes.front()->partRightTop = nodes.front()->nodeRightBottom->partLeftTop;

            nodes.front()->partRightTop->editPart(nodes.front()->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_RIGHT);

            nodes.front()->partRightTop->nodeBottom = nodes.front();

            nodes.front()->nodeRightBottom->partLeftTop = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::CENTR_RIGHT);
            nodes.front()->partRightBottom = nodes.front()->nodeRightBottom->partLeftTop;

            nodes.front()->nodeRightBottom->partLeftTop->nodeBottom = nodes.front()->nodeRightBottom;
            nodes.front()->partRightBottom->nodeTop = nodes.front();
        }
    }

    for (int i = 1; i < nodes.size() - 1; ++i) {
        nodes[i]->partLeftTop = nodes[i]->nodeLeftBottom->partRightTop;
        nodes[i]->partRightTop = nodes[i]->nodeRightBottom->partLeftTop;

        nodes[i]->partLeftTop->editPart(nodes[i]->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_LEFT);
        nodes[i]->partRightTop->editPart(nodes[i]->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_RIGHT);

        nodes[i]->partLeftTop->nodeBottom = nodes[i];
        nodes[i]->partRightTop->nodeBottom = nodes[i];

        nodes[i]->nodeLeftBottom->partRightTop = createPart(*nodes[i], SchemeObliqueObjectPart::DirectionsPart::CENTR_LEFT);
        nodes[i]->partLeftBottom = nodes[i]->nodeLeftBottom->partRightTop;

        nodes[i]->nodeLeftBottom->partRightTop->nodeBottom = nodes[i]->nodeLeftBottom;
        nodes[i]->partLeftBottom->nodeTop = nodes[i];

        nodes[i]->nodeRightBottom->partLeftTop = createPart(*nodes[i], SchemeObliqueObjectPart::DirectionsPart::CENTR_RIGHT);
        nodes[i]->partRightBottom = nodes[i]->nodeRightBottom->partLeftTop;

        nodes[i]->nodeRightBottom->partLeftTop->nodeBottom = nodes[i]->nodeRightBottom;
        nodes[i]->partRightBottom->nodeTop = nodes[i];
    }

    if (nodes.front() != nodes.back()) {
        nodes.back()->partLeftTop = nodes.back()->nodeLeftBottom->partRightTop;

        nodes.back()->partLeftTop->editPart(nodes.back()->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_LEFT);

        nodes.back()->partLeftTop->nodeBottom = nodes.back();

        nodes.back()->nodeLeftBottom->partRightTop = createPart(*nodes.back(), SchemeObliqueObjectPart::DirectionsPart::CENTR_LEFT);
        nodes.back()->partLeftBottom = nodes.back()->nodeLeftBottom->partRightTop;

        nodes.back()->nodeLeftBottom->partRightTop->nodeBottom = nodes.back()->nodeLeftBottom;
        nodes.back()->partLeftBottom->nodeTop = nodes.back();

        if (nodes.back()->nodeRightBottom->nodeRightTop == nodes.back()) {
            nodes.back()->partRightTop = nodes.back()->nodeRightBottom->partRightTop;

            nodes.back()->partRightTop->editPart(nodes.back()->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_RIGHT);

            nodes.back()->partRightTop->nodeBottom = nodes.back();

            nodes.back()->nodeRightBottom->partRightTop = createPart(*nodes.back(), SchemeObliqueObjectPart::DirectionsPart::CORNER_RIGHT);
            nodes.back()->partRightBottom = nodes.back()->nodeRightBottom->partRightTop;

            nodes.back()->nodeRightBottom->partRightTop->nodeBottom = nodes.back()->nodeRightBottom;
            nodes.back()->partRightBottom->nodeTop = nodes.back();
        } else {
            nodes.back()->partRightTop = nodes.back()->nodeRightBottom->partLeftTop;

            nodes.back()->partRightTop->editPart(nodes.back()->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_RIGHT);

            nodes.back()->partRightTop->nodeBottom = nodes.back();

            nodes.back()->nodeRightBottom->partLeftTop = createPart(*nodes.back(), SchemeObliqueObjectPart::DirectionsPart::CENTR_RIGHT);
            nodes.back()->partRightBottom = nodes.back()->nodeRightBottom->partLeftTop;

            nodes.back()->nodeRightBottom->partLeftTop->nodeBottom = nodes.back()->nodeRightBottom;
            nodes.back()->partRightBottom->nodeTop = nodes.back();

            nodes.back()->nodeRightBottom->partRightTop->editPart(nodes.back()->nodeRightBottom->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_RIGHT);

            nodes.back()->nodeRightBottom->partRightTop->nodeBottom = nodes.back()->nodeRightBottom;
        }
    }
}

void SchemeObliqueSatelliteParts::createPartsBottom(const QList<SchemeObliqueObjectNode *> &nodes)
{
    nodes.front()->partLeftBottom = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::END_LEFT);
    nodes.front()->partRightBottom = createPart(*nodes.front(), SchemeObliqueObjectPart::DirectionsPart::END_RIGHT);

    nodes.front()->partLeftBottom->nodeTop = nodes.front();
    nodes.front()->partRightBottom->nodeTop = nodes.front();

    if (nodes.front()->nodeLeftTop->nodeLeftBottom == nodes.front()) {
        nodes.front()->nodeLeftTop->partLeftBottom->editPart(nodes.front()->nodeLeftTop->pos, SchemeObliqueObjectPart::DirectionsPart::CORNER_LEFT);
        nodes.front()->partLeftTop = nodes.front()->nodeLeftTop->partLeftBottom;

        nodes.front()->nodeLeftTop->partLeftBottom->nodeTop = nodes.front()->nodeLeftTop;
        nodes.front()->partLeftTop->nodeBottom = nodes.front();

        nodes.front()->nodeRightTop->partLeftBottom->editPart(nodes.front()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::CENTR_LEFT);
        nodes.front()->partRightTop = nodes.front()->nodeRightTop->partLeftBottom;

        nodes.front()->nodeRightTop->partLeftBottom->nodeTop = nodes.front()->nodeRightTop;
        nodes.front()->partRightTop->nodeBottom = nodes.front();

        if (nodes.front() == nodes.back()) {
            nodes.front()->nodeRightTop->partRightBottom->editPart(nodes.front()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::END_CORNER_RIGHT);

            nodes.front()->nodeRightTop->partRightBottom->nodeTop = nodes.front()->nodeRightTop;
        }
    } else {
        nodes.front()->nodeLeftTop->partRightBottom->editPart(nodes.front()->nodeLeftTop->pos, SchemeObliqueObjectPart::DirectionsPart::CENTR_RIGHT);
        nodes.front()->partLeftTop = nodes.front()->nodeLeftTop->partRightBottom;

        nodes.front()->nodeLeftTop->partRightBottom->nodeTop = nodes.front()->nodeLeftTop;
        nodes.front()->partLeftTop->nodeBottom = nodes.front();

        nodes.front()->nodeLeftTop->partLeftBottom->editPart(nodes.front()->nodeLeftTop->pos, SchemeObliqueObjectPart::DirectionsPart::END_CORNER_LEFT);

        nodes.front()->nodeLeftTop->partLeftBottom->nodeTop = nodes.front()->nodeLeftTop;

        if (nodes.front() == nodes.back()) {
            if (nodes.front()->nodeRightTop->nodeRightBottom == nodes.front()) {
                nodes.front()->nodeRightTop->partRightBottom->editPart(nodes.front()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::CORNER_RIGHT);
                nodes.front()->partRightTop = nodes.front()->nodeRightTop->partRightBottom;

                nodes.front()->nodeRightTop->partRightBottom->nodeTop = nodes.front()->nodeRightTop;
                nodes.front()->partRightTop->nodeBottom = nodes.front();
            } else {
                nodes.front()->nodeRightTop->partLeftBottom->editPart(nodes.front()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::CENTR_LEFT);
                nodes.front()->partRightTop = nodes.front()->nodeRightTop->partLeftBottom;

                nodes.front()->nodeRightTop->partLeftBottom->nodeTop = nodes.front()->nodeRightTop;
                nodes.front()->partRightTop->nodeBottom = nodes.front();

                nodes.front()->nodeRightTop->partRightBottom->editPart(nodes.front()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::END_CORNER_RIGHT);

                nodes.front()->nodeRightTop->partRightBottom->nodeTop = nodes.front()->nodeRightTop;
            }
        } else {
            nodes.front()->nodeRightTop->partLeftBottom->editPart(nodes.front()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::CENTR_LEFT);
            nodes.front()->partRightTop = nodes.front()->nodeRightTop->partLeftBottom;

            nodes.front()->nodeRightTop->partLeftBottom->nodeTop = nodes.front()->nodeRightTop;
            nodes.front()->partRightTop->nodeBottom = nodes.front();
        }
    }

    for (int i = 1; i < nodes.size() - 1; ++i) {
        nodes[i]->partLeftBottom = createPart(*nodes[i], SchemeObliqueObjectPart::DirectionsPart::END_LEFT);
        nodes[i]->partRightBottom = createPart(*nodes[i], SchemeObliqueObjectPart::DirectionsPart::END_RIGHT);

        nodes[i]->partLeftBottom->nodeTop = nodes[i];
        nodes[i]->partRightBottom->nodeTop = nodes[i];

        nodes[i]->nodeLeftTop->partRightBottom->editPart(nodes[i]->nodeLeftTop->pos, SchemeObliqueObjectPart::DirectionsPart::CENTR_RIGHT);
        nodes[i]->partLeftTop = nodes[i]->nodeLeftTop->partRightBottom;

        nodes[i]->nodeLeftTop->partRightBottom->nodeTop = nodes[i]->nodeLeftTop;
        nodes[i]->partLeftTop->nodeBottom = nodes[i];

        nodes[i]->nodeRightTop->partLeftBottom->editPart(nodes[i]->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::CENTR_LEFT);
        nodes[i]->partRightTop = nodes[i]->nodeRightTop->partLeftBottom;

        nodes[i]->nodeRightTop->partLeftBottom->nodeTop = nodes[i]->nodeRightTop;
        nodes[i]->partRightTop->nodeBottom = nodes[i];
    }

    if (nodes.front() != nodes.back()) {
        nodes.back()->partLeftBottom = createPart(*nodes.back(), SchemeObliqueObjectPart::DirectionsPart::END_LEFT);
        nodes.back()->partRightBottom = createPart(*nodes.back(), SchemeObliqueObjectPart::DirectionsPart::END_RIGHT);

        nodes.back()->partLeftBottom->nodeTop = nodes.back();
        nodes.back()->partRightBottom->nodeTop = nodes.back();

        nodes.back()->nodeLeftTop->partRightBottom->editPart(nodes.back()->nodeLeftTop->pos, SchemeObliqueObjectPart::DirectionsPart::CENTR_RIGHT);
        nodes.back()->partLeftTop = nodes.back()->nodeLeftTop->partRightBottom;

        nodes.back()->nodeLeftTop->partRightBottom->nodeTop = nodes.back()->nodeLeftTop;
        nodes.back()->partLeftTop->nodeBottom = nodes.back();

        if (nodes.back()->nodeRightTop->nodeRightBottom == nodes.back()) {
            nodes.back()->nodeRightTop->partRightBottom->editPart(nodes.back()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::CORNER_RIGHT);
            nodes.back()->partRightTop = nodes.back()->nodeRightTop->partRightBottom;

            nodes.back()->nodeRightTop->partRightBottom->nodeTop = nodes.back()->nodeRightTop;
            nodes.back()->partRightTop->nodeBottom = nodes.back();
        } else {
            nodes.back()->nodeRightTop->partLeftBottom->editPart(nodes.back()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::CENTR_LEFT);
            nodes.back()->partRightTop = nodes.back()->nodeRightTop->partLeftBottom;

            nodes.back()->nodeRightTop->partLeftBottom->nodeTop = nodes.back()->nodeRightTop;
            nodes.back()->partRightTop->nodeBottom = nodes.back();

            nodes.back()->nodeRightTop->partRightBottom->editPart(nodes.back()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::END_CORNER_RIGHT);

            nodes.back()->nodeRightTop->partRightBottom->nodeTop = nodes.back()->nodeRightTop;
        }
    }
}

void SchemeObliqueSatelliteParts::removePartsLeft(const QList<SchemeObliqueObjectNode *> &nodes)
{
    if (nodes.front() == nodes.back()) {
        if (nodes.front()->nodeRightTop && nodes.front()->nodeRightBottom) {
            nodes.front()->nodeRightTop->partLeftBottom->editPart(nodes.front()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::CORNER_LEFT);
            nodes.front()->nodeRightBottom->partLeftTop = nodes.front()->nodeRightTop->partLeftBottom;

            delete nodes.front()->partLeftTop;
            delete nodes.front()->partRightBottom;
            delete nodes.front()->partLeftBottom;

        } else if (nodes.front()->nodeRightTop) {
            nodes.front()->nodeRightTop->partLeftBottom->editPart(nodes.front()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::END_CORNER_LEFT);

            delete nodes.front()->partLeftTop;
            delete nodes.front()->partRightBottom;
            delete nodes.front()->partLeftBottom;

        } else {
            delete nodes.front()->nodeRightBottom->partLeftTop;

            nodes.front()->nodeRightBottom->partLeftTop = nodes.front()->partRightTop;
            nodes.front()->nodeRightBottom->partLeftTop->editPart(nodes.front()->nodeRightBottom->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_LEFT);

            delete nodes.front()->partLeftTop;
            delete nodes.front()->partLeftBottom;
        }
    } else {
        if (nodes.front()->nodeRightTop) {
            nodes.front()->nodeRightTop->partLeftBottom->editPart(nodes.front()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::CORNER_LEFT);
            nodes.front()->nodeRightBottom->partLeftTop = nodes.front()->nodeRightTop->partLeftBottom;

            delete nodes.front()->partLeftTop;
            delete nodes.front()->partRightBottom;
            delete nodes.front()->partLeftBottom;

        } else {
            delete nodes.front()->nodeRightBottom->partLeftTop;

            nodes.front()->nodeRightBottom->partLeftTop = nodes.front()->partRightTop;
            nodes.front()->nodeRightBottom->partLeftTop->editPart(nodes.front()->nodeRightBottom->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_LEFT);

            delete nodes.front()->partLeftTop;
            delete nodes.front()->partLeftBottom;
        }
    }

    for (int i = 1; i < nodes.size() - 1; ++i) {
        nodes[i]->nodeRightTop->partLeftBottom->editPart(nodes[i]->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::CORNER_LEFT);
        nodes[i]->nodeRightBottom->partLeftTop = nodes[i]->nodeRightTop->partLeftBottom;

        delete nodes[i]->partRightBottom;
        delete nodes[i]->partLeftBottom;
    }

    if (nodes.front() != nodes.back()) {
        if (nodes.back()->nodeRightBottom) {
            nodes.back()->nodeRightTop->partLeftBottom->editPart(nodes.back()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::CORNER_LEFT);
            nodes.back()->nodeRightBottom->partLeftTop = nodes.back()->nodeRightTop->partLeftBottom;

            delete nodes.back()->partRightBottom;
            delete nodes.back()->partLeftBottom;
        } else {
            nodes.back()->nodeRightTop->partLeftBottom->editPart(nodes.back()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::END_CORNER_LEFT);

            delete nodes.back()->partRightBottom;
            delete nodes.back()->partLeftBottom;
        }
    }
}

void SchemeObliqueSatelliteParts::removePartsRight(const QList<SchemeObliqueObjectNode *> &nodes)
{
    if (nodes.front() == nodes.back()) {
        if (nodes.front()->nodeLeftTop && nodes.front()->nodeLeftBottom) {
            nodes.front()->nodeLeftTop->partRightBottom->editPart(nodes.front()->nodeLeftTop->pos, SchemeObliqueObjectPart::DirectionsPart::CORNER_RIGHT);
            nodes.front()->nodeLeftBottom->partRightTop = nodes.front()->nodeLeftTop->partRightBottom;

            delete nodes.front()->partRightTop;
            delete nodes.front()->partLeftBottom;
            delete nodes.front()->partRightBottom;

        } else if (nodes.front()->nodeLeftTop) {
            nodes.front()->nodeLeftTop->partRightBottom->editPart(nodes.front()->nodeLeftTop->pos, SchemeObliqueObjectPart::DirectionsPart::END_CORNER_RIGHT);

            delete nodes.front()->partRightTop;
            delete nodes.front()->partLeftBottom;
            delete nodes.front()->partRightBottom;

        } else {
            delete nodes.front()->nodeLeftBottom->partRightTop;

            nodes.front()->nodeLeftBottom->partRightTop = nodes.front()->partLeftTop;
            nodes.front()->nodeLeftBottom->partRightTop->editPart(nodes.front()->nodeLeftBottom->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_RIGHT);

            delete nodes.front()->partRightTop;
            delete nodes.front()->partRightBottom;
        }
    } else {
        if (nodes.front()->nodeLeftTop) {
            nodes.front()->nodeLeftTop->partRightBottom->editPart(nodes.front()->nodeLeftTop->pos, SchemeObliqueObjectPart::DirectionsPart::CORNER_RIGHT);
            nodes.front()->nodeLeftBottom->partRightTop = nodes.front()->nodeLeftTop->partRightBottom;

            delete nodes.front()->partRightTop;
            delete nodes.front()->partLeftBottom;
            delete nodes.front()->partRightBottom;

        } else {
            delete nodes.front()->nodeLeftBottom->partRightTop;

            nodes.front()->nodeLeftBottom->partRightTop = nodes.front()->partLeftTop;
            nodes.front()->nodeLeftBottom->partRightTop->editPart(nodes.front()->nodeLeftBottom->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_RIGHT);

            delete nodes.front()->partRightTop;
            delete nodes.front()->partRightBottom;
        }
    }

    for (int i = 1; i < nodes.size() - 1; ++i) {
        nodes[i]->nodeLeftTop->partRightBottom->editPart(nodes[i]->nodeLeftTop->pos, SchemeObliqueObjectPart::DirectionsPart::CORNER_RIGHT);
        nodes[i]->nodeLeftBottom->partRightTop = nodes[i]->nodeLeftTop->partRightBottom;

        delete nodes[i]->partLeftBottom;
        delete nodes[i]->partRightBottom;
    }

    if (nodes.front() != nodes.back()) {
        if (nodes.back()->nodeLeftBottom) {
            nodes.back()->nodeLeftTop->partRightBottom->editPart(nodes.back()->nodeLeftTop->pos, SchemeObliqueObjectPart::DirectionsPart::CORNER_RIGHT);
            nodes.back()->nodeLeftBottom->partRightTop = nodes.back()->nodeLeftTop->partRightBottom;

            delete nodes.back()->partLeftBottom;
            delete nodes.back()->partRightBottom;
        } else {
            nodes.back()->nodeLeftTop->partRightBottom->editPart(nodes.back()->nodeLeftTop->pos, SchemeObliqueObjectPart::DirectionsPart::END_CORNER_RIGHT);

            delete nodes.back()->partLeftBottom;
            delete nodes.back()->partRightBottom;
        }
    }
}

void SchemeObliqueSatelliteParts::removePartsTop(const QList<SchemeObliqueObjectNode *> &nodes)
{
    if (nodes.front()->nodeLeftBottom->nodeLeftTop == nodes.front()) {
        delete nodes.front()->nodeLeftBottom->partLeftTop;
        delete nodes.front()->nodeRightBottom->partLeftTop;

        nodes.front()->nodeLeftBottom->partLeftTop = nodes.front()->partLeftTop;
        nodes.front()->nodeRightBottom->partLeftTop = nodes.front()->partRightTop;

        nodes.front()->nodeLeftBottom->partLeftTop->nodeBottom = nodes.front()->nodeLeftBottom;
        nodes.front()->nodeRightBottom->partLeftTop->nodeBottom = nodes.front()->nodeRightBottom;

        nodes.front()->nodeLeftBottom->partLeftTop->editPart(nodes.front()->nodeLeftBottom->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_LEFT);
        nodes.front()->nodeRightBottom->partLeftTop->editPart(nodes.front()->nodeRightBottom->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_LEFT);

        if (nodes.front() == nodes.back()) {
            nodes.front()->nodeRightBottom->partRightTop->editPart(nodes.front()->nodeRightBottom->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_RIGHT);
        }
    } else {
        delete nodes.front()->nodeLeftBottom->partRightTop;

        nodes.front()->nodeLeftBottom->partRightTop = nodes.front()->partLeftTop;

        nodes.front()->nodeLeftBottom->partRightTop->nodeBottom = nodes.front()->nodeLeftBottom;

        nodes.front()->nodeLeftBottom->partRightTop->editPart(nodes.front()->nodeLeftBottom->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_RIGHT);
        nodes.front()->nodeLeftBottom->partLeftTop->editPart(nodes.front()->nodeLeftBottom->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_LEFT);

        if (nodes.front() == nodes.back()) {
            if (nodes.front()->nodeRightBottom->nodeRightTop == nodes.front()) {
                delete nodes.front()->nodeRightBottom->partRightTop;

                nodes.front()->nodeRightBottom->partRightTop = nodes.front()->partRightTop;

                nodes.front()->nodeRightBottom->partRightTop->nodeBottom = nodes.front()->nodeRightBottom;

                nodes.front()->nodeRightBottom->partRightTop->editPart(nodes.front()->nodeRightBottom->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_RIGHT);
            } else {
                delete nodes.front()->nodeRightBottom->partLeftTop;

                nodes.front()->nodeRightBottom->partLeftTop = nodes.front()->partRightTop;

                nodes.front()->nodeRightBottom->partLeftTop->nodeBottom = nodes.front()->nodeRightBottom;

                nodes.front()->nodeRightBottom->partLeftTop->editPart(nodes.front()->nodeRightBottom->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_RIGHT);
                nodes.front()->nodeRightBottom->partRightTop->editPart(nodes.front()->nodeRightBottom->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_RIGHT);
            }
        } else {
            delete nodes.front()->nodeRightBottom->partLeftTop;

            nodes.front()->nodeRightBottom->partLeftTop = nodes.front()->partRightTop;

            nodes.front()->nodeRightBottom->partLeftTop->nodeBottom = nodes.front()->nodeRightBottom;

            nodes.front()->nodeRightBottom->partLeftTop->editPart(nodes.front()->nodeRightBottom->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_LEFT);
        }
    }

    for (int i = 1; i < nodes.size() - 1; ++i) {
        delete nodes[i]->nodeLeftBottom->partRightTop;
        delete nodes[i]->nodeRightBottom->partLeftTop;

        nodes[i]->nodeLeftBottom->partRightTop = nodes[i]->partLeftTop;
        nodes[i]->nodeRightBottom->partLeftTop = nodes[i]->partRightTop;

        nodes[i]->nodeLeftBottom->partRightTop->nodeBottom = nodes[i]->nodeLeftBottom;
        nodes[i]->nodeRightBottom->partLeftTop->nodeBottom = nodes[i]->nodeRightBottom;

        nodes[i]->nodeLeftBottom->partRightTop->editPart(nodes[i]->nodeLeftBottom->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_RIGHT);
        nodes[i]->nodeRightBottom->partLeftTop->editPart(nodes[i]->nodeRightBottom->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_LEFT);
    }

    if (nodes.front() != nodes.back()) {
        delete nodes.back()->nodeLeftBottom->partRightTop;

        nodes.back()->nodeLeftBottom->partRightTop = nodes.back()->partLeftTop;

        nodes.back()->nodeLeftBottom->partRightTop->nodeBottom =  nodes.back()->nodeLeftBottom;

        nodes.back()->nodeLeftBottom->partRightTop->editPart(nodes.back()->nodeLeftBottom->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_RIGHT);

        if (nodes.back()->nodeRightBottom->nodeRightTop == nodes.back()) {
            delete nodes.back()->nodeRightBottom->partRightTop;

            nodes.back()->nodeRightBottom->partRightTop = nodes.back()->partRightTop;

            nodes.back()->nodeRightBottom->partRightTop->nodeBottom =  nodes.back()->nodeRightBottom;

            nodes.back()->nodeRightBottom->partRightTop->editPart(nodes.back()->nodeRightBottom->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_CORNER_RIGHT);
        } else {
            delete nodes.back()->nodeRightBottom->partLeftTop;

            nodes.back()->nodeRightBottom->partLeftTop = nodes.back()->partRightTop;

            nodes.back()->nodeRightBottom->partLeftTop->nodeBottom =  nodes.back()->nodeRightBottom;

            nodes.back()->nodeRightBottom->partRightTop->editPart(nodes.back()->nodeRightBottom->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_RIGHT);

            nodes.back()->nodeRightBottom->partLeftTop->editPart(nodes.back()->nodeRightBottom->pos, SchemeObliqueObjectPart::DirectionsPart::BEGGINING_LEFT);
        }
    }
}

void SchemeObliqueSatelliteParts::removePartsBottom(const QList<SchemeObliqueObjectNode *> &nodes)
{
    delete nodes.front()->partLeftBottom;
    delete nodes.front()->partRightBottom;

    if (nodes.front()->nodeLeftTop->nodeLeftBottom == nodes.front()) {
        nodes.front()->nodeLeftTop->partLeftBottom->editPart(nodes.front()->nodeLeftTop->pos, SchemeObliqueObjectPart::DirectionsPart::END_CORNER_LEFT);

        nodes.front()->nodeRightTop->partLeftBottom->editPart(nodes.front()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::END_LEFT);

        if (nodes.front() == nodes.back()) {
            nodes.front()->nodeRightTop->partRightBottom->editPart(nodes.front()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::END_RIGHT);
        }
    } else {
        nodes.front()->nodeLeftTop->partRightBottom->editPart(nodes.front()->nodeLeftTop->pos, SchemeObliqueObjectPart::DirectionsPart::END_RIGHT);
        nodes.front()->nodeLeftTop->partLeftBottom->editPart(nodes.front()->nodeLeftTop->pos, SchemeObliqueObjectPart::DirectionsPart::END_LEFT);

        if (nodes.front() == nodes.back()) {
            if (nodes.front()->nodeRightTop->nodeRightBottom == nodes.front()) {
                nodes.front()->nodeRightTop->partRightBottom->editPart(nodes.front()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::END_CORNER_RIGHT);
            } else {
                nodes.front()->nodeRightTop->partLeftBottom->editPart(nodes.front()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::END_RIGHT);
                nodes.front()->nodeRightTop->partRightBottom->editPart(nodes.front()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::END_CORNER_RIGHT);
            }
        } else {
            nodes.front()->nodeRightTop->partLeftBottom->editPart(nodes.front()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::END_LEFT);
        }
    }

    for (int i = 1; i < nodes.size() - 1; ++i) {
        delete nodes[i]->partLeftBottom;
        delete nodes[i]->partRightBottom;

        nodes[i]->nodeLeftTop->partRightBottom->editPart(nodes[i]->nodeLeftTop->pos, SchemeObliqueObjectPart::DirectionsPart::END_RIGHT);

        nodes[i]->nodeRightTop->partLeftBottom->editPart(nodes[i]->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::END_LEFT);
    }

    if (nodes.front() != nodes.back()) {
        delete nodes.back()->partLeftBottom;
        delete nodes.back()->partRightBottom;

        nodes.back()->nodeLeftTop->partRightBottom->editPart(nodes.back()->nodeLeftTop->pos, SchemeObliqueObjectPart::DirectionsPart::END_RIGHT);

        if (nodes.back()->nodeRightTop->nodeRightBottom == nodes.back()) {
            nodes.back()->nodeRightTop->partRightBottom->editPart(nodes.back()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::END_CORNER_RIGHT);
        } else {
            nodes.back()->nodeRightTop->partLeftBottom->editPart(nodes.back()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::END_LEFT);
            nodes.back()->nodeRightTop->partRightBottom->editPart(nodes.back()->nodeRightTop->pos, SchemeObliqueObjectPart::DirectionsPart::END_RIGHT);
        }
    }
}

SchemeObliqueObjectPart *SchemeObliqueSatelliteParts::createPart(SchemeObliqueObjectNode &node, const SchemeObliqueObjectPart::DirectionsPart &type)
{
    SchemeObliqueObjectPart *part = new SchemeObliqueObjectPart(node.pos, type);

    this->scene->addItem(part);

    return part;
}
