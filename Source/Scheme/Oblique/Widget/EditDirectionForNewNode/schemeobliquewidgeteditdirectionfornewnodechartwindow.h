#ifndef SCHEMEOBLIQUEWIDGETEDITDIRECTIONFORNEWNODEWINDOW_H
#define SCHEMEOBLIQUEWIDGETEDITDIRECTIONFORNEWNODEWINDOW_H

#include <QWidget>

#include "Scheme/Oblique/Widget/EditDirectionForNewNode/Chart/schemeobliquewidgeteditdirectionfornewnodechartview.h"

namespace Ui {
class SchemeObliqueWidgetEditDirectionForNewNodeWindow;
}

class SchemeObliqueWidgetEditDirectionForNewNodeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SchemeObliqueWidgetEditDirectionForNewNodeWindow(QWidget *parent = nullptr);
    ~SchemeObliqueWidgetEditDirectionForNewNodeWindow();

    void open();

private:
    Ui::SchemeObliqueWidgetEditDirectionForNewNodeWindow *ui;

    SchemeObliqueWidgetEditDirectionForNewNodeChartView &schemeObliqueWidgetEditDirectionForNewNodeChartView;
};

#endif // SCHEMEOBLIQUEWIDGETEDITDIRECTIONFORNEWNODEWINDOW_H
