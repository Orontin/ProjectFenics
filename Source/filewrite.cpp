#include "filewrite.h"

#include "Abstract/abstractschemefilesetting.h"

#include <QFileDialog>
#include <QMessageBox>

FileWrite::FileWrite(QList<AbstractScheme *> &schemes): schemes(schemes)
{

}

FileWrite::~FileWrite()
{

}

void FileWrite::writeFile(AbstractSchemeChartView &view)
{
    for (AbstractScheme *scheme : schemes) {
        if (view.getTypeScheme() == scheme->typeScheme) {
            QFileDialog dialog(nullptr, "Сохранить схему",
                               AbstractSchemeFileSetting::getValue("FileWriteDirectory", QDir::homePath()).isEmpty() ? QDir::homePath() : AbstractSchemeFileSetting::getValue("FileWriteDirectory", QDir::homePath()),
                               scheme->fileWrite->filter);
            dialog.setFileMode(QFileDialog::AnyFile);
            dialog.setAcceptMode(QFileDialog::AcceptSave);
            dialog.setDefaultSuffix(scheme->fileWrite->prefix);
            dialog.selectFile(view.name);

            if (dialog.exec()) {
                AbstractSchemeFileSetting::setValue("FileWriteDirectory", dialog.directory().path());
                QString filePath = dialog.selectedFiles().back();
                if (!filePath.isEmpty()) {
                    QFile file(filePath);
                    if (file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate)) {
                        file.write(scheme->fileWrite->writeScheme(view));
                        file.close();
                    } else {
                        QMessageBox::warning(nullptr, filePath, "Не удалось создать/перезаписать файл");
                    }
                }
            }
        }
    }
}
