#include "schemeobliquechartscene.h"

#include "Scheme/Oblique/Object/schemeobliqueobjectnode.h"

int SchemeObliqueChartScene::spaceBetweenNodeOne{68};
int SchemeObliqueChartScene::spaceBetweenNodeTwo{spaceBetweenNodeOne * 2};
int SchemeObliqueChartScene::spaceBetweenNodeThree{spaceBetweenNodeOne * 3};
int SchemeObliqueChartScene::spaceBetweenNodeFour{spaceBetweenNodeOne * 4};
int SchemeObliqueChartScene::spaceBetweenNodeFive{spaceBetweenNodeOne * 5};
int SchemeObliqueChartScene::spaceBetweenNodeSix{spaceBetweenNodeOne * 6};

int SchemeObliqueChartScene::maximumCount{2147483647};
int SchemeObliqueChartScene::defaultCountThread{3};
int SchemeObliqueChartScene:: defaultCountHalfrow{2};
bool SchemeObliqueChartScene::defaultIsNode1_2{true};
QString SchemeObliqueChartScene::defaultNameScheme{"Феникс"};
QBrush SchemeObliqueChartScene::defaultBrush{QBrush(Qt::gray)};

SchemeObliqueChartScene::SchemeObliqueChartScene(const int &countThreads, const int &countHalfrow, const bool &isNode1_2): info(this), nodes(this), parts(this), connects(this), colors(this)
{
    this->setBackgroundBrush(defaultBrush);
    this->setItemIndexMethod(NoIndex);

    this->editScene(countThreads, countHalfrow, isNode1_2);
}

SchemeObliqueChartScene::SchemeObliqueChartScene(const int &countThreads, const int &countHalfrow, const bool &isNode1_2, const QList<int> &nodeDirections, QList<QBrush> &colorThreads): info(this), nodes(this), parts(this), connects(this), colors(this)
{
    this->setBackgroundBrush(defaultBrush);
    this->setItemIndexMethod(NoIndex);

    this->editScene(countThreads, countHalfrow, isNode1_2, nodeDirections, colorThreads);
}

SchemeObliqueChartScene::~SchemeObliqueChartScene()
{
    removeScene();
}

void SchemeObliqueChartScene::editScene(const int &countThreads, const int &countHalfrow, const bool &isNode1_2)
{
    removeScene();

    QList<SchemeObliqueObjectNode*> listNodes = this->nodes.createNodes(isNode1_2);
    this->parts.createParts(isNode1_2, listNodes);
    this->connects.createConnects(isNode1_2, listNodes);

    for (int i = 0; i < countThreads - SchemeObliqueChartScene::defaultCountThread; ++i) {
        this->editNodes(AbstractSchemeChartScene::Directions::ADD_RIGHT, false);
    }

    for (int i = 0; i < countHalfrow - SchemeObliqueChartScene::defaultCountHalfrow; ++i) {
        this->editNodes(AbstractSchemeChartScene::Directions::ADD_BOTTOM, false);
    }

    this->updateScene();
}

void SchemeObliqueChartScene::editScene(const int &countThreads, const int &countHalfrow, const bool &isNode1_2, const QList<int> &nodeDirections, QList<QBrush> &colorThreads)
{
    removeScene();

    QList<SchemeObliqueObjectNode*> listNodes = this->nodes.createNodes(isNode1_2);
    this->parts.createParts(isNode1_2, listNodes);
    this->connects.createConnects(isNode1_2, listNodes);

    for (int i = 0; i < countThreads - SchemeObliqueChartScene::defaultCountThread; ++i) {
        this->editNodes(AbstractSchemeChartScene::Directions::ADD_RIGHT, false);
    }

    for (int i = 0; i < countHalfrow - SchemeObliqueChartScene::defaultCountHalfrow; ++i) {
        this->editNodes(AbstractSchemeChartScene::Directions::ADD_BOTTOM, false);
    }

    this->nodes.setNodeDirections(nodeDirections);
    this->parts.setThreadColors(this->nodes.top, colorThreads);

    this->updateScene();
}

void SchemeObliqueChartScene::removeScene()
{
    int sizeThread = this->info.getSizeThread() - SchemeObliqueChartScene::defaultCountThread;
    for (int i = 0; i < sizeThread; ++i) {
        this->editNodes(AbstractSchemeChartScene::Directions::REMOVE_RIGHT, false);
    }

    int sizeHalfrow = this->info.getSizeHalfrow() - SchemeObliqueChartScene::defaultCountHalfrow;
    for (int i = 0; i < sizeHalfrow; ++i) {
        this->editNodes(AbstractSchemeChartScene::Directions::REMOVE_BOTTOM, false);
    }

    if (this->nodes.top.size() != 0 && this->nodes.bottom.size() != 0) {
        this->parts.removeParts(*this->nodes.top.back(), *this->nodes.bottom.back());
        this->nodes.removeNodes();
    }
}

