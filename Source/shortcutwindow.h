#ifndef SHORTCUTWINDOW_H
#define SHORTCUTWINDOW_H

#include <QLabel>
#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QScrollArea>
#include <QGridLayout>
#include <QKeySequenceEdit>

class ShortcutWindow : public QWidget
{
    Q_OBJECT

public:
    static ShortcutWindow &getInstance();

    QGridLayout &getGridLayouWidgetScrollArea();

    void open();

signals:
    void clickedShortcutSetDefaultShortcut();
    void clickedShortcutCancel();
    void clickedShortcutSave();

protected:
    void showEvent(QShowEvent *event) override final;
    void closeEvent(QCloseEvent *event) override final;
    void moveEvent(QMoveEvent *event) override final;
    void resizeEvent(QResizeEvent *event) override final;

private slots:
    void onClickedSetDefaultShortcut();
    void onClickedCancel();
    void onClickedSave();

private:
    explicit ShortcutWindow();
    ~ShortcutWindow();

    void setDefaultShortcutInWidget();
    void setShortcutInWidget();
    void setInWidget(QList<QKeySequence> &listShortcutOpenFile, QList<QKeySequence> &listShortcutEditSaveOpenScheme, QList<QKeySequence> &listShortcutDeleteOpenScheme, QList<QKeySequence> &listShortcutShortcutWidget);
    void saveShortcutInFile();

    void visible();
    void setPosition();

    QGridLayout gridLayout;

    QPushButton setDefaultShortcut;
    QPushButton cancel;
    QPushButton save;

    QScrollArea scrollArea;
    QWidget widgetScrollArea;
    QGridLayout widgetScrollAreaGridLayout;
    QGridLayout gridLayouWidgetScrollArea;

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

    static ShortcutWindow *shortcutWindow;
};

#endif // SHORTCUTWINDOW_H
