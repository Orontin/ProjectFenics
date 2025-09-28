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

void Settings::setShortcut_Action_OpenFile(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue("Shortcut/Coomon/OpenFile", valueParam);
}

void Settings::setShortcut_Action_SaveScheme(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue("Shortcut/Coomon/SaveScheme", valueParam);
}

void Settings::setShortcut_Action_DeleteOpenScheme(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue("Shortcut/Coomon/DeleteOpenScheme", valueParam);
}

QString Settings::getShortcut_Action_OpenFile()
{
    return AbstractSchemeFileSetting::getValue("Shortcut/Coomon/OpenFile", "Ctrl+O");
}

QString Settings::getShortcut_Action_SaveScheme()
{
    return AbstractSchemeFileSetting::getValue("Shortcut/Coomon/SaveScheme", "Ctrl+S");
}

QString Settings::getShortcut_Action_DeleteOpenScheme()
{
    return AbstractSchemeFileSetting::getValue("Shortcut/Coomon/DeleteOpenScheme", "Ctrl+D");
}
