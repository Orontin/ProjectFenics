#include "settings.h"

#include <QDir>

void Settings::setFileReadDirectory(const QString &valueParam)
{
    return AbstractSchemeFileSetting::setValue("File/Directory/Read", valueParam);
}

QString Settings::getFileReadDirectory()
{
    return AbstractSchemeFileSetting::getValue("File/Directory/Read", QDir::homePath());
}

void Settings::setFileWriteDirectory(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue("File/Directory/Write", valueParam);
}

QString Settings::getFileWriteDirectory()
{
    return AbstractSchemeFileSetting::getValue("File/Directory/Write", QDir::homePath());
}

void Settings::setShortcut_Action_OpenFile(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue("Shortcut/Coomon/OpenFile", AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

void Settings::setShortcut_Action_SaveScheme(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue("Shortcut/Coomon/SaveScheme", AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

void Settings::setShortcut_Action_DeleteOpenScheme(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue("Shortcut/Coomon/DeleteOpenScheme", AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

void Settings::setShortcut_Action_OpenShortcutWidget(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue("Shortcut/Coomon/OpenShortcutWidget", AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

QList<QKeySequence> Settings::getShortcut_Action_OpenFile()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue("Shortcut/Coomon/OpenFile", QStringList{"Ctrl+O"}));
}

QList<QKeySequence> Settings::getShortcut_Action_SaveScheme()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue("Shortcut/Coomon/SaveScheme", QStringList{"Ctrl+S"}));
}

QList<QKeySequence> Settings::getShortcut_Action_DeleteOpenScheme()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue("Shortcut/Coomon/DeleteOpenScheme", QStringList{"Ctrl+D"}));
}

QList<QKeySequence> Settings::getShortcut_Action_OpenShortcutWidget()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue("Shortcut/Coomon/OpenShortcutWidget", QStringList{"Escape"}));
}
