#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "tabwidget.h"
#include "fileread.h"
#include "filewrite.h"

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

private slots:
    // файл
    void onOpenSchemeTriggered();
    void onSaveSchemeTriggered();

    // схема
    void onDeleteSchemeTriggered();

private:
    void updateMenu(int index);

    QMenu *currentMenuHistory = nullptr;
    QMenu *currentMenuView = nullptr;

    QAction *separatorManagment = nullptr;
    QAction *separatorSettings = nullptr;

    QMenu *currentMenuManagment = nullptr;
    QMenu *currentMenuSettings = nullptr;

    Ui::MainWindow *ui;

    QList<AbstractScheme*> &schemes;
    TabWidget tabWidget;
    FileRead fileRead;
    FileWrite fileWrite;
};
#endif // MAINWINDOW_H
