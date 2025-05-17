#ifndef SCHEMEOBLIQUEFILEREADFBD_H
#define SCHEMEOBLIQUEFILEREADFBD_H

#include <QBitArray>
#include <QBrush>

#include "Abstract/abstractschemefileread.h"

class SchemeObliqueFileReadFBD: public AbstractSchemeFileRead
{
public:
    SchemeObliqueFileReadFBD();
    ~SchemeObliqueFileReadFBD();

    AbstractSchemeChartView &readScheme(QByteArray byteArray, QString name);

private:
    int readCountThread(QByteArray &byteArray, int &countThread);
    int readCountHalfrow(QByteArray &byteArray);
    int readIsNode1_2(QByteArray &byteArray, int &countThreads);

    int readInteger(QByteArray &byteArray);

    QList<bool> readListIsSetColor(QByteArray &byteArray, const int &countThread, const int &isNode1_2);

    void readIsColor(QByteArray &byteArray, const int &countThread, QList<bool> &result);

    QList<QBrush> readListColorThreads(QByteArray &byteArray, const QList<bool> &isColor);
    QList<int> readListNodeDirections(QByteArray &byteArray, const int &countRows, const int &coutDirection);

    int countMatrixElemets(const int &countThread, const int &isNode1_2);
};

#endif // SCHEMEOBLIQUEFILEREADFBD_H
