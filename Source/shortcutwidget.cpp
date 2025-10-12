#include "shortcutwidget.h"

ShortcutWidget::ShortcutWidget()
{
    this->setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
    this->setWindowModality(Qt::ApplicationModal);
    this->setWindowTitle("Настройка сочетаний клавиш");
    this->resize(400, 800);

    this->gridLayout.setSizeConstraint(QLayout::SetFixedSize);
    this->gridLayout.addWidget(nullptr, 0, 0, 1, 1);

    this->verticalLayoutKeySequenceEdit_1.setText("Сочетание 1");
    this->verticalLayoutKeySequenceEdit_1.setAlignment(Qt::AlignCenter);
    this->gridLayout.addWidget(&verticalLayoutKeySequenceEdit_1, 0, 1, 1, 1);

    this->verticalLayoutKeySequenceEdit_2.setText("Сочетание 2");
    this->verticalLayoutKeySequenceEdit_2.setAlignment(Qt::AlignCenter);
    this->gridLayout.addWidget(&verticalLayoutKeySequenceEdit_2, 0, 2, 1, 1);

    this->verticalLayoutKeySequenceEdit_3.setText("Сочетание 3");
    this->verticalLayoutKeySequenceEdit_3.setAlignment(Qt::AlignCenter);
    this->gridLayout.addWidget(&verticalLayoutKeySequenceEdit_3, 0, 3, 1, 1);

    this->verticalLayoutKeySequenceEdit_4.setText("Сочетание 4");
    this->verticalLayoutKeySequenceEdit_4.setAlignment(Qt::AlignCenter);
    this->gridLayout.addWidget(&verticalLayoutKeySequenceEdit_4, 0, 4, 1, 1);

    this->labelName.setText(" --- Общие сочетания клавиш --- ");
    this->labelName.setAlignment(Qt::AlignCenter);
    this->labelName.setStyleSheet("font-weight: bold");
    this->gridLayout.addWidget(&labelName, 1, 0, 1, 5);

    this->labelOpenFile.setText("Открыть файл");
    this->gridLayout.addWidget(&labelOpenFile, 2, 0, 1, 1);
    this->gridLayout.addWidget(&KeySequenceEditOpenFile_1, 2, 1, 1, 1);
    this->gridLayout.addWidget(&KeySequenceEditOpenFile_2, 2, 2, 1, 1);
    this->gridLayout.addWidget(&KeySequenceEditOpenFile_3, 2, 3, 1, 1);
    this->gridLayout.addWidget(&KeySequenceEditOpenFile_4, 2, 4, 1, 1);

    this->labelSaveOpenScheme.setText("Сохранить открытую схему");
    this->gridLayout.addWidget(&labelSaveOpenScheme, 3, 0, 1, 1);
    this->gridLayout.addWidget(&KeySequenceEditSaveOpenScheme_1, 3, 1, 1, 1);
    this->gridLayout.addWidget(&KeySequenceEditSaveOpenScheme_2, 3, 2, 1, 1);
    this->gridLayout.addWidget(&KeySequenceEditSaveOpenScheme_3, 3, 3, 1, 1);
    this->gridLayout.addWidget(&KeySequenceEditSaveOpenScheme_4, 3, 4, 1, 1);

    this->labelDeleteOpenScheme.setText("Удалить открытую схему");
    this->gridLayout.addWidget(&labelDeleteOpenScheme, 4, 0, 1, 1);
    this->gridLayout.addWidget(&KeySequenceEditDeleteOpenScheme_1, 4, 1, 1, 1);
    this->gridLayout.addWidget(&KeySequenceEditDeleteOpenScheme_2, 4, 2, 1, 1);
    this->gridLayout.addWidget(&KeySequenceEditDeleteOpenScheme_3, 4, 3, 1, 1);
    this->gridLayout.addWidget(&KeySequenceEditDeleteOpenScheme_4, 4, 4, 1, 1);

    this->labelShortcutWidget.setText("Сочетания клавиш");
    this->gridLayout.addWidget(&labelShortcutWidget, 5, 0, 1, 1);
    this->gridLayout.addWidget(&KeySequenceEditShortcutWidget_1, 5, 1, 1, 1);
    this->gridLayout.addWidget(&KeySequenceEditShortcutWidget_2, 5, 2, 1, 1);
    this->gridLayout.addWidget(&KeySequenceEditShortcutWidget_3, 5, 3, 1, 1);
    this->gridLayout.addWidget(&KeySequenceEditShortcutWidget_4, 5, 4, 1, 1);

    this->setLayout(&this->gridLayout);
}

ShortcutWidget::~ShortcutWidget()
{

}
