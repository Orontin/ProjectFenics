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
        this->ui->createNewScheme->addAction(&scheme->getActionCreate());
    }

    connect(this->ui->deleteOpenScheme, &QAction::triggered, this, &MainWindow::onDeleteSchemeTriggered);
    connect(this->ui->openFile, &QAction::triggered, this, &MainWindow::onOpenSchemeTriggered);
    connect(this->ui->saveScheme, &QAction::triggered, this, &MainWindow::onSaveSchemeTriggered);

    this->separatorManagment = this->ui->scheme->addSeparator();
    this->separatorSettings = this->ui->scheme->addSeparator();

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
    this->currentMenuHistory = nullptr;
    this->currentMenuView = nullptr;
    this->currentMenuManagment = nullptr;
    this->currentMenuSettings = nullptr;

    this->tabWidget.deleteScheme();
}

void MainWindow::updateMenu(int index)
{
    if (index == -1) {
        this->ui->deleteOpenScheme->setEnabled(false);
        this->ui->saveScheme->setEnabled(false);
    } else {
        if (currentMenuHistory) {
            this->ui->menubar->removeAction(this->currentMenuHistory->menuAction());
            this->currentMenuHistory = nullptr;
        }
        if (currentMenuView) {
            this->ui->menubar->removeAction(this->currentMenuView->menuAction());
            this->currentMenuView = nullptr;
        }

        if (currentMenuManagment) {
            this->ui->scheme->removeAction(this->currentMenuManagment->menuAction());
            this->currentMenuManagment = nullptr;
        }
        if (currentMenuSettings) {
            this->ui->scheme->removeAction(this->currentMenuSettings->menuAction());
            this->currentMenuSettings = nullptr;
        }

        this->ui->deleteOpenScheme->setEnabled(true);
        this->ui->saveScheme->setEnabled(true);

        this->currentMenuHistory = &static_cast<AbstractSchemeChartView*>(&this->tabWidget.getCurrentScheme())->getMenuView();
        this->currentMenuView = &static_cast<AbstractSchemeChartScene*>(this->tabWidget.getCurrentScheme().scene())->getMenuHistory();

        this->ui->menubar->insertMenu(this->ui->scheme->menuAction(), currentMenuHistory);
        this->ui->menubar->insertMenu(this->ui->scheme->menuAction(), currentMenuView);

        this->currentMenuManagment = &static_cast<AbstractSchemeChartScene*>(this->tabWidget.getCurrentScheme().scene())->getMenuManagment();
        this->ui->scheme->insertMenu(this->separatorManagment, this->currentMenuManagment);

        this->currentMenuSettings = &static_cast<AbstractSchemeChartScene*>(this->tabWidget.getCurrentScheme().scene())->getMenuSettings();
        this->ui->scheme->insertMenu(this->separatorSettings, this->currentMenuSettings);

        static_cast<AbstractSchemeChartScene*>(this->tabWidget.getCurrentScheme().scene())->updateScene();
    }
}

