#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "tabwidget.h"
#include "fileread.h"
#include "filewrite.h"
#include "editdirectionfornewnodewindow.h"

#include "Abstract/abstractscheme.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QList<AbstractScheme*> &schemes, QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void enabledRemoveThread(bool enabled);
    void enabledRemoveHalfrow(bool enabled);
    void enabledAddedThread(bool enabled);
    void enabledAddedHalfrow(bool enabled);

    void enabledHistoryBack(bool enabled);
    void enabledHistoryNext(bool enabled);

private slots:
    // файл
    void on_openScheme_triggered();
    void on_saveScheme_triggered();

    // вид
    void on_zoomOut_triggered();
    void on_zoomIn_triggered();

    void on_movingDown_triggered();
    void on_movingUp_triggered();
    void on_movingLeft_triggered();
    void on_movingRight_triggered();

    void on_rotateLeft_triggered();
    void on_rotateRight_triggered();

    // схема
    void on_deleteScheme_triggered();
    void on_editScheme_triggered();

    void on_removeThreadLeft_triggered();
    void on_removeThreadRight_triggered();

    void on_addThreadLeft_triggered();
    void on_addThreadRight_triggered();

    void on_removeHalfrowDown_triggered();
    void on_removeHalfrowTop_triggered();

    void on_addHalfrowDown_triggered();
    void on_addHalfrowTop_triggered();

    void on_historyBack_triggered();
    void on_historyNext_triggered();

private:
    void updateMenu(int index);

    Ui::MainWindow *ui;

    QList<AbstractScheme*> &schemes;
    TabWidget tabWidget;
    FileRead fileRead;
    FileWrite fileWrite;
    EditDirectionForNewNodeWindow editDirectionForNewNodeWindow;
};
#endif // MAINWINDOW_H
