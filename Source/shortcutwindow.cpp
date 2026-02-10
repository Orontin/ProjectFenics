#include "shortcutwindow.h"

#include "settings.h"

#include <QScreen>

ShortcutWindow *ShortcutWindow::shortcutWindow{nullptr};

ShortcutWindow &ShortcutWindow::getInstance()
{
    if (!ShortcutWindow::shortcutWindow) {
        ShortcutWindow::shortcutWindow = new ShortcutWindow;
    }
    return *ShortcutWindow::shortcutWindow;
}

QGridLayout &ShortcutWindow::getGridLayouWidgetScrollArea()
{
    return gridLayouWidgetScrollArea;
}

void ShortcutWindow::open()
{
    this->visible();
}

void ShortcutWindow::showEvent(QShowEvent *event)
{
    onClickedCancel();
    QWidget::showEvent(event);
}

void ShortcutWindow::closeEvent(QCloseEvent *event)
{
    onClickedCancel();
    QWidget::closeEvent(event);
}

void ShortcutWindow::moveEvent(QMoveEvent *event)
{
    Q_UNUSED(event)

    Settings::setShortcutWindowX(this->geometry().x());
    Settings::setShortcutWindowY(this->geometry().y());

    Settings::setShortcutWindowScreenWidth(this->screen()->geometry().width());
    Settings::setShortcutWindowScreenHeight(this->screen()->geometry().height());
}

void ShortcutWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)

    Settings::setShortcutWindowWidth(this->geometry().width());
    Settings::setShortcutWindowHeight(this->geometry().height());

    Settings::setShortcutWindowScreenWidth(this->screen()->geometry().width());
    Settings::setShortcutWindowScreenHeight(this->screen()->geometry().height());
}

void ShortcutWindow::onClickedSetDefaultShortcut()
{
    setDefaultShortcutInWidget();
    emit this->clickedShortcutSetDefaultShortcut();
}

void ShortcutWindow::onClickedCancel()
{
    setShortcutInWidget();
    emit this->clickedShortcutCancel();
}

void ShortcutWindow::onClickedSave()
{
    saveShortcutInFile();
    emit this->clickedShortcutSave();
    this->close();
}

ShortcutWindow::ShortcutWindow()
{
    this->setWindowModality(Qt::ApplicationModal);
    this->setWindowTitle("Настройка сочетаний клавиш");
    this->setPosition();

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

    connect(&this->setDefaultShortcut, &QPushButton::clicked, this, &ShortcutWindow::onClickedSetDefaultShortcut);
    connect(&this->cancel, &QPushButton::clicked, this, &ShortcutWindow::onClickedCancel);
    connect(&this->save, &QPushButton::clicked, this, &ShortcutWindow::onClickedSave);
}

ShortcutWindow::~ShortcutWindow()
{

}

void ShortcutWindow::setDefaultShortcutInWidget()
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

void ShortcutWindow::setShortcutInWidget()
{
    QList<QKeySequence> listShortcutOpenFile = Settings::getListShortcutActionOpenFile();
    QList<QKeySequence> listShortcutEditSaveOpenScheme = Settings::getListShortcutActionSaveScheme();
    QList<QKeySequence> listShortcutDeleteOpenScheme = Settings::getListShortcutActionDeleteOpenScheme();
    QList<QKeySequence> listShortcutShortcutWidget = Settings::getListShortcutActionOpenShortcutWidget();

    setInWidget(listShortcutOpenFile, listShortcutEditSaveOpenScheme, listShortcutDeleteOpenScheme, listShortcutShortcutWidget);
}

void ShortcutWindow::setInWidget(QList<QKeySequence> &listShortcutOpenFile, QList<QKeySequence> &listShortcutEditSaveOpenScheme, QList<QKeySequence> &listShortcutDeleteOpenScheme, QList<QKeySequence> &listShortcutShortcutWidget)
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

void ShortcutWindow::saveShortcutInFile()
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

void ShortcutWindow::visible()
{
    this->show();
    this->setPosition();
}

void ShortcutWindow::setPosition()
{
    int screenWidth = this->screen()->geometry().width();
    int screenHeight = this->screen()->geometry().height();

    int colorMapWindowScreenWidth = Settings::getShortcutWindowScreenWidth(screenWidth);
    int colorMapWindowScreenHeight = Settings::getShortcutWindowScreenHeight(screenHeight);

    this->setGeometry(
        ((Settings::getShortcutWindowX(screenWidth) * screenWidth) / colorMapWindowScreenWidth),
        ((Settings::getShortcutWindowY(screenHeight) * screenHeight) / colorMapWindowScreenHeight),
        ((Settings::getShortcutWindowWidth() * screenWidth) / colorMapWindowScreenWidth),
        ((Settings::getShortcutWindowHeight() * screenHeight) / colorMapWindowScreenHeight)
    );
}
