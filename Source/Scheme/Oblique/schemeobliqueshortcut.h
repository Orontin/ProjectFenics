#ifndef SCHEMEOBLIQUESHORTCUT_H
#define SCHEMEOBLIQUESHORTCUT_H

#include <QObject>
#include <QLabel>
#include <QGridLayout>
#include <QKeySequenceEdit>

class SchemeObliqueShortcut : public QObject
{
    Q_OBJECT
public:
    static SchemeObliqueShortcut &getInstance();

    void setShortcut(QGridLayout &gridLayouShortcut);

    void setDefaultShortcutInWidget();
    void setShortcutInWidget();
    void saveShortcutInFile();

private:
    SchemeObliqueShortcut();
    ~SchemeObliqueShortcut();

    void setInWidget(QList<QKeySequence> listShortcutSceneCreate,
                     QList<QKeySequence> listShortcutHistoryBack,
                     QList<QKeySequence> listShortcutHistoryNext,
                     QList<QKeySequence> listShortcutSceneThreadRemoveLeft,
                     QList<QKeySequence> listShortcutSceneThreadRemoveRight,
                     QList<QKeySequence> listShortcutSceneThreadAddLeft,
                     QList<QKeySequence> listShortcutSceneThreadAddRight,
                     QList<QKeySequence> listShortcutSceneHalfrowRemoveDown,
                     QList<QKeySequence> listShortcutSceneHalfrowRemoveTop,
                     QList<QKeySequence> listShortcutSceneHalfrowAddDown,
                     QList<QKeySequence> listShortcutSceneHalfrowAddTop,
                     QList<QKeySequence> listShortcutSceneEditDirectionNewNode,
                     QList<QKeySequence> listShortcutSceneColorMap,
                     QList<QKeySequence> listShortcutViewZoomOut,
                     QList<QKeySequence> listShortcutViewZoomIn,
                     QList<QKeySequence> listShortcutViewToBottom,
                     QList<QKeySequence> listShortcutViewToTop,
                     QList<QKeySequence> listShortcutViewToLeft,
                     QList<QKeySequence> listShortcutViewToRight,
                     QList<QKeySequence> listShortcutViewRotateLeft,
                     QList<QKeySequence> listShortcutViewRotateRight);

    static SchemeObliqueShortcut *schemeObliqueShortcut;

    QLabel labelName;
    QLabel labelCommon;
    QLabel labelView;
    QLabel labelHistory;
    QLabel labelManagment;

    QLabel labelCreate;
    QKeySequenceEdit keySequenceEditCreate_1;
    QKeySequenceEdit keySequenceEditCreate_2;
    QKeySequenceEdit keySequenceEditCreate_3;
    QKeySequenceEdit keySequenceEditCreate_4;

    QLabel labelEditDirectionNewNode;
    QKeySequenceEdit keySequenceEditEditDirectionNewNode_1;
    QKeySequenceEdit keySequenceEditEditDirectionNewNode_2;
    QKeySequenceEdit keySequenceEditEditDirectionNewNode_3;
    QKeySequenceEdit keySequenceEditEditDirectionNewNode_4;

    QLabel labelColorMap;
    QKeySequenceEdit keySequenceEditColorMap_1;
    QKeySequenceEdit keySequenceEditColorMap_2;
    QKeySequenceEdit keySequenceEditColorMap_3;
    QKeySequenceEdit keySequenceEditColorMap_4;

    QLabel labelZoomOut;
    QKeySequenceEdit keySequenceEditZoomOut_1;
    QKeySequenceEdit keySequenceEditZoomOut_2;
    QKeySequenceEdit keySequenceEditZoomOut_3;
    QKeySequenceEdit keySequenceEditZoomOut_4;

    QLabel labelZoomIn;
    QKeySequenceEdit keySequenceEditZoomIn_1;
    QKeySequenceEdit keySequenceEditZoomIn_2;
    QKeySequenceEdit keySequenceEditZoomIn_3;
    QKeySequenceEdit keySequenceEditZoomIn_4;

    QLabel labelToBottom;
    QKeySequenceEdit keySequenceEditToBottom_1;
    QKeySequenceEdit keySequenceEditToBottom_2;
    QKeySequenceEdit keySequenceEditToBottom_3;
    QKeySequenceEdit keySequenceEditToBottom_4;

    QLabel labelToTop;
    QKeySequenceEdit keySequenceEditToTop_1;
    QKeySequenceEdit keySequenceEditToTop_2;
    QKeySequenceEdit keySequenceEditToTop_3;
    QKeySequenceEdit keySequenceEditToTop_4;

