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

    static void setShortcut_Action_OpenFile(const QList<QKeySequence> &valueParam);
    static void setShortcut_Action_SaveScheme(const QList<QKeySequence> &valueParam);
    static void setShortcut_Action_DeleteOpenScheme(const QList<QKeySequence> &valueParam);
    static QList<QKeySequence> getShortcut_Action_OpenFile();
    static QList<QKeySequence> getShortcut_Action_SaveScheme();
    static QList<QKeySequence> getShortcut_Action_DeleteOpenScheme();
};

#endif // SETTINGS_H
