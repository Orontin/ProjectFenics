#include "shortcutwidget.h"

ShortcutWidget::ShortcutWidget():
    verticalSpacer(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding)
{
    this->setWindowTitle("Настройка сочетаний клавиш");
    this->resize(800, 600);

    this->labelOpenFile.setText("Открыть файл");
    this->labelSaveOpenScheme.setText("Сохранить открытую схему");
    this->labelDeleteOpenScheme.setText("Удалить открытую схему");
    this->labelShortcutWidget.setText("Сочетания клавиш");

    this->verticalLayoutLabel.addWidget(&this->labelOpenFile);
    this->verticalLayoutLabel.addWidget(&this->labelSaveOpenScheme);
    this->verticalLayoutLabel.addWidget(&this->labelDeleteOpenScheme);
    this->verticalLayoutLabel.addWidget(&this->labelShortcutWidget);

    this->verticalLayoutLineEdit.addWidget(&this->lineEditOpenFile);
    this->verticalLayoutLineEdit.addWidget(&this->lineEditSaveOpenScheme);
    this->verticalLayoutLineEdit.addWidget(&this->lineEditDeleteOpenScheme);
    this->verticalLayoutLineEdit.addWidget(&this->lineShortcutWidget);

    this->gridLayoutGroupBoxCommonShortcut.addLayout(&this->verticalLayoutLabel, 0, 0, 1, 1);
    this->gridLayoutGroupBoxCommonShortcut.addLayout(&this->verticalLayoutLineEdit, 0, 1, 1, 1);

    this->groupBoxCommonShortcut.setTitle("Общие сочетания клавиш");
    this->groupBoxCommonShortcut.setLayout(&this->gridLayoutGroupBoxCommonShortcut);

    this->gridLayout.addWidget(&this->groupBoxCommonShortcut);
    this->gridLayout.addItem(&this->verticalSpacer, 1, 0, 1, 1);

    this->setLayout(&this->gridLayout);
}

ShortcutWidget::~ShortcutWidget()
{

}
