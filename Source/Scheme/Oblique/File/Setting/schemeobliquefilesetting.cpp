#include "schemeobliquefilesetting.h"

void SchemeObliqueFileSetting::setStandartDirectionObliqueNode(const SchemeObliqueObjectNode::DirectionsNode &standartDirectionObliqueNode)
{
    AbstractSchemeFileSetting::setValue("standartDirectionObliqueNode", QString::number(static_cast<int>(standartDirectionObliqueNode)));
}

SchemeObliqueObjectNode::DirectionsNode SchemeObliqueFileSetting::getStandartDirectionObliqueNode()
{
    return static_cast<SchemeObliqueObjectNode::DirectionsNode>(AbstractSchemeFileSetting::getValue("standartDirectionObliqueNode", "7").toInt());
}
