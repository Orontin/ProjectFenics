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
    this->tabWidget.deleteScheme();
}

void MainWindow::updateMenu(int index)
{
    if (index == -1) {
    } else {
        static_cast<AbstractSchemeChartScene*>(this->tabWidget.getCurrentScheme().scene())->updateScene();
    }
}

