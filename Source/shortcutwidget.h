#ifndef SHORTCUTWIDGET_H
#define SHORTCUTWIDGET_H

#include <QLabel>
#include <QKeySequenceEdit>
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

    QLabel verticalLayoutLabel;
    QLabel verticalLayoutKeySequenceEdit_1;
    QLabel verticalLayoutKeySequenceEdit_2;
    QLabel verticalLayoutKeySequenceEdit_3;
    QLabel verticalLayoutKeySequenceEdit_4;

    QLabel labelName;

    QLabel labelOpenFile;
    QKeySequenceEdit KeySequenceEditOpenFile_1;
    QKeySequenceEdit KeySequenceEditOpenFile_2;
    QKeySequenceEdit KeySequenceEditOpenFile_3;
    QKeySequenceEdit KeySequenceEditOpenFile_4;

    QLabel labelSaveOpenScheme;
    QKeySequenceEdit KeySequenceEditSaveOpenScheme_1;
    QKeySequenceEdit KeySequenceEditSaveOpenScheme_2;
    QKeySequenceEdit KeySequenceEditSaveOpenScheme_3;
    QKeySequenceEdit KeySequenceEditSaveOpenScheme_4;

    QLabel labelDeleteOpenScheme;
    QKeySequenceEdit KeySequenceEditDeleteOpenScheme_1;
    QKeySequenceEdit KeySequenceEditDeleteOpenScheme_2;
    QKeySequenceEdit KeySequenceEditDeleteOpenScheme_3;
    QKeySequenceEdit KeySequenceEditDeleteOpenScheme_4;

    QLabel labelShortcutWidget;
    QKeySequenceEdit KeySequenceEditShortcutWidget_1;
    QKeySequenceEdit KeySequenceEditShortcutWidget_2;
    QKeySequenceEdit KeySequenceEditShortcutWidget_3;
    QKeySequenceEdit KeySequenceEditShortcutWidget_4;
};

#endif // SHORTCUTWIDGET_H
