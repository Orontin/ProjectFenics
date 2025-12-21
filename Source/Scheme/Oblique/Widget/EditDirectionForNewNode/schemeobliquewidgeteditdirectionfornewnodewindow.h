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

protected:
    void moveEvent(QMoveEvent *event) override final;
    void resizeEvent(QResizeEvent *event) override final;

private:
    explicit SchemeObliqueWidgetEditDirectionForNewNodeWindow(QWidget *parent = nullptr);
    ~SchemeObliqueWidgetEditDirectionForNewNodeWindow();

    void visible();
    void setPosition();

    static SchemeObliqueWidgetEditDirectionForNewNodeWindow *schemeObliqueWidgetEditDirectionForNewNodeWindow;

    QGridLayout gridLayout;
};

#endif // SCHEMEOBLIQUEWIDGETEDITDIRECTIONFORNEWNODEWINDOW_H
