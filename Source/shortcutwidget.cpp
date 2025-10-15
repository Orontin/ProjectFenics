#include "shortcutwidget.h"

#include "settings.h"

ShortcutWidget *ShortcutWidget::shortcutWidget{nullptr};

ShortcutWidget &ShortcutWidget::getInstance()
{
    if (!ShortcutWidget::shortcutWidget) {
        ShortcutWidget::shortcutWidget = new ShortcutWidget;
    }
    return *ShortcutWidget::shortcutWidget;
}

QGridLayout &ShortcutWidget::getGridLayouWidgetScrollArea()
{
    return gridLayouWidgetScrollArea;
}

void ShortcutWidget::showEvent(QShowEvent *event)
{
    onClickedCancel();
    QWidget::showEvent(event);
}

void ShortcutWidget::closeEvent(QCloseEvent *event)
{
    onClickedCancel();
    QWidget::closeEvent(event);
}

void ShortcutWidget::onClickedSetDefaultShortcut()
{
    setDefaultShortcutInWidget();
    emit this->clickedShortcutSetDefaultShortcut();
}

void ShortcutWidget::onClickedCancel()
{
    setShortcutInWidget();
    emit this->clickedShortcutCancel();
}

void ShortcutWidget::onClickedSave()
{
    saveShortcutInFile();
    emit this->clickedShortcutSave();
    this->close();
}


ShortcutWidget::ShortcutWidget()
{
    this->setWindowModality(Qt::ApplicationModal);
    this->setWindowTitle("Настройка сочетаний клавиш");

    int rowCount = this->gridLayouWidgetScrollArea.rowCount();
    this->labelName.setText("Общие сочетания клавиш");
    this->labelName.setAlignment(Qt::AlignCenter);
    this->labelName.setStyleSheet("font-weight: bold; text-decoration: underline; font-style: italic;");
    this->gridLayouWidgetScrollArea.addWidget(&this->labelName, rowCount, 0, 1, 5);

    rowCount = this->gridLayouWidgetScrollArea.rowCount();
    this->labelOpenFile.setText("Открыть файл");
    this->gridLayouWidgetScrollArea.addWidget(&this->labelOpenFile, rowCount, 0, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditOpenFile_1, rowCount, 1, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditOpenFile_2, rowCount, 2, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditOpenFile_3, rowCount, 3, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditOpenFile_4, rowCount, 4, 1, 1);

    rowCount = this->gridLayouWidgetScrollArea.rowCount();
    this->labelSaveOpenScheme.setText("Сохранить открытую схему");
    this->gridLayouWidgetScrollArea.addWidget(&this->labelSaveOpenScheme, rowCount, 0, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditSaveOpenScheme_1, rowCount, 1, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditSaveOpenScheme_2, rowCount, 2, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditSaveOpenScheme_3, rowCount, 3, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditSaveOpenScheme_4, rowCount, 4, 1, 1);

    rowCount = this->gridLayouWidgetScrollArea.rowCount();
    this->labelDeleteOpenScheme.setText("Удалить открытую схему");
    this->gridLayouWidgetScrollArea.addWidget(&this->labelDeleteOpenScheme, rowCount, 0, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditDeleteOpenScheme_1, rowCount, 1, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditDeleteOpenScheme_2, rowCount, 2, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditDeleteOpenScheme_3, rowCount, 3, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditDeleteOpenScheme_4, rowCount, 4, 1, 1);

    rowCount = this->gridLayouWidgetScrollArea.rowCount();
    this->labelShortcutWidget.setText("Сочетания клавиш");
    this->gridLayouWidgetScrollArea.addWidget(&this->labelShortcutWidget, rowCount, 0, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditShortcutWidget_1, rowCount, 1, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditShortcutWidget_2, rowCount, 2, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditShortcutWidget_3, rowCount, 3, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditShortcutWidget_4, rowCount, 4, 1, 1);

    this->widgetScrollAreaGridLayout.addLayout(&this->gridLayouWidgetScrollArea, 0, 0, 1, 1);
    this->widgetScrollAreaGridLayout.setRowStretch(0, 0);
    this->widgetScrollAreaGridLayout.setRowStretch(1, 1);
    this->widgetScrollArea.setLayout(&this->widgetScrollAreaGridLayout);
    this->scrollArea.setWidget(&this->widgetScrollArea);
    this->scrollArea.setWidgetResizable(true);
    this->scrollArea.setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    this->scrollArea.setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    this->gridLayout.addWidget(&this->scrollArea, 0, 0, 1, 3);

    this->setDefaultShortcut.setText("Вернуть дефолтные сочетания клавиш");
    this->gridLayout.addWidget(&this->setDefaultShortcut, 1, 0);
    this->cancel.setText("Отменить изменения");
    this->gridLayout.addWidget(&this->cancel, 1, 1);
    this->save.setText("Сохранить изменения");
    this->gridLayout.addWidget(&this->save, 1, 2);

    this->setLayout(&this->gridLayout);

    connect(&this->setDefaultShortcut, &QPushButton::clicked, this, &ShortcutWidget::onClickedSetDefaultShortcut);
    connect(&this->cancel, &QPushButton::clicked, this, &ShortcutWidget::onClickedCancel);
    connect(&this->save, &QPushButton::clicked, this, &ShortcutWidget::onClickedSave);
}

