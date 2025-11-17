#include "schemeobliquefilewritepfco.h"

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"

SchemeObliqueFileWritePFCO *SchemeObliqueFileWritePFCO::schemeObliqueFileWritePFCO{nullptr};

SchemeObliqueFileWritePFCO &SchemeObliqueFileWritePFCO::getInstance()
{
    if (!SchemeObliqueFileWritePFCO::schemeObliqueFileWritePFCO) {
        SchemeObliqueFileWritePFCO::schemeObliqueFileWritePFCO = new SchemeObliqueFileWritePFCO;
    }
    return *schemeObliqueFileWritePFCO;
}

QByteArray SchemeObliqueFileWritePFCO::writeScheme(const AbstractSchemeChartView &view)
{
    QJsonObject jsonObject;

    QJsonArray threadsArray;
    QStringList colorThreads = static_cast<SchemeObliqueChartScene*>(view.scene())->info.getThreadColors();
    for (const QString &colorThread : colorThreads) {
        threadsArray.append(colorThread);
    }
    jsonObject["ColorThreads"] = threadsArray;

    QJsonArray directionNodesArray;
    QStringList directionNodes = static_cast<SchemeObliqueChartScene*>(view.scene())->info.getNodeDirections();
    for (const QString &directionNode : directionNodes) {
        directionNodesArray.append(directionNode);
    }
    jsonObject["DirectionNodes"] = directionNodesArray;

    jsonObject["IsNode1_2"] = QString::number(static_cast<SchemeObliqueChartScene*>(view.scene())->info.getIsNode1_2());
    jsonObject["CountHalfrow"] = QString::number(static_cast<SchemeObliqueChartScene*>(view.scene())->info.getSizeHalfrow());
    jsonObject["CountThreads"] = QString::number(static_cast<SchemeObliqueChartScene*>(view.scene())->info.getSizeThread());

    QJsonDocument jsonDoc(jsonObject);
    return jsonDoc.toJson(QJsonDocument::Indented);
}

SchemeObliqueFileWritePFCO::SchemeObliqueFileWritePFCO(): AbstractSchemeFileWrite("pf.co", "Project Fenics - Complicated Oblique") {

}

SchemeObliqueFileWritePFCO::~SchemeObliqueFileWritePFCO()
{

}

