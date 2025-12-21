#include "settings.h"

#include <QDir>

const QString Settings::PATH_TO_FILE_DIRECTORY_READ{"Common/File/Directory/read"};
const QString Settings::PATH_TO_FILE_DIRECTORY_WRITE{"Common/File/Directory/write"};
const QString Settings::PATH_TO_WINDOW_MAIN_X{"Common/Window/Main/x"};
const QString Settings::PATH_TO_WINDOW_MAIN_Y{"Common/Window/Main/y"};
const QString Settings::PATH_TO_WINDOW_MAIN_WIDTH{"Common/Window/Main/width"};
const QString Settings::PATH_TO_WINDOW_MAIN_HEIDGHT{"Common/Window/Main/height"};
const QString Settings::PATH_TO_WINDOW_MAIN_SCREEN_WIDTH{"Common/Window/Main/Screen/width"};
const QString Settings::PATH_TO_WINDOW_MAIN_SCREEN_HEIDGHT{"Common/Window/Main/Screen/height"};
const QString Settings::PATH_TO_WINDOW_SHORTCUT_X{"Common/Window/Shortcut/x"};
const QString Settings::PATH_TO_WINDOW_SHORTCUT_Y{"Common/Window/Shortcut/y"};
const QString Settings::PATH_TO_WINDOW_SHORTCUT_WIDTH{"Common/Window/Shortcut/width"};
const QString Settings::PATH_TO_WINDOW_SHORTCUT_HEIDGHT{"Common/Window/Shortcut/height"};
const QString Settings::PATH_TO_WINDOW_SHORTCUT_SCREEN_WIDTH{"Common/Window/Shortcut/Screen/width"};
const QString Settings::PATH_TO_WINDOW_SHORTCUT_SCREEN_HEIDGHT{"Common/Window/Shortcut/Screen/height"};
const QString Settings::PATH_TO_LIST_SHORTCUT_ACTION_OPEN_FILE{"Common/Shortcut/Action/openFile"};
const QString Settings::PATH_TO_LIST_SHORTCUT_ACTION_SAVE_SCHEME{"Common/Shortcut/Action/saveScheme"};
const QString Settings::PATH_TO_LIST_SHORTCUT_ACTION_DELETE_OPEN_SCHEME{"Common/Shortcut/Action/deleteOpenScheme"};
const QString Settings::PATH_TO_LIST_SHORTCUT_ACTION_OPEN_SHORTCUT_WIDGET{"Common/Shortcut/Action/openShortcutWidget"};

const QString Settings::DEFAULT_VALUE_FILE_DIRECTORY_READ{QDir::homePath()};
const QString Settings::DEFAULT_VALUE_FILE_DIRECTORY_WRITE{QDir::homePath()};
const QString Settings::DEFAULT_VALUE_WINDOW_MAIN_X{"0"};
const QString Settings::DEFAULT_VALUE_WINDOW_MAIN_Y{"0"};
const QString Settings::DEFAULT_VALUE_WINDOW_MAIN_WIDTH{"800"};
const QString Settings::DEFAULT_VALUE_WINDOW_MAIN_HEIDGHT{"600"};
const QString Settings::DEFAULT_VALUE_WINDOW_MAIN_SCREEN_WIDTH{"800"};
const QString Settings::DEFAULT_VALUE_WINDOW_MAIN_SCREEN_HEIDGHT{"600"};
const QString Settings::DEFAULT_VALUE_WINDOW_SHORTCUT_X{"0"};
const QString Settings::DEFAULT_VALUE_WINDOW_SHORTCUT_Y{"0"};
const QString Settings::DEFAULT_VALUE_WINDOW_SHORTCUT_WIDTH{"800"};
const QString Settings::DEFAULT_VALUE_WINDOW_SHORTCUT_HEIDGHT{"600"};
const QString Settings::DEFAULT_VALUE_WINDOW_SHORTCUT_SCREEN_WIDTH{"800"};
const QString Settings::DEFAULT_VALUE_WINDOW_SHORTCUT_SCREEN_HEIDGHT{"600"};
const QStringList Settings::DEFAULT_VALUE_LIST_SHORTCUT_ACTION_OPEN_FILE{"Ctrl+O", "", "", ""};
const QStringList Settings::DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SAVE_SCHEME{"Ctrl+S", "", "", ""};
const QStringList Settings::DEFAULT_VALUE_LIST_SHORTCUT_ACTION_DELETE_OPEN_SCHEME{"Ctrl+D", "", "", ""};
const QStringList Settings::DEFAULT_VALUE_LIST_SHORTCUT_ACTION_OPEN_SHORTCUT_WIDGET{"Escape", "", "", ""};

