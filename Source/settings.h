#ifndef SETTINGS_H
#define SETTINGS_H

#include "Abstract/abstractschemefilesetting.h"

class Settings : public AbstractSchemeFileSetting
{
public:
    static void setFileReadDirectory(const QString &valueParam);
    static QString getFileReadDirectory();

    static void setFileWriteDirectory(const QString &valueParam);
    static QString getFileWriteDirectory();

    static void setShortcut_Action_OpenFile(const QString &valueParam);
    static void setShortcut_Action_SaveScheme(const QString &valueParam);
    static void setShortcut_Action_DeleteOpenScheme(const QString &valueParam);
    static QString getShortcut_Action_OpenFile();
    static QString getShortcut_Action_SaveScheme();
    static QString getShortcut_Action_DeleteOpenScheme();
};

#endif // SETTINGS_H
