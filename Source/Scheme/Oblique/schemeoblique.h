#ifndef SCHEMEOBLIQUE_H
#define SCHEMEOBLIQUE_H

#include <QObject>

#include "Abstract/abstractscheme.h"
#include "Scheme/Oblique/Widget/CreateScheme/schemeobliquewidgetcreatescheme.h"
#include "Scheme/Oblique/Widget/EditDirectionForNewNode/schemeobliquewidgeteditdirectionfornewnodechartwindow.h"

class SchemeOblique : public AbstractScheme
{
    Q_OBJECT
public:
    enum Directions {
        ADD_TOP       = 0,
        ADD_BOTTOM    = 1,
        ADD_LEFT      = 2,
        ADD_RIGHT     = 3,
        REMOVE_TOP    = 4,
        REMOVE_BOTTOM = 5,
        REMOVE_LEFT   = 6,
        REMOVE_RIGHT  = 7
    };

    SchemeOblique();
    ~SchemeOblique();

    void setMenuCreate(QMenu &menuCreate);
    void setMenuSettings(QMenu &menuSettings);
    void updateShortcut();
    QList<AbstractSchemeFileRead*> &getListFileRead();
    AbstractSchemeFileWrite &getFileWrite();
    const QString &getTypeScheme();

private:
    void commonCreate();

    QMenu menuSettings;
    QAction actionCreate;
    QAction actionEditDirectionNewNode;

    SchemeObliqueWidgetCreateScheme schemeObliqueWidgetCreateScheme;
    SchemeObliqueWidgetEditDirectionForNewNodeWindow schemeObliqueWidgetEditDirectionForNewNodeWindow;
};

#endif // SCHEMEOBLIQUE_H
