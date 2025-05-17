#include "schemeobliquewidgeteditdirectionfornewnodeview.h"

#include "Scheme/Oblique/Widget/EditDirectionForNewNode/schemeobliquewidgeteditdirectionfornewnodescene.h"

SchemeObliqueWidgetEditDirectionForNewNodeView::SchemeObliqueWidgetEditDirectionForNewNodeView()
{
    this->setScene(new SchemeObliqueWidgetEditDirectionForNewNodeScene());

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

SchemeObliqueWidgetEditDirectionForNewNodeView::~SchemeObliqueWidgetEditDirectionForNewNodeView()
{
    delete this->scene();
}
