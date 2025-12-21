#ifndef SETTINGS_H
#define SETTINGS_H

#include "Abstract/abstractschemefilesettings.h"

class Settings : public AbstractSchemeFileSettings
{
public:
    static void setFileDirectoryRead(const QString &valueParam);
    static QString getFileDirectoryRead();

    static void setFileDirectoryWrite(const QString &valueParam);
    static QString getFileDirectoryWrite();

    static void setMainWindowX(const int &x);
    static int getMainWindowX();
    static void setMainWindowY(const int &y);
    static int getMainWindowY();
    static void setMainWindowWidth(const int &width);
    static int getMainWindowWidth();
    static void setMainWindowHeight(const int &height);
    static int getMainWindowHeight();
    static void setMainWindowScreenWidth(const int &width);
    static int getMainWindowScreenWidth();
    static void setMainWindowScreenHeight(const int &height);
    static int getMainWindowScreenHeight();

    static void setShortcutWindowX(const int &x);
    static int getShortcutWindowX();
    static void setShortcutWindowY(const int &y);
    static int getShortcutWindowY();
    static void setShortcutWindowWidth(const int &width);
    static int getShortcutWindowWidth();
    static void setShortcutWindowHeight(const int &height);
    static int getShortcutWindowHeight();
    static void setShortcutWindowScreenWidth(const int &width);
    static int getShortcutWindowScreenWidth();
    static void setShortcutWindowScreenHeight(const int &height);
    static int getShortcutWindowScreenHeight();

    static void setListShortcutActionOpenFile(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionSaveScheme(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionDeleteOpenScheme(const QList<QKeySequence> &valueParam);
    static void setListShortcutActionOpenShortcutWidget(const QList<QKeySequence> &valueParam);

    static QList<QKeySequence> getListShortcutActionOpenFile();
    static QList<QKeySequence> getListShortcutActionSaveScheme();
    static QList<QKeySequence> getListShortcutActionDeleteOpenScheme();
    static QList<QKeySequence> getListShortcutActionOpenShortcutWidget();

    static QList<QKeySequence> getListDefaultShortcutActionOpenFile();
    static QList<QKeySequence> getListDefaultShortcutActionSaveScheme();
    static QList<QKeySequence> getListDefaultShortcutActionDeleteOpenScheme();
    static QList<QKeySequence> getListDefaultShortcutActionOpenShortcutWidget();

    static void setDefaultShrotcuts();

private:
    static const QString PATH_TO_FILE_DIRECTORY_READ;
    static const QString PATH_TO_FILE_DIRECTORY_WRITE;

    static const QString PATH_TO_WINDOW_MAIN_X;
    static const QString PATH_TO_WINDOW_MAIN_Y;
    static const QString PATH_TO_WINDOW_MAIN_WIDTH;
    static const QString PATH_TO_WINDOW_MAIN_HEIDGHT;
    static const QString PATH_TO_WINDOW_MAIN_SCREEN_WIDTH;
    static const QString PATH_TO_WINDOW_MAIN_SCREEN_HEIDGHT;

    static const QString PATH_TO_WINDOW_SHORTCUT_X;
    static const QString PATH_TO_WINDOW_SHORTCUT_Y;
    static const QString PATH_TO_WINDOW_SHORTCUT_WIDTH;
    static const QString PATH_TO_WINDOW_SHORTCUT_HEIDGHT;
    static const QString PATH_TO_WINDOW_SHORTCUT_SCREEN_WIDTH;
    static const QString PATH_TO_WINDOW_SHORTCUT_SCREEN_HEIDGHT;

    static const QString PATH_TO_LIST_SHORTCUT_ACTION_OPEN_FILE;
    static const QString PATH_TO_LIST_SHORTCUT_ACTION_SAVE_SCHEME;
    static const QString PATH_TO_LIST_SHORTCUT_ACTION_DELETE_OPEN_SCHEME;
    static const QString PATH_TO_LIST_SHORTCUT_ACTION_OPEN_SHORTCUT_WIDGET;

    static const QString DEFAULT_VALUE_FILE_DIRECTORY_READ;
    static const QString DEFAULT_VALUE_FILE_DIRECTORY_WRITE;

    static const QString DEFAULT_VALUE_WINDOW_MAIN_X;
    static const QString DEFAULT_VALUE_WINDOW_MAIN_Y;
    static const QString DEFAULT_VALUE_WINDOW_MAIN_WIDTH;
    static const QString DEFAULT_VALUE_WINDOW_MAIN_HEIDGHT;
    static const QString DEFAULT_VALUE_WINDOW_MAIN_SCREEN_WIDTH;
    static const QString DEFAULT_VALUE_WINDOW_MAIN_SCREEN_HEIDGHT;

    static const QString DEFAULT_VALUE_WINDOW_SHORTCUT_X;
    static const QString DEFAULT_VALUE_WINDOW_SHORTCUT_Y;
    static const QString DEFAULT_VALUE_WINDOW_SHORTCUT_WIDTH;
    static const QString DEFAULT_VALUE_WINDOW_SHORTCUT_HEIDGHT;
    static const QString DEFAULT_VALUE_WINDOW_SHORTCUT_SCREEN_WIDTH;
    static const QString DEFAULT_VALUE_WINDOW_SHORTCUT_SCREEN_HEIDGHT;

    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_OPEN_FILE;
    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SAVE_SCHEME;
    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_DELETE_OPEN_SCHEME;
    static const QStringList DEFAULT_VALUE_LIST_SHORTCUT_ACTION_OPEN_SHORTCUT_WIDGET;
};

#endif // SETTINGS_H
