#ifndef SCHEMEOBLIQUEFILESETTING_H
#define SCHEMEOBLIQUEFILESETTING_H

#include "Abstract/abstractschemefilesetting.h"

#include "Scheme/Oblique/Widget/EditDirectionForNewNode/Chart/schemeobliquewidgeteditdirectionfornewnodechartscene.h"

class SchemeObliqueFileSetting: public AbstractSchemeFileSetting
{
public:
    static void setStandartDirectionObliqueNode(const SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode &standartDirectionObliqueNode);
    static SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode getStandartDirectionObliqueNode();

    static void setShortcut_Action_ZoomOut(const QList<QKeySequence> &valueParam);
    static void setShortcut_Action_ZoomIn(const QList<QKeySequence> &valueParam);
    static void setShortcut_Action_ToBottom(const QList<QKeySequence> &valueParam);
    static void setShortcut_Action_ToTop(const QList<QKeySequence> &valueParam);
    static void setShortcut_Action_ToLeft(const QList<QKeySequence> &valueParam);
    static void setShortcut_Action_ToRight(const QList<QKeySequence> &valueParam);
    static void setShortcut_Action_RotateLeft(const QList<QKeySequence> &valueParam);
    static void setShortcut_Action_RotateRight(const QList<QKeySequence> &valueParam);
    static QList<QKeySequence> getShortcut_Action_ZoomOut();
    static QList<QKeySequence> getShortcut_Action_ZoomIn();
    static QList<QKeySequence> getShortcut_Action_ToBottom();
    static QList<QKeySequence> getShortcut_Action_ToTop();
    static QList<QKeySequence> getShortcut_Action_ToLeft();
    static QList<QKeySequence> getShortcut_Action_ToRight();
    static QList<QKeySequence> getShortcut_Action_RotateLeft();
    static QList<QKeySequence> getShortcut_Action_RotateRight();

    static void setShortcut_Action_HistoryBack(const QList<QKeySequence> &valueParam);
    static void setShortcut_Action_HistoryNext(const QList<QKeySequence> &valueParam);
    static void setShortcut_Action_RemoveThreadLeft(const QList<QKeySequence> &valueParam);
    static void setShortcut_Action_RemoveThreadRight(const QList<QKeySequence> &valueParam);
    static void setShortcut_Action_AddThreadLeft(const QList<QKeySequence> &valueParam);
    static void setShortcut_Action_AddThreadRight(const QList<QKeySequence> &valueParam);
    static void setShortcut_Action_RemoveHalfrowDown(const QList<QKeySequence> &valueParam);
    static void setShortcut_Action_RemoveHalfrowTop(const QList<QKeySequence> &valueParam);
    static void setShortcut_Action_AddHalfrowDown(const QList<QKeySequence> &valueParam);
    static void setShortcut_Action_AddHalfrowTop(const QList<QKeySequence> &valueParam);
    static void setShortcut_Action_EditDirectionNewNode(const QList<QKeySequence> &valueParam);
    static QList<QKeySequence> getShortcut_Action_HistoryBack();
    static QList<QKeySequence> getShortcut_Action_HistoryNext();
    static QList<QKeySequence> getShortcut_Action_RemoveThreadLeft();
    static QList<QKeySequence> getShortcut_Action_RemoveThreadRight();
    static QList<QKeySequence> getShortcut_Action_AddThreadLeft();
    static QList<QKeySequence> getShortcut_Action_AddThreadRight();
    static QList<QKeySequence> getShortcut_Action_RemoveHalfrowDown();
    static QList<QKeySequence> getShortcut_Action_RemoveHalfrowTop();
    static QList<QKeySequence> getShortcut_Action_AddHalfrowDown();
    static QList<QKeySequence> getShortcut_Action_AddHalfrowTop();
    static QList<QKeySequence> getShortcut_Action_EditDirectionNewNode();

    static void setShortcut_Action_Create(const QList<QKeySequence> &valueParam);
    static QList<QKeySequence> getShortcut_Action_Create();

};

#endif // SCHEMEOBLIQUEFILESETTING_H
