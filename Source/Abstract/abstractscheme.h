#ifndef ABSTRACTSCHEME_H
#define ABSTRACTSCHEME_H

#include <QAction>
#include <QList>
#include <QMenu>

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

    virtual void setMenuCreate(QMenu &menuCreate) = 0;
    virtual void setMenuSettings(QMenu &menuSettings) = 0;
    virtual void updateShortcut() = 0;
    virtual QList<AbstractSchemeFileRead*> &getListFileRead() = 0;
    virtual AbstractSchemeFileWrite &getFileWrite() = 0;
    virtual const QString &getTypeScheme() = 0;

signals:
    void createOut(AbstractSchemeChartView &view);

protected:
    QList<AbstractSchemeFileRead*> *listFileRead;
    AbstractSchemeFileWrite *fileWrite;
};

#endif // ABSTRACTSCHEME_H
