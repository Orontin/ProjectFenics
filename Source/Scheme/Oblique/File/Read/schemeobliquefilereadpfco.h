#ifndef SCHEMEOBLIQUEFILEREADPFCO_H
#define SCHEMEOBLIQUEFILEREADPFCO_H

#include "Abstract/abstractschemefileread.h"

class SchemeObliqueFileReadPFCO : public AbstractSchemeFileRead
{
public:
    static SchemeObliqueFileReadPFCO &getInstance(AbstractScheme &scheme);

    void readScheme(QByteArray byteArray, QString name) override final;;

private:
    SchemeObliqueFileReadPFCO(AbstractScheme &scheme);
    ~SchemeObliqueFileReadPFCO();

    void setColorThreads(QList<QBrush> &colorThreads, const QJsonObject &jsonObject);
    void setDirectionNode(QList<int> &nodeDirections, const QJsonObject &jsonObject);
    void setIsNode1_2(bool &isNode1_2, const QJsonObject &jsonObject);
    void setCountHalfrow(int &countHalfrow, const QJsonObject &jsonObject);
    void setCountThreads(int &countThreads, const QJsonObject &jsonObject);

    static SchemeObliqueFileReadPFCO *schemeObliqueFileReadPFCO;
};

#endif // SCHEMEOBLIQUEFILEREADPFCO_H
