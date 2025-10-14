#include "schemeobliqueshortcut.h"

#include "Scheme/Oblique/File/Setting/schemeobliquefilesetting.h"

SchemeObliqueShortcut *SchemeObliqueShortcut::schemeObliqueShortcut{nullptr};

SchemeObliqueShortcut &SchemeObliqueShortcut::getInstance()
{
    if (!SchemeObliqueShortcut::schemeObliqueShortcut) {
        SchemeObliqueShortcut::schemeObliqueShortcut = new SchemeObliqueShortcut;
    }
    return *SchemeObliqueShortcut::schemeObliqueShortcut;
}

void SchemeObliqueShortcut::setShortcut(QGridLayout &gridLayouShortcut)
{

    int rowCount = gridLayouShortcut.rowCount();

    this->labelName.setText(" --- Сочетания клавиш усложненной косой схемы --- ");
    this->labelName.setAlignment(Qt::AlignCenter);
    this->labelName.setStyleSheet("font-weight: bold; text-decoration: underline; font-style: italic;");
    gridLayouShortcut.addWidget(&this->labelName, rowCount, 0, 1, gridLayouShortcut.columnCount());

    rowCount = gridLayouShortcut.rowCount();
    this->labelCommon.setAlignment(Qt::AlignCenter);
    this->labelCommon.setStyleSheet("font-weight: bold; text-decoration: underline;");
    this->labelCommon.setText(" -- Общие -- ");
    gridLayouShortcut.addWidget(&this->labelCommon, rowCount, 0, 1, gridLayouShortcut.columnCount());

    rowCount = gridLayouShortcut.rowCount();
    this->labelCreate.setText("Создать новую схему");
    gridLayouShortcut.addWidget(&this->labelCreate, rowCount, 0, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditCreate_1, rowCount, 1, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditCreate_2, rowCount, 2, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditCreate_3, rowCount, 3, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditCreate_4, rowCount, 4, 1, 1);

    rowCount = gridLayouShortcut.rowCount();
    this->labelEditDirectionNewNode.setText("Изменить направление для новых узлов");
    gridLayouShortcut.addWidget(&this->labelEditDirectionNewNode, rowCount, 0, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditEditDirectionNewNode_1, rowCount, 1, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditEditDirectionNewNode_2, rowCount, 2, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditEditDirectionNewNode_3, rowCount, 3, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditEditDirectionNewNode_4, rowCount, 4, 1, 1);

    rowCount = gridLayouShortcut.rowCount();
    this->labelView.setAlignment(Qt::AlignCenter);
    this->labelView.setStyleSheet("font-weight: bold; text-decoration: underline;");
    this->labelView.setText(" -- Вид -- ");
    gridLayouShortcut.addWidget(&this->labelView, rowCount, 0, 1, gridLayouShortcut.columnCount());

    rowCount = gridLayouShortcut.rowCount();
    this->labelZoomOut.setText("Отдалить");
    gridLayouShortcut.addWidget(&this->labelZoomOut, rowCount, 0, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditZoomOut_1, rowCount, 1, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditZoomOut_2, rowCount, 2, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditZoomOut_3, rowCount, 3, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditZoomOut_4, rowCount, 4, 1, 1);

    rowCount = gridLayouShortcut.rowCount();
    this->labelZoomIn.setText("Приблизить");
    gridLayouShortcut.addWidget(&this->labelZoomIn, rowCount, 0, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditZoomIn_1, rowCount, 1, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditZoomIn_2, rowCount, 2, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditZoomIn_3, rowCount, 3, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditZoomIn_4, rowCount, 4, 1, 1);

    rowCount = gridLayouShortcut.rowCount();
    this->labelToBottom.setText("Вниз");
    gridLayouShortcut.addWidget(&this->labelToBottom, rowCount, 0, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditToBottom_1, rowCount, 1, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditToBottom_2, rowCount, 2, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditToBottom_3, rowCount, 3, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditToBottom_4, rowCount, 4, 1, 1);

    rowCount = gridLayouShortcut.rowCount();
    this->labelToTop.setText("Вверх");
    gridLayouShortcut.addWidget(&this->labelToTop, rowCount, 0, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditToTop_1, rowCount, 1, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditToTop_2, rowCount, 2, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditToTop_3, rowCount, 3, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditToTop_4, rowCount, 4, 1, 1);

    rowCount = gridLayouShortcut.rowCount();
    this->labelToLeft.setText("Влево");
    gridLayouShortcut.addWidget(&this->labelToLeft, rowCount, 0, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditToLeft_1, rowCount, 1, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditToLeft_2, rowCount, 2, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditToLeft_3, rowCount, 3, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditToLeft_4, rowCount, 4, 1, 1);

    rowCount = gridLayouShortcut.rowCount();
    this->labelToRight.setText("Вправо");
    gridLayouShortcut.addWidget(&this->labelToRight, rowCount, 0, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditToRight_1, rowCount, 1, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditToRight_2, rowCount, 2, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditToRight_3, rowCount, 3, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditToRight_4, rowCount, 4, 1, 1);

    rowCount = gridLayouShortcut.rowCount();
    this->labelRotateLeft.setText("Повернуть влево");
    gridLayouShortcut.addWidget(&this->labelRotateLeft, rowCount, 0, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditRotateLeft_1, rowCount, 1, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditRotateLeft_2, rowCount, 2, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditRotateLeft_3, rowCount, 3, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditRotateLeft_4, rowCount, 4, 1, 1);

    rowCount = gridLayouShortcut.rowCount();
    this->labelRotateRight.setText("Повернуть вправо");
    gridLayouShortcut.addWidget(&this->labelRotateRight, rowCount, 0, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditRotateRight_1, rowCount, 1, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditRotateRight_2, rowCount, 2, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditRotateRight_3, rowCount, 3, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditRotateRight_4, rowCount, 4, 1, 1);

    rowCount = gridLayouShortcut.rowCount();
    this->labelHistory.setAlignment(Qt::AlignCenter);
    this->labelHistory.setStyleSheet("font-weight: bold; text-decoration: underline;");
    this->labelHistory.setText(" -- История -- ");
    gridLayouShortcut.addWidget(&this->labelHistory, rowCount, 0, 1, gridLayouShortcut.columnCount());

    rowCount = gridLayouShortcut.rowCount();
    this->labelBack.setText("Назад");
    gridLayouShortcut.addWidget(&this->labelBack, rowCount, 0, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditBack_1, rowCount, 1, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditBack_2, rowCount, 2, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditBack_3, rowCount, 3, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditBack_4, rowCount, 4, 1, 1);

    rowCount = gridLayouShortcut.rowCount();
    this->labelNext.setText("Вперед");
    gridLayouShortcut.addWidget(&this->labelNext, rowCount, 0, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditNext_1, rowCount, 1, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditNext_2, rowCount, 2, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditNext_3, rowCount, 3, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditNext_4, rowCount, 4, 1, 1);

    rowCount = gridLayouShortcut.rowCount();
    this->labelManagment.setAlignment(Qt::AlignCenter);
    this->labelManagment.setStyleSheet("font-weight: bold; text-decoration: underline;");
    this->labelManagment.setText(" -- Управление -- ");
    gridLayouShortcut.addWidget(&this->labelManagment, rowCount, 0, 1, gridLayouShortcut.columnCount());

    rowCount = gridLayouShortcut.rowCount();
    this->labelRemoveThreadLeft.setText("Убрать нить слева");
    gridLayouShortcut.addWidget(&this->labelRemoveThreadLeft, rowCount, 0, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditRemoveThreadLeft_1, rowCount, 1, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditRemoveThreadLeft_2, rowCount, 2, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditRemoveThreadLeft_3, rowCount, 3, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditRemoveThreadLeft_4, rowCount, 4, 1, 1);

    rowCount = gridLayouShortcut.rowCount();
    this->labelRemoveThreadRight.setText("Убрать нить справа");
    gridLayouShortcut.addWidget(&this->labelRemoveThreadRight, rowCount, 0, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditRemoveThreadRight_1, rowCount, 1, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditRemoveThreadRight_2, rowCount, 2, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditRemoveThreadRight_3, rowCount, 3, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditRemoveThreadRight_4, rowCount, 4, 1, 1);

    rowCount = gridLayouShortcut.rowCount();
    this->labelAddThreadLeft.setText("Добавить нить слева");
    gridLayouShortcut.addWidget(&this->labelAddThreadLeft, rowCount, 0, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditAddThreadLeft_1, rowCount, 1, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditAddThreadLeft_2, rowCount, 2, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditAddThreadLeft_3, rowCount, 3, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditAddThreadLeft_4, rowCount, 4, 1, 1);

    rowCount = gridLayouShortcut.rowCount();
    this->labelAddThreadRight.setText("Добавить нить справа");
    gridLayouShortcut.addWidget(&this->labelAddThreadRight, rowCount, 0, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditAddThreadRight_1, rowCount, 1, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditAddThreadRight_2, rowCount, 2, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditAddThreadRight_3, rowCount, 3, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditAddThreadRight_4, rowCount, 4, 1, 1);

    rowCount = gridLayouShortcut.rowCount();
    this->labelRemoveHalfrowDown.setText("Убрать полуряд снизу");
    gridLayouShortcut.addWidget(&this->labelRemoveHalfrowDown, rowCount, 0, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditRemoveHalfrowDown_1, rowCount, 1, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditRemoveHalfrowDown_2, rowCount, 2, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditRemoveHalfrowDown_3, rowCount, 3, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditRemoveHalfrowDown_4, rowCount, 4, 1, 1);

    rowCount = gridLayouShortcut.rowCount();
    this->labelRemoveHalfrowTop.setText("Убрать полуряд сверху");
    gridLayouShortcut.addWidget(&this->labelRemoveHalfrowTop, rowCount, 0, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditRemoveHalfrowTop_1, rowCount, 1, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditRemoveHalfrowTop_2, rowCount, 2, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditRemoveHalfrowTop_3, rowCount, 3, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditRemoveHalfrowTop_4, rowCount, 4, 1, 1);

    rowCount = gridLayouShortcut.rowCount();
    this->labelAddHalfrowDown.setText("Добавить полуряд снизу");
    gridLayouShortcut.addWidget(&this->labelAddHalfrowDown, rowCount, 0, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditAddHalfrowDown_1, rowCount, 1, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditAddHalfrowDown_2, rowCount, 2, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditAddHalfrowDown_3, rowCount, 3, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditAddHalfrowDown_4, rowCount, 4, 1, 1);

    rowCount = gridLayouShortcut.rowCount();
    this->labelAddHalfrowTop.setText("Добавить полуряд сверху");
    gridLayouShortcut.addWidget(&this->labelAddHalfrowTop, rowCount, 0, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditAddHalfrowTop_1, rowCount, 1, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditAddHalfrowTop_2, rowCount, 2, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditAddHalfrowTop_3, rowCount, 3, 1, 1);
    gridLayouShortcut.addWidget(&this->keySequenceEditAddHalfrowTop_4, rowCount, 4, 1, 1);
}

