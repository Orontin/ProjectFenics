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
#include "shortcutwidget.h"

#include "Abstract/abstractscheme.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QList<AbstractScheme*> &schemes, QWidget *parent = nullptr);
    ~MainWindow();

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

    TabWidget tabWidget;
    FileRead fileRead;
    FileWrite fileWrite;
    QList<AbstractScheme*> &schemes;
};
#endif // MAINWINDOW_H
