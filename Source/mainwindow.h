#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QGridLayout>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>

#include "tabwidget.h"
#include "fileread.h"
#include "filewrite.h"

#include "Abstract/abstractscheme.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QList<AbstractScheme*> &schemes, QWidget *parent = nullptr);
    ~MainWindow();

    void open();

protected:
    void moveEvent(QMoveEvent *event) override final;
    void resizeEvent(QResizeEvent *event) override final;

private slots:
    // файл
    void onOpenSchemeTriggered();
    void onSaveOpenSchemeTriggered();
    void onOpenShortcutWidgetTriggered();

    // схема
    void onDeleteSchemeTriggered();

    // шорткаты
    void onShortcutSetDefaultShortcut();
    void onShortcutCancel();
    void onShortcutSave();

private:
    void updateShortcut();
    void updateMenu(int index);

    void visible();
    void setPosition();

    QMenu file;
    QAction openFile;
    QAction saveOpenScheme;

    QMenu view;

    QMenu history;

    QMenu scheme;
    QMenu createNewScheme;
    QAction deleteOpenScheme;
    QMenu managmentOpenScheme;
    QMenu settingsOpenScheme;

    QMenu settings;
    QAction settingsShortcut;
    QMenu settingsScheme;

    QGridLayout gridLayout;
    QMenuBar menubar;
    QStatusBar statusbar;

    QList<AbstractScheme*> &schemes;
    TabWidget tabWidget;
    FileRead fileRead;
    FileWrite fileWrite;    
};
#endif // MAINWINDOW_H
