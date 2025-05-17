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
    void editIn(AbstractSchemeChartView &view);

private slots:
    void on_createOrEdit_clicked();
    void on_cancel_clicked();

private:
    Ui::SchemeObliqueWidgetCreateOrEditScheme *ui;
};

#endif // SCHEMEOBLIQUEWIDGETCREATEOREDITSCHEME_H