void SchemeObliqueShortcut::setDefaultShortcutInWidget()
{
    QList<QKeySequence> listShortcutSceneCreate = SchemeObliqueFileSetting::getListDefaultShortcutActionSchemeObliqueShortcutSceneCreate();
    QList<QKeySequence> listShortcutHistoryBack = SchemeObliqueFileSetting::getListDefaultShortcutActionSchemeObliqueShortcutHistoryBack();
    QList<QKeySequence> listShortcutHistoryNext = SchemeObliqueFileSetting::getListDefaultShortcutActionSchemeObliqueShortcutHistoryNext();
    QList<QKeySequence> listShortcutSceneThreadRemoveLeft = SchemeObliqueFileSetting::getListDefaultShortcutActionSchemeObliqueShortcutSceneThreadRemoveLeft();
    QList<QKeySequence> listShortcutSceneThreadRemoveRight = SchemeObliqueFileSetting::getListDefaultShortcutActionSchemeObliqueShortcutSceneThreadRemoveRight();
    QList<QKeySequence> listShortcutSceneThreadAddLeft = SchemeObliqueFileSetting::getListDefaultShortcutActionSchemeObliqueShortcutSceneThreadAddLeft();
    QList<QKeySequence> listShortcutSceneThreadAddRight = SchemeObliqueFileSetting::getListDefaultShortcutActionSchemeObliqueShortcutSceneThreadAddRight();
    QList<QKeySequence> listShortcutSceneHalfrowRemoveDown = SchemeObliqueFileSetting::getListDefaultShortcutActionSchemeObliqueShortcutSceneHalfrowRemoveDown();
    QList<QKeySequence> listShortcutSceneHalfrowRemoveTop = SchemeObliqueFileSetting::getListDefaultShortcutActionSchemeObliqueShortcutSceneHalfrowRemoveTop();
    QList<QKeySequence> listShortcutSceneHalfrowAddDown = SchemeObliqueFileSetting::getListDefaultShortcutActionSchemeObliqueShortcutSceneHalfrowAddDown();
    QList<QKeySequence> listShortcutSceneHalfrowAddTop = SchemeObliqueFileSetting::getListDefaultShortcutActionSchemeObliqueShortcutSceneHalfrowAddTop();
    QList<QKeySequence> listShortcutSceneEditDirectionNewNode = SchemeObliqueFileSetting::getListDefaultShortcutActionSchemeObliqueShortcutSceneEditDirectionNewNode();
    QList<QKeySequence> listShortcutViewZoomOut = SchemeObliqueFileSetting::getListDefaultShortcutActionSchemeObliqueShortcutViewZoomOut();
    QList<QKeySequence> listShortcutViewZoomIn = SchemeObliqueFileSetting::getListDefaultShortcutActionSchemeObliqueShortcutViewZoomIn();
    QList<QKeySequence> listShortcutViewToBottom = SchemeObliqueFileSetting::getListDefaultShortcutActionSchemeObliqueShortcutViewToBottom();
    QList<QKeySequence> listShortcutViewToTop = SchemeObliqueFileSetting::getListDefaultShortcutActionSchemeObliqueShortcutViewToTop();
    QList<QKeySequence> listShortcutViewToLeft = SchemeObliqueFileSetting::getListDefaultShortcutActionSchemeObliqueShortcutViewToLeft();
    QList<QKeySequence> listShortcutViewToRight = SchemeObliqueFileSetting::getListDefaultShortcutActionSchemeObliqueShortcutViewToRight();
    QList<QKeySequence> listShortcutViewRotateLeft = SchemeObliqueFileSetting::getListDefaultShortcutActionSchemeObliqueShortcutViewRotateLeft();
    QList<QKeySequence> listShortcutViewRotateRight = SchemeObliqueFileSetting::getListDefaultShortcutActionSchemeObliqueShortcutViewRotateRight();

    this->setInWidget(listShortcutSceneCreate,
                      listShortcutHistoryBack,
                      listShortcutHistoryNext,
                      listShortcutSceneThreadRemoveLeft,
                      listShortcutSceneThreadRemoveRight,
                      listShortcutSceneThreadAddLeft,
                      listShortcutSceneThreadAddRight,
                      listShortcutSceneHalfrowRemoveDown,
                      listShortcutSceneHalfrowRemoveTop,
                      listShortcutSceneHalfrowAddDown,
                      listShortcutSceneHalfrowAddTop,
                      listShortcutSceneEditDirectionNewNode,
                      listShortcutViewZoomOut,
                      listShortcutViewZoomIn,
                      listShortcutViewToBottom,
                      listShortcutViewToTop,
                      listShortcutViewToLeft,
                      listShortcutViewToRight,
                      listShortcutViewRotateLeft,
                      listShortcutViewRotateRight);
}