void Settings::setFileDirectoryRead(const QString &valueParam)
{
    return AbstractSchemeFileSettings::setValue(Settings::PATH_TO_FILE_DIRECTORY_READ, valueParam);
}

QString Settings::getFileDirectoryRead()
{
    return AbstractSchemeFileSettings::getValue(Settings::PATH_TO_FILE_DIRECTORY_READ, Settings::DEFAULT_VALUE_FILE_DIRECTORY_READ);
}

void Settings::setFileDirectoryWrite(const QString &valueParam)
{
    AbstractSchemeFileSettings::setValue(Settings::PATH_TO_FILE_DIRECTORY_WRITE, valueParam);
}

QString Settings::getFileDirectoryWrite()
{
    return AbstractSchemeFileSettings::getValue(Settings::PATH_TO_FILE_DIRECTORY_WRITE, Settings::DEFAULT_VALUE_FILE_DIRECTORY_WRITE);
}

void Settings::setMainWindowX(const int &x)
{
    AbstractSchemeFileSettings::setValue(Settings::PATH_TO_WINDOW_MAIN_X, QString::number(x));
}

int Settings::getMainWindowX()
{
    return AbstractSchemeFileSettings::getValue(Settings::PATH_TO_WINDOW_MAIN_X, Settings::DEFAULT_VALUE_WINDOW_MAIN_X).toInt();
}

void Settings::setMainWindowY(const int &y)
{
    AbstractSchemeFileSettings::setValue(Settings::PATH_TO_WINDOW_MAIN_Y, QString::number(y));
}

int Settings::getMainWindowY()
{
    return AbstractSchemeFileSettings::getValue(Settings::PATH_TO_WINDOW_MAIN_Y, Settings::DEFAULT_VALUE_WINDOW_MAIN_Y).toInt();
}

void Settings::setMainWindowWidth(const int &width)
{
    AbstractSchemeFileSettings::setValue(Settings::PATH_TO_WINDOW_MAIN_WIDTH, QString::number(width));
}

int Settings::getMainWindowWidth()
{
    return AbstractSchemeFileSettings::getValue(Settings::PATH_TO_WINDOW_MAIN_WIDTH, Settings::DEFAULT_VALUE_WINDOW_MAIN_WIDTH).toInt();
}

void Settings::setMainWindowHeight(const int &height)
{
    AbstractSchemeFileSettings::setValue(Settings::PATH_TO_WINDOW_MAIN_HEIDGHT, QString::number(height));
}

int Settings::getMainWindowHeight()
{
    return AbstractSchemeFileSettings::getValue(Settings::PATH_TO_WINDOW_MAIN_HEIDGHT, Settings::DEFAULT_VALUE_WINDOW_MAIN_HEIDGHT).toInt();
}

void Settings::setMainWindowScreenWidth(const int &width)
{
    AbstractSchemeFileSettings::setValue(Settings::PATH_TO_WINDOW_MAIN_SCREEN_WIDTH, QString::number(width));
};

int Settings::getMainWindowScreenWidth()
{
    return AbstractSchemeFileSettings::getValue(Settings::PATH_TO_WINDOW_MAIN_SCREEN_WIDTH, Settings::DEFAULT_VALUE_WINDOW_MAIN_SCREEN_WIDTH).toInt();
};

void Settings::setMainWindowScreenHeight(const int &height)
{
    AbstractSchemeFileSettings::setValue(Settings::PATH_TO_WINDOW_MAIN_SCREEN_HEIDGHT, QString::number(height));
};

