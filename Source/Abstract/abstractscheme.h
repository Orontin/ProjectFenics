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
                   QGraphicsView *editDirectionForNewNodeView,
                   const QString &typeScheme):
                                                listFileRead(listFileRead),
                                                fileWrite(fileWrite),
                                                widgetCreateScheme(widgetCreateScheme),
                                                editDirectionForNewNodeView(editDirectionForNewNodeView),
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
        delete editDirectionForNewNodeView;
    };

    QList<AbstractSchemeFileRead*> *listFileRead;
    AbstractSchemeFileWrite *fileWrite;
    AbstractSchemeWidgetCreateScheme *widgetCreateScheme;
    QGraphicsView *editDirectionForNewNodeView;
    const QString &typeScheme;
};

#endif // ABSTRACTSCHEME_H
