#ifndef SHORTCUTWIDGET_H
#define SHORTCUTWIDGET_H

#include <QLabel>
#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QScrollArea>
#include <QGridLayout>
#include <QKeySequenceEdit>

class ShortcutWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ShortcutWidget();
    ~ShortcutWidget();

signals:
    void clickedSetDefaultShortcut();
    void clickedCancel();
    void clickedSave();

protected:
    void showEvent(QShowEvent *event) override;
    void closeEvent(QCloseEvent *event) override;

private slots:
    void onClickedSetDefaultShortcut();
    void onClickedCancel();
    void onClickedSave();

private:
    QGridLayout gridLayout;

    QPushButton setDefaultShortcut;
    QPushButton cancel;
    QPushButton save;

    QScrollArea scrollArea;
    QWidget widgetScrollArea;
    QGridLayout widgetScrollAreaGridLayout;
    QGridLayout gridLayouWidgetScrollArea;

    QLabel verticalLayoutKeySequenceEdit_1;
    QLabel verticalLayoutKeySequenceEdit_2;
    QLabel verticalLayoutKeySequenceEdit_3;
    QLabel verticalLayoutKeySequenceEdit_4;

    QLabel labelName;

    QLabel labelOpenFile;
    QKeySequenceEdit keySequenceEditOpenFile_1;
    QKeySequenceEdit keySequenceEditOpenFile_2;
    QKeySequenceEdit keySequenceEditOpenFile_3;
    QKeySequenceEdit keySequenceEditOpenFile_4;

    QLabel labelSaveOpenScheme;
    QKeySequenceEdit keySequenceEditSaveOpenScheme_1;
    QKeySequenceEdit keySequenceEditSaveOpenScheme_2;
    QKeySequenceEdit keySequenceEditSaveOpenScheme_3;
    QKeySequenceEdit keySequenceEditSaveOpenScheme_4;

    QLabel labelDeleteOpenScheme;
    QKeySequenceEdit keySequenceEditDeleteOpenScheme_1;
    QKeySequenceEdit keySequenceEditDeleteOpenScheme_2;
    QKeySequenceEdit keySequenceEditDeleteOpenScheme_3;
    QKeySequenceEdit keySequenceEditDeleteOpenScheme_4;

    QLabel labelShortcutWidget;
    QKeySequenceEdit keySequenceEditShortcutWidget_1;
    QKeySequenceEdit keySequenceEditShortcutWidget_2;
    QKeySequenceEdit keySequenceEditShortcutWidget_3;
    QKeySequenceEdit keySequenceEditShortcutWidget_4;

    QList<QKeySequenceEdit*> listShortcutOpenFile;
    QList<QKeySequenceEdit*> listShortcutEditSaveOpenScheme;
    QList<QKeySequenceEdit*> listShortcutDeleteOpenScheme;
    QList<QKeySequenceEdit*> listShortcutShortcutWidget;

    void setShortcutInWidget();
    void saveShortcutInFile();
};

#endif // SHORTCUTWIDGET_H
