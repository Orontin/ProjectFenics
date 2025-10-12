#include "shortcutwidget.h"

#include "settings.h"

ShortcutWidget::ShortcutWidget():
    listShortcutOpenFile{&keySequenceEditOpenFile_1, &keySequenceEditOpenFile_2, &keySequenceEditOpenFile_3, &keySequenceEditOpenFile_4},
    listShortcutEditSaveOpenScheme{&keySequenceEditSaveOpenScheme_1, &keySequenceEditSaveOpenScheme_2, &keySequenceEditSaveOpenScheme_3, &keySequenceEditSaveOpenScheme_4},
    listShortcutDeleteOpenScheme{&keySequenceEditDeleteOpenScheme_1, &keySequenceEditDeleteOpenScheme_2, &keySequenceEditDeleteOpenScheme_3, &keySequenceEditDeleteOpenScheme_4},
    listShortcutShortcutWidget{&keySequenceEditShortcutWidget_1, &keySequenceEditShortcutWidget_2, &keySequenceEditShortcutWidget_3, &keySequenceEditShortcutWidget_4}
{
    this->setWindowModality(Qt::ApplicationModal);
    this->setWindowTitle("Настройка сочетаний клавиш");

    this->verticalLayoutKeySequenceEdit_1.setText("Сочетание 1");
    this->verticalLayoutKeySequenceEdit_1.setAlignment(Qt::AlignCenter);
    this->gridLayouWidgetScrollArea.addWidget(&this->verticalLayoutKeySequenceEdit_1, 0, 1, 1, 1);

    this->verticalLayoutKeySequenceEdit_2.setText("Сочетание 2");
    this->verticalLayoutKeySequenceEdit_2.setAlignment(Qt::AlignCenter);
    this->gridLayouWidgetScrollArea.addWidget(&this->verticalLayoutKeySequenceEdit_2, 0, 2, 1, 1);

    this->verticalLayoutKeySequenceEdit_3.setText("Сочетание 3");
    this->verticalLayoutKeySequenceEdit_3.setAlignment(Qt::AlignCenter);
    this->gridLayouWidgetScrollArea.addWidget(&this->verticalLayoutKeySequenceEdit_3, 0, 3, 1, 1);

    this->verticalLayoutKeySequenceEdit_4.setText("Сочетание 4");
    this->verticalLayoutKeySequenceEdit_4.setAlignment(Qt::AlignCenter);
    this->gridLayouWidgetScrollArea.addWidget(&this->verticalLayoutKeySequenceEdit_4, 0, 4, 1, 1);

    this->labelName.setText(" --- Общие сочетания клавиш --- ");
    this->labelName.setAlignment(Qt::AlignCenter);
    this->labelName.setStyleSheet("font-weight: bold; text-decoration: underline;");
    this->gridLayouWidgetScrollArea.addWidget(&this->labelName, 1, 0, 1, 5);

    this->labelOpenFile.setText("Открыть файл");
    this->gridLayouWidgetScrollArea.addWidget(&this->labelOpenFile, 2, 0, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditOpenFile_1, 2, 1, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditOpenFile_2, 2, 2, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditOpenFile_3, 2, 3, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditOpenFile_4, 2, 4, 1, 1);

    this->labelSaveOpenScheme.setText("Сохранить открытую схему");
    this->gridLayouWidgetScrollArea.addWidget(&this->labelSaveOpenScheme, 3, 0, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditSaveOpenScheme_1, 3, 1, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditSaveOpenScheme_2, 3, 2, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditSaveOpenScheme_3, 3, 3, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditSaveOpenScheme_4, 3, 4, 1, 1);

    this->labelDeleteOpenScheme.setText("Удалить открытую схему");
    this->gridLayouWidgetScrollArea.addWidget(&this->labelDeleteOpenScheme, 4, 0, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditDeleteOpenScheme_1, 4, 1, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditDeleteOpenScheme_2, 4, 2, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditDeleteOpenScheme_3, 4, 3, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditDeleteOpenScheme_4, 4, 4, 1, 1);

    this->labelShortcutWidget.setText("Сочетания клавиш");
    this->gridLayouWidgetScrollArea.addWidget(&this->labelShortcutWidget, 5, 0, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditShortcutWidget_1, 5, 1, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditShortcutWidget_2, 5, 2, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditShortcutWidget_3, 5, 3, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->keySequenceEditShortcutWidget_4, 5, 4, 1, 1);

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
    Settings::setDefaultShrotcuts();
    setShortcutInWidget();
    emit clickedSetDefaultShortcut();
}

void ShortcutWidget::onClickedCancel()
{
    setShortcutInWidget();
    emit clickedCancel();
}

void ShortcutWidget::onClickedSave()
{
    saveShortcutInFile();
    emit clickedSave();
    this->close();
}

void ShortcutWidget::setShortcutInWidget()
{
    QList<QKeySequence> listShortcutOpenFile = Settings::getListShortcutActionOpenFile();
    for (int i = 0; i < listShortcutOpenFile.size(); i++) {
        this->listShortcutOpenFile[i]->setKeySequence(listShortcutOpenFile[i]);
    }

    QList<QKeySequence> listShortcutEditSaveOpenScheme = Settings::getListShortcutActionSaveScheme();
    for (int i = 0; i < listShortcutEditSaveOpenScheme.size(); i++) {
        this->listShortcutEditSaveOpenScheme[i]->setKeySequence(listShortcutEditSaveOpenScheme[i]);
    }

    QList<QKeySequence> listShortcutDeleteOpenScheme = Settings::getListShortcutActionDeleteOpenScheme();
    for (int i = 0; i < listShortcutDeleteOpenScheme.size(); i++) {
        this->listShortcutDeleteOpenScheme[i]->setKeySequence(listShortcutDeleteOpenScheme[i]);
    }

    QList<QKeySequence> listShortcutShortcutWidget = Settings::getListShortcutActionOpenShortcutWidget();
    for (int i = 0; i < listShortcutShortcutWidget.size(); i++) {
        this->listShortcutShortcutWidget[i]->setKeySequence(listShortcutShortcutWidget[i]);
    }
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
