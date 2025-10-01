#ifndef SCHEMEOBLIQUEFILEWRITEPFCO_H
#define SCHEMEOBLIQUEFILEWRITEPFCO_H

#include "Abstract/abstractschemefilewrite.h"

#include <QByteArray>

class SchemeObliqueFileWritePFCO : public AbstractSchemeFileWrite
{
public:
    SchemeObliqueFileWritePFCO();
    ~SchemeObliqueFileWritePFCO();

    QByteArray writeScheme(const AbstractSchemeChartView &view) override final;
};

#endif // SCHEMEOBLIQUEFILEWRITEPFCO_H
