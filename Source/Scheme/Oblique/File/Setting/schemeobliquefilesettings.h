#ifndef SCHEMEOBLIQUEFILESETTINGS_H
#define SCHEMEOBLIQUEFILESETTINGS_H

#include "Abstract/abstractschemefilesettings.h"

#include "Scheme/Oblique/Widget/EditDirectionForNewNode/Chart/schemeobliquewidgeteditdirectionfornewnodechartscene.h"

class SchemeObliqueFileSettings: public AbstractSchemeFileSettings
{
public:
    static void setStandartDirectionObliqueNode(const SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode &standartDirectionObliqueNode);
    static SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode getStandartDirectionObliqueNode();

    static void setColorMapScroll(const int &scroll);
    static int getColorMapScroll();
    static void setColorMapVisible(const bool &visible);
    static bool getColorMapVisible();
    static void setColorMapWindowX(const int &x);
    static int getColorMapWindowX(const int &screenWidth);
    static void setColorMapWindowY(const int &y);
    static int getColorMapWindowY(const int &screenHeight);
    static void setColorMapWindowWidth(const int &width);
    static int getColorMapWindowWidth();
    static void setColorMapWindowHeight(const int &height);
    static int getColorMapWindowHeight();
    static void setColorMapWindowScreenWidth(const int &width);
    static int getColorMapWindowScreenWidth(const int &screenWidth);
    static void setColorMapWindowScreenHeight(const int &height);
    static int getColorMapWindowScreenHeight(const int &screenHeight);

    static void setCreateSchemeWindowX(const int &x);
    static int getCreateSchemeWindowX(const int &screenWidth);
    static void setCreateSchemeWindowY(const int &y);
    static int getCreateSchemeWindowY(const int &screenHeight);
    static void setCreateSchemeWindowWidth(const int &width);
    static int getCreateSchemeWindowWidth();
    static void setCreateSchemeWindowHeight(const int &height);
    static int getCreateSchemeWindowHeight();
    static void setCreateSchemeWindowScreenWidth(const int &width);
    static int getCreateSchemeWindowScreenWidth(const int &screenWidth);
    static void setCreateSchemeWindowScreenHeight(const int &height);
    static int getCreateSchemeWindowScreenHeight(const int &screenHeight);

    static void setEditDirectionForNewNodeWindowX(const int &x);
    static int getEditDirectionForNewNodeWindowX(const int &screenWidth);
    static void setEditDirectionForNewNodeWindowY(const int &y);
    static int getEditDirectionForNewNodeWindowY(const int &screenHeight);
    static void setEditDirectionForNewNodeWindowWidth(const int &width);
    static int getEditDirectionForNewNodeWindowWidth();
    static void setEditDirectionForNewNodeWindowHeight(const int &height);
    static int getEditDirectionForNewNodeWindowHeight();
    static void setEditDirectionForNewNodeWindowScreenWidth(const int &width);
    static int getEditDirectionForNewNodeWindowScreenWidth(const int &screenWidth);
    static void setEditDirectionForNewNodeWindowScreenHeight(const int &height);
    static int getEditDirectionForNewNodeWindowScreenHeight(const int &screenHeight);

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
    static const QString PATH_TO_SCHEME_OBLIQUE_WINDOW_STANDART_DIRECTION_OBLIQUE_NODE;

    static const QString PATH_TO_SCHEME_OBLIQUE_WINDOW_COLOR_MAP_SCROLL;
    static const QString PATH_TO_SCHEME_OBLIQUE_WINDOW_COLOR_MAP_VISIBLE;
    static const QString PATH_TO_SCHEME_OBLIQUE_WINDOW_COLOR_MAP_X;
    static const QString PATH_TO_SCHEME_OBLIQUE_WINDOW_COLOR_MAP_Y;
    static const QString PATH_TO_SCHEME_OBLIQUE_WINDOW_COLOR_MAP_WIDTH;
    static const QString PATH_TO_SCHEME_OBLIQUE_WINDOW_COLOR_MAP_HEIDGHT;
    static const QString PATH_TO_SCHEME_OBLIQUE_WINDOW_COLOR_MAP_SCREEN_WIDTH;
    static const QString PATH_TO_SCHEME_OBLIQUE_WINDOW_COLOR_MAP_SCREEN_HEIDGHT;

    static const QString PATH_TO_SCHEME_OBLIQUE_WINDOW_CREATE_SCHEME_X;
    static const QString PATH_TO_SCHEME_OBLIQUE_WINDOW_CREATE_SCHEME_Y;
    static const QString PATH_TO_SCHEME_OBLIQUE_WINDOW_CREATE_SCHEME_WIDTH;
    static const QString PATH_TO_SCHEME_OBLIQUE_WINDOW_CREATE_SCHEME_HEIDGHT;
    static const QString PATH_TO_SCHEME_OBLIQUE_WINDOW_CREATE_SCHEME_SCREEN_WIDTH;
    static const QString PATH_TO_SCHEME_OBLIQUE_WINDOW_CREATE_SCHEME_SCREEN_HEIDGHT;

    static const QString PATH_TO_SCHEME_OBLIQUE_WINDOW_EDIT_DIRECTION_FOR_NEW_NODE_X;
    static const QString PATH_TO_SCHEME_OBLIQUE_WINDOW_EDIT_DIRECTION_FOR_NEW_NODE_Y;
    static const QString PATH_TO_SCHEME_OBLIQUE_WINDOW_EDIT_DIRECTION_FOR_NEW_NODE_WIDTH;
    static const QString PATH_TO_SCHEME_OBLIQUE_WINDOW_EDIT_DIRECTION_FOR_NEW_NODE_HEIDGHT;
    static const QString PATH_TO_SCHEME_OBLIQUE_WINDOW_EDIT_DIRECTION_FOR_NEW_NODE_SCREEN_WIDTH;
    static const QString PATH_TO_SCHEME_OBLIQUE_WINDOW_EDIT_DIRECTION_FOR_NEW_NODE_SCREEN_HEIDGHT;

