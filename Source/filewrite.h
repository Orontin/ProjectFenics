#ifndef FILEWRITE_H
#define FILEWRITE_H

#include <QObject>
#include <QFile>

#include "Abstract/abstractscheme.h"

class FileWrite: public QObject
{
    Q_OBJECT

public:
    FileWrite(QList<AbstractScheme*> &schemes);
    ~FileWrite();

    void writeFile(AbstractSchemeChartView &view);

private:

    QString filter;
    QList<AbstractScheme*> &schemes;
};

#endif // FILEWRITE_H
