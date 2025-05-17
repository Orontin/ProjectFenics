#include "fileread.h"

#include "Abstract/abstractschemefilesetting.h"

#include <QFileDialog>
#include <QMessageBox>

FileRead::FileRead(QList<AbstractScheme*> &schemes): schemes(schemes)
{
    setFilterRead();
}

FileRead::~FileRead()
{
}

void FileRead::readFile()
{
    QFileDialog dialog(nullptr, "Выберите файл(ы) сохранений",
                       AbstractSchemeFileSetting::getValue("FileReadDirectory", QDir::homePath()).isEmpty() ? QDir::homePath() : AbstractSchemeFileSetting::getValue("FileReadDirectory", QDir::homePath())
                       , this->filter);
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setAcceptMode(QFileDialog::AcceptOpen);

    if (dialog.exec()) {
        AbstractSchemeFileSetting::setValue("FileReadDirectory", dialog.directory().path());
        for (const QString &filePath : dialog.selectedFiles()) {
            QFile file(filePath);
            if (file.open(QFile::OpenModeFlag::ReadOnly)) {
                QString prefix = QFileInfo(file.fileName()).completeSuffix();
                QList<AbstractSchemeFileRead*> listAbstractSchemeFileRead;

                searchAbstractSchemeFileRead(prefix, listAbstractSchemeFileRead);
                workAbstractSchemeFileRead(listAbstractSchemeFileRead, file);
            } else {
                showMessageBoxError(file.fileName(), QString("Не удалось открыть файл"));
            }
        }
    }
}

void FileRead::searchAbstractSchemeFileRead(const QString &prefix, QList<AbstractSchemeFileRead *> &listAbstractSchemeFileRead)
{
    for (AbstractScheme *scheme : schemes) {
        for (AbstractSchemeFileRead *abstractSchemeFileRead : *scheme->listFileRead) {
            if (abstractSchemeFileRead->prefix == prefix) {
                listAbstractSchemeFileRead.push_back(abstractSchemeFileRead);
            }
        }
    }
}

void FileRead::workAbstractSchemeFileRead(QList<AbstractSchemeFileRead*> &listAbstractSchemeFileRead, QFile &file)
{
    try {
        if (listAbstractSchemeFileRead.size() == 0) {
            showMessageBoxError(file.fileName(), QString("Файл не является файлом схемы фенички"));
        } else if (listAbstractSchemeFileRead.size() == 1)  {
            emit createOut(listAbstractSchemeFileRead.back()->readScheme(file.readAll(), QFileInfo(file.fileName()).baseName()));
        } else {
            // задать вопрос какую схему создавать.
        }
    } catch (QString &error) {
        showMessageBoxError(file.fileName(), error);
    }
}

void FileRead::showMessageBoxError(const QString &pathFile, const QString &error)
{
    QMessageBox::warning(nullptr, pathFile, error);
}

void FileRead::setFilterRead()
{
    QString patternFilters = QString("%1;;");
    QString stringFilters = "";

    QString patternSupportFiles = QString("*.%1");
    QString stringSupportFiles = "";

    for (AbstractScheme *scheme : schemes) {
        for (AbstractSchemeFileRead *abstractSchemeFileRead : *scheme->listFileRead) {
            stringFilters = stringFilters + patternFilters.arg(abstractSchemeFileRead->filter);
            stringSupportFiles = stringSupportFiles + patternSupportFiles.arg(abstractSchemeFileRead->prefix);
            stringSupportFiles = stringSupportFiles + QString(" ");
        }
    }

    this->filter = QString("Supported Files (%1);;%2").arg(stringSupportFiles).arg(stringFilters);
}
