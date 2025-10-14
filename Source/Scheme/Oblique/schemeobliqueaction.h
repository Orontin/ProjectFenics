#ifndef SCHEMEOBLIQUEACTION_H
#define SCHEMEOBLIQUEACTION_H

#include <QGridLayout>
#include <QAction>
#include <QList>
#include <QMenu>
#include <QObject>

class SchemeObliqueAction : public QObject
{
    Q_OBJECT
public:
    static SchemeObliqueAction &getInstance();

    void setMenuCreate(QMenu &menuCreate);
    void setMenuSettings(QMenu &menuSettings);
    void setMenuHistory(QMenu &menuHistory);
    void setMenuManagment(QMenu &menuManagment);
    void setMenuSettingsOpenScheme(QMenu &menuSettingsOpenScheme);
    void setMenuView(QMenu &menuView);

    QAction actionCreate;
    QAction actionEditDirectionNewNode;

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

    QAction actionZoomOut;
    QAction actionZoomIn;
    QAction actionToBottom;
    QAction actionToTop;
    QAction actionToLeft;
    QAction actionToRight;
    QAction actionRotateLeft;
    QAction actionRotateRight;

public slots:
    void onActionEnableRemoveThreadLeftAndRight(const bool enable);
    void onActionEnableRemoveHalfrowDownAndTop(const bool enable);
    void onActionEnableAddThreadLeftAndRight(const bool enable);
    void onActionEnableAddHalfrowDownAndTop(const bool enable);

    void onActionEnableBack(const bool enable);
    void onActionEnableNext(const bool enable);

private:
    SchemeObliqueAction();
    ~SchemeObliqueAction();

    static SchemeObliqueAction *schemeObliqueAction;

    void createActions();
    void createActionOblique();
    void createActionView();
    void createActionScene();

    QMenu menuSettings;

    QMenu menuThread;
    QMenu menuHalfrow;

    QMenu menuZoom;
    QMenu menuTo;
    QMenu menuRotate;
};

#endif // SCHEMEOBLIQUEACTION_H
