#ifndef SCHEMEOBLIQUEFILESETTING_H
#define SCHEMEOBLIQUEFILESETTING_H

#include "Abstract/abstractschemefilesetting.h"

#include "Scheme/Oblique/Object/schemeobliqueobjectnode.h"

class SchemeObliqueFileSetting: public AbstractSchemeFileSetting
{
public:
    static void setStandartDirectionObliqueNode(const SchemeObliqueObjectNode::DirectionsNode &standartDirectionObliqueNode);
    static SchemeObliqueObjectNode::DirectionsNode getStandartDirectionObliqueNode();

    static void setShortcut_Action_ZoomOut(const QString &valueParam);
    static void setShortcut_Action_ZoomIn(const QString &valueParam);
    static void setShortcut_Action_ToBottom(const QString &valueParam);
    static void setShortcut_Action_ToTop(const QString &valueParam);
    static void setShortcut_Action_ToLeft(const QString &valueParam);
    static void setShortcut_Action_ToRight(const QString &valueParam);
    static void setShortcut_Action_RotateLeft(const QString &valueParam);
    static void setShortcut_Action_RotateRight(const QString &valueParam);
    static QString getShortcut_Action_ZoomOut();
    static QString getShortcut_Action_ZoomIn();
    static QString getShortcut_Action_ToBottom();
    static QString getShortcut_Action_ToTop();
    static QString getShortcut_Action_ToLeft();
    static QString getShortcut_Action_ToRight();
    static QString getShortcut_Action_RotateLeft();
    static QString getShortcut_Action_RotateRight();

    static void setShortcut_Action_HistoryBack(const QString &valueParam);
    static void setShortcut_Action_HistoryNext(const QString &valueParam);
    static void setShortcut_Action_RemoveThreadLeft(const QString &valueParam);
    static void setShortcut_Action_RemoveThreadRight(const QString &valueParam);
    static void setShortcut_Action_AddThreadLeft(const QString &valueParam);
    static void setShortcut_Action_AddThreadRight(const QString &valueParam);
    static void setShortcut_Action_RemoveHalfrowDown(const QString &valueParam);
    static void setShortcut_Action_RemoveHalfrowTop(const QString &valueParam);
    static void setShortcut_Action_AddHalfrowDown(const QString &valueParam);
    static void setShortcut_Action_AddHalfrowTop(const QString &valueParam);
    static void setShortcut_Action_EditDirectionNewNode(const QString &valueParam);
    static QString getShortcut_Action_HistoryBack();
    static QString getShortcut_Action_HistoryNext();
    static QString getShortcut_Action_RemoveThreadLeft();
    static QString getShortcut_Action_RemoveThreadRight();
    static QString getShortcut_Action_AddThreadLeft();
    static QString getShortcut_Action_AddThreadRight();
    static QString getShortcut_Action_RemoveHalfrowDown();
    static QString getShortcut_Action_RemoveHalfrowTop();
    static QString getShortcut_Action_AddHalfrowDown();
    static QString getShortcut_Action_AddHalfrowTop();
    static QString getShortcut_Action_EditDirectionNewNode();

    static void setShortcut_Action_Create(const QString &valueParam);
    static QString getShortcut_Action_Create();

};

#endif // SCHEMEOBLIQUEFILESETTING_H
