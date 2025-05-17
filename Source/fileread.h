#ifndef FILEREAD_H
#define FILEREAD_H

#include <QObject>
#include <QFile>

#include "Abstract/abstractscheme.h"

class FileRead: public QObject
{
    Q_OBJECT

public:
    FileRead(QList<AbstractScheme*> &schemes);
    ~FileRead();

    void readFile();

signals:
    void createOut(AbstractSchemeChartView &view);

private:
    void searchAbstractSchemeFileRead(const QString &prefix, QList<AbstractSchemeFileRead*> &listAbstractSchemeFileRead);
    void workAbstractSchemeFileRead(QList<AbstractSchemeFileRead*> &listAbstractSchemeFileRead, QFile &file);

    void showMessageBoxError(const QString &pathFile, const QString &error);

    void setFilterRead();

    QString filter;
    QList<AbstractScheme*> &schemes;
};

#endif // FILEREAD_H
