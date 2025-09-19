#ifndef SCHEMEOBLIQUEWIDGETEDITDIRECTIONFORNEWNODECHARTSCENE_H
#define SCHEMEOBLIQUEWIDGETEDITDIRECTIONFORNEWNODECHARTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include "Scheme/Oblique/Object/schemeobliqueobjectnode.h"
#include "Scheme/Oblique/Object/schemeobliqueobjectpart.h"

class SchemeObliqueWidgetEditDirectionForNewNodeChartScene : public QGraphicsScene
{
    Q_OBJECT

public:
    SchemeObliqueWidgetEditDirectionForNewNodeChartScene();
    ~SchemeObliqueWidgetEditDirectionForNewNodeChartScene();

protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    SchemeObliqueObjectNode *node;
    SchemeObliqueObjectPart *partLeftTop;
    SchemeObliqueObjectPart *partLeftBottom;
    SchemeObliqueObjectPart *partRightTop;
    SchemeObliqueObjectPart *partRightBottom;
};

#endif // SCHEMEOBLIQUEWIDGETEDITDIRECTIONFORNEWNODECHARTSCENE_H
