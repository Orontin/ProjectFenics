#include "schemeobliquewidgeteditdirectionfornewnodewindow.h"

#include "Scheme/Oblique/Widget/EditDirectionForNewNode/Chart/schemeobliquewidgeteditdirectionfornewnodechartview.h"

#include "Scheme/Oblique/File/Setting/schemeobliquefilesettings.h"

#include <QScreen>

SchemeObliqueWidgetEditDirectionForNewNodeWindow *SchemeObliqueWidgetEditDirectionForNewNodeWindow::schemeObliqueWidgetEditDirectionForNewNodeWindow{nullptr};

SchemeObliqueWidgetEditDirectionForNewNodeWindow &SchemeObliqueWidgetEditDirectionForNewNodeWindow::getInstance()
{
    if (!SchemeObliqueWidgetEditDirectionForNewNodeWindow::schemeObliqueWidgetEditDirectionForNewNodeWindow) {
        SchemeObliqueWidgetEditDirectionForNewNodeWindow::schemeObliqueWidgetEditDirectionForNewNodeWindow = new SchemeObliqueWidgetEditDirectionForNewNodeWindow;
    }
    return *SchemeObliqueWidgetEditDirectionForNewNodeWindow::schemeObliqueWidgetEditDirectionForNewNodeWindow;
}

void SchemeObliqueWidgetEditDirectionForNewNodeWindow::open()
{
    this->visible();
}

void SchemeObliqueWidgetEditDirectionForNewNodeWindow::moveEvent(QMoveEvent *event)
{
    Q_UNUSED(event)

    SchemeObliqueFileSettings::setEditDirectionForNewNodeWindowX(this->geometry().x());
    SchemeObliqueFileSettings::setEditDirectionForNewNodeWindowY(this->geometry().y());

    SchemeObliqueFileSettings::setEditDirectionForNewNodeWindowScreenWidth(this->screen()->geometry().width());
    SchemeObliqueFileSettings::setEditDirectionForNewNodeWindowScreenHeight(this->screen()->geometry().height());
}

void SchemeObliqueWidgetEditDirectionForNewNodeWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)

    SchemeObliqueFileSettings::setEditDirectionForNewNodeWindowWidth(this->geometry().width());
    SchemeObliqueFileSettings::setEditDirectionForNewNodeWindowHeight(this->geometry().height());

    SchemeObliqueFileSettings::setEditDirectionForNewNodeWindowScreenWidth(this->screen()->geometry().width());
    SchemeObliqueFileSettings::setEditDirectionForNewNodeWindowScreenHeight(this->screen()->geometry().height());
}

SchemeObliqueWidgetEditDirectionForNewNodeWindow::SchemeObliqueWidgetEditDirectionForNewNodeWindow(QWidget *parent): QWidget(parent)
{
    this->setWindowTitle("Изменить направление новых узлов");
    this->setWindowModality(Qt::ApplicationModal);
    this->setPosition();

    this->gridLayout.setSpacing(0);
    this->gridLayout.setContentsMargins(0, 0, 0, 0);
    this->gridLayout.addWidget(&SchemeObliqueWidgetEditDirectionForNewNodeChartView::getInstance());
    this->setLayout(&this->gridLayout);
}

SchemeObliqueWidgetEditDirectionForNewNodeWindow::~SchemeObliqueWidgetEditDirectionForNewNodeWindow()
{

}

void SchemeObliqueWidgetEditDirectionForNewNodeWindow::visible()
{
    this->show();
    this->setPosition();
}

void SchemeObliqueWidgetEditDirectionForNewNodeWindow::setPosition()
{
    int screenWidth = this->screen()->geometry().width();
    int screenHeight = this->screen()->geometry().height();

    int colorMapWindowScreenWidth = SchemeObliqueFileSettings::getEditDirectionForNewNodeWindowScreenWidth(screenWidth);
    int colorMapWindowScreenHeight = SchemeObliqueFileSettings::getEditDirectionForNewNodeWindowScreenHeight(screenHeight);

    this->setGeometry(
        ((SchemeObliqueFileSettings::getEditDirectionForNewNodeWindowX() * screenWidth) / colorMapWindowScreenWidth),
        ((SchemeObliqueFileSettings::getEditDirectionForNewNodeWindowY() * screenHeight) / colorMapWindowScreenHeight),
        ((SchemeObliqueFileSettings::getEditDirectionForNewNodeWindowWidth() * screenWidth) / colorMapWindowScreenWidth),
        ((SchemeObliqueFileSettings::getEditDirectionForNewNodeWindowHeight() * screenHeight) / colorMapWindowScreenHeight)
    );
    this->setMinimumSize(this->geometry().width(), this->geometry().height());
    this->setMaximumSize(this->geometry().width(), this->geometry().height());
}
