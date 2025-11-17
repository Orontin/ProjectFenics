#ifndef SCHEMEOBLIQUEWIDGETEDITDIRECTIONFORNEWNODECHARTSCENE_H
#define SCHEMEOBLIQUEWIDGETEDITDIRECTIONFORNEWNODECHARTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include "Scheme/Oblique/Object/schemeobliqueobjectpart.h"

class SchemeObliqueWidgetEditDirectionForNewNodeChartScene : public QGraphicsScene
{
    Q_OBJECT

public:
    enum DirectionsNode {
        GAP                                 = 0,
        PARALLEL                            = 1,
        LEFT_UP__IN__RIGHT_BOTTOM_NO_NODE   = 2,
        RIGHT_UP__IN__LEFT_BOTTOM_NO_NODE   = 3,
        LEFT_UP__IN__LEFT_BOTTOM            = 4,
        RIGHT_UP__IN__RIGHT_BOTTOM          = 5,
        LEFT_UP__IN__RIGHT_BOTTOM           = 6,
        RIGHT_UP__IN__LEFT_BOTTOM           = 7,
    };

    static SchemeObliqueWidgetEditDirectionForNewNodeChartScene &getInstance();

    void setStandartDirectionObliqueNode(const SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode &directionNode);
    SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode getStandartDirectionObliqueNode();

protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    SchemeObliqueWidgetEditDirectionForNewNodeChartScene();
    ~SchemeObliqueWidgetEditDirectionForNewNodeChartScene();

    static SchemeObliqueWidgetEditDirectionForNewNodeChartScene *schemeObliqueWidgetEditDirectionForNewNodeChartScene;

    SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode standartDirectionObliqueNode;

    SchemeObliqueObjectNode *node;
    SchemeObliqueObjectPart *partLeftTop;
    SchemeObliqueObjectPart *partLeftBottom;
    SchemeObliqueObjectPart *partRightTop;
    SchemeObliqueObjectPart *partRightBottom;
};

#endif // SCHEMEOBLIQUEWIDGETEDITDIRECTIONFORNEWNODECHARTSCENE_H
