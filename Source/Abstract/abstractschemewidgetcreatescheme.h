#ifndef ABSTRACTSCHEMEWIDGETCREATESCHEME_H
#define ABSTRACTSCHEMEWIDGETCREATESCHEME_H

#include <QWidget>

#include "Abstract/abstractschemechartview.h"

class AbstractSchemeWidgetCreateScheme : public QWidget
{
    Q_OBJECT

public:
    AbstractSchemeWidgetCreateScheme(QWidget *parent = nullptr) : QWidget(parent) {};
    ~AbstractSchemeWidgetCreateScheme() {};

public slots:
    virtual void createIn() = 0;

signals:
    void createOut(AbstractSchemeChartView &view);
};

#endif // ABSTRACTSCHEMEWIDGETCREATESCHEME_H
