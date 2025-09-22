#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Abstract/abstractschemechartscene.h"
#include "Abstract/abstractschemechartview.h"

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

    separatorManagment = this->ui->menu2->addSeparator();
    separatorSettings = this->ui->menu2->addSeparator();
}

MainWindow::~MainWindow()
{
    disconnect(&this->tabWidget, &TabWidget::currentChanged, this, &MainWindow::updateMenu);
    delete this->ui;
}

void MainWindow::onOpenSchemeTriggered()
{
    fileRead.readFile();
}

void MainWindow::onSaveSchemeTriggered()
{
    fileWrite.writeFile(this->tabWidget.getCurrentScheme());
}

void MainWindow::onDeleteSchemeTriggered()
{
    currentMenuHistory = nullptr;
    currentMenuView = nullptr;
    currentMenuManagment = nullptr;
    currentMenuSettings = nullptr;

    this->tabWidget.deleteScheme();
}

void MainWindow::updateMenu(int index)
{
    if (index == -1) {
        this->ui->deleteOpenScheme->setEnabled(false);
        this->ui->saveScheme->setEnabled(false);
    } else {
        if (currentMenuHistory) {
            this->ui->menubar->removeAction(currentMenuHistory->menuAction());
            currentMenuHistory = nullptr;
        }
        if (currentMenuView) {
            this->ui->menubar->removeAction(currentMenuView->menuAction());
            currentMenuView = nullptr;
        }

        if (currentMenuManagment) {
            this->ui->menu2->removeAction(currentMenuManagment->menuAction());
            currentMenuManagment = nullptr;
        }
        if (currentMenuSettings) {
            this->ui->menu2->removeAction(currentMenuSettings->menuAction());
            currentMenuSettings = nullptr;
        }

        this->ui->deleteOpenScheme->setEnabled(true);
        this->ui->saveScheme->setEnabled(true);

        currentMenuHistory = &static_cast<AbstractSchemeChartView*>(&this->tabWidget.getCurrentScheme())->getMenuView();
        currentMenuView = &static_cast<AbstractSchemeChartScene*>(this->tabWidget.getCurrentScheme().scene())->getMenuHistory();

        this->ui->menubar->insertMenu(this->ui->menu2->menuAction(), currentMenuView);
        this->ui->menubar->insertMenu(this->ui->menu2->menuAction(), currentMenuHistory);

        currentMenuManagment = &static_cast<AbstractSchemeChartScene*>(this->tabWidget.getCurrentScheme().scene())->getMenuManagment();
        this->ui->menu2->insertMenu(separatorManagment, currentMenuManagment);

        currentMenuSettings = &static_cast<AbstractSchemeChartScene*>(this->tabWidget.getCurrentScheme().scene())->getMenuSettings();
        this->ui->menu2->insertMenu(separatorSettings, currentMenuSettings);

        static_cast<AbstractSchemeChartScene*>(this->tabWidget.getCurrentScheme().scene())->updateScene();
    }
}

