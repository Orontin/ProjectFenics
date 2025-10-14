#ifndef SCHEMEOBLIQUE_H
#define SCHEMEOBLIQUE_H

#include <QObject>

#include "Abstract/abstractscheme.h"

#include "Abstract/abstractschemechartscene.h"
#include "Abstract/abstractschemechartview.h"

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

    void setMenuCreate(QMenu &menuCreate) override final;
    void setMenuSettings(QMenu &menuSettings) override final;
    void setMenuHistory(QMenu &menuHistory) override final;
    void setMenuManagment(QMenu &menuManagment) override final;
    void setMenuSettingsOpenScheme(QMenu &menuSettingsOpenScheme) override final;
    void setMenuView(QMenu &menuView) override final;

    QList<AbstractSchemeFileRead*> &getListFileRead() override final;
    AbstractSchemeFileWrite &getFileWrite() override final;

private slots:
    void connectsView(AbstractSchemeChartView &view);
    void connectsScene(AbstractSchemeChartScene &scene);

    void onActionEnableRemoveThreadLeftAndRight(const bool enable);
    void onActionEnableRemoveHalfrowDownAndTop(const bool enable);
    void onActionEnableAddThreadLeftAndRight(const bool enable);
    void onActionEnableAddHalfrowDownAndTop(const bool enable);

    void onActionEnableBack(const bool enable);
    void onActionEnableNext(const bool enable);

private:
    SchemeOblique();
    ~SchemeOblique();

    void onUpdateShortcutOblique();
    void onUpdateShortcutView();
    void onUpdateShortcutScene();

    void createActions();
    void createActionOblique();
    void createActionView();
    void createActionScene();

    QMenu menuSettings;
    QAction actionCreate;
    QAction actionEditDirectionNewNode;

    QMenu menuThread;
    QMenu menuHalfrow;
    QAction actionBack;
    QAction actionNext;
    QAction actionRemoveThreadLeft;
    QAction actionRemoveThreadRight;
    QAction actionAddThreadLeft;
    QAction actionAddThreadRight;
    QAction actionRemoveHalfrowDown;
    QAction actionRemoveHalfrowTop;
    QAction actionAddHalfrowDown;
    QAction actionAddHalfrowTop;

    QMenu menuZoom;
    QMenu menuTo;
    QMenu menuRotate;
    QAction actionZoomOut;
    QAction actionZoomIn;
    QAction actionToBottom;
    QAction actionToTop;
    QAction actionToLeft;
    QAction actionToRight;
    QAction actionRotateLeft;
    QAction actionRotateRight;

    QList<AbstractSchemeFileRead*> listFileRead;

    static SchemeOblique *schemeOblique;
};

#endif // SCHEMEOBLIQUE_H
