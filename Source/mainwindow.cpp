#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Abstract/abstractschemechartscene.h"
#include "Abstract/abstractschemechartview.h"

#include "settings.h"

#include <QKeySequence>

MainWindow::MainWindow(QList<AbstractScheme*> &schemes, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    schemes(schemes),
    tabWidget(schemes),
    fileRead(schemes),
    fileWrite(schemes)
{
    ui->setupUi(this);

    this->setWindowTitle("Проект Феникс v3.0.0.0");

    this->connect(&this->fileRead, &FileRead::createOut, &this->tabWidget, &TabWidget::createOut);

    this->setCentralWidget(&this->tabWidget);

    this->connect(&this->tabWidget, &TabWidget::currentChanged, this, &MainWindow::updateMenu);
    this->updateMenu(-1);

    for (AbstractScheme *scheme : schemes) {
        scheme->setMenuCreate(*ui->createNewScheme);
    }

    for (AbstractScheme *scheme : schemes) {
        scheme->setMenuSettings(*ui->settingsScheme);
    }

    connect(this->ui->deleteOpenScheme, &QAction::triggered, this, &MainWindow::onDeleteSchemeTriggered);
    connect(this->ui->openFile, &QAction::triggered, this, &MainWindow::onOpenSchemeTriggered);
    connect(this->ui->saveScheme, &QAction::triggered, this, &MainWindow::onSaveSchemeTriggered);

    this->ui->deleteOpenScheme->setShortcuts(Settings::getShortcut_Action_DeleteOpenScheme());
    this->ui->openFile->setShortcuts(Settings::getShortcut_Action_OpenFile());
    this->ui->saveScheme->setShortcuts(Settings::getShortcut_Action_SaveScheme());
}

MainWindow::~MainWindow()
{
    disconnect(&this->tabWidget, &TabWidget::currentChanged, this, &MainWindow::updateMenu);
    delete this->ui;
}

void MainWindow::onOpenSchemeTriggered()
{
    this->fileRead.readFile();
}

void MainWindow::onSaveSchemeTriggered()
{
    this->fileWrite.writeFile(this->tabWidget.getCurrentScheme());
}

void MainWindow::onDeleteSchemeTriggered()
{
    this->tabWidget.deleteScheme();
}

void MainWindow::updateMenu(int index)
{
    if (index == -1) {
        this->ui->deleteOpenScheme->setEnabled(false);
        this->ui->saveScheme->setEnabled(false);

        this->ui->view->setEnabled(false);
        this->ui->history->setEnabled(false);
        this->ui->managment->setEnabled(false);
        this->ui->settingsOpenScheme->setEnabled(false);
    } else {
        static_cast<AbstractSchemeChartView*>(&this->tabWidget.getCurrentScheme())->setMenuView(*this->ui->view);

        static_cast<AbstractSchemeChartScene*>(this->tabWidget.getCurrentScheme().scene())->setMenuHistory(*this->ui->history);
        static_cast<AbstractSchemeChartScene*>(this->tabWidget.getCurrentScheme().scene())->setMenuManagment(*this->ui->managment);
        static_cast<AbstractSchemeChartScene*>(this->tabWidget.getCurrentScheme().scene())->setMenuSettingsOpenScheme(*this->ui->settingsOpenScheme);

        static_cast<AbstractSchemeChartScene*>(this->tabWidget.getCurrentScheme().scene())->updateScene();

        this->ui->deleteOpenScheme->setEnabled(true);
        this->ui->saveScheme->setEnabled(true);

        if (this->ui->view->actions().count()) {
            this->ui->view->setEnabled(true);
        } else {
            this->ui->view->setEnabled(false);
        }
        if (this->ui->history->actions().count()) {
            this->ui->history->setEnabled(true);
        } else {
            this->ui->history->setEnabled(false);
        }
        if (this->ui->managment->actions().count()) {
            this->ui->managment->setEnabled(true);
        } else {
            this->ui->managment->setEnabled(false);
        }
        if (this->ui->settingsOpenScheme->actions().count()) {
            this->ui->settingsOpenScheme->setEnabled(true);
        } else {
            this->ui->settingsOpenScheme->setEnabled(false);
        }
    }
}

