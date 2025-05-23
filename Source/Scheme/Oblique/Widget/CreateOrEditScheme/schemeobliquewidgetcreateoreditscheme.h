#ifndef SCHEMEOBLIQUEWIDGETCREATEOREDITSCHEME_H
#define SCHEMEOBLIQUEWIDGETCREATEOREDITSCHEME_H

#include <QWidget>

#include "Abstract/abstractschemewidgetcreateoreditscheme.h"

namespace Ui {
class SchemeObliqueWidgetCreateOrEditScheme;
}

class SchemeObliqueWidgetCreateOrEditScheme : public AbstractSchemeWidgetCreateOrEditScheme
{
    Q_OBJECT

public:
    explicit SchemeObliqueWidgetCreateOrEditScheme();
    ~SchemeObliqueWidgetCreateOrEditScheme();

public slots:
    void createIn();

private slots:
    void on_cancel_clicked();
    void on_create_clicked();

private:
    Ui::SchemeObliqueWidgetCreateOrEditScheme *ui;
};

#endif // SCHEMEOBLIQUEWIDGETCREATEOREDITSCHEME_H
