#include "mainwindow.h"
#include "shortcutwindow.h"

#include "Abstract/abstractschemechartscene.h"
#include "Abstract/abstractschemechartview.h"

#include "settings.h"

#include <QScreen>
#include <QKeySequence>

MainWindow::MainWindow(QList<AbstractScheme*> &schemes, QWidget *parent):
    QMainWindow(parent),
    schemes(schemes),
    tabWidget(schemes),
    fileRead(schemes),
    fileWrite(schemes)
{
    this->setWindowTitle("Проект Феникс v3.0.0");
    this->setPosition();

    this->setMenuBar(&menubar);

    this->setStatusBar(&statusbar);

    this->menubar.addAction(file.menuAction());
    this->file.addAction(&openFile);
    this->file.addAction(&saveOpenScheme);
    this->file.setTitle("Файл");
    this->openFile.setText("Открыть файл");
    this->saveOpenScheme.setText("Сохранить открытую схему");

    this->menubar.addAction(view.menuAction());
    this->view.setTitle("Вид");

    this->menubar.addAction(history.menuAction());
    this->history.setTitle("История");

    this->menubar.addAction(scheme.menuAction());
    this->scheme.addAction(createNewScheme.menuAction());
    this->scheme.addAction(&deleteOpenScheme);
    this->scheme.addSeparator();
    this->scheme.addAction(managmentOpenScheme.menuAction());
    this->scheme.addSeparator();
    this->scheme.addAction(settingsOpenScheme.menuAction());
    this->scheme.setTitle("Схема");
    this->createNewScheme.setTitle("Создать новую схему");
    this->deleteOpenScheme.setText("Удалить открытую схему");
    this->managmentOpenScheme.setTitle("Управление открытой схемой");
    this->settingsOpenScheme.setTitle("Настроить открытую схему");

    this->menubar.addAction(settings.menuAction());
    this->settings.addAction(&settingsShortcut);
    this->settings.addAction(settingsScheme.menuAction());
    this->settings.setTitle("Настройки");
    this->settingsShortcut.setText("Сочетания клавиш");
    this->settingsScheme.setTitle("Схем");

    this->setCentralWidget(&this->tabWidget);

    for (AbstractScheme *scheme : schemes) {
        scheme->setMenuCreate(this->createNewScheme);
        scheme->setMenuSettings(this->settingsScheme);
        scheme->setShortcut(ShortcutWindow::getInstance().getGridLayouWidgetScrollArea());
        connect(&ShortcutWindow::getInstance(), &ShortcutWindow::clickedShortcutSetDefaultShortcut, scheme, &AbstractScheme::onShortcutSetDefaultShortcut);
        connect(&ShortcutWindow::getInstance(), &ShortcutWindow::clickedShortcutCancel, scheme, &AbstractScheme::onShortcutCancel);
        connect(&ShortcutWindow::getInstance(), &ShortcutWindow::clickedShortcutSave, scheme, &AbstractScheme::onShortcutSave);
    }

    connect(&this->deleteOpenScheme, &QAction::triggered, this, &MainWindow::onDeleteSchemeTriggered);
    connect(&this->openFile, &QAction::triggered, this, &MainWindow::onOpenSchemeTriggered);
    connect(&this->saveOpenScheme, &QAction::triggered, this, &MainWindow::onSaveOpenSchemeTriggered);
    connect(&this->settingsShortcut, &QAction::triggered, this, &MainWindow::onOpenShortcutWidgetTriggered);

    connect(&ShortcutWindow::getInstance(), &ShortcutWindow::clickedShortcutSetDefaultShortcut, this, &MainWindow::onShortcutSetDefaultShortcut);
    connect(&ShortcutWindow::getInstance(), &ShortcutWindow::clickedShortcutCancel, this, &MainWindow::onShortcutCancel);
    connect(&ShortcutWindow::getInstance(), &ShortcutWindow::clickedShortcutSave, this, &MainWindow::onShortcutSave);

    connect(&this->tabWidget, &TabWidget::currentChanged, this, &MainWindow::updateMenu);

    this->updateMenu(-1);
}

MainWindow::~MainWindow()
{
    disconnect(&this->tabWidget, &TabWidget::currentChanged, this, &MainWindow::updateMenu);
}

void MainWindow::open()
{
    this->visible();
}

