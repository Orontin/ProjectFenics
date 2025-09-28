#include "filewrite.h"

#include "settings.h"

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
    for (AbstractScheme *scheme : this->schemes) {
        if (view.getTypeScheme() == scheme->getTypeScheme()) {
            QFileDialog dialog(nullptr, "Сохранить схему",
                               Settings::getFileWriteDirectory(),
                               scheme->getFileWrite().filter);
            dialog.setFileMode(QFileDialog::AnyFile);
            dialog.setAcceptMode(QFileDialog::AcceptSave);
            dialog.setDefaultSuffix(scheme->getFileWrite().prefix);
            dialog.selectFile(view.name);

            if (dialog.exec()) {
                Settings::setFileWriteDirectory(dialog.directory().path());
                QString filePath = dialog.selectedFiles().back();
                if (!filePath.isEmpty()) {
                    QFile file(filePath);
                    if (file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate)) {
                        file.write(scheme->getFileWrite().writeScheme(view));
                        file.close();
                    } else {
                        QMessageBox::warning(nullptr, filePath, "Не удалось создать/перезаписать файл");
                    }
                }
            }
        }
    }
}
