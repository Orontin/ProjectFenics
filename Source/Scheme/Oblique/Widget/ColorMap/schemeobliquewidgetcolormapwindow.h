#ifndef SCHEMEOBLIQUEWIDGETCOLORMAPWINDOW_H
#define SCHEMEOBLIQUEWIDGETCOLORMAPWINDOW_H

#include <QWidget>
#include <QGridLayout>

class SchemeObliqueWidgetColorMapWindow : public QWidget
{
    Q_OBJECT

public:
    static SchemeObliqueWidgetColorMapWindow &getInstance();

    void visible(const bool &isVisible);

signals:
    void closed();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    explicit SchemeObliqueWidgetColorMapWindow(QWidget *parent = nullptr);
    ~SchemeObliqueWidgetColorMapWindow();

    static SchemeObliqueWidgetColorMapWindow *schemeObliqueWidgetColorMapWindow;

    QGridLayout gridLayout;
};

#endif // SCHEMEOBLIQUEWIDGETCOLORMAPWINDOW_H
