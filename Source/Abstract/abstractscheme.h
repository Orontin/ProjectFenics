#ifndef ABSTRACTSCHEME_H
#define ABSTRACTSCHEME_H

#include "abstractschemefileread.h"
#include "abstractschemefilewrite.h"
#include "abstractschemewidgetcreatescheme.h"

class AbstractScheme {
public:
    AbstractScheme(QList<AbstractSchemeFileRead*> *listFileRead,
                   AbstractSchemeFileWrite *fileWrite,
                   AbstractSchemeWidgetCreateScheme *widgetCreateScheme,
                   const QString &typeScheme):
                                                listFileRead(listFileRead),
                                                fileWrite(fileWrite),
                                                widgetCreateScheme(widgetCreateScheme),
                                                typeScheme(typeScheme)
    {};
    ~AbstractScheme()
    {
        for (AbstractSchemeFileRead *fileRead : *listFileRead) {
            delete fileRead;
        }
        delete listFileRead;
        delete fileWrite;
        delete widgetCreateScheme;
    };

    QList<AbstractSchemeFileRead*> *listFileRead;
    AbstractSchemeFileWrite *fileWrite;
    AbstractSchemeWidgetCreateScheme *widgetCreateScheme;
    const QString &typeScheme;
};

#endif // ABSTRACTSCHEME_H
