#include "schemeobliquefilewritepfco.h"

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"

SchemeObliqueFileWritePFCO::SchemeObliqueFileWritePFCO(): AbstractSchemeFileWrite("pf.co", "Project Fenics - Complicated Oblique") {

}

SchemeObliqueFileWritePFCO::~SchemeObliqueFileWritePFCO()
{

}

QByteArray SchemeObliqueFileWritePFCO::writeScheme(const AbstractSchemeChartView &view)
{
    QJsonObject jsonObject;

    QJsonArray threadsArray;
    QStringList colorThreads = static_cast<SchemeObliqueChartScene*>(view.scene())->getThreadColors();
    for (const QString &colorThread : colorThreads) {
        threadsArray.append(colorThread);
    }
    jsonObject["ColorThreads"] = threadsArray;

    QJsonArray directionNodesArray;
    QStringList directionNodes = static_cast<SchemeObliqueChartScene*>(view.scene())->getNodeDirections();
    for (const QString &directionNode : directionNodes) {
        directionNodesArray.append(directionNode);
    }
    jsonObject["DirectionNodes"] = directionNodesArray;

    jsonObject["IsNode1_2"] = QString::number(static_cast<SchemeObliqueChartScene*>(view.scene())->getIsNode1_2());
    jsonObject["CountHalfrow"] = QString::number(static_cast<SchemeObliqueChartScene*>(view.scene())->getSizeHalfrow());
    jsonObject["CountThreads"] = QString::number(static_cast<SchemeObliqueChartScene*>(view.scene())->getSizeThread());

    QJsonDocument jsonDoc(jsonObject);
    return jsonDoc.toJson(QJsonDocument::Indented);
}
