#ifndef EDITDIRECTIONFORNEWNODEWINDOW_H
#define EDITDIRECTIONFORNEWNODEWINDOW_H

#include <QWidget>

#include "Abstract/abstractscheme.h"

namespace Ui {
class EditDirectionForNewNodeWindow;
}

class EditDirectionForNewNodeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EditDirectionForNewNodeWindow(QList<AbstractScheme*> &schemes, QWidget *parent = nullptr);
    ~EditDirectionForNewNodeWindow();

    void open(const QString &typeScheme);

private:
    Ui::EditDirectionForNewNodeWindow *ui;

    QList<AbstractScheme*> &schemes;
};

#endif // EDITDIRECTIONFORNEWNODEWINDOW_H
