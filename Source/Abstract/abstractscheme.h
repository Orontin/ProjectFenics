#ifndef ABSTRACTSCHEME_H
#define ABSTRACTSCHEME_H

#include <QAction>
#include <QList>
#include <QMenu>

#include "Abstract/abstractschemechartview.h"
#include "Abstract/abstractschemefileread.h"
#include "Abstract/abstractschemefilewrite.h"

class AbstractScheme: public QObject
{
    Q_OBJECT

public:
    virtual void onUpdateShortcut() = 0;

    virtual void disconnects() = 0;
    virtual void connects(AbstractSchemeChartView &view) = 0;

    virtual void setMenuCreate(QMenu &menuCreate) = 0;
    virtual void setMenuSettings(QMenu &menuSettings) = 0;
    virtual void setMenuHistory(QMenu &menuHistory) = 0;
    virtual void setMenuManagment(QMenu &menuManagment) = 0;
    virtual void setMenuView(QMenu &menuView) = 0;
    virtual void setMenuSettingsOpenScheme(QMenu &menuSettingsOpenScheme) = 0;

    virtual QList<AbstractSchemeFileRead*> &getListFileRead() = 0;
    virtual AbstractSchemeFileWrite &getFileWrite() = 0;

signals:
    void createOut(AbstractSchemeChartView &view);
};

#endif // ABSTRACTSCHEME_H
