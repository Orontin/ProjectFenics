#include "schemeobliquesatellitecolors.h"

SchemeObliqueSatelliteColors::SchemeObliqueSatelliteColors(SchemeObliqueChartScene *scene, QObject *parent):
    QObject{parent},
    scene(scene)
{

}

SchemeObliqueSatelliteColors::~SchemeObliqueSatelliteColors()
{

}

void SchemeObliqueSatelliteColors::createColorsLeft(const QList<SchemeObliqueObjectNode *> &nodes)
{
    for (const SchemeObliqueObjectNode *node : nodes) {
        node->partRightTop->updateColor();
        node->partLeftTop->updateColor();
    }
}

void SchemeObliqueSatelliteColors::createColorsRight(const QList<SchemeObliqueObjectNode *> &nodes)
{
    for (const SchemeObliqueObjectNode *node : nodes) {
        node->partRightTop->updateColor();
        node->partLeftTop->updateColor();
    }
}

void SchemeObliqueSatelliteColors::createColorsTop(const QList<SchemeObliqueObjectNode *> &nodes)
{
    for (const SchemeObliqueObjectNode *node : nodes) {
        node->partLeftTop->updateColor();
        node->partRightTop->updateColor();
    }
}

void SchemeObliqueSatelliteColors::createColorsBottom(const QList<SchemeObliqueObjectNode *> &nodes)
{
    for (const SchemeObliqueObjectNode *node : nodes) {
        node->partLeftTop->updateColor();
        node->partRightTop->updateColor();
    }
}

void SchemeObliqueSatelliteColors::removeColorsLeft(const QList<SchemeObliqueObjectNode *> &nodes)
{
    for (const SchemeObliqueObjectNode *node : nodes) {
        node->partLeftTop->updateColor();
        node->partRightTop->updateColor();
    }
}

void SchemeObliqueSatelliteColors::removeColorsRight(const QList<SchemeObliqueObjectNode *> &nodes)
{
    for (const SchemeObliqueObjectNode *node : nodes) {
        node->partLeftTop->updateColor();
        node->partRightTop->updateColor();
    }
}

void SchemeObliqueSatelliteColors::removeColorsTop(const QList<SchemeObliqueObjectNode *> &nodes)
{
    for (const SchemeObliqueObjectNode *node : nodes) {
        node->partRightTop->updateColor();
        node->partLeftTop->updateColor();
    }
}

void SchemeObliqueSatelliteColors::removeColorsBottom(const QList<SchemeObliqueObjectNode *> &nodes)
{
    Q_UNUSED(nodes)
}
