#ifndef SCHEMEOBLIQUEWIDGETEDITDIRECTIONFORNEWNODEWINDOW_H
#define SCHEMEOBLIQUEWIDGETEDITDIRECTIONFORNEWNODEWINDOW_H

#include <QWidget>
#include <QGridLayout>

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

    QGridLayout gridLayout;
};

#endif // SCHEMEOBLIQUEWIDGETEDITDIRECTIONFORNEWNODEWINDOW_H
