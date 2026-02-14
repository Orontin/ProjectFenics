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
    QFileDialog dialog(nullptr, "Сохранить схему",
                       Settings::getFileDirectoryWrite(),
                       view.getScheme().getFileWrite().filter);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.setDefaultSuffix(view.getScheme().getFileWrite().prefix);
    dialog.selectFile(view.name);

    if (dialog.exec()) {
        Settings::setFileDirectoryWrite(dialog.directory().path());
        QString filePath = dialog.selectedFiles().back();
        if (!filePath.isEmpty()) {
            QFile file(filePath);
            if (file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate)) {
                file.write(view.getScheme().getFileWrite().writeScheme(view));
                file.close();
            } else {
                QMessageBox::warning(nullptr, filePath, "Не удалось создать/перезаписать файл");
            }
        }
    }

    // QSvgGenerator generator;
    // generator.setFileName("C:/Users/oront/Desktop/333.svg");
    // generator.setSize(QSize(view.scene()->width(), view.scene()->height()));          // размер изображения в пикселях (логических)
    // generator.setViewBox(QRect(0, 0, view.scene()->width(), view.scene()->height())); // область, которая попадёт в SVG
    // generator.setTitle(tr("SVG из QGraphicsScene"));
    // generator.setDescription(tr("Создано с помощью Qt"));

    // QPainter painter;
    // painter.begin(&generator);

    // painter.setRenderHint(QPainter::RenderHint::Antialiasing, true);
    // painter.setRenderHint(QPainter::RenderHint::TextAntialiasing, true);
    // painter.setRenderHint(QPainter::RenderHint::SmoothPixmapTransform, true);
    // painter.setRenderHint(QPainter::RenderHint::VerticalSubpixelPositioning, true);
    // painter.setRenderHint(QPainter::RenderHint::LosslessImageRendering, true);
    // painter.setRenderHint(QPainter::RenderHint::NonCosmeticBrushPatterns, true);
    // view.scene()->render(&painter);

    // painter.end();
}