void SchemeObliqueShortcut::setShortcutInWidget()
{
    QList<QKeySequence> listShortcutSceneCreate = SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutSceneCreate();
    QList<QKeySequence> listShortcutHistoryBack = SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutHistoryBack();
    QList<QKeySequence> listShortcutHistoryNext = SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutHistoryNext();
    QList<QKeySequence> listShortcutSceneThreadRemoveLeft = SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutSceneThreadRemoveLeft();
    QList<QKeySequence> listShortcutSceneThreadRemoveRight = SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutSceneThreadRemoveRight();
    QList<QKeySequence> listShortcutSceneThreadAddLeft = SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutSceneThreadAddLeft();
    QList<QKeySequence> listShortcutSceneThreadAddRight = SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutSceneThreadAddRight();
    QList<QKeySequence> listShortcutSceneHalfrowRemoveDown = SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutSceneHalfrowRemoveDown();
    QList<QKeySequence> listShortcutSceneHalfrowRemoveTop = SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutSceneHalfrowRemoveTop();
    QList<QKeySequence> listShortcutSceneHalfrowAddDown = SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutSceneHalfrowAddDown();
    QList<QKeySequence> listShortcutSceneHalfrowAddTop = SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutSceneHalfrowAddTop();
    QList<QKeySequence> listShortcutSceneEditDirectionNewNode = SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutSceneEditDirectionNewNode();
    QList<QKeySequence> listShortcutViewZoomOut = SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutViewZoomOut();
    QList<QKeySequence> listShortcutViewZoomIn = SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutViewZoomIn();
    QList<QKeySequence> listShortcutViewToBottom = SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutViewToBottom();
    QList<QKeySequence> listShortcutViewToTop = SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutViewToTop();
    QList<QKeySequence> listShortcutViewToLeft = SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutViewToLeft();
    QList<QKeySequence> listShortcutViewToRight = SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutViewToRight();
    QList<QKeySequence> listShortcutViewRotateLeft = SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutViewRotateLeft();
    QList<QKeySequence> listShortcutViewRotateRight = SchemeObliqueFileSetting::getListShortcutActionSchemeObliqueShortcutViewRotateRight();

    this->setInWidget(listShortcutSceneCreate,
                      listShortcutHistoryBack,
                      listShortcutHistoryNext,
                      listShortcutSceneThreadRemoveLeft,
                      listShortcutSceneThreadRemoveRight,
                      listShortcutSceneThreadAddLeft,
                      listShortcutSceneThreadAddRight,
                      listShortcutSceneHalfrowRemoveDown,
                      listShortcutSceneHalfrowRemoveTop,
                      listShortcutSceneHalfrowAddDown,
                      listShortcutSceneHalfrowAddTop,
                      listShortcutSceneEditDirectionNewNode,
                      listShortcutViewZoomOut,
                      listShortcutViewZoomIn,
                      listShortcutViewToBottom,
                      listShortcutViewToTop,
                      listShortcutViewToLeft,
                      listShortcutViewToRight,
                      listShortcutViewRotateLeft,
                      listShortcutViewRotateRight);
}

