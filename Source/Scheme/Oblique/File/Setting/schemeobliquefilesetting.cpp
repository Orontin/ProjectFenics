#include "schemeobliquefilesetting.h"

void SchemeObliqueFileSetting::setStandartDirectionObliqueNode(const SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode &standartDirectionObliqueNode)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Common/standartDirectionObliqueNode", QString::number(static_cast<int>(standartDirectionObliqueNode)));
}

SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode SchemeObliqueFileSetting::getStandartDirectionObliqueNode()
{
    return static_cast<SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode>(AbstractSchemeFileSetting::getValue("Scheme/Oblique/Common/standartDirectionObliqueNode", "7").toInt());
}

void SchemeObliqueFileSetting::setShortcut_Action_ZoomOut(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/View/Zoom/Out", AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

void SchemeObliqueFileSetting::setShortcut_Action_ZoomIn(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/View/Zoom/In", AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

void SchemeObliqueFileSetting::setShortcut_Action_ToBottom(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/View/To/Bottom", AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

void SchemeObliqueFileSetting::setShortcut_Action_ToTop(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/View/To/Top", AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

void SchemeObliqueFileSetting::setShortcut_Action_ToLeft(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/View/To/Left", AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

void SchemeObliqueFileSetting::setShortcut_Action_ToRight(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/View/To/Right", AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

void SchemeObliqueFileSetting::setShortcut_Action_RotateLeft(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/View/Rotate/Left", AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

void SchemeObliqueFileSetting::setShortcut_Action_RotateRight(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/View/Rotate/Right", AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

QList<QKeySequence> SchemeObliqueFileSetting::getShortcut_Action_ZoomOut()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/View/Zoom/Out", QStringList{"Ctrl+-"}));
}

QList<QKeySequence> SchemeObliqueFileSetting::getShortcut_Action_ZoomIn()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/View/Zoom/In", QStringList{"Ctrl+="}));
}

QList<QKeySequence> SchemeObliqueFileSetting::getShortcut_Action_ToBottom()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/View/To/Bottom", QStringList{"Down"}));
}

QList<QKeySequence> SchemeObliqueFileSetting::getShortcut_Action_ToTop()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/View/To/Top", QStringList{"Up"}));
}

QList<QKeySequence> SchemeObliqueFileSetting::getShortcut_Action_ToLeft()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/View/To/Left", QStringList{"Left"}));
}

QList<QKeySequence> SchemeObliqueFileSetting::getShortcut_Action_ToRight()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/View/To/Right", QStringList{"Right"}));
}

QList<QKeySequence> SchemeObliqueFileSetting::getShortcut_Action_RotateLeft()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/View/Rotate/Left", QStringList{"Shift+Left"}));
}

QList<QKeySequence> SchemeObliqueFileSetting::getShortcut_Action_RotateRight()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/View/Rotate/Right", QStringList{"Shift+Right"}));
}

void SchemeObliqueFileSetting::setShortcut_Action_HistoryBack(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/History/Back", AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

void SchemeObliqueFileSetting::setShortcut_Action_HistoryNext(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/History/Next", AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

void SchemeObliqueFileSetting::setShortcut_Action_RemoveThreadLeft(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/Scene/Thread/RemoveLeft", AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

void SchemeObliqueFileSetting::setShortcut_Action_RemoveThreadRight(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/Scene/Thread/RemoveRight", AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

void SchemeObliqueFileSetting::setShortcut_Action_AddThreadLeft(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/Scene/Thread/AddLeft", AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

void SchemeObliqueFileSetting::setShortcut_Action_AddThreadRight(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/Scene/Thread/AddRight", AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

void SchemeObliqueFileSetting::setShortcut_Action_RemoveHalfrowDown(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/Scene/Halfrow/RemoveDown", AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

void SchemeObliqueFileSetting::setShortcut_Action_RemoveHalfrowTop(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/Scene/Halfrow/RemoveTop", AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

void SchemeObliqueFileSetting::setShortcut_Action_AddHalfrowDown(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/Scene/Halfrow/AddDown", AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

void SchemeObliqueFileSetting::setShortcut_Action_AddHalfrowTop(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/Scene/Halfrow/AddTop", AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

void SchemeObliqueFileSetting::setShortcut_Action_EditDirectionNewNode(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/Scene/Setting/EditDirectionNewNode", AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

QList<QKeySequence> SchemeObliqueFileSetting::getShortcut_Action_HistoryBack()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/History/Back", QStringList{"Ctrl+Z"}));
}

QList<QKeySequence> SchemeObliqueFileSetting::getShortcut_Action_HistoryNext()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/History/Next", QStringList{"Ctrl+Y", "Ctrl+Shift+Z"}));
}

QList<QKeySequence> SchemeObliqueFileSetting::getShortcut_Action_RemoveThreadLeft()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/Scene/Thread/RemoveLeft", QStringList{"Alt+Left"}));
}

QList<QKeySequence> SchemeObliqueFileSetting::getShortcut_Action_RemoveThreadRight()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/Scene/Thread/RemoveRight", QStringList{"Alt+Right"}));
}

QList<QKeySequence> SchemeObliqueFileSetting::getShortcut_Action_AddThreadLeft()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/Scene/Thread/AddLeft", QStringList{"Ctrl+Left"}));
}

QList<QKeySequence> SchemeObliqueFileSetting::getShortcut_Action_AddThreadRight()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/Scene/Thread/AddRight", QStringList{"Ctrl+Right"}));
}

QList<QKeySequence> SchemeObliqueFileSetting::getShortcut_Action_RemoveHalfrowDown()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/Scene/Halfrow/RemoveDown", QStringList{"Alt+Down"}));
}

QList<QKeySequence> SchemeObliqueFileSetting::getShortcut_Action_RemoveHalfrowTop()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/Scene/Halfrow/RemoveTop", QStringList{"Alt+Up"}));
}

QList<QKeySequence> SchemeObliqueFileSetting::getShortcut_Action_AddHalfrowDown()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/Scene/Halfrow/AddDown", QStringList{"Ctrl+Down"}));
}

QList<QKeySequence> SchemeObliqueFileSetting::getShortcut_Action_AddHalfrowTop()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/Scene/Halfrow/AddTop", QStringList{"Ctrl+Up"}));
}

QList<QKeySequence> SchemeObliqueFileSetting::getShortcut_Action_EditDirectionNewNode()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/Scene/Setting/EditDirectionNewNode", QStringList{"Ctrl+F1"}));
}

void SchemeObliqueFileSetting::setShortcut_Action_Create(const QList<QKeySequence> &valueParam)
{
    return AbstractSchemeFileSetting::setValue("Scheme/Oblique/Shortcut/Scene/Create", AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

QList<QKeySequence> SchemeObliqueFileSetting::getShortcut_Action_Create()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue("Scheme/Oblique/Shortcut/Scene/Create", QStringList{"F1"}));
}
