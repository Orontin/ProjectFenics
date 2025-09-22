#ifndef SCHEMEOBLIQUE_H
#define SCHEMEOBLIQUE_H

#include <QObject>

#include "Abstract/abstractscheme.h"
#include "Scheme/Oblique/Widget/CreateScheme/schemeobliquewidgetcreatescheme.h"

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

    QAction &getActionCreate();
    QList<AbstractSchemeFileRead*> &getListFileRead();
    AbstractSchemeFileWrite &getFileWrite();
    const QString &getTypeScheme();

private:
    SchemeObliqueWidgetCreateScheme schemeObliqueWidgetCreateScheme;
};

#endif // SCHEMEOBLIQUE_H