    QLabel labelToLeft;
    QKeySequenceEdit keySequenceEditToLeft_1;
    QKeySequenceEdit keySequenceEditToLeft_2;
    QKeySequenceEdit keySequenceEditToLeft_3;
    QKeySequenceEdit keySequenceEditToLeft_4;

    QLabel labelToRight;
    QKeySequenceEdit keySequenceEditToRight_1;
    QKeySequenceEdit keySequenceEditToRight_2;
    QKeySequenceEdit keySequenceEditToRight_3;
    QKeySequenceEdit keySequenceEditToRight_4;

    QLabel labelRotateLeft;
    QKeySequenceEdit keySequenceEditRotateLeft_1;
    QKeySequenceEdit keySequenceEditRotateLeft_2;
    QKeySequenceEdit keySequenceEditRotateLeft_3;
    QKeySequenceEdit keySequenceEditRotateLeft_4;

    QLabel labelRotateRight;
    QKeySequenceEdit keySequenceEditRotateRight_1;
    QKeySequenceEdit keySequenceEditRotateRight_2;
    QKeySequenceEdit keySequenceEditRotateRight_3;
    QKeySequenceEdit keySequenceEditRotateRight_4;

    QLabel labelBack;
    QKeySequenceEdit keySequenceEditBack_1;
    QKeySequenceEdit keySequenceEditBack_2;
    QKeySequenceEdit keySequenceEditBack_3;
    QKeySequenceEdit keySequenceEditBack_4;

    QLabel labelNext;
    QKeySequenceEdit keySequenceEditNext_1;
    QKeySequenceEdit keySequenceEditNext_2;
    QKeySequenceEdit keySequenceEditNext_3;
    QKeySequenceEdit keySequenceEditNext_4;

    QLabel labelRemoveThreadLeft;
    QKeySequenceEdit keySequenceEditRemoveThreadLeft_1;
    QKeySequenceEdit keySequenceEditRemoveThreadLeft_2;
    QKeySequenceEdit keySequenceEditRemoveThreadLeft_3;
    QKeySequenceEdit keySequenceEditRemoveThreadLeft_4;

    QLabel labelRemoveThreadRight;
    QKeySequenceEdit keySequenceEditRemoveThreadRight_1;
    QKeySequenceEdit keySequenceEditRemoveThreadRight_2;
    QKeySequenceEdit keySequenceEditRemoveThreadRight_3;
    QKeySequenceEdit keySequenceEditRemoveThreadRight_4;

    QLabel labelAddThreadLeft;
    QKeySequenceEdit keySequenceEditAddThreadLeft_1;
    QKeySequenceEdit keySequenceEditAddThreadLeft_2;
    QKeySequenceEdit keySequenceEditAddThreadLeft_3;
    QKeySequenceEdit keySequenceEditAddThreadLeft_4;

    QLabel labelAddThreadRight;
    QKeySequenceEdit keySequenceEditAddThreadRight_1;
    QKeySequenceEdit keySequenceEditAddThreadRight_2;
    QKeySequenceEdit keySequenceEditAddThreadRight_3;
    QKeySequenceEdit keySequenceEditAddThreadRight_4;

    QLabel labelRemoveHalfrowDown;
    QKeySequenceEdit keySequenceEditRemoveHalfrowDown_1;
    QKeySequenceEdit keySequenceEditRemoveHalfrowDown_2;
    QKeySequenceEdit keySequenceEditRemoveHalfrowDown_3;
    QKeySequenceEdit keySequenceEditRemoveHalfrowDown_4;

    QLabel labelRemoveHalfrowTop;
    QKeySequenceEdit keySequenceEditRemoveHalfrowTop_1;
    QKeySequenceEdit keySequenceEditRemoveHalfrowTop_2;
    QKeySequenceEdit keySequenceEditRemoveHalfrowTop_3;
    QKeySequenceEdit keySequenceEditRemoveHalfrowTop_4;

    QLabel labelAddHalfrowDown;
    QKeySequenceEdit keySequenceEditAddHalfrowDown_1;
    QKeySequenceEdit keySequenceEditAddHalfrowDown_2;
    QKeySequenceEdit keySequenceEditAddHalfrowDown_3;
    QKeySequenceEdit keySequenceEditAddHalfrowDown_4;

    QLabel labelAddHalfrowTop;
    QKeySequenceEdit keySequenceEditAddHalfrowTop_1;
    QKeySequenceEdit keySequenceEditAddHalfrowTop_2;
    QKeySequenceEdit keySequenceEditAddHalfrowTop_3;
    QKeySequenceEdit keySequenceEditAddHalfrowTop_4;
};

#endif // SCHEMEOBLIQUESHORTCUT_H
