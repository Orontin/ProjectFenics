#ifndef SETTINGS_H
#define SETTINGS_H

#include "Abstract/abstractschemefilesetting.h"

class Settings : public AbstractSchemeFileSetting
{
public:
    static void setFileReadDirectory(const QString &valueParam);
    static QString getFileReadDirectory(const QString &defaultValueParam);

    static void setFileWriteDirectory(const QString &valueParam);
    static QString getFileWriteDirectory(const QString &defaultValueParam);
};

#endif // SETTINGS_H
