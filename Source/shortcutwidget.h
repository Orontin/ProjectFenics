#ifndef SHORTCUTWIDGET_H
#define SHORTCUTWIDGET_H

#include <QLabel>
#include <QLineEdit>
#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QSpacerItem>

class ShortcutWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ShortcutWidget();
    ~ShortcutWidget();

private:
    QGridLayout gridLayout;

    QGroupBox groupBoxCommonShortcut;
    QGridLayout gridLayoutGroupBoxCommonShortcut;

    QVBoxLayout verticalLayoutLabel;
    QVBoxLayout verticalLayoutLineEdit;

    QLabel labelOpenFile;
    QLabel labelSaveOpenScheme;
    QLabel labelDeleteOpenScheme;
    QLabel labelShortcutWidget;

    QLineEdit lineEditOpenFile;
    QLineEdit lineEditSaveOpenScheme;
    QLineEdit lineEditDeleteOpenScheme;
    QLineEdit lineShortcutWidget;

    QSpacerItem verticalSpacer;
};

#endif // SHORTCUTWIDGET_H
