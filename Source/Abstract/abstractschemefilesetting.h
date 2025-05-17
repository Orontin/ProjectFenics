#ifndef ABSTRACTSCHEMEFILESETTING_H
#define ABSTRACTSCHEMEFILESETTING_H

#include <QString>
#include <QSettings>

class AbstractSchemeFileSetting
{
public:
    static void setValue(const QString &nameParam, const QString &valueParam){
        QSettings settings(QSettings::NativeFormat, QSettings::UserScope, "Orontin", "ProjectFenics");
        settings.setValue(nameParam, valueParam);
    };
    static QString getValue(const QString &nameParam, const QString &defaultValueParam) {
        QSettings settings(QSettings::NativeFormat, QSettings::UserScope, "Orontin", "ProjectFenics");
        return settings.value(nameParam, defaultValueParam).toString();
    };
};

#endif // ABSTRACTSCHEMEFILESETTING_H
