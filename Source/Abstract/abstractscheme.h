#ifndef ABSTRACTSCHEME_H
#define ABSTRACTSCHEME_H

#include "abstractschemefileread.h"
#include "abstractschemefilewrite.h"
#include "abstractschemewidgetcreateoreditscheme.h"

class AbstractScheme {
public:
    AbstractScheme(QList<AbstractSchemeFileRead*> *listFileRead,
                   AbstractSchemeFileWrite *fileWrite,
                   AbstractSchemeWidgetCreateOrEditScheme *widgetCreateOrEditScheme,
                   QGraphicsView *editDirectionForNewNodeView,
                   const QString &typeScheme):
                                                listFileRead(listFileRead),
                                                fileWrite(fileWrite),
                                                widgetCreateOrEditScheme(widgetCreateOrEditScheme),
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
        delete widgetCreateOrEditScheme;
        delete editDirectionForNewNodeView;
    };

    QList<AbstractSchemeFileRead*> *listFileRead;
    AbstractSchemeFileWrite *fileWrite;
    AbstractSchemeWidgetCreateOrEditScheme *widgetCreateOrEditScheme;
    QGraphicsView *editDirectionForNewNodeView;
    const QString &typeScheme;
};

#endif // ABSTRACTSCHEME_H
