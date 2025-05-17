#ifndef SCHEMEOBLIQUESATELLITEINFOS_H
#define SCHEMEOBLIQUESATELLITEINFOS_H

#include <QObject>

class SchemeObliqueChartScene;

class SchemeObliqueSatelliteInfos : public QObject
{
    Q_OBJECT

public:
    SchemeObliqueSatelliteInfos(SchemeObliqueChartScene *scene, QObject *parent = nullptr);
    ~SchemeObliqueSatelliteInfos();

    int getSizeThread();
    int getSizeHalfrow();
    bool getIsNode1_2();
    QStringList getNodeDirections();
    QStringList getThreadColors();

private:
    SchemeObliqueChartScene *scene = nullptr;
};

#endif // SCHEMEOBLIQUESATELLITEINFOS_H
