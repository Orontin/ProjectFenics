#ifndef SCHEMEOBLIQUEWIDGETEDITDIRECTIONFORNEWNODEWINDOW_H
#define SCHEMEOBLIQUEWIDGETEDITDIRECTIONFORNEWNODEWINDOW_H

#include <QWidget>

namespace Ui {
class SchemeObliqueWidgetEditDirectionForNewNodeWindow;
}

class SchemeObliqueWidgetEditDirectionForNewNodeWindow : public QWidget
{
    Q_OBJECT

public:
    static SchemeObliqueWidgetEditDirectionForNewNodeWindow &getInstance();

    void open();

private:
    explicit SchemeObliqueWidgetEditDirectionForNewNodeWindow(QWidget *parent = nullptr);
    ~SchemeObliqueWidgetEditDirectionForNewNodeWindow();

    static SchemeObliqueWidgetEditDirectionForNewNodeWindow *schemeObliqueWidgetEditDirectionForNewNodeWindow;

    Ui::SchemeObliqueWidgetEditDirectionForNewNodeWindow *ui;
};

#endif // SCHEMEOBLIQUEWIDGETEDITDIRECTIONFORNEWNODEWINDOW_H
