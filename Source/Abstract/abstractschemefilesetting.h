#ifndef ABSTRACTSCHEMEFILESETTING_H
#define ABSTRACTSCHEMEFILESETTING_H

#include <QList>
#include <QString>
#include <QSettings>
#include <QStringList>
#include <QKeySequence>

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
    static void setValue(const QString &nameParam, const QStringList &valueParam){
        QSettings settings(QSettings::NativeFormat, QSettings::UserScope, "Orontin", "ProjectFenics");
        settings.setValue(nameParam, valueParam);
    };
    static QStringList getValue(const QString &nameParam, const QStringList &defaultValueParam) {
        QSettings settings(QSettings::NativeFormat, QSettings::UserScope, "Orontin", "ProjectFenics");
        return settings.value(nameParam, defaultValueParam).toStringList();
    };
protected:
    static QStringList convertListKeySequenceToStringList(const QList<QKeySequence> &valueParam) {
        QStringList stringList;
        for (const QKeySequence &keySequence : valueParam) {
            stringList.push_back(keySequence.toString(QKeySequence::SequenceFormat::PortableText));
        }
        return stringList;
    };
    static QList<QKeySequence> convertStringListToListKeySequence(const QStringList &valueParam) {
        QList<QKeySequence> listKeySequence;
        for (const QString &string : valueParam) {
            listKeySequence.push_back(QKeySequence::fromString(string));
        }
        return listKeySequence;
    };
};

#endif // ABSTRACTSCHEMEFILESETTING_H
