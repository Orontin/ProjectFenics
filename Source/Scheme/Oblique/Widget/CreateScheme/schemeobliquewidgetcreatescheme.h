#ifndef SCHEMEOBLIQUEWIDGETCREATESCHEME_H
#define SCHEMEOBLIQUEWIDGETCREATESCHEME_H

#include <QWidget>

#include "Abstract/abstractschemewidgetcreatescheme.h"

namespace Ui {
class SchemeObliqueWidgetCreateScheme;
}

class SchemeObliqueWidgetCreateScheme : public AbstractSchemeWidgetCreateScheme
{
    Q_OBJECT

public:
    explicit SchemeObliqueWidgetCreateScheme();
    ~SchemeObliqueWidgetCreateScheme();

public slots:
    void createIn();

private slots:
    void onCancelClicked();
    void onCreateClicked();

private:
    Ui::SchemeObliqueWidgetCreateScheme *ui;
};

#endif // SCHEMEOBLIQUEWIDGETCREATESCHEME_H
