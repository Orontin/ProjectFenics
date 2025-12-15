#ifndef SCHEMEOBLIQUEFILESETTING_H
#define SCHEMEOBLIQUEFILESETTING_H

#include "Abstract/abstractschemefilesetting.h"

#include "Scheme/Oblique/Widget/EditDirectionForNewNode/Chart/schemeobliquewidgeteditdirectionfornewnodechartscene.h"

class SchemeObliqueFileSetting: public AbstractSchemeFileSetting
{
public:
    static void setStandartDirectionObliqueNode(const SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode &standartDirectionObliqueNode);
    static SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode getStandartDirectionObliqueNode();

    static void setListShortcutActionSchemeObliqueShortcutSceneCreate(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionSchemeObliqueShortcutHistoryBack(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionSchemeObliqueShortcutHistoryNext(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionSchemeObliqueShortcutSceneThreadRemoveLeft(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionSchemeObliqueShortcutSceneThreadRemoveRight(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionSchemeObliqueShortcutSceneThreadAddLeft(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionSchemeObliqueShortcutSceneThreadAddRight(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionSchemeObliqueShortcutSceneHalfrowRemoveDown(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionSchemeObliqueShortcutSceneHalfrowRemoveTop(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionSchemeObliqueShortcutSceneHalfrowAddDown(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionSchemeObliqueShortcutSceneHalfrowAddTop(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionSchemeObliqueShortcutSceneEditDirectionNewNode(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionSchemeObliqueShortcutSceneColorMap(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionSchemeObliqueShortcutViewZoomOut(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionSchemeObliqueShortcutViewZoomIn(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionSchemeObliqueShortcutViewToBottom(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionSchemeObliqueShortcutViewToTop(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionSchemeObliqueShortcutViewToLeft(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionSchemeObliqueShortcutViewToRight(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionSchemeObliqueShortcutViewRotateLeft(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionSchemeObliqueShortcutViewRotateRight(const QList<QKeySequence> &valueParam);

    static QList<QKeySequence> getListShortcutActionSchemeObliqueShortcutSceneCreate();
    static QList<QKeySequence> getListShortcutActionSchemeObliqueShortcutHistoryBack();
    static QList<QKeySequence> getListShortcutActionSchemeObliqueShortcutHistoryNext();
    static QList<QKeySequence> getListShortcutActionSchemeObliqueShortcutSceneThreadRemoveLeft();
    static QList<QKeySequence> getListShortcutActionSchemeObliqueShortcutSceneThreadRemoveRight();
    static QList<QKeySequence> getListShortcutActionSchemeObliqueShortcutSceneThreadAddLeft();
    static QList<QKeySequence> getListShortcutActionSchemeObliqueShortcutSceneThreadAddRight();
    static QList<QKeySequence> getListShortcutActionSchemeObliqueShortcutSceneHalfrowRemoveDown();
    static QList<QKeySequence> getListShortcutActionSchemeObliqueShortcutSceneHalfrowRemoveTop();
    static QList<QKeySequence> getListShortcutActionSchemeObliqueShortcutSceneHalfrowAddDown();
    static QList<QKeySequence> getListShortcutActionSchemeObliqueShortcutSceneHalfrowAddTop();
    static QList<QKeySequence> getListShortcutActionSchemeObliqueShortcutSceneEditDirectionNewNode();
    static QList<QKeySequence> getListShortcutActionSchemeObliqueShortcutSceneColorMap();
    static QList<QKeySequence> getListShortcutActionSchemeObliqueShortcutViewZoomOut();
    static QList<QKeySequence> getListShortcutActionSchemeObliqueShortcutViewZoomIn();
    static QList<QKeySequence> getListShortcutActionSchemeObliqueShortcutViewToBottom();
    static QList<QKeySequence> getListShortcutActionSchemeObliqueShortcutViewToTop();
    static QList<QKeySequence> getListShortcutActionSchemeObliqueShortcutViewToLeft();
    static QList<QKeySequence> getListShortcutActionSchemeObliqueShortcutViewToRight();
    static QList<QKeySequence> getListShortcutActionSchemeObliqueShortcutViewRotateLeft();
    static QList<QKeySequence> getListShortcutActionSchemeObliqueShortcutViewRotateRight();

    static QList<QKeySequence> getListDefaultShortcutActionSchemeObliqueShortcutSceneCreate();
    static QList<QKeySequence> getListDefaultShortcutActionSchemeObliqueShortcutHistoryBack();
    static QList<QKeySequence> getListDefaultShortcutActionSchemeObliqueShortcutHistoryNext();
    static QList<QKeySequence> getListDefaultShortcutActionSchemeObliqueShortcutSceneThreadRemoveLeft();
    static QList<QKeySequence> getListDefaultShortcutActionSchemeObliqueShortcutSceneThreadRemoveRight();
    static QList<QKeySequence> getListDefaultShortcutActionSchemeObliqueShortcutSceneThreadAddLeft();
    static QList<QKeySequence> getListDefaultShortcutActionSchemeObliqueShortcutSceneThreadAddRight();
    static QList<QKeySequence> getListDefaultShortcutActionSchemeObliqueShortcutSceneHalfrowRemoveDown();
    static QList<QKeySequence> getListDefaultShortcutActionSchemeObliqueShortcutSceneHalfrowRemoveTop();
    static QList<QKeySequence> getListDefaultShortcutActionSchemeObliqueShortcutSceneHalfrowAddDown();
    static QList<QKeySequence> getListDefaultShortcutActionSchemeObliqueShortcutSceneHalfrowAddTop();
    static QList<QKeySequence> getListDefaultShortcutActionSchemeObliqueShortcutSceneEditDirectionNewNode();
    static QList<QKeySequence> getListDefaultShortcutActionSchemeObliqueShortcutSceneColorMap();
    static QList<QKeySequence> getListDefaultShortcutActionSchemeObliqueShortcutViewZoomOut();
    static QList<QKeySequence> getListDefaultShortcutActionSchemeObliqueShortcutViewZoomIn();
    static QList<QKeySequence> getListDefaultShortcutActionSchemeObliqueShortcutViewToBottom();
    static QList<QKeySequence> getListDefaultShortcutActionSchemeObliqueShortcutViewToTop();
    static QList<QKeySequence> getListDefaultShortcutActionSchemeObliqueShortcutViewToLeft();
    static QList<QKeySequence> getListDefaultShortcutActionSchemeObliqueShortcutViewToRight();
    static QList<QKeySequence> getListDefaultShortcutActionSchemeObliqueShortcutViewRotateLeft();
    static QList<QKeySequence> getListDefaultShortcutActionSchemeObliqueShortcutViewRotateRight();

    static void setDefaultShrotcuts();

private:
    static QString PATH_TO_SCHEME_OBLIQUE_COMMON_STANDART_DIRECTION_OBLIQUE_NODE;

    static QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_CREATE;
    static QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_HISTORY_BACK;
    static QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_HISTORY_NEXT;
    static QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_THREAD_REMOVE_LEFT;
    static QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_THREAD_REMOVE_RIGHT;
    static QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_THREAD_ADD_LEFT;
    static QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_THREAD_ADD_RIGHT;
    static QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_HALFROW_REMOVE_DOWN;
    static QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_HALFROW_REMOVE_TOP;
    static QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_HALFROW_ADD_DOWN;
    static QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_HALFROW_ADD_TOP;
    static QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_EDIT_DIRECTION_NEW_NODE;
    static QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_COLOR_MAP;
    static QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_ZOOM_OUT;
    static QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_ZOOM_IN;
    static QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_TO_BOTTOM;
    static QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_TO_TOP;
    static QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_TO_LEFT;
    static QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_TO_RIGHT;
    static QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_ROTATE_LEFT;
    static QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_ROTATE_RIGHT;

    static QString SCHEME_OBLIQUE_COMMON_STANDART_DIRECTION_OBLIQUE_NODE;

    static QStringList LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_CREATE;
    static QStringList LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_HISTORY_BACK;
    static QStringList LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_HISTORY_NEXT;
    static QStringList LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_THREAD_REMOVE_LEFT;
    static QStringList LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_THREAD_REMOVE_RIGHT;
    static QStringList LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_THREAD_ADD_LEFT;
    static QStringList LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_THREAD_ADD_RIGHT;
    static QStringList LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_HALFROW_REMOVE_DOWN;
    static QStringList LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_HALFROW_REMOVE_TOP;
    static QStringList LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_HALFROW_ADD_DOWN;
    static QStringList LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_HALFROW_ADD_TOP;
    static QStringList LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_EDIT_DIRECTION_NEW_NODE;
    static QStringList LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_COLOR_MAP;
    static QStringList LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_ZOOM_OUT;
    static QStringList LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_ZOOM_IN;
    static QStringList LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_TO_BOTTOM;
    static QStringList LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_TO_TOP;
    static QStringList LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_TO_LEFT;
    static QStringList LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_TO_RIGHT;
    static QStringList LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_ROTATE_LEFT;
    static QStringList LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_ROTATE_RIGHT;
};

#endif // SCHEMEOBLIQUEFILESETTING_H
