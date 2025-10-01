#ifndef SCHEMEOBLIQUEFILEREADRNX_H
#define SCHEMEOBLIQUEFILEREADRNX_H

#include <QBitArray>
#include <QBrush>

#include "Abstract/abstractschemefileread.h"

class SchemeObliqueFileReadRNX: public AbstractSchemeFileRead
{
public:
    static SchemeObliqueFileReadRNX &getInstance();

    AbstractSchemeChartView &readScheme(QByteArray byteArray, QString name);

private:
    SchemeObliqueFileReadRNX();
    ~SchemeObliqueFileReadRNX();

    int readCountLine(QByteArray &byteArray);
    int readCountRow(QByteArray &byteArray);

    int readInteger(QByteArray &byteArray);

    QList<QBrush> readListColorThreads(QByteArray &byteArray, int countThreads);
    QList<int> readListKnotDirections(QByteArray &byteArray, int countRows);

    static SchemeObliqueFileReadRNX *schemeObliqueFileReadRNX;
};

#endif // SCHEMEOBLIQUEFILEREADRNX_H
