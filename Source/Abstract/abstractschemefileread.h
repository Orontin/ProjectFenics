#ifndef ABSTRACTSCHEMEFILEREAD_H
#define ABSTRACTSCHEMEFILEREAD_H

#include <QObject>

#include "Abstract/abstractschemechartview.h"

class AbstractSchemeFileRead: public QObject
{
    Q_OBJECT

public:
    AbstractSchemeFileRead(const QString &prefix, const QString &filter, AbstractScheme &scheme): prefix(prefix), filter(QString("%1 (*.%2)").arg(filter).arg(prefix)), scheme(scheme) {};
    ~AbstractSchemeFileRead() {};

    virtual void readScheme(QByteArray byteArray, QString name) = 0;

    AbstractScheme &getScheme() { return this->scheme; };

    const QString prefix;
    const QString filter;

signals:
    void createOut(AbstractSchemeChartView &view);

private:
    AbstractScheme &scheme;
};

#endif // ABSTRACTSCHEMEFILEREAD_H
