#include "shortcutwidget.h"

#include "settings.h"

ShortcutWidget::ShortcutWidget(): spacer(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding)
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
    this->gridLayouWidgetScrollArea.addWidget(&this->KeySequenceEditOpenFile_1, 2, 1, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->KeySequenceEditOpenFile_2, 2, 2, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->KeySequenceEditOpenFile_3, 2, 3, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->KeySequenceEditOpenFile_4, 2, 4, 1, 1);

    this->labelSaveOpenScheme.setText("Сохранить открытую схему");
    this->gridLayouWidgetScrollArea.addWidget(&this->labelSaveOpenScheme, 3, 0, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->KeySequenceEditSaveOpenScheme_1, 3, 1, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->KeySequenceEditSaveOpenScheme_2, 3, 2, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->KeySequenceEditSaveOpenScheme_3, 3, 3, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->KeySequenceEditSaveOpenScheme_4, 3, 4, 1, 1);

    this->labelDeleteOpenScheme.setText("Удалить открытую схему");
    this->gridLayouWidgetScrollArea.addWidget(&this->labelDeleteOpenScheme, 4, 0, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->KeySequenceEditDeleteOpenScheme_1, 4, 1, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->KeySequenceEditDeleteOpenScheme_2, 4, 2, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->KeySequenceEditDeleteOpenScheme_3, 4, 3, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->KeySequenceEditDeleteOpenScheme_4, 4, 4, 1, 1);

    this->labelShortcutWidget.setText("Сочетания клавиш");
    this->gridLayouWidgetScrollArea.addWidget(&this->labelShortcutWidget, 5, 0, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->KeySequenceEditShortcutWidget_1, 5, 1, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->KeySequenceEditShortcutWidget_2, 5, 2, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->KeySequenceEditShortcutWidget_3, 5, 3, 1, 1);
    this->gridLayouWidgetScrollArea.addWidget(&this->KeySequenceEditShortcutWidget_4, 5, 4, 1, 1);

    this->widgetScrollAreaGridLayout.addItem(&this->gridLayouWidgetScrollArea, 0, 0, 1, 1);
    this->widgetScrollAreaGridLayout.addItem(&this->spacer, 1, 0, 1, 1);
    this->widgetScrollArea.setLayout(&this->widgetScrollAreaGridLayout);
    this->scrollArea.setWidget(&this->widgetScrollArea);
    this->scrollArea.setWidgetResizable(true);
    this->scrollArea.setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    this->scrollArea.setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    this->gridLayout.addWidget(&this->scrollArea);

    this->setLayout(&this->gridLayout);
}

ShortcutWidget::~ShortcutWidget()
{

}
