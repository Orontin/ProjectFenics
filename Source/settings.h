#ifndef SETTINGS_H
#define SETTINGS_H

#include "Abstract/abstractschemefilesetting.h"

class Settings : public AbstractSchemeFileSetting
{
public:
    static void setFileDirectoryRead(const QString &valueParam);
    static QString getFileDirectoryRead();

    static void setFileDirectoryWrite(const QString &valueParam);
    static QString getFileDirectoryWrite();

    static void setListShortcutActionOpenFile(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionSaveScheme(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionDeleteOpenScheme(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionOpenShortcutWidget(const QList<QKeySequence> &valueParam);

    static QList<QKeySequence> getListShortcutActionOpenFile();
    static QList<QKeySequence> getListShortcutActionSaveScheme();
    static QList<QKeySequence> getListShortcutActionDeleteOpenScheme();
    static QList<QKeySequence> getListShortcutActionOpenShortcutWidget();

    static void setDefaultShrotcuts();

private:
    static QString PATH_TO_FILE_DIRECTORY_READ;
    static QString PATH_TO_FILE_DIRECTORY_WRITE;

    static QString FILE_DIRECTORY_READ;
    static QString FILE_DIRECTORY_WRITE;

    static QString PATH_TO_LIST_SHORTCUT_ACTION_OPEN_FILE;
    static QString PATH_TO_LIST_SHORTCUT_ACTION_SAVE_SCHEME;
    static QString PATH_TO_LIST_SHORTCUT_ACTION_DELETE_OPEN_SCHEME;
    static QString PATH_TO_LIST_SHORTCUT_ACTION_OPEN_SHORTCUT_WIDGET;

    static QStringList LIST_SHORTCUT_ACTION_OPEN_FILE;
    static QStringList LIST_SHORTCUT_ACTION_SAVE_SCHEME;
    static QStringList LIST_SHORTCUT_ACTION_DELETE_OPEN_SCHEME;
    static QStringList LIST_SHORTCUT_ACTION_OPEN_SHORTCUT_WIDGET;
};

#endif // SETTINGS_H
