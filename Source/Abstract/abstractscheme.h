#ifndef ABSTRACTSCHEME_H
#define ABSTRACTSCHEME_H

#include <QAction>

#include "Abstract/abstractschemechartview.h"

class AbstractScheme: public QObject {
public:
    AbstractScheme() {};
    ~AbstractScheme() {};

    virtual QAction &getActionCreate() = 0;

signals:
    void createOut(AbstractSchemeChartView &view);

protected:
    QAction actionCreate;
};

#endif // ABSTRACTSCHEME_H
