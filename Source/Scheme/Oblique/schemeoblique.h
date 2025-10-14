#ifndef SCHEMEOBLIQUE_H
#define SCHEMEOBLIQUE_H

#include <QObject>
#include <QLabel>
#include <QKeySequenceEdit>

#include "Abstract/abstractscheme.h"
#include "Abstract/abstractschemechartview.h"

class SchemeObliqueChartView;
class SchemeObliqueChartScene;

class SchemeOblique : public AbstractScheme
{
    Q_OBJECT
public:
    enum Directions {
        ADD_TOP       = 0,
        ADD_BOTTOM    = 1,
        ADD_LEFT      = 2,
        ADD_RIGHT     = 3,
        REMOVE_TOP    = 4,
        REMOVE_BOTTOM = 5,
        REMOVE_LEFT   = 6,
        REMOVE_RIGHT  = 7
    };

    static SchemeOblique &getInstance();

    void onUpdateShortcut() override final;

    void disconnects() override final;
    void connects(AbstractSchemeChartView &view) override final;

    void setShortcut(QGridLayout &gridLayouShortcut) override final;
    void setMenuCreate(QMenu &menuCreate) override final;
    void setMenuSettings(QMenu &menuSettings) override final;
    void setMenuHistory(QMenu &menuHistory) override final;
    void setMenuManagment(QMenu &menuManagment) override final;
    void setMenuSettingsOpenScheme(QMenu &menuSettingsOpenScheme) override final;
    void setMenuView(QMenu &menuView) override final;

    QList<AbstractSchemeFileRead*> &getListFileRead() override final;
    AbstractSchemeFileWrite &getFileWrite() override final;

public slots:
    void onShortcutSetDefaultShortcut() override final;
    void onShortcutCancel() override final;
    void onShortcutSave() override final;

private:
    SchemeOblique();
    ~SchemeOblique();

    void connectsView(SchemeObliqueChartView &view);
    void connectsScene(SchemeObliqueChartScene &scene);

    void onUpdateShortcutOblique();
    void onUpdateShortcutView();
    void onUpdateShortcutScene();

    QList<AbstractSchemeFileRead*> listFileRead;

    QMetaObject::Connection connectActionEnableRemoveThreadLeftAndRight;
    QMetaObject::Connection connectActionEnableRemoveHalfrowDownAndTop;
    QMetaObject::Connection connectActionEnableAddThreadLeftAndRight;
    QMetaObject::Connection connectActionEnableAddHalfrowDownAndTop;
    QMetaObject::Connection connectActionEnableBack;
    QMetaObject::Connection connectActionEnableNext;

    static SchemeOblique *schemeOblique;
};

#endif // SCHEMEOBLIQUE_H