    static const QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_CREATE;
    static const QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_HISTORY_BACK;
    static const QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_HISTORY_NEXT;
    static const QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_THREAD_REMOVE_LEFT;
    static const QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_THREAD_REMOVE_RIGHT;
    static const QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_THREAD_ADD_LEFT;
    static const QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_THREAD_ADD_RIGHT;
    static const QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_HALFROW_REMOVE_DOWN;
    static const QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_HALFROW_REMOVE_TOP;
    static const QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_HALFROW_ADD_DOWN;
    static const QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_HALFROW_ADD_TOP;
    static const QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_EDIT_DIRECTION_NEW_NODE;
    static const QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_COLOR_MAP;
    static const QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_ZOOM_OUT;
    static const QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_ZOOM_IN;
    static const QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_TO_BOTTOM;
    static const QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_TO_TOP;
    static const QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_TO_LEFT;
    static const QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_TO_RIGHT;
    static const QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_ROTATE_LEFT;
    static const QString PATH_TO_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_ROTATE_RIGHT;

    static const QString DEFAULT_VALUE_SCHEME_OBLIQUE_WINDOW_STANDART_DIRECTION_OBLIQUE_NODE;

    static const QString DEFAULT_VALUE_SCHEME_OBLIQUE_WINDOW_COLOR_MAP_SCROLL;
    static const QString DEFAULT_VALUE_SCHEME_OBLIQUE_WINDOW_COLOR_MAP_VISIBLE;
    static const QString DEFAULT_VALUE_SCHEME_OBLIQUE_WINDOW_COLOR_MAP_X;
    static const QString DEFAULT_VALUE_SCHEME_OBLIQUE_WINDOW_COLOR_MAP_Y;
    static const QString DEFAULT_VALUE_SCHEME_OBLIQUE_WINDOW_COLOR_MAP_WIDTH;
    static const QString DEFAULT_VALUE_SCHEME_OBLIQUE_WINDOW_COLOR_MAP_HEIDGHT;
    static const QString DEFAULT_VALUE_SCHEME_OBLIQUE_WINDOW_COLOR_MAP_SCREEN_WIDTH;
    static const QString DEFAULT_VALUE_SCHEME_OBLIQUE_WINDOW_COLOR_MAP_SCREEN_HEIDGHT;

    static const QString DEFAULT_VALUE_SCHEME_OBLIQUE_WINDOW_CREATE_SCHEME_X;
    static const QString DEFAULT_VALUE_SCHEME_OBLIQUE_WINDOW_CREATE_SCHEME_Y;
    static const QString DEFAULT_VALUE_SCHEME_OBLIQUE_WINDOW_CREATE_SCHEME_WIDTH;
    static const QString DEFAULT_VALUE_SCHEME_OBLIQUE_WINDOW_CREATE_SCHEME_HEIDGHT;
    static const QString DEFAULT_VALUE_SCHEME_OBLIQUE_WINDOW_CREATE_SCHEME_SCREEN_WIDTH;
    static const QString DEFAULT_VALUE_SCHEME_OBLIQUE_WINDOW_CREATE_SCHEME_SCREEN_HEIDGHT;

    static const QString DEFAULT_VALUE_SCHEME_OBLIQUE_WINDOW_EDIT_DIRECTION_FOR_NEW_NODE_X;
    static const QString DEFAULT_VALUE_SCHEME_OBLIQUE_WINDOW_EDIT_DIRECTION_FOR_NEW_NODE_Y;
    static const QString DEFAULT_VALUE_SCHEME_OBLIQUE_WINDOW_EDIT_DIRECTION_FOR_NEW_NODE_WIDTH;
    static const QString DEFAULT_VALUE_SCHEME_OBLIQUE_WINDOW_EDIT_DIRECTION_FOR_NEW_NODE_HEIDGHT;
    static const QString DEFAULT_VALUE_SCHEME_OBLIQUE_WINDOW_EDIT_DIRECTION_FOR_NEW_NODE_SCREEN_WIDTH;
    static const QString DEFAULT_VALUE_SCHEME_OBLIQUE_WINDOW_EDIT_DIRECTION_FOR_NEW_NODE_SCREEN_HEIDGHT;

    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_CREATE;
    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_HISTORY_BACK;
    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_HISTORY_NEXT;
    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_THREAD_REMOVE_LEFT;
    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_THREAD_REMOVE_RIGHT;
    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_THREAD_ADD_LEFT;
    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_THREAD_ADD_RIGHT;
    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_HALFROW_REMOVE_DOWN;
    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_HALFROW_REMOVE_TOP;
    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_HALFROW_ADD_DOWN;
    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_HALFROW_ADD_TOP;
    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_EDIT_DIRECTION_NEW_NODE;
    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_SCENE_COLOR_MAP;
    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_ZOOM_OUT;
    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_ZOOM_IN;
    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_TO_BOTTOM;
    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_TO_TOP;
    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_TO_LEFT;
    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_TO_RIGHT;
    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_ROTATE_LEFT;
    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SCHEME_OBLIQUE_SHORTCUT_VIEW_ROTATE_RIGHT;
};

#endif // SCHEMEOBLIQUEFILESETTINGS_H
