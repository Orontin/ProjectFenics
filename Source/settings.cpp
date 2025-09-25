#include "settings.h"

#include "QDir"

void Settings::setFileReadDirectory(const QString &valueParam)
{
    return AbstractSchemeFileSetting::setValue("FileReadDirectory", valueParam);
}

QString Settings::getFileReadDirectory(const QString &defaultValueParam)
{
    return AbstractSchemeFileSetting::getValue("FileReadDirectory", defaultValueParam);
}

void Settings::setFileWriteDirectory(const QString &valueParam)
{
    AbstractSchemeFileSetting::setValue("FileWriteDirectory", valueParam);
}

QString Settings::getFileWriteDirectory(const QString &defaultValueParam)
{
    return AbstractSchemeFileSetting::getValue("FileWriteDirectory", defaultValueParam);
}
