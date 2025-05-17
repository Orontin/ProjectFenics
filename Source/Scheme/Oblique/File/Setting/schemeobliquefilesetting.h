#ifndef SCHEMEOBLIQUEFILESETTING_H
#define SCHEMEOBLIQUEFILESETTING_H

#include "Abstract/abstractschemefilesetting.h"

#include "Scheme/Oblique/Object/schemeobliqueobjectnode.h"

class SchemeObliqueFileSetting: public AbstractSchemeFileSetting
{
public:
    static void setStandartDirectionObliqueNode(const SchemeObliqueObjectNode::DirectionsNode &standartDirectionObliqueNode);
    static SchemeObliqueObjectNode::DirectionsNode getStandartDirectionObliqueNode();
};

#endif // SCHEMEOBLIQUEFILESETTING_H