void SchemeObliqueShortcut::saveShortcutInFile()
{
    QList<QKeySequence> listShortcutSceneCreate;
    QList<QKeySequence> listShortcutHistoryBack;
    QList<QKeySequence> listShortcutHistoryNext;
    QList<QKeySequence> listShortcutSceneThreadRemoveLeft;
    QList<QKeySequence> listShortcutSceneThreadRemoveRight;
    QList<QKeySequence> listShortcutSceneThreadAddLeft;
    QList<QKeySequence> listShortcutSceneThreadAddRight;
    QList<QKeySequence> listShortcutSceneHalfrowRemoveDown;
    QList<QKeySequence> listShortcutSceneHalfrowRemoveTop;
    QList<QKeySequence> listShortcutSceneHalfrowAddDown;
    QList<QKeySequence> listShortcutSceneHalfrowAddTop;
    QList<QKeySequence> listShortcutSceneEditDirectionNewNode;
    QList<QKeySequence> listShortcutViewZoomOut;
    QList<QKeySequence> listShortcutViewZoomIn;
    QList<QKeySequence> listShortcutViewToBottom;
    QList<QKeySequence> listShortcutViewToTop;
    QList<QKeySequence> listShortcutViewToLeft;
    QList<QKeySequence> listShortcutViewToRight;
    QList<QKeySequence> listShortcutViewRotateLeft;
    QList<QKeySequence> listShortcutViewRotateRight;

    listShortcutSceneCreate.push_back(this->keySequenceEditCreate_1.keySequence());
    listShortcutSceneCreate.push_back(this->keySequenceEditCreate_2.keySequence());
    listShortcutSceneCreate.push_back(this->keySequenceEditCreate_3.keySequence());
    listShortcutSceneCreate.push_back(this->keySequenceEditCreate_4.keySequence());

    listShortcutHistoryBack.push_back(this->keySequenceEditBack_1.keySequence());
    listShortcutHistoryBack.push_back(this->keySequenceEditBack_2.keySequence());
    listShortcutHistoryBack.push_back(this->keySequenceEditBack_3.keySequence());
    listShortcutHistoryBack.push_back(this->keySequenceEditBack_4.keySequence());

    listShortcutHistoryNext.push_back(this->keySequenceEditNext_1.keySequence());
    listShortcutHistoryNext.push_back(this->keySequenceEditNext_2.keySequence());
    listShortcutHistoryNext.push_back(this->keySequenceEditNext_3.keySequence());
    listShortcutHistoryNext.push_back(this->keySequenceEditNext_4.keySequence());

    listShortcutSceneThreadRemoveLeft.push_back(this->keySequenceEditRemoveThreadLeft_1.keySequence());
    listShortcutSceneThreadRemoveLeft.push_back(this->keySequenceEditRemoveThreadLeft_2.keySequence());
    listShortcutSceneThreadRemoveLeft.push_back(this->keySequenceEditRemoveThreadLeft_3.keySequence());
    listShortcutSceneThreadRemoveLeft.push_back(this->keySequenceEditRemoveThreadLeft_4.keySequence());

    listShortcutSceneThreadRemoveRight.push_back(this->keySequenceEditRemoveThreadRight_1.keySequence());
    listShortcutSceneThreadRemoveRight.push_back(this->keySequenceEditRemoveThreadRight_2.keySequence());
    listShortcutSceneThreadRemoveRight.push_back(this->keySequenceEditRemoveThreadRight_3.keySequence());
    listShortcutSceneThreadRemoveRight.push_back(this->keySequenceEditRemoveThreadRight_4.keySequence());

    listShortcutSceneThreadAddLeft.push_back(this->keySequenceEditAddThreadLeft_1.keySequence());
    listShortcutSceneThreadAddLeft.push_back(this->keySequenceEditAddThreadLeft_2.keySequence());
    listShortcutSceneThreadAddLeft.push_back(this->keySequenceEditAddThreadLeft_3.keySequence());
    listShortcutSceneThreadAddLeft.push_back(this->keySequenceEditAddThreadLeft_4.keySequence());

    listShortcutSceneThreadAddRight.push_back(this->keySequenceEditAddThreadRight_1.keySequence());
    listShortcutSceneThreadAddRight.push_back(this->keySequenceEditAddThreadRight_2.keySequence());
    listShortcutSceneThreadAddRight.push_back(this->keySequenceEditAddThreadRight_3.keySequence());
    listShortcutSceneThreadAddRight.push_back(this->keySequenceEditAddThreadRight_4.keySequence());

    listShortcutSceneHalfrowRemoveDown.push_back(this->keySequenceEditRemoveHalfrowDown_1.keySequence());
    listShortcutSceneHalfrowRemoveDown.push_back(this->keySequenceEditRemoveHalfrowDown_2.keySequence());
    listShortcutSceneHalfrowRemoveDown.push_back(this->keySequenceEditRemoveHalfrowDown_3.keySequence());
    listShortcutSceneHalfrowRemoveDown.push_back(this->keySequenceEditRemoveHalfrowDown_4.keySequence());

    listShortcutSceneHalfrowRemoveTop.push_back(this->keySequenceEditRemoveHalfrowTop_1.keySequence());
    listShortcutSceneHalfrowRemoveTop.push_back(this->keySequenceEditRemoveHalfrowTop_2.keySequence());
    listShortcutSceneHalfrowRemoveTop.push_back(this->keySequenceEditRemoveHalfrowTop_3.keySequence());
    listShortcutSceneHalfrowRemoveTop.push_back(this->keySequenceEditRemoveHalfrowTop_4.keySequence());

    listShortcutSceneHalfrowAddDown.push_back(this->keySequenceEditAddHalfrowDown_1.keySequence());
    listShortcutSceneHalfrowAddDown.push_back(this->keySequenceEditAddHalfrowDown_2.keySequence());
    listShortcutSceneHalfrowAddDown.push_back(this->keySequenceEditAddHalfrowDown_3.keySequence());
    listShortcutSceneHalfrowAddDown.push_back(this->keySequenceEditAddHalfrowDown_4.keySequence());

    listShortcutSceneHalfrowAddTop.push_back(this->keySequenceEditAddHalfrowTop_1.keySequence());
    listShortcutSceneHalfrowAddTop.push_back(this->keySequenceEditAddHalfrowTop_2.keySequence());
    listShortcutSceneHalfrowAddTop.push_back(this->keySequenceEditAddHalfrowTop_3.keySequence());
    listShortcutSceneHalfrowAddTop.push_back(this->keySequenceEditAddHalfrowTop_4.keySequence());

    listShortcutSceneEditDirectionNewNode.push_back(this->keySequenceEditEditDirectionNewNode_1.keySequence());
    listShortcutSceneEditDirectionNewNode.push_back(this->keySequenceEditEditDirectionNewNode_2.keySequence());
    listShortcutSceneEditDirectionNewNode.push_back(this->keySequenceEditEditDirectionNewNode_3.keySequence());
    listShortcutSceneEditDirectionNewNode.push_back(this->keySequenceEditEditDirectionNewNode_4.keySequence());

    listShortcutViewZoomOut.push_back(this->keySequenceEditZoomOut_1.keySequence());
    listShortcutViewZoomOut.push_back(this->keySequenceEditZoomOut_2.keySequence());
    listShortcutViewZoomOut.push_back(this->keySequenceEditZoomOut_3.keySequence());
    listShortcutViewZoomOut.push_back(this->keySequenceEditZoomOut_4.keySequence());

    listShortcutViewZoomIn.push_back(this->keySequenceEditZoomIn_1.keySequence());
    listShortcutViewZoomIn.push_back(this->keySequenceEditZoomIn_2.keySequence());
    listShortcutViewZoomIn.push_back(this->keySequenceEditZoomIn_3.keySequence());
    listShortcutViewZoomIn.push_back(this->keySequenceEditZoomIn_4.keySequence());

    listShortcutViewToBottom.push_back(this->keySequenceEditToBottom_1.keySequence());
    listShortcutViewToBottom.push_back(this->keySequenceEditToBottom_2.keySequence());
    listShortcutViewToBottom.push_back(this->keySequenceEditToBottom_3.keySequence());
    listShortcutViewToBottom.push_back(this->keySequenceEditToBottom_4.keySequence());

    listShortcutViewToTop.push_back(this->keySequenceEditToTop_1.keySequence());
    listShortcutViewToTop.push_back(this->keySequenceEditToTop_2.keySequence());
    listShortcutViewToTop.push_back(this->keySequenceEditToTop_3.keySequence());
    listShortcutViewToTop.push_back(this->keySequenceEditToTop_4.keySequence());

    listShortcutViewToLeft.push_back(this->keySequenceEditToLeft_1.keySequence());
    listShortcutViewToLeft.push_back(this->keySequenceEditToLeft_2.keySequence());
    listShortcutViewToLeft.push_back(this->keySequenceEditToLeft_3.keySequence());
    listShortcutViewToLeft.push_back(this->keySequenceEditToLeft_4.keySequence());

    listShortcutViewToRight.push_back(this->keySequenceEditToRight_1.keySequence());
    listShortcutViewToRight.push_back(this->keySequenceEditToRight_2.keySequence());
    listShortcutViewToRight.push_back(this->keySequenceEditToRight_3.keySequence());
    listShortcutViewToRight.push_back(this->keySequenceEditToRight_4.keySequence());

    listShortcutViewRotateLeft.push_back(this->keySequenceEditRotateLeft_1.keySequence());
    listShortcutViewRotateLeft.push_back(this->keySequenceEditRotateLeft_2.keySequence());
    listShortcutViewRotateLeft.push_back(this->keySequenceEditRotateLeft_3.keySequence());
    listShortcutViewRotateLeft.push_back(this->keySequenceEditRotateLeft_4.keySequence());

    listShortcutViewRotateRight.push_back(this->keySequenceEditRotateRight_1.keySequence());
    listShortcutViewRotateRight.push_back(this->keySequenceEditRotateRight_2.keySequence());
    listShortcutViewRotateRight.push_back(this->keySequenceEditRotateRight_3.keySequence());
    listShortcutViewRotateRight.push_back(this->keySequenceEditRotateRight_4.keySequence());

    SchemeObliqueFileSetting::setListShortcutActionSchemeObliqueShortcutSceneCreate(listShortcutSceneCreate);
    SchemeObliqueFileSetting::setListShortcutActionSchemeObliqueShortcutHistoryBack(listShortcutHistoryBack);
    SchemeObliqueFileSetting::setListShortcutActionSchemeObliqueShortcutHistoryNext(listShortcutHistoryNext);
    SchemeObliqueFileSetting::setListShortcutActionSchemeObliqueShortcutSceneThreadRemoveLeft(listShortcutSceneThreadRemoveLeft);
    SchemeObliqueFileSetting::setListShortcutActionSchemeObliqueShortcutSceneThreadRemoveRight(listShortcutSceneThreadRemoveRight);
    SchemeObliqueFileSetting::setListShortcutActionSchemeObliqueShortcutSceneThreadAddLeft(listShortcutSceneThreadAddLeft);
    SchemeObliqueFileSetting::setListShortcutActionSchemeObliqueShortcutSceneThreadAddRight(listShortcutSceneThreadAddRight);
    SchemeObliqueFileSetting::setListShortcutActionSchemeObliqueShortcutSceneHalfrowRemoveDown(listShortcutSceneHalfrowRemoveDown);
    SchemeObliqueFileSetting::setListShortcutActionSchemeObliqueShortcutSceneHalfrowRemoveTop(listShortcutSceneHalfrowRemoveTop);
    SchemeObliqueFileSetting::setListShortcutActionSchemeObliqueShortcutSceneHalfrowAddDown(listShortcutSceneHalfrowAddDown);
    SchemeObliqueFileSetting::setListShortcutActionSchemeObliqueShortcutSceneHalfrowAddTop(listShortcutSceneHalfrowAddTop);
    SchemeObliqueFileSetting::setListShortcutActionSchemeObliqueShortcutSceneEditDirectionNewNode(listShortcutSceneEditDirectionNewNode);
    SchemeObliqueFileSetting::setListShortcutActionSchemeObliqueShortcutViewZoomOut(listShortcutViewZoomOut);
    SchemeObliqueFileSetting::setListShortcutActionSchemeObliqueShortcutViewZoomIn(listShortcutViewZoomIn);
    SchemeObliqueFileSetting::setListShortcutActionSchemeObliqueShortcutViewToBottom(listShortcutViewToBottom);
    SchemeObliqueFileSetting::setListShortcutActionSchemeObliqueShortcutViewToTop(listShortcutViewToTop);
    SchemeObliqueFileSetting::setListShortcutActionSchemeObliqueShortcutViewToLeft(listShortcutViewToLeft);
    SchemeObliqueFileSetting::setListShortcutActionSchemeObliqueShortcutViewToRight(listShortcutViewToRight);
    SchemeObliqueFileSetting::setListShortcutActionSchemeObliqueShortcutViewRotateLeft(listShortcutViewRotateLeft);
    SchemeObliqueFileSetting::setListShortcutActionSchemeObliqueShortcutViewRotateRight(listShortcutViewRotateRight);
}

