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
    fileWrite(schemes),
    editDirectionForNewNodeWindow(schemes)
{
    ui->setupUi(this);

    this->setWindowTitle("Проект Феникс v3.0.0.0");

    for (AbstractScheme *scheme : schemes) {
        QAction *actionCreateNewScheme = ui->menuCreateNewScheme->addAction(scheme->typeScheme);
        QAction *actionEditDirectionNewNode = ui->menuEditDirectionNewNode->addAction(scheme->typeScheme);

        connect(actionCreateNewScheme, &QAction::triggered, [=](){
            this->tabWidget.addScheme(scheme->typeScheme);
        });

        connect(actionEditDirectionNewNode, &QAction::triggered, [=](){
            this->editDirectionForNewNodeWindow.open(scheme->typeScheme);
        });
    }

    this->connect(&this->fileRead, &FileRead::createOut, &this->tabWidget, &TabWidget::createOut);

    this->setCentralWidget(&this->tabWidget);

    this->connect(&this->tabWidget, &TabWidget::enabledRemoveHalfrow, this, &MainWindow::enabledRemoveHalfrow);
    this->connect(&this->tabWidget, &TabWidget::enabledRemoveThread, this, &MainWindow::enabledRemoveThread);
    this->connect(&this->tabWidget, &TabWidget::enabledAddedThread, this, &MainWindow::enabledAddedThread);
    this->connect(&this->tabWidget, &TabWidget::enabledAddedHalfrow, this, &MainWindow::enabledAddedHalfrow);

    this->connect(&this->tabWidget, &TabWidget::currentChanged, this, &MainWindow::updateMenu);
    this->updateMenu(-1);
}

MainWindow::~MainWindow()
{
    disconnect(&this->tabWidget, &TabWidget::currentChanged, this, &MainWindow::updateMenu);
    delete this->ui;
}

void MainWindow::enabledRemoveThread(bool enabled)
{
    this->ui->removeThreadLeft->setEnabled(enabled);
    this->ui->removeThreadRight->setEnabled(enabled);
}

void MainWindow::enabledRemoveHalfrow(bool enabled)
{
    this->ui->removeHalfrowDown->setEnabled(enabled);
    this->ui->removeHalfrowTop->setEnabled(enabled);
}

void MainWindow::enabledAddedThread(bool enabled)
{
    this->ui->addThreadLeft->setEnabled(enabled);
    this->ui->addThreadRight->setEnabled(enabled);
}

void MainWindow::enabledAddedHalfrow(bool enabled)
{
    this->ui->addHalfrowDown->setEnabled(enabled);
    this->ui->addHalfrowTop->setEnabled(enabled);
}

void MainWindow::on_openScheme_triggered()
{
    fileRead.readFile();
}

void MainWindow::on_saveScheme_triggered()
{
    fileWrite.writeFile(this->tabWidget.getCurrentScheme());
}

void MainWindow::on_zoomOut_triggered()
{
    static_cast<AbstractSchemeChartView*>(this->tabWidget.currentWidget())->zoomOut();
}

void MainWindow::on_zoomIn_triggered()
{
    static_cast<AbstractSchemeChartView*>(this->tabWidget.currentWidget())->zoomIn();
}

void MainWindow::on_movingDown_triggered()
{
    static_cast<AbstractSchemeChartView*>(this->tabWidget.currentWidget())->toBottom();
}

void MainWindow::on_movingUp_triggered()
{
    static_cast<AbstractSchemeChartView*>(this->tabWidget.currentWidget())->toTop();
}

void MainWindow::on_movingLeft_triggered()
{
    static_cast<AbstractSchemeChartView*>(this->tabWidget.currentWidget())->toLeft();
}

void MainWindow::on_movingRight_triggered()
{
    static_cast<AbstractSchemeChartView*>(this->tabWidget.currentWidget())->toRight();
}

void MainWindow::on_rotateLeft_triggered()
{
    static_cast<AbstractSchemeChartView*>(this->tabWidget.currentWidget())->rotateLeft();
}

void MainWindow::on_rotateRight_triggered()
{
    static_cast<AbstractSchemeChartView*>(this->tabWidget.currentWidget())->rotateRight();
}

void MainWindow::on_deleteScheme_triggered()
{
    this->tabWidget.deleteScheme();
}

void MainWindow::on_editScheme_triggered()
{
    this->tabWidget.editScheme();
}