void MainWindow::moveEvent(QMoveEvent *event)
{
    Q_UNUSED(event)

    Settings::setMainWindowX(this->geometry().x());
    Settings::setMainWindowY(this->geometry().y());

    Settings::setMainWindowScreenWidth(this->screen()->geometry().width());
    Settings::setMainWindowScreenHeight(this->screen()->geometry().height());
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)

    Settings::setMainWindowWidth(this->geometry().width());
    Settings::setMainWindowHeight(this->geometry().height());

    Settings::setMainWindowScreenWidth(this->screen()->geometry().width());
    Settings::setMainWindowScreenHeight(this->screen()->geometry().height());
}

void MainWindow::onOpenSchemeTriggered()
{
    this->fileRead.readFile();
}

void MainWindow::onSaveOpenSchemeTriggered()
{
    this->fileWrite.writeFile(this->tabWidget.getCurrentView());
}

void MainWindow::onOpenShortcutWidgetTriggered()
{
    ShortcutWindow::getInstance().open();
}

void MainWindow::onDeleteSchemeTriggered()
{
    this->tabWidget.deleteView();
}

void MainWindow::onShortcutSetDefaultShortcut()
{
    this->updateShortcut();
}

void MainWindow::onShortcutCancel()
{
    this->updateShortcut();
}

void MainWindow::onShortcutSave()
{
    this->updateShortcut();
}

void MainWindow::updateShortcut()
{
    this->deleteOpenScheme.setShortcuts(Settings::getListShortcutActionDeleteOpenScheme());
    this->openFile.setShortcuts(Settings::getListShortcutActionOpenFile());
    this->saveOpenScheme.setShortcuts(Settings::getListShortcutActionSaveScheme());
    this->settingsShortcut.setShortcuts(Settings::getListShortcutActionOpenShortcutWidget());
}

void MainWindow::updateMenu(int index)
{
    for (AbstractScheme *scheme : schemes) {
        scheme->disconnects();
    }

    if (index == -1) {
        this->deleteOpenScheme.setEnabled(false);
        this->saveOpenScheme.setEnabled(false);

        this->view.setEnabled(false);
        this->history.setEnabled(false);
        this->managmentOpenScheme.setEnabled(false);
        this->settingsOpenScheme.setEnabled(false);
    } else {
        static_cast<AbstractSchemeChartView&>(this->tabWidget.getCurrentView()).getScheme().setMenuView(this->view);
        static_cast<AbstractSchemeChartView&>(this->tabWidget.getCurrentView()).getScheme().setMenuHistory(this->history);
        static_cast<AbstractSchemeChartView&>(this->tabWidget.getCurrentView()).getScheme().setMenuManagment(this->managmentOpenScheme);
        static_cast<AbstractSchemeChartView&>(this->tabWidget.getCurrentView()).getScheme().setMenuSettingsOpenScheme(this->settingsOpenScheme);

        static_cast<AbstractSchemeChartView&>(this->tabWidget.getCurrentView()).getScheme().connects(static_cast<AbstractSchemeChartView&>(this->tabWidget.getCurrentView()));

        static_cast<AbstractSchemeChartScene*>(this->tabWidget.getCurrentView().scene())->updateScene();

        this->deleteOpenScheme.setEnabled(true);
        this->saveOpenScheme.setEnabled(true);

        if (this->view.actions().count()) {
            this->view.setEnabled(true);
        } else {
            this->view.setEnabled(false);
        }
        if (this->history.actions().count()) {
            this->history.setEnabled(true);
        } else {
            this->history.setEnabled(false);
        }
        if (this->managmentOpenScheme.actions().count()) {
            this->managmentOpenScheme.setEnabled(true);
        } else {
            this->managmentOpenScheme.setEnabled(false);
        }
        if (this->settingsOpenScheme.actions().count()) {
            this->settingsOpenScheme.setEnabled(true);
        } else {
            this->settingsOpenScheme.setEnabled(false);
        }
    }
}

void MainWindow::visible()
{
    this->show();
    this->setPosition();
}

void MainWindow::setPosition()
{
    this->setGeometry(
        ((Settings::getMainWindowX() * this->screen()->geometry().width()) / Settings::getMainWindowScreenWidth()),
        ((Settings::getMainWindowY() * this->screen()->geometry().height()) / Settings::getMainWindowScreenHeight()),
        ((Settings::getMainWindowWidth() * this->screen()->geometry().width()) / Settings::getMainWindowScreenWidth()),
        ((Settings::getMainWindowHeight() * this->screen()->geometry().height()) / Settings::getMainWindowScreenHeight())
    );
}