int Settings::getMainWindowScreenHeight()
{
    return AbstractSchemeFileSettings::getValue(Settings::PATH_TO_WINDOW_MAIN_SCREEN_HEIDGHT, Settings::DEFAULT_VALUE_WINDOW_MAIN_SCREEN_HEIDGHT).toInt();
};

void Settings::setShortcutWindowX(const int &x)
{
    AbstractSchemeFileSettings::setValue(Settings::PATH_TO_WINDOW_SHORTCUT_X, QString::number(x));
}

int Settings::getShortcutWindowX()
{
    return AbstractSchemeFileSettings::getValue(Settings::PATH_TO_WINDOW_SHORTCUT_X, Settings::DEFAULT_VALUE_WINDOW_SHORTCUT_X).toInt();
}

void Settings::setShortcutWindowY(const int &y)
{
    AbstractSchemeFileSettings::setValue(Settings::PATH_TO_WINDOW_SHORTCUT_Y, QString::number(y));
}

int Settings::getShortcutWindowY()
{
    return AbstractSchemeFileSettings::getValue(Settings::PATH_TO_WINDOW_SHORTCUT_Y, Settings::DEFAULT_VALUE_WINDOW_SHORTCUT_Y).toInt();
}

void Settings::setShortcutWindowWidth(const int &width)
{
    AbstractSchemeFileSettings::setValue(Settings::PATH_TO_WINDOW_SHORTCUT_WIDTH, QString::number(width));
}

int Settings::getShortcutWindowWidth()
{
    return AbstractSchemeFileSettings::getValue(Settings::PATH_TO_WINDOW_SHORTCUT_WIDTH, Settings::DEFAULT_VALUE_WINDOW_SHORTCUT_WIDTH).toInt();
}

void Settings::setShortcutWindowHeight(const int &height)
{
    AbstractSchemeFileSettings::setValue(Settings::PATH_TO_WINDOW_SHORTCUT_HEIDGHT, QString::number(height));
}

int Settings::getShortcutWindowHeight()
{
    return AbstractSchemeFileSettings::getValue(Settings::PATH_TO_WINDOW_SHORTCUT_HEIDGHT, Settings::DEFAULT_VALUE_WINDOW_SHORTCUT_HEIDGHT).toInt();
}

void Settings::setShortcutWindowScreenWidth(const int &width)
{
    AbstractSchemeFileSettings::setValue(Settings::PATH_TO_WINDOW_SHORTCUT_SCREEN_WIDTH, QString::number(width));
};

int Settings::getShortcutWindowScreenWidth()
{
    return AbstractSchemeFileSettings::getValue(Settings::PATH_TO_WINDOW_SHORTCUT_SCREEN_WIDTH, Settings::DEFAULT_VALUE_WINDOW_SHORTCUT_SCREEN_WIDTH).toInt();
};

void Settings::setShortcutWindowScreenHeight(const int &height)
{
    AbstractSchemeFileSettings::setValue(Settings::PATH_TO_WINDOW_SHORTCUT_SCREEN_HEIDGHT, QString::number(height));
};

int Settings::getShortcutWindowScreenHeight()
{
    return AbstractSchemeFileSettings::getValue(Settings::PATH_TO_WINDOW_SHORTCUT_SCREEN_HEIDGHT, Settings::DEFAULT_VALUE_WINDOW_SHORTCUT_SCREEN_HEIDGHT).toInt();
};

void Settings::setListShortcutActionOpenFile(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSettings::setValue(Settings::PATH_TO_LIST_SHORTCUT_ACTION_OPEN_FILE, AbstractSchemeFileSettings::convertListKeySequenceToStringList(valueParam));
}

void Settings::setListShortcutActionSaveScheme(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSettings::setValue(Settings::PATH_TO_LIST_SHORTCUT_ACTION_SAVE_SCHEME, AbstractSchemeFileSettings::convertListKeySequenceToStringList(valueParam));
}

void Settings::setListShortcutActionDeleteOpenScheme(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSettings::setValue(Settings::PATH_TO_LIST_SHORTCUT_ACTION_DELETE_OPEN_SCHEME, AbstractSchemeFileSettings::convertListKeySequenceToStringList(valueParam));
}

