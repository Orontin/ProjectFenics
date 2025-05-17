#include "editdirectionfornewnodewindow.h"
#include "ui_editdirectionfornewnodewindow.h"

EditDirectionForNewNodeWindow::EditDirectionForNewNodeWindow(QList<AbstractScheme*> &schemes, QWidget *parent):
    QWidget(parent),
    ui(new Ui::EditDirectionForNewNodeWindow),
    schemes(schemes)
{
    ui->setupUi(this);

    this->setWindowModality(Qt::ApplicationModal);

    this->setWindowTitle("Изменить направление новых узлов");
}

EditDirectionForNewNodeWindow::~EditDirectionForNewNodeWindow()
{
    delete this->ui;
}

void EditDirectionForNewNodeWindow::open(const QString &typeScheme)
{
    for (AbstractScheme *scheme : schemes) {
        if (scheme->typeScheme == typeScheme) {
            this->ui->centralWidget->addWidget(scheme->editDirectionForNewNodeView);
            break;
        }
    }
    this->show();
}
