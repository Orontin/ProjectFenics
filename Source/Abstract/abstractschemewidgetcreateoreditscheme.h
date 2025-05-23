#ifndef ABSTRACTSCHEMEWIDGETCREATEOREDITSCHEME_H
#define ABSTRACTSCHEMEWIDGETCREATEOREDITSCHEME_H

#include <QWidget>

#include "Abstract/abstractschemechartview.h"

class AbstractSchemeWidgetCreateOrEditScheme : public QWidget
{
    Q_OBJECT

public:
    AbstractSchemeWidgetCreateOrEditScheme(QWidget *parent = nullptr) : QWidget(parent) {};
    ~AbstractSchemeWidgetCreateOrEditScheme() {};

public slots:
    virtual void createIn() = 0;

signals:
    void createOut(AbstractSchemeChartView &view);
};

#endif // ABSTRACTSCHEMEWIDGETCREATEOREDITSCHEME_H
