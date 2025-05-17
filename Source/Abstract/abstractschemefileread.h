#ifndef ABSTRACTSCHEMEFILEREAD_H
#define ABSTRACTSCHEMEFILEREAD_H

#include <QObject>

#include "Abstract/abstractschemechartview.h"

class AbstractSchemeFileRead: public QObject
{
    Q_OBJECT

public:
    AbstractSchemeFileRead(const QString &prefix, const QString &filter): prefix(prefix), filter(QString("%1 (*.%2)").arg(filter).arg(prefix)) {};
    ~AbstractSchemeFileRead() {};

    virtual AbstractSchemeChartView &readScheme(QByteArray byteArray, QString name) = 0;

    const QString prefix;
    const QString filter;
};

#endif // ABSTRACTSCHEMEFILEREAD_H