SchemeObliqueShortcut::SchemeObliqueShortcut()
{

}

SchemeObliqueShortcut::~SchemeObliqueShortcut()
{

}

void SchemeObliqueShortcut::setInWidget(QList<QKeySequence> listShortcutSceneCreate,
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
                                        QList<QKeySequence> listShortcutViewZoomOut,
                                        QList<QKeySequence> listShortcutViewZoomIn,
                                        QList<QKeySequence> listShortcutViewToBottom,
                                        QList<QKeySequence> listShortcutViewToTop,
                                        QList<QKeySequence> listShortcutViewToLeft,
                                        QList<QKeySequence> listShortcutViewToRight,
                                        QList<QKeySequence> listShortcutViewRotateLeft,
                                        QList<QKeySequence> listShortcutViewRotateRight)
{
    this->keySequenceEditCreate_1.setKeySequence(listShortcutSceneCreate[0]);
    this->keySequenceEditCreate_2.setKeySequence(listShortcutSceneCreate[1]);
    this->keySequenceEditCreate_3.setKeySequence(listShortcutSceneCreate[2]);
    this->keySequenceEditCreate_4.setKeySequence(listShortcutSceneCreate[3]);

    this->keySequenceEditBack_1.setKeySequence(listShortcutHistoryBack[0]);
    this->keySequenceEditBack_2.setKeySequence(listShortcutHistoryBack[1]);
    this->keySequenceEditBack_3.setKeySequence(listShortcutHistoryBack[2]);
    this->keySequenceEditBack_4.setKeySequence(listShortcutHistoryBack[3]);

    this->keySequenceEditNext_1.setKeySequence(listShortcutHistoryNext[0]);
    this->keySequenceEditNext_2.setKeySequence(listShortcutHistoryNext[1]);
    this->keySequenceEditNext_3.setKeySequence(listShortcutHistoryNext[2]);
    this->keySequenceEditNext_4.setKeySequence(listShortcutHistoryNext[3]);

    this->keySequenceEditRemoveThreadLeft_1.setKeySequence(listShortcutSceneThreadRemoveLeft[0]);
    this->keySequenceEditRemoveThreadLeft_2.setKeySequence(listShortcutSceneThreadRemoveLeft[1]);
    this->keySequenceEditRemoveThreadLeft_3.setKeySequence(listShortcutSceneThreadRemoveLeft[2]);
    this->keySequenceEditRemoveThreadLeft_4.setKeySequence(listShortcutSceneThreadRemoveLeft[3]);

    this->keySequenceEditRemoveThreadRight_1.setKeySequence(listShortcutSceneThreadRemoveRight[0]);
    this->keySequenceEditRemoveThreadRight_2.setKeySequence(listShortcutSceneThreadRemoveRight[1]);
    this->keySequenceEditRemoveThreadRight_3.setKeySequence(listShortcutSceneThreadRemoveRight[2]);
    this->keySequenceEditRemoveThreadRight_4.setKeySequence(listShortcutSceneThreadRemoveRight[3]);

    this->keySequenceEditAddThreadLeft_1.setKeySequence(listShortcutSceneThreadAddLeft[0]);
    this->keySequenceEditAddThreadLeft_2.setKeySequence(listShortcutSceneThreadAddLeft[1]);
    this->keySequenceEditAddThreadLeft_3.setKeySequence(listShortcutSceneThreadAddLeft[2]);
    this->keySequenceEditAddThreadLeft_4.setKeySequence(listShortcutSceneThreadAddLeft[3]);

    this->keySequenceEditAddThreadRight_1.setKeySequence(listShortcutSceneThreadAddRight[0]);
    this->keySequenceEditAddThreadRight_2.setKeySequence(listShortcutSceneThreadAddRight[1]);
    this->keySequenceEditAddThreadRight_3.setKeySequence(listShortcutSceneThreadAddRight[2]);
    this->keySequenceEditAddThreadRight_4.setKeySequence(listShortcutSceneThreadAddRight[3]);

    this->keySequenceEditRemoveHalfrowDown_1.setKeySequence(listShortcutSceneHalfrowRemoveDown[0]);
    this->keySequenceEditRemoveHalfrowDown_2.setKeySequence(listShortcutSceneHalfrowRemoveDown[1]);
    this->keySequenceEditRemoveHalfrowDown_3.setKeySequence(listShortcutSceneHalfrowRemoveDown[2]);
    this->keySequenceEditRemoveHalfrowDown_4.setKeySequence(listShortcutSceneHalfrowRemoveDown[3]);

    this->keySequenceEditRemoveHalfrowTop_1.setKeySequence(listShortcutSceneHalfrowRemoveTop[0]);
    this->keySequenceEditRemoveHalfrowTop_2.setKeySequence(listShortcutSceneHalfrowRemoveTop[1]);
    this->keySequenceEditRemoveHalfrowTop_3.setKeySequence(listShortcutSceneHalfrowRemoveTop[2]);
    this->keySequenceEditRemoveHalfrowTop_4.setKeySequence(listShortcutSceneHalfrowRemoveTop[3]);

    this->keySequenceEditAddHalfrowDown_1.setKeySequence(listShortcutSceneHalfrowAddDown[0]);
    this->keySequenceEditAddHalfrowDown_2.setKeySequence(listShortcutSceneHalfrowAddDown[1]);
    this->keySequenceEditAddHalfrowDown_3.setKeySequence(listShortcutSceneHalfrowAddDown[2]);
    this->keySequenceEditAddHalfrowDown_4.setKeySequence(listShortcutSceneHalfrowAddDown[3]);

    this->keySequenceEditAddHalfrowTop_1.setKeySequence(listShortcutSceneHalfrowAddTop[0]);
    this->keySequenceEditAddHalfrowTop_2.setKeySequence(listShortcutSceneHalfrowAddTop[1]);
    this->keySequenceEditAddHalfrowTop_3.setKeySequence(listShortcutSceneHalfrowAddTop[2]);
    this->keySequenceEditAddHalfrowTop_4.setKeySequence(listShortcutSceneHalfrowAddTop[3]);

    this->keySequenceEditEditDirectionNewNode_1.setKeySequence(listShortcutSceneEditDirectionNewNode[0]);
    this->keySequenceEditEditDirectionNewNode_2.setKeySequence(listShortcutSceneEditDirectionNewNode[1]);
    this->keySequenceEditEditDirectionNewNode_3.setKeySequence(listShortcutSceneEditDirectionNewNode[2]);
    this->keySequenceEditEditDirectionNewNode_4.setKeySequence(listShortcutSceneEditDirectionNewNode[3]);

    this->keySequenceEditZoomOut_1.setKeySequence(listShortcutViewZoomOut[0]);
    this->keySequenceEditZoomOut_2.setKeySequence(listShortcutViewZoomOut[1]);
    this->keySequenceEditZoomOut_3.setKeySequence(listShortcutViewZoomOut[2]);
    this->keySequenceEditZoomOut_4.setKeySequence(listShortcutViewZoomOut[3]);

    this->keySequenceEditZoomIn_1.setKeySequence(listShortcutViewZoomIn[0]);
    this->keySequenceEditZoomIn_2.setKeySequence(listShortcutViewZoomIn[1]);
    this->keySequenceEditZoomIn_3.setKeySequence(listShortcutViewZoomIn[2]);
    this->keySequenceEditZoomIn_4.setKeySequence(listShortcutViewZoomIn[3]);

    this->keySequenceEditToBottom_1.setKeySequence(listShortcutViewToBottom[0]);
    this->keySequenceEditToBottom_2.setKeySequence(listShortcutViewToBottom[1]);
    this->keySequenceEditToBottom_3.setKeySequence(listShortcutViewToBottom[2]);
    this->keySequenceEditToBottom_4.setKeySequence(listShortcutViewToBottom[3]);

    this->keySequenceEditToTop_1.setKeySequence(listShortcutViewToTop[0]);
    this->keySequenceEditToTop_2.setKeySequence(listShortcutViewToTop[1]);
    this->keySequenceEditToTop_3.setKeySequence(listShortcutViewToTop[2]);
    this->keySequenceEditToTop_4.setKeySequence(listShortcutViewToTop[3]);

    this->keySequenceEditToLeft_1.setKeySequence(listShortcutViewToLeft[0]);
    this->keySequenceEditToLeft_2.setKeySequence(listShortcutViewToLeft[1]);
    this->keySequenceEditToLeft_3.setKeySequence(listShortcutViewToLeft[2]);
    this->keySequenceEditToLeft_4.setKeySequence(listShortcutViewToLeft[3]);

    this->keySequenceEditToRight_1.setKeySequence(listShortcutViewToRight[0]);
    this->keySequenceEditToRight_2.setKeySequence(listShortcutViewToRight[1]);
    this->keySequenceEditToRight_3.setKeySequence(listShortcutViewToRight[2]);
    this->keySequenceEditToRight_4.setKeySequence(listShortcutViewToRight[3]);

    this->keySequenceEditRotateLeft_1.setKeySequence(listShortcutViewRotateLeft[0]);
    this->keySequenceEditRotateLeft_2.setKeySequence(listShortcutViewRotateLeft[1]);
    this->keySequenceEditRotateLeft_3.setKeySequence(listShortcutViewRotateLeft[2]);
    this->keySequenceEditRotateLeft_4.setKeySequence(listShortcutViewRotateLeft[3]);

    this->keySequenceEditRotateRight_1.setKeySequence(listShortcutViewRotateRight[0]);
    this->keySequenceEditRotateRight_2.setKeySequence(listShortcutViewRotateRight[1]);
    this->keySequenceEditRotateRight_3.setKeySequence(listShortcutViewRotateRight[2]);
    this->keySequenceEditRotateRight_4.setKeySequence(listShortcutViewRotateRight[3]);
}
