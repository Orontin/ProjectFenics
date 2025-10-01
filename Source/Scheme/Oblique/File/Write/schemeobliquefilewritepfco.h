#ifndef SCHEMEOBLIQUEFILEWRITEPFCO_H
#define SCHEMEOBLIQUEFILEWRITEPFCO_H

#include "Abstract/abstractschemefilewrite.h"

#include <QByteArray>

class SchemeObliqueFileWritePFCO : public AbstractSchemeFileWrite
{
public:
    static SchemeObliqueFileWritePFCO &getInstance();

    QByteArray writeScheme(const AbstractSchemeChartView &view) override final;

private:
    SchemeObliqueFileWritePFCO();
    ~SchemeObliqueFileWritePFCO();

    static SchemeObliqueFileWritePFCO *schemeObliqueFileWritePFCO;
};

#endif // SCHEMEOBLIQUEFILEWRITEPFCO_H