void Settings::setListShortcutActionOpenShortcutWidget(const QList<QKeySequence> &valueParam)
{
    AbstractSchemeFileSettings::setValue(Settings::PATH_TO_LIST_SHORTCUT_ACTION_OPEN_SHORTCUT_WIDGET, AbstractSchemeFileSettings::convertListKeySequenceToStringList(valueParam));
}

QList<QKeySequence> Settings::getListShortcutActionOpenFile()
{
    return AbstractSchemeFileSettings::convertStringListToListKeySequence(AbstractSchemeFileSettings::getValue(Settings::PATH_TO_LIST_SHORTCUT_ACTION_OPEN_FILE, Settings::DEFAULT_VALUE_LIST_SHORTCUT_ACTION_OPEN_FILE));
}

QList<QKeySequence> Settings::getListShortcutActionSaveScheme()
{
    return AbstractSchemeFileSettings::convertStringListToListKeySequence(AbstractSchemeFileSettings::getValue(Settings::PATH_TO_LIST_SHORTCUT_ACTION_SAVE_SCHEME, Settings::DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SAVE_SCHEME));
}

QList<QKeySequence> Settings::getListShortcutActionDeleteOpenScheme()
{
    return AbstractSchemeFileSettings::convertStringListToListKeySequence(AbstractSchemeFileSettings::getValue(Settings::PATH_TO_LIST_SHORTCUT_ACTION_DELETE_OPEN_SCHEME, Settings::DEFAULT_VALUE_LIST_SHORTCUT_ACTION_DELETE_OPEN_SCHEME));
}

QList<QKeySequence> Settings::getListShortcutActionOpenShortcutWidget()
{
    return AbstractSchemeFileSettings::convertStringListToListKeySequence(AbstractSchemeFileSettings::getValue(Settings::PATH_TO_LIST_SHORTCUT_ACTION_OPEN_SHORTCUT_WIDGET, Settings::DEFAULT_VALUE_LIST_SHORTCUT_ACTION_OPEN_SHORTCUT_WIDGET));
}

QList<QKeySequence> Settings::getListDefaultShortcutActionOpenFile()
{
    return AbstractSchemeFileSettings::convertStringListToListKeySequence(Settings::DEFAULT_VALUE_LIST_SHORTCUT_ACTION_OPEN_FILE);
}

QList<QKeySequence> Settings::getListDefaultShortcutActionSaveScheme()
{
    return AbstractSchemeFileSettings::convertStringListToListKeySequence(Settings::DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SAVE_SCHEME);
}

QList<QKeySequence> Settings::getListDefaultShortcutActionDeleteOpenScheme()
{
    return AbstractSchemeFileSettings::convertStringListToListKeySequence(Settings::DEFAULT_VALUE_LIST_SHORTCUT_ACTION_DELETE_OPEN_SCHEME);
}

QList<QKeySequence> Settings::getListDefaultShortcutActionOpenShortcutWidget()
{
    return AbstractSchemeFileSettings::convertStringListToListKeySequence(Settings::DEFAULT_VALUE_LIST_SHORTCUT_ACTION_OPEN_SHORTCUT_WIDGET);
}

void Settings::setDefaultShrotcuts()
{
    AbstractSchemeFileSettings::setValue(Settings::PATH_TO_LIST_SHORTCUT_ACTION_OPEN_FILE, Settings::DEFAULT_VALUE_LIST_SHORTCUT_ACTION_OPEN_FILE);
    AbstractSchemeFileSettings::setValue(Settings::PATH_TO_LIST_SHORTCUT_ACTION_SAVE_SCHEME, Settings::DEFAULT_VALUE_LIST_SHORTCUT_ACTION_SAVE_SCHEME);
    AbstractSchemeFileSettings::setValue(Settings::PATH_TO_LIST_SHORTCUT_ACTION_DELETE_OPEN_SCHEME, Settings::DEFAULT_VALUE_LIST_SHORTCUT_ACTION_DELETE_OPEN_SCHEME);
    AbstractSchemeFileSettings::setValue(Settings::PATH_TO_LIST_SHORTCUT_ACTION_OPEN_SHORTCUT_WIDGET, Settings::DEFAULT_VALUE_LIST_SHORTCUT_ACTION_OPEN_SHORTCUT_WIDGET);
}
