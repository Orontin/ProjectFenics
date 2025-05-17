#ifndef SCHEMEOBLIQUEWIDGETEDITDIRECTIONFORNEWNODESCENE_H
#define SCHEMEOBLIQUEWIDGETEDITDIRECTIONFORNEWNODESCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include "Scheme/Oblique/Object/schemeobliqueobjectnode.h"
#include "Scheme/Oblique/Object/schemeobliqueobjectpart.h"

class SchemeObliqueWidgetEditDirectionForNewNodeScene : public QGraphicsScene
{
    Q_OBJECT

public:
    SchemeObliqueWidgetEditDirectionForNewNodeScene();
    ~SchemeObliqueWidgetEditDirectionForNewNodeScene();

protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    SchemeObliqueObjectNode *node;
    SchemeObliqueObjectPart *partLeftTop;
    SchemeObliqueObjectPart *partLeftBottom;
    SchemeObliqueObjectPart *partRightTop;
    SchemeObliqueObjectPart *partRightBottom;
};

#endif // SCHEMEOBLIQUEWIDGETEDITDIRECTIONFORNEWNODESCENE_H