ShortcutWidget::~ShortcutWidget()
{

}

void ShortcutWidget::setDefaultShortcutInWidget()
{
    QList<QKeySequence> listShortcutOpenFile = Settings::getListDefaultShortcutActionOpenFile();
    QList<QKeySequence> listShortcutEditSaveOpenScheme = Settings::getListDefaultShortcutActionSaveScheme();
    QList<QKeySequence> listShortcutDeleteOpenScheme = Settings::getListDefaultShortcutActionDeleteOpenScheme();
    QList<QKeySequence> listShortcutShortcutWidget = Settings::getListDefaultShortcutActionOpenShortcutWidget();

    this->keySequenceEditOpenFile_1.setKeySequence(listShortcutOpenFile[0]);
    this->keySequenceEditOpenFile_2.setKeySequence(listShortcutOpenFile[1]);
    this->keySequenceEditOpenFile_3.setKeySequence(listShortcutOpenFile[2]);
    this->keySequenceEditOpenFile_4.setKeySequence(listShortcutOpenFile[3]);

    this->keySequenceEditSaveOpenScheme_1.setKeySequence(listShortcutEditSaveOpenScheme[0]);
    this->keySequenceEditSaveOpenScheme_2.setKeySequence(listShortcutEditSaveOpenScheme[1]);
    this->keySequenceEditSaveOpenScheme_3.setKeySequence(listShortcutEditSaveOpenScheme[2]);
    this->keySequenceEditSaveOpenScheme_4.setKeySequence(listShortcutEditSaveOpenScheme[3]);

    this->keySequenceEditDeleteOpenScheme_1.setKeySequence(listShortcutDeleteOpenScheme[0]);
    this->keySequenceEditDeleteOpenScheme_2.setKeySequence(listShortcutDeleteOpenScheme[1]);
    this->keySequenceEditDeleteOpenScheme_3.setKeySequence(listShortcutDeleteOpenScheme[2]);
    this->keySequenceEditDeleteOpenScheme_4.setKeySequence(listShortcutDeleteOpenScheme[3]);

    this->keySequenceEditShortcutWidget_1.setKeySequence(listShortcutShortcutWidget[0]);
    this->keySequenceEditShortcutWidget_2.setKeySequence(listShortcutShortcutWidget[1]);
    this->keySequenceEditShortcutWidget_3.setKeySequence(listShortcutShortcutWidget[2]);
    this->keySequenceEditShortcutWidget_4.setKeySequence(listShortcutShortcutWidget[3]);
}

void ShortcutWidget::setShortcutInWidget()
{
    QList<QKeySequence> listShortcutOpenFile = Settings::getListShortcutActionOpenFile();
    QList<QKeySequence> listShortcutEditSaveOpenScheme = Settings::getListShortcutActionSaveScheme();
    QList<QKeySequence> listShortcutDeleteOpenScheme = Settings::getListShortcutActionDeleteOpenScheme();
    QList<QKeySequence> listShortcutShortcutWidget = Settings::getListShortcutActionOpenShortcutWidget();

    setInWidget(listShortcutOpenFile, listShortcutEditSaveOpenScheme, listShortcutDeleteOpenScheme, listShortcutShortcutWidget);
}

