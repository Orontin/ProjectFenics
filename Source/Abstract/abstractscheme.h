#ifndef ABSTRACTSCHEME_H
#define ABSTRACTSCHEME_H

#include <QAction>
#include <QList>

#include "Abstract/abstractschemechartview.h"
#include "Abstract/abstractschemefileread.h"
#include "Abstract/abstractschemefilewrite.h"

class AbstractScheme: public QObject {
    Q_OBJECT

public:
    AbstractScheme(QList<AbstractSchemeFileRead*> &listFileRead, AbstractSchemeFileWrite &fileWrite): listFileRead(&listFileRead), fileWrite(&fileWrite) {};
    ~AbstractScheme() {
        for (AbstractSchemeFileRead *abstractSchemeFileRead : *listFileRead) {
            delete abstractSchemeFileRead;
        }
        delete listFileRead;
        delete fileWrite;
    };

    virtual QAction &getActionCreate() = 0;
    virtual QList<AbstractSchemeFileRead*> &getListFileRead() = 0;
    virtual AbstractSchemeFileWrite &getFileWrite() = 0;
    virtual const QString &getTypeScheme() = 0;

signals:
    void createOut(AbstractSchemeChartView &view);

protected:
    QAction actionCreate;

    QList<AbstractSchemeFileRead*> *listFileRead;
    AbstractSchemeFileWrite *fileWrite;
};

#endif // ABSTRACTSCHEME_H
