#include "schemeobliquesatelliteinfos.h"

#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"

SchemeObliqueSatelliteInfos::SchemeObliqueSatelliteInfos(SchemeObliqueChartScene *scene, QObject *parent): QObject(parent), scene(scene)
{

}

SchemeObliqueSatelliteInfos::~SchemeObliqueSatelliteInfos()
{

}

int SchemeObliqueSatelliteInfos::getSizeThread()
{
    int size = 0;

    if (this->scene->nodes.getSizeTop() == 0) {
        size = SchemeObliqueChartScene::defaultCountThread;
    } else {
        size = this->scene->nodes.getSizeTop() * 2;
        if (this->scene->nodes.getTopBack() != this->scene->nodes.getRightFront()) {
            size++;
        }
        if (this->scene->nodes.getTopFront() != this->scene->nodes.getLeftFront()) {
            size++;
        }
    }

    return size;
}

int SchemeObliqueSatelliteInfos::getSizeHalfrow()
{
    int size = 0;

    if (this->scene->nodes.getSizeLeft() == 0) {
        size = SchemeObliqueChartScene::defaultCountHalfrow;
    } else {
        size = this->scene->nodes.getSizeLeft() * 2 - 1;
        if (this->scene->nodes.getLeftFront() != this->scene->nodes.getTopFront()) {
            size++;
        }
        if (this->scene->nodes.getLeftBack() != this->scene->nodes.getBottomFront()) {
            size++;
        }
    }

    return size;
}

bool SchemeObliqueSatelliteInfos::getIsNode1_2()
{
    bool isNode1_2 = 0;

    if (this->scene->nodes.getSizeLeft() == 0 && this->scene->nodes.getSizeTop() == 0) {
        return SchemeObliqueChartScene::defaultIsNode1_2;
    } else {
        return this->scene->nodes.getLeftFront() == this->scene->nodes.getTopFront();
    }

    return isNode1_2;
}

QStringList SchemeObliqueSatelliteInfos::getNodeDirections()
{
    return scene->nodes.getNodeDirections();
}

QStringList SchemeObliqueSatelliteInfos::getThreadColors()
{
    QStringList listThreadColors;

    for (const QBrush &brush : scene->parts.getThreadColors(scene->nodes.top)) {
        listThreadColors.push_back(brush.color().name());
    }

    return listThreadColors;
}