void MainWindow::on_removeThreadLeft_triggered()
{
    static_cast<AbstractSchemeChartScene*>(static_cast<AbstractSchemeChartView*>(this->tabWidget.currentWidget())->scene())->editNodes(AbstractSchemeChartScene::Directions::REMOVE_LEFT, true);
}

void MainWindow::on_removeThreadRight_triggered()
{
    static_cast<AbstractSchemeChartScene*>(static_cast<AbstractSchemeChartView*>(this->tabWidget.currentWidget())->scene())->editNodes(AbstractSchemeChartScene::Directions::REMOVE_RIGHT, true);
}

void MainWindow::on_addThreadLeft_triggered()
{
    static_cast<AbstractSchemeChartScene*>(static_cast<AbstractSchemeChartView*>(this->tabWidget.currentWidget())->scene())->editNodes(AbstractSchemeChartScene::Directions::ADD_LEFT, true);
}

void MainWindow::on_addThreadRight_triggered()
{
    static_cast<AbstractSchemeChartScene*>(static_cast<AbstractSchemeChartView*>(this->tabWidget.currentWidget())->scene())->editNodes(AbstractSchemeChartScene::Directions::ADD_RIGHT, true);
}

void MainWindow::on_removeHalfrowDown_triggered()
{
    static_cast<AbstractSchemeChartScene*>(static_cast<AbstractSchemeChartView*>(this->tabWidget.currentWidget())->scene())->editNodes(AbstractSchemeChartScene::Directions::REMOVE_BOTTOM, true);
}

void MainWindow::on_removeHalfrowTop_triggered()
{
    static_cast<AbstractSchemeChartScene*>(static_cast<AbstractSchemeChartView*>(this->tabWidget.currentWidget())->scene())->editNodes(AbstractSchemeChartScene::Directions::REMOVE_TOP, true);
}

void MainWindow::on_addHalfrowDown_triggered()
{
    static_cast<AbstractSchemeChartScene*>(static_cast<AbstractSchemeChartView*>(this->tabWidget.currentWidget())->scene())->editNodes(AbstractSchemeChartScene::Directions::ADD_BOTTOM, true);
}

void MainWindow::on_addHalfrowTop_triggered()
{
    static_cast<AbstractSchemeChartScene*>(static_cast<AbstractSchemeChartView*>(this->tabWidget.currentWidget())->scene())->editNodes(AbstractSchemeChartScene::Directions::ADD_TOP, true);
}

void MainWindow::updateMenu(int index)
{
    if (index == -1) {
        this->ui->saveScheme->setEnabled(false);

        this->ui->zoomIn->setEnabled(false);
        this->ui->zoomOut->setEnabled(false);

        this->ui->movingDown->setEnabled(false);
        this->ui->movingUp->setEnabled(false);
        this->ui->movingLeft->setEnabled(false);
        this->ui->movingRight->setEnabled(false);

        this->ui->rotateRight->setEnabled(false);
        this->ui->rotateLeft->setEnabled(false);

        this->ui->deleteScheme->setEnabled(false);
        this->ui->editScheme->setEnabled(false);

        this->ui->addHalfrowDown->setEnabled(false);
        this->ui->addHalfrowTop->setEnabled(false);
        this->ui->addThreadLeft->setEnabled(false);
        this->ui->addThreadRight->setEnabled(false);

        this->ui->removeHalfrowDown->setEnabled(false);
        this->ui->removeHalfrowTop->setEnabled(false);
        this->ui->removeThreadLeft->setEnabled(false);
        this->ui->removeThreadRight->setEnabled(false);
    } else {
        this->ui->saveScheme->setEnabled(true);

        this->ui->zoomIn->setEnabled(true);
        this->ui->zoomOut->setEnabled(true);

        this->ui->movingDown->setEnabled(true);
        this->ui->movingUp->setEnabled(true);
        this->ui->movingLeft->setEnabled(true);
        this->ui->movingRight->setEnabled(true);

        this->ui->rotateRight->setEnabled(true);
        this->ui->rotateLeft->setEnabled(true);

        this->ui->deleteScheme->setEnabled(true);
        this->ui->editScheme->setEnabled(true);

        this->ui->addHalfrowDown->setEnabled(true);
        this->ui->addHalfrowTop->setEnabled(true);
        this->ui->addThreadLeft->setEnabled(true);
        this->ui->addThreadRight->setEnabled(true);

        this->ui->removeHalfrowDown->setEnabled(true);
        this->ui->removeHalfrowTop->setEnabled(true);
        this->ui->removeThreadLeft->setEnabled(true);
        this->ui->removeThreadRight->setEnabled(true);
    }
}
