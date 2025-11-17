#include "settings.h"

#include <QDir>

QString Settings::PATH_TO_FILE_DIRECTORY_READ{"File/Directory/Read"};
QString Settings::PATH_TO_FILE_DIRECTORY_WRITE{"File/Directory/Write"};

QString Settings::FILE_DIRECTORY_READ{QDir::homePath()};
QString Settings::FILE_DIRECTORY_WRITE{QDir::homePath()};

QString Settings::PATH_TO_LIST_SHORTCUT_ACTION_OPEN_FILE{"Shortcut/Coomon/OpenFile"};
QString Settings::PATH_TO_LIST_SHORTCUT_ACTION_SAVE_SCHEME{"Shortcut/Coomon/SaveScheme"};
QString Settings::PATH_TO_LIST_SHORTCUT_ACTION_DELETE_OPEN_SCHEME{"Shortcut/Coomon/DeleteOpenScheme"};
QString Settings::PATH_TO_LIST_SHORTCUT_ACTION_OPEN_SHORTCUT_WIDGET{"Shortcut/Coomon/OpenShortcutWidget"};

QStringList Settings::LIST_SHORTCUT_ACTION_OPEN_FILE{"Ctrl+O", "", "", ""};
QStringList Settings::LIST_SHORTCUT_ACTION_SAVE_SCHEME{"Ctrl+S", "", "", ""};
QStringList Settings::LIST_SHORTCUT_ACTION_DELETE_OPEN_SCHEME{"Ctrl+D", "", "", ""};
QStringList Settings::LIST_SHORTCUT_ACTION_OPEN_SHORTCUT_WIDGET{"Escape", "", "", ""};

void Settings::setFileDirectoryRead(const QString &valueParam)
{
    return AbstractSchemeFileSetting::setValue(Settings::PATH_TO_FILE_DIRECTORY_READ, valueParam);
}

QString Settings::getFileDirectoryRead()
{
    return AbstractSchemeFileSetting::getValue(Settings::PATH_TO_FILE_DIRECTORY_READ, Settings::FILE_DIRECTORY_READ);
}

void Settings::setFileDirectoryWrite(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue(Settings::PATH_TO_FILE_DIRECTORY_WRITE, valueParam);
}

QString Settings::getFileDirectoryWrite()
{
    return AbstractSchemeFileSetting::getValue(Settings::PATH_TO_FILE_DIRECTORY_WRITE, Settings::FILE_DIRECTORY_WRITE);
}

void Settings::setListShortcutActionOpenFile(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue(Settings::PATH_TO_LIST_SHORTCUT_ACTION_OPEN_FILE, AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

void Settings::setListShortcutActionSaveScheme(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue(Settings::PATH_TO_LIST_SHORTCUT_ACTION_SAVE_SCHEME, AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

void Settings::setListShortcutActionDeleteOpenScheme(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue(Settings::PATH_TO_LIST_SHORTCUT_ACTION_DELETE_OPEN_SCHEME, AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

void Settings::setListShortcutActionOpenShortcutWidget(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSetting::setValue(Settings::PATH_TO_LIST_SHORTCUT_ACTION_OPEN_SHORTCUT_WIDGET, AbstractSchemeFileSetting::convertListKeySequenceToStringList(valueParam));
}

QList<QKeySequence> Settings::getListShortcutActionOpenFile()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue(Settings::PATH_TO_LIST_SHORTCUT_ACTION_OPEN_FILE, Settings::LIST_SHORTCUT_ACTION_OPEN_FILE));
}

QList<QKeySequence> Settings::getListShortcutActionSaveScheme()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue(Settings::PATH_TO_LIST_SHORTCUT_ACTION_SAVE_SCHEME, Settings::LIST_SHORTCUT_ACTION_SAVE_SCHEME));
}

QList<QKeySequence> Settings::getListShortcutActionDeleteOpenScheme()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue(Settings::PATH_TO_LIST_SHORTCUT_ACTION_DELETE_OPEN_SCHEME, Settings::LIST_SHORTCUT_ACTION_DELETE_OPEN_SCHEME));
}

QList<QKeySequence> Settings::getListShortcutActionOpenShortcutWidget()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(AbstractSchemeFileSetting::getValue(Settings::PATH_TO_LIST_SHORTCUT_ACTION_OPEN_SHORTCUT_WIDGET, Settings::LIST_SHORTCUT_ACTION_OPEN_SHORTCUT_WIDGET));
}

QList<QKeySequence> Settings::getListDefaultShortcutActionOpenFile()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(Settings::LIST_SHORTCUT_ACTION_OPEN_FILE);
}

QList<QKeySequence> Settings::getListDefaultShortcutActionSaveScheme()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(Settings::LIST_SHORTCUT_ACTION_SAVE_SCHEME);
}

QList<QKeySequence> Settings::getListDefaultShortcutActionDeleteOpenScheme()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(Settings::LIST_SHORTCUT_ACTION_DELETE_OPEN_SCHEME);
}

QList<QKeySequence> Settings::getListDefaultShortcutActionOpenShortcutWidget()
{
    return AbstractSchemeFileSetting::convertStringListToListKeySequence(Settings::LIST_SHORTCUT_ACTION_OPEN_SHORTCUT_WIDGET);
}

void Settings::setDefaultShrotcuts()
{
    AbstractSchemeFileSetting::setValue(Settings::PATH_TO_LIST_SHORTCUT_ACTION_OPEN_FILE, Settings::LIST_SHORTCUT_ACTION_OPEN_FILE);
    AbstractSchemeFileSetting::setValue(Settings::PATH_TO_LIST_SHORTCUT_ACTION_SAVE_SCHEME, Settings::LIST_SHORTCUT_ACTION_SAVE_SCHEME);
    AbstractSchemeFileSetting::setValue(Settings::PATH_TO_LIST_SHORTCUT_ACTION_DELETE_OPEN_SCHEME, Settings::LIST_SHORTCUT_ACTION_DELETE_OPEN_SCHEME);
    AbstractSchemeFileSetting::setValue(Settings::PATH_TO_LIST_SHORTCUT_ACTION_OPEN_SHORTCUT_WIDGET, Settings::LIST_SHORTCUT_ACTION_OPEN_SHORTCUT_WIDGET);
}
