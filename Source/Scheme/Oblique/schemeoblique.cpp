#include "schemeoblique.h"

SchemeOblique::SchemeOblique(): AbstractScheme{}
{

    connect(&actionCreate, &QAction::triggered, &schemeObliqueWidgetCreateScheme, &SchemeObliqueWidgetCreateScheme::createIn);
    connect(&schemeObliqueWidgetCreateScheme, &SchemeObliqueWidgetCreateScheme::createOut, this, &SchemeOblique::createOut);
}

SchemeOblique::~SchemeOblique()
{

}

QAction &SchemeOblique::getActionCreate()
{
    return actionCreate;
}