void SchemeObliqueChartScene::editNodes(const AbstractSchemeChartScene::Directions &direction, const bool &isUpdate)
{
    switch (direction) {
    case AbstractSchemeChartScene::Directions::ADD_TOP:
        this->nodes.createNodeTop();
        this->parts.createPartsTop(this->nodes.top);
        this->connects.createConnectsTop(this->nodes.top);
        this->colors.createColorsTop(this->nodes.top);
        break;
    case AbstractSchemeChartScene::Directions::ADD_BOTTOM:
        this->nodes.createNodeBottom();
        this->parts.createPartsBottom(this->nodes.bottom);
        this->connects.createConnectsBottom(this->nodes.bottom);
        this->colors.createColorsBottom(this->nodes.bottom);
        break;
    case AbstractSchemeChartScene::Directions::ADD_LEFT:
        this->nodes.createNodeLeft();
        this->parts.createPartsLeft(this->nodes.left);
        this->connects.createConnectsLeft(this->nodes.left);
        this->colors.createColorsLeft(this->nodes.left);
        break;
    case AbstractSchemeChartScene::Directions::ADD_RIGHT:
        this->nodes.createNodeRight();
        this->parts.createPartsRight(this->nodes.right);
        this->connects.createConnectsRight(this->nodes.right);
        this->colors.createColorsRight(this->nodes.right);
        break;
    case AbstractSchemeChartScene::Directions::REMOVE_TOP:
        this->parts.removePartsTop(this->nodes.top);
        this->nodes.removeNodeTop();
        this->connects.removeConnectsTop(this->nodes.top);
        this->colors.removeColorsTop(this->nodes.top);
        break;
    case AbstractSchemeChartScene::Directions::REMOVE_BOTTOM:
        this->parts.removePartsBottom(this->nodes.bottom);
        this->nodes.removeNodeBottom();
        this->connects.removeConnectsBottom(this->nodes.bottom);
        this->colors.removeColorsBottom(this->nodes.bottom);
        break;
    case AbstractSchemeChartScene::Directions::REMOVE_LEFT:
        this->parts.removePartsLeft(this->nodes.left);
        this->nodes.removeNodeLeft();
        this->connects.removeConnectsLeft(this->nodes.left);
        this->colors.removeColorsLeft(this->nodes.left);
        break;
    case AbstractSchemeChartScene::Directions::REMOVE_RIGHT:
        this->parts.removePartsRight(this->nodes.right);
        this->nodes.removeNodeRight();
        this->connects.removeConnectsRight(this->nodes.right);
        this->colors.removeColorsRight(this->nodes.right);
        break;
    }

    if (isUpdate) {
        this->updateScene();
    }
}

void SchemeObliqueChartScene::updateScene()
{
    this->updateRectScene();
    this->updateEnabledEditNodeAndThread();

    this->update();
}

int SchemeObliqueChartScene::getSizeThread()
{
    return info.getSizeThread();
}

int SchemeObliqueChartScene::getSizeHalfrow()
{
    return info.getSizeHalfrow();
}

bool SchemeObliqueChartScene::getIsNode1_2()
{
    return info.getIsNode1_2();
}

QStringList SchemeObliqueChartScene::getNodeDirections()
{
    return info.getNodeDirections();
}

QStringList SchemeObliqueChartScene::getThreadColors()
{
    return info.getThreadColors();
}

void SchemeObliqueChartScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem *item = this->itemAt(event->scenePos(), QTransform());
    SchemeObliqueObjectNode *node = dynamic_cast<SchemeObliqueObjectNode *>(item);
    SchemeObliqueObjectPart *part = dynamic_cast<SchemeObliqueObjectPart *>(item);
    if (node) {
        node->click();
    } else if (part) {
        part->click();
    }
}

void SchemeObliqueChartScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);
}

void SchemeObliqueChartScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
}

void SchemeObliqueChartScene::updateRectScene()
{
    int posX_TopLeft = 0;
    int posY_TopLeft = 0;
    int posX_BottomRight = 0;
    int posY_BottomRight = 0;

    SchemeObliqueObjectNode *top = this->nodes.getTopFront();
    SchemeObliqueObjectNode *right = this->nodes.getRightBack();
    SchemeObliqueObjectNode *bottom = this->nodes.getBottomBack();
    SchemeObliqueObjectNode *left = this->nodes.getLeftFront();

    if (top == left) {
        posX_TopLeft = top->pos.x();
        posY_TopLeft = top->pos.y();
    } else {
        posX_TopLeft = left->pos.x();
        posY_TopLeft = top->pos.y();
    }

    if (bottom == right) {
        posX_BottomRight = bottom->pos.x();
        posY_BottomRight = bottom->pos.y();
    } else {
        posX_BottomRight = right->pos.x();
        posY_BottomRight = bottom->pos.y();
    }
    this->setSceneRect(QRectF(posX_TopLeft - SchemeObliqueChartScene::spaceBetweenNodeThree, posY_TopLeft - SchemeObliqueChartScene::spaceBetweenNodeThree, abs(posX_BottomRight - posX_TopLeft) + SchemeObliqueChartScene::spaceBetweenNodeSix, abs(posY_BottomRight - posY_TopLeft) + SchemeObliqueChartScene::spaceBetweenNodeSix));
}

void SchemeObliqueChartScene::updateEnabledEditNodeAndThread()
{
    if (this->info.getSizeThread() == SchemeObliqueChartScene::defaultCountThread) {
        emit this->enabledRemoveThread(false);
    } else {
        emit this->enabledRemoveThread(true);
    }

    if (this->info.getSizeHalfrow() == SchemeObliqueChartScene::defaultCountHalfrow) {
        emit this->enabledRemoveNode(false);
    } else {
        emit this->enabledRemoveNode(true);
    }

    if (this->info.getSizeThread() == SchemeObliqueChartScene::maximumCount) {
        emit this->enabledAddedThread(false);
    } else {
        emit this->enabledAddedThread(true);
    }

    if (this->info.getSizeHalfrow() == SchemeObliqueChartScene::maximumCount) {
        emit this->enabledAddedNode(false);
    } else {
        emit this->enabledAddedNode(true);
    }
}
