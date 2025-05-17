#ifndef ABSTRACTSCHEMEFILEWRITE_H
#define ABSTRACTSCHEMEFILEWRITE_H

#include <QObject>

#include "Abstract/abstractschemechartview.h"

class AbstractSchemeFileWrite: public QObject
{
    Q_OBJECT

public:
    AbstractSchemeFileWrite(const QString &prefix, const QString &filter): prefix(prefix), filter(QString("%1 (*.%2)").arg(filter).arg(prefix)) {};
    ~AbstractSchemeFileWrite() {};

    virtual QByteArray writeScheme(const AbstractSchemeChartView &view) = 0;

    const QString prefix;
    const QString filter;
};

#endif // ABSTRACTSCHEMEFILEWRITE_H