void ShortcutWidget::setInWidget(QList<QKeySequence> &listShortcutOpenFile, QList<QKeySequence> &listShortcutEditSaveOpenScheme, QList<QKeySequence> &listShortcutDeleteOpenScheme, QList<QKeySequence> &listShortcutShortcutWidget)
{
    this->keySequenceEditOpenFile_1.setKeySequence(listShortcutOpenFile[0]);
    this->keySequenceEditOpenFile_2.setKeySequence(listShortcutOpenFile[1]);
    this->keySequenceEditOpenFile_3.setKeySequence(listShortcutOpenFile[2]);
    this->keySequenceEditOpenFile_4.setKeySequence(listShortcutOpenFile[3]);

    this->keySequenceEditSaveOpenScheme_1.setKeySequence(listShortcutEditSaveOpenScheme[0]);
    this->keySequenceEditSaveOpenScheme_2.setKeySequence(listShortcutEditSaveOpenScheme[1]);
    this->keySequenceEditSaveOpenScheme_3.setKeySequence(listShortcutEditSaveOpenScheme[2]);
    this->keySequenceEditSaveOpenScheme_4.setKeySequence(listShortcutEditSaveOpenScheme[3]);

    this->keySequenceEditDeleteOpenScheme_1.setKeySequence(listShortcutDeleteOpenScheme[0]);
    this->keySequenceEditDeleteOpenScheme_2.setKeySequence(listShortcutDeleteOpenScheme[1]);
    this->keySequenceEditDeleteOpenScheme_3.setKeySequence(listShortcutDeleteOpenScheme[2]);
    this->keySequenceEditDeleteOpenScheme_4.setKeySequence(listShortcutDeleteOpenScheme[3]);

    this->keySequenceEditShortcutWidget_1.setKeySequence(listShortcutShortcutWidget[0]);
    this->keySequenceEditShortcutWidget_2.setKeySequence(listShortcutShortcutWidget[1]);
    this->keySequenceEditShortcutWidget_3.setKeySequence(listShortcutShortcutWidget[2]);
    this->keySequenceEditShortcutWidget_4.setKeySequence(listShortcutShortcutWidget[3]);
}

void ShortcutWidget::saveShortcutInFile()
{
    QList<QKeySequence> listShortcutOpenFile;
    listShortcutOpenFile.push_back(this->keySequenceEditOpenFile_1.keySequence());
    listShortcutOpenFile.push_back(this->keySequenceEditOpenFile_2.keySequence());
    listShortcutOpenFile.push_back(this->keySequenceEditOpenFile_3.keySequence());
    listShortcutOpenFile.push_back(this->keySequenceEditOpenFile_4.keySequence());
    Settings::setListShortcutActionOpenFile(listShortcutOpenFile);

    QList<QKeySequence> listShortcutEditSaveOpenScheme;
    listShortcutEditSaveOpenScheme.push_back(this->keySequenceEditSaveOpenScheme_1.keySequence());
    listShortcutEditSaveOpenScheme.push_back(this->keySequenceEditSaveOpenScheme_2.keySequence());
    listShortcutEditSaveOpenScheme.push_back(this->keySequenceEditSaveOpenScheme_3.keySequence());
    listShortcutEditSaveOpenScheme.push_back(this->keySequenceEditSaveOpenScheme_4.keySequence());
    Settings::setListShortcutActionSaveScheme(listShortcutEditSaveOpenScheme);

    QList<QKeySequence> listShortcutDeleteOpenScheme;
    listShortcutDeleteOpenScheme.push_back(this->keySequenceEditDeleteOpenScheme_1.keySequence());
    listShortcutDeleteOpenScheme.push_back(this->keySequenceEditDeleteOpenScheme_2.keySequence());
    listShortcutDeleteOpenScheme.push_back(this->keySequenceEditDeleteOpenScheme_3.keySequence());
    listShortcutDeleteOpenScheme.push_back(this->keySequenceEditDeleteOpenScheme_4.keySequence());
    Settings::setListShortcutActionDeleteOpenScheme(listShortcutDeleteOpenScheme);

    QList<QKeySequence> listShortcutShortcutWidget;
    listShortcutShortcutWidget.push_back(this->keySequenceEditShortcutWidget_1.keySequence());
    listShortcutShortcutWidget.push_back(this->keySequenceEditShortcutWidget_2.keySequence());
    listShortcutShortcutWidget.push_back(this->keySequenceEditShortcutWidget_3.keySequence());
    listShortcutShortcutWidget.push_back(this->keySequenceEditShortcutWidget_4.keySequence());
    Settings::setListShortcutActionOpenShortcutWidget(listShortcutShortcutWidget);
}
