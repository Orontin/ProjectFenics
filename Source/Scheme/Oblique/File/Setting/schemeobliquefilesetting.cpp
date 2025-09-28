#include "schemeobliquefilesetting.h"

void SchemeObliqueFileSetting::setStandartDirectionObliqueNode(const SchemeObliqueObjectNode::DirectionsNode &standartDirectionObliqueNode)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Common/standartDirectionObliqueNode", QString::number(static_cast<int>(standartDirectionObliqueNode)));
}

SchemeObliqueObjectNode::DirectionsNode SchemeObliqueFileSetting::getStandartDirectionObliqueNode()
{
    return static_cast<SchemeObliqueObjectNode::DirectionsNode>(AbstractSchemeFileSetting::getValue("Scheme/Oblique/Common/standartDirectionObliqueNode", "7").toInt());
}

void SchemeObliqueFileSetting::setShortcut_Action_ZoomOut(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/View/Zoom/Out", valueParam);
}

void SchemeObliqueFileSetting::setShortcut_Action_ZoomIn(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/View/Zoom/In", valueParam);
}

void SchemeObliqueFileSetting::setShortcut_Action_ToBottom(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/View/To/Bottom", valueParam);
}

void SchemeObliqueFileSetting::setShortcut_Action_ToTop(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/View/To/Top", valueParam);
}

void SchemeObliqueFileSetting::setShortcut_Action_ToLeft(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/View/To/Left", valueParam);
}

void SchemeObliqueFileSetting::setShortcut_Action_ToRight(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/View/To/Right", valueParam);
}

void SchemeObliqueFileSetting::setShortcut_Action_RotateLeft(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/View/Rotate/Left", valueParam);
}

void SchemeObliqueFileSetting::setShortcut_Action_RotateRight(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/View/Rotate/Right", valueParam);
}

QString SchemeObliqueFileSetting::getShortcut_Action_ZoomOut()
{
    return AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/View/Zoom/Out", "Ctrl+-");
}

QString SchemeObliqueFileSetting::getShortcut_Action_ZoomIn()
{
    return AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/View/Zoom/In", "Ctrl+=");
}

QString SchemeObliqueFileSetting::getShortcut_Action_ToBottom()
{
    return AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/View/To/Bottom", "Down");
}

QString SchemeObliqueFileSetting::getShortcut_Action_ToTop()
{
    return AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/View/To/Top", "Up");
}

QString SchemeObliqueFileSetting::getShortcut_Action_ToLeft()
{
    return AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/View/To/Left", "Left");
}

QString SchemeObliqueFileSetting::getShortcut_Action_ToRight()
{
    return AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/View/To/Right", "Right");
}

QString SchemeObliqueFileSetting::getShortcut_Action_RotateLeft()
{
    return AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/View/Rotate/Left", "Shift+Left");
}

QString SchemeObliqueFileSetting::getShortcut_Action_RotateRight()
{
    return AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/View/Rotate/Right", "Shift+Right");
}

void SchemeObliqueFileSetting::setShortcut_Action_HistoryBack(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/History/Back", valueParam);
}

void SchemeObliqueFileSetting::setShortcut_Action_HistoryNext(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/History/Next", valueParam);
}

void SchemeObliqueFileSetting::setShortcut_Action_RemoveThreadLeft(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/Scene/Thread/RemoveLeft", valueParam);
}

void SchemeObliqueFileSetting::setShortcut_Action_RemoveThreadRight(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/Scene/Thread/RemoveRight", valueParam);
}

void SchemeObliqueFileSetting::setShortcut_Action_AddThreadLeft(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/Scene/Thread/AddLeft", valueParam);
}

void SchemeObliqueFileSetting::setShortcut_Action_AddThreadRight(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/Scene/Thread/AddRight", valueParam);
}

void SchemeObliqueFileSetting::setShortcut_Action_RemoveHalfrowDown(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/Scene/Halfrow/RemoveDown", valueParam);
}

void SchemeObliqueFileSetting::setShortcut_Action_RemoveHalfrowTop(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/Scene/Halfrow/RemoveTop", valueParam);
}

void SchemeObliqueFileSetting::setShortcut_Action_AddHalfrowDown(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/Scene/Halfrow/AddDown", valueParam);
}

void SchemeObliqueFileSetting::setShortcut_Action_AddHalfrowTop(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/Scene/Halfrow/AddTop", valueParam);
}

void SchemeObliqueFileSetting::setShortcut_Action_EditDirectionNewNode(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/Scene/Setting/EditDirectionNewNode", valueParam);
}

QString SchemeObliqueFileSetting::getShortcut_Action_HistoryBack()
{
    return AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/History/Back", "Ctrl+Z");
}

QString SchemeObliqueFileSetting::getShortcut_Action_HistoryNext()
{
    return AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/History/Next", "Ctrl+Y");
}

QString SchemeObliqueFileSetting::getShortcut_Action_RemoveThreadLeft()
{
    return AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/Scene/Thread/RemoveLeft", "Alt+Left");
}

QString SchemeObliqueFileSetting::getShortcut_Action_RemoveThreadRight()
{
    return AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/Scene/Thread/RemoveRight", "Alt+Right");
}

QString SchemeObliqueFileSetting::getShortcut_Action_AddThreadLeft()
{
    return AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/Scene/Thread/AddLeft", "Ctrl+Left");
}

QString SchemeObliqueFileSetting::getShortcut_Action_AddThreadRight()
{
    return AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/Scene/Thread/AddRight", "Ctrl+Right");
}

QString SchemeObliqueFileSetting::getShortcut_Action_RemoveHalfrowDown()
{
    return AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/Scene/Halfrow/RemoveDown", "Alt+Down");
}

QString SchemeObliqueFileSetting::getShortcut_Action_RemoveHalfrowTop()
{
    return AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/Scene/Halfrow/RemoveTop", "Alt+Up");
}

QString SchemeObliqueFileSetting::getShortcut_Action_AddHalfrowDown()
{
    return AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/Scene/Halfrow/AddDown", "Ctrl+Down");
}

QString SchemeObliqueFileSetting::getShortcut_Action_AddHalfrowTop()
{
    return AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/Scene/Halfrow/AddTop", "Ctrl+Up");
}

QString SchemeObliqueFileSetting::getShortcut_Action_EditDirectionNewNode()
{
    return AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/Scene/Setting/EditDirectionNewNode", "Ctrl+F1");
}

void SchemeObliqueFileSetting::setShortcut_Action_Create(const QString &valueParam)
{
    return AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/Scene/Create", valueParam);
}

QString SchemeObliqueFileSetting::getShortcut_Action_Create()
{
    return AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/Scene/Create", "F1");
}
