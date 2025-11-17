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
int SchemeObliqueChartScene::defaultCountHalfrow{2};
bool SchemeObliqueChartScene::defaultIsNode1_2{true};
QString SchemeObliqueChartScene::defaultNameScheme{"Феникс"};
QBrush SchemeObliqueChartScene::defaultBrush{QBrush(Qt::gray)};

SchemeObliqueChartScene::SchemeObliqueChartScene(const int &countThreads, const int &countHalfrow, const bool &isNode1_2): info(this), nodes(this), parts(this), connects(this), colors(this), history(this)
{
    this->editScene(countThreads, countHalfrow, isNode1_2);

    this->commonCreate();
}

SchemeObliqueChartScene::SchemeObliqueChartScene(const int &countThreads, const int &countHalfrow, const bool &isNode1_2, const QList<int> &nodeDirections, const QList<QBrush> &colorThreads): info(this), nodes(this), parts(this), connects(this), colors(this), history(this)
{
    this->editScene(countThreads, countHalfrow, isNode1_2, nodeDirections, colorThreads);

    this->commonCreate();
}

SchemeObliqueChartScene::~SchemeObliqueChartScene()
{
    this->removeScene();
}

void SchemeObliqueChartScene::editNodesDirectionsRemoveLeft()
{
    if (this->isActive()) {

    }
    this->editNodes(SchemeOblique::Directions::REMOVE_LEFT, true, true);
}

void SchemeObliqueChartScene::editNodesDirectionsRemoveRight()
{
    this->editNodes(SchemeOblique::Directions::REMOVE_RIGHT, true, true);
}

void SchemeObliqueChartScene::editNodesDirectionsAddLeft()
{
    this->editNodes(SchemeOblique::Directions::ADD_LEFT, true, true);
}

void SchemeObliqueChartScene::editNodesDirectionsAddRight()
{
    this->editNodes(SchemeOblique::Directions::ADD_RIGHT, true, true);
}

void SchemeObliqueChartScene::editNodesDirectionsRemoveBottom()
{
    this->editNodes(SchemeOblique::Directions::REMOVE_BOTTOM, true, true);
}

void SchemeObliqueChartScene::editNodesDirectionsRemoveTop()
{
    this->editNodes(SchemeOblique::Directions::REMOVE_TOP, true, true);
}

void SchemeObliqueChartScene::editNodesDirectionsAddBottom()
{
    this->editNodes(SchemeOblique::Directions::ADD_BOTTOM, true, true);
}

void SchemeObliqueChartScene::editNodesDirectionsAddTop()
{
    this->editNodes(SchemeOblique::Directions::ADD_TOP, true, true);
}

void SchemeObliqueChartScene::updateScene()
{
    this->updateRectScene();
    this->updateEnabledEditNodeAndThread();
    this->updateEnabledHistory();

    this->update();
}

void SchemeObliqueChartScene::backHistory()
{
    this->history.back();
}

void SchemeObliqueChartScene::nextHistory()
{
    this->history.next();
}

void SchemeObliqueChartScene::editFromHistory(const int &numberRow, const int &numberColumn, const SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode &directionsNode)
{
    this->nodes.setNodeDirection(numberRow, numberColumn, directionsNode);

    this->updateScene();
}

void SchemeObliqueChartScene::editFromHistory(const int &numberThread, const QBrush &brush)
{
    SchemeObliqueObjectPart *part = this->parts.getThreadBeggining(this->nodes.top).at(numberThread);

    part->setColor(brush);
    part->updateColor();

    this->updateScene();
}

void SchemeObliqueChartScene::editFromHistory(const SchemeOblique::Directions &direction, const QList<SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode> &directionNode, const QBrush &brush)
{
    switch (direction) {
    case SchemeOblique::Directions::ADD_TOP:
        this->nodes.createNodeTop();
        this->parts.createPartsTop(this->nodes.top);
        this->connects.createConnectsTop(this->nodes.top);
        this->colors.createColorsTop(this->nodes.top);
        this->nodes.setNodeDirectionTop(directionNode);
        break;
    case SchemeOblique::Directions::ADD_BOTTOM:
        this->nodes.createNodeBottom();
        this->parts.createPartsBottom(this->nodes.bottom);
        this->connects.createConnectsBottom(this->nodes.bottom);
        this->colors.createColorsBottom(this->nodes.bottom);
        this->nodes.setNodeDirectionBottom(directionNode);
        break;
    case SchemeOblique::Directions::ADD_LEFT:
        this->nodes.createNodeLeft();
        this->parts.createPartsLeft(this->nodes.left);
        this->connects.createConnectsLeft(this->nodes.left);
        this->colors.createColorsLeft(this->nodes.left);
        this->nodes.setNodeDirectionLeft(directionNode);
        this->parts.setThreadColorsLeft(this->nodes.top.front(), brush);
        break;
    case SchemeOblique::Directions::ADD_RIGHT:
        this->nodes.createNodeRight();
        this->parts.createPartsRight(this->nodes.right);
        this->connects.createConnectsRight(this->nodes.right);
        this->colors.createColorsRight(this->nodes.right);
        this->nodes.setNodeDirectionRight(directionNode);
        this->parts.setThreadColorsRight(this->nodes.top.back(), brush);
        break;
    case SchemeOblique::Directions::REMOVE_TOP:
        this->parts.removePartsTop(this->nodes.top);
        this->nodes.removeNodeTop();
        this->connects.removeConnectsTop(this->nodes.top);
        this->colors.removeColorsTop(this->nodes.top);
        break;
    case SchemeOblique::Directions::REMOVE_BOTTOM:
        this->parts.removePartsBottom(this->nodes.bottom);
        this->nodes.removeNodeBottom();
        this->connects.removeConnectsBottom(this->nodes.bottom);
        this->colors.removeColorsBottom(this->nodes.bottom);
        break;
    case SchemeOblique::Directions::REMOVE_LEFT:
        this->parts.removePartsLeft(this->nodes.left);
        this->nodes.removeNodeLeft();
        this->connects.removeConnectsLeft(this->nodes.left);
        this->colors.removeColorsLeft(this->nodes.left);
        break;
    case SchemeOblique::Directions::REMOVE_RIGHT:
        this->parts.removePartsRight(this->nodes.right);
        this->nodes.removeNodeRight();
        this->connects.removeConnectsRight(this->nodes.right);
        this->colors.removeColorsRight(this->nodes.right);
        break;
    }

    this->updateScene();
}

void SchemeObliqueChartScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem *item = this->itemAt(event->scenePos(), QTransform());
    SchemeObliqueObjectNode *node = dynamic_cast<SchemeObliqueObjectNode *>(item);
    SchemeObliqueObjectPart *part = dynamic_cast<SchemeObliqueObjectPart *>(item);
    if (node) {
        SchemeObliqueWidgetEditDirectionForNewNodeChartScene::DirectionsNode directionsNodeBack = node->directionNode;
        node->click();
        this->history.addHistory(node->getNumberRow(), node->getNumberColumn(), node->directionNode, directionsNodeBack);
        this->updateScene();
    } else if (part) {
        QBrush colorBack = part->brush;
        SchemeObliqueObjectPart* partBeggining = part->click();
        if (partBeggining) {
            this->history.addHistory(this->parts.getThreadBeggining(this->nodes.top).indexOf(partBeggining), partBeggining->brush.color(), colorBack);
            this->updateScene();
        }
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

void SchemeObliqueChartScene::commonCreate()
{
    this->setBackgroundBrush(defaultBrush);
    this->setItemIndexMethod(NoIndex);
}

void SchemeObliqueChartScene::editNodes(const SchemeOblique::Directions &direction, const bool &isUpdate, const bool &isSetHistory)
{
    switch (direction) {
    case SchemeOblique::Directions::ADD_TOP:
        this->nodes.createNodeTop();
        this->parts.createPartsTop(this->nodes.top);
        this->connects.createConnectsTop(this->nodes.top);
        this->colors.createColorsTop(this->nodes.top);
        if (isSetHistory) {
            this->history.addHistory(direction, QBrush(), this->nodes.getNodeDirectionTop());
        }
        break;
    case SchemeOblique::Directions::ADD_BOTTOM:
        this->nodes.createNodeBottom();
        this->parts.createPartsBottom(this->nodes.bottom);
        this->connects.createConnectsBottom(this->nodes.bottom);
        this->colors.createColorsBottom(this->nodes.bottom);
        if (isSetHistory) {
            this->history.addHistory(direction, QBrush(), this->nodes.getNodeDirectionBottom());
        }
        break;
    case SchemeOblique::Directions::ADD_LEFT:
        this->nodes.createNodeLeft();
        this->parts.createPartsLeft(this->nodes.left);
        this->connects.createConnectsLeft(this->nodes.left);
        this->colors.createColorsLeft(this->nodes.left);
        if (isSetHistory) {
            this->history.addHistory(direction, this->parts.getThreadColorsLeft(this->nodes.top.front()), this->nodes.getNodeDirectionLeft());
        }
        break;
    case SchemeOblique::Directions::ADD_RIGHT:
        this->nodes.createNodeRight();
        this->parts.createPartsRight(this->nodes.right);
        this->connects.createConnectsRight(this->nodes.right);
        this->colors.createColorsRight(this->nodes.right);
        if (isSetHistory) {
            this->history.addHistory(direction, this->parts.getThreadColorsRight(this->nodes.top.back()), this->nodes.getNodeDirectionRight());
        }
        break;
    case SchemeOblique::Directions::REMOVE_TOP:
        if (isSetHistory) {
            this->history.addHistory(direction, QBrush(), this->nodes.getNodeDirectionTop());
        }
        this->parts.removePartsTop(this->nodes.top);
        this->nodes.removeNodeTop();
        this->connects.removeConnectsTop(this->nodes.top);
        this->colors.removeColorsTop(this->nodes.top);
        break;
    case SchemeOblique::Directions::REMOVE_BOTTOM:
        if (isSetHistory) {
            this->history.addHistory(direction, QBrush(), this->nodes.getNodeDirectionBottom());
        }
        this->parts.removePartsBottom(this->nodes.bottom);
        this->nodes.removeNodeBottom();
        this->connects.removeConnectsBottom(this->nodes.bottom);
        this->colors.removeColorsBottom(this->nodes.bottom);
        break;
    case SchemeOblique::Directions::REMOVE_LEFT:
        if (isSetHistory) {
            this->history.addHistory(direction, this->parts.getThreadColorsLeft(this->nodes.top.front()), this->nodes.getNodeDirectionLeft());
        }
        this->parts.removePartsLeft(this->nodes.left);
        this->nodes.removeNodeLeft();
        this->connects.removeConnectsLeft(this->nodes.left);
        this->colors.removeColorsLeft(this->nodes.left);
        break;
    case SchemeOblique::Directions::REMOVE_RIGHT:
        if (isSetHistory) {
            this->history.addHistory(direction, this->parts.getThreadColorsRight(this->nodes.top.back()), this->nodes.getNodeDirectionRight());
        }
        this->parts.removePartsRight(this->nodes.right);
        this->nodes.removeNodeRight();
        this->connects.removeConnectsRight(this->nodes.right);
        this->colors.removeColorsRight(this->nodes.right);
        break;
    }

    if (isUpdate || isSetHistory) {
        this->updateScene();
    }
}

void SchemeObliqueChartScene::editScene(const int &countThreads, const int &countHalfrow, const bool &isNode1_2)
{
    this->removeScene();

    QList<SchemeObliqueObjectNode*> listNodes = this->nodes.createNodes(isNode1_2);
    this->parts.createParts(isNode1_2, listNodes);
    this->connects.createConnects(isNode1_2, listNodes);

    for (int i = 0; i < countThreads - SchemeObliqueChartScene::defaultCountThread; ++i) {
        this->editNodes(SchemeOblique::Directions::ADD_RIGHT, false, false);
    }

    for (int i = 0; i < countHalfrow - SchemeObliqueChartScene::defaultCountHalfrow; ++i) {
        this->editNodes(SchemeOblique::Directions::ADD_BOTTOM, false, false);
    }

    this->updateScene();
}

void SchemeObliqueChartScene::editScene(const int &countThreads, const int &countHalfrow, const bool &isNode1_2, const QList<int> &nodeDirections, const QList<QBrush> &colorThreads)
{
    this->removeScene();

    QList<SchemeObliqueObjectNode*> listNodes = this->nodes.createNodes(isNode1_2);
    this->parts.createParts(isNode1_2, listNodes);
    this->connects.createConnects(isNode1_2, listNodes);

    for (int i = 0; i < countThreads - SchemeObliqueChartScene::defaultCountThread; ++i) {
        this->editNodes(SchemeOblique::Directions::ADD_RIGHT, false, false);
    }

    for (int i = 0; i < countHalfrow - SchemeObliqueChartScene::defaultCountHalfrow; ++i) {
        this->editNodes(SchemeOblique::Directions::ADD_BOTTOM, false, false);
    }

    this->nodes.setNodeDirections(nodeDirections);
    this->parts.setThreadColors(this->nodes.top, colorThreads);

    this->updateScene();
}

void SchemeObliqueChartScene::removeScene()
{
    int sizeThread = this->info.getSizeThread() - SchemeObliqueChartScene::defaultCountThread;
    for (int i = 0; i < sizeThread; ++i) {
        this->editNodes(SchemeOblique::Directions::REMOVE_RIGHT, false, false);
    }

    int sizeHalfrow = this->info.getSizeHalfrow() - SchemeObliqueChartScene::defaultCountHalfrow;
    for (int i = 0; i < sizeHalfrow; ++i) {
        this->editNodes(SchemeOblique::Directions::REMOVE_BOTTOM, false, false);
    }

    if (this->nodes.top.size() != 0 && this->nodes.bottom.size() != 0) {
        this->parts.removeParts(*this->nodes.top.back(), *this->nodes.bottom.back());
        this->nodes.removeNodes();
    }
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
        emit this->actionEnableRemoveThreadLeftAndRight(false);
    } else {
        emit this->actionEnableRemoveThreadLeftAndRight(true);
    }

    if (this->info.getSizeHalfrow() == SchemeObliqueChartScene::defaultCountHalfrow) {
        emit this->actionEnableRemoveHalfrowDownAndTop(false);
    } else {
        emit this->actionEnableRemoveHalfrowDownAndTop(true);
    }

    if (this->info.getSizeThread() == SchemeObliqueChartScene::maximumCount) {
        emit this->actionEnableAddThreadLeftAndRight(false);
    } else {
        emit this->actionEnableAddThreadLeftAndRight(true);
    }

    if (this->info.getSizeHalfrow() == SchemeObliqueChartScene::maximumCount) {
        emit this->actionEnableAddHalfrowDownAndTop(false);
    } else {
        emit this->actionEnableAddHalfrowDownAndTop(true);
    }
}

void SchemeObliqueChartScene::updateEnabledHistory()
{
    if (this->history.getIterator() == this->history.getIteratorMinimum()) {
        emit this->actionEnableBack(false);
    } else {
        emit this->actionEnableBack(true);
    }

    if (this->history.getIterator() == this->history.getIteratorMaximum()) {
        emit this->actionEnableNext(false);
    } else {
        emit this->actionEnableNext(true);
    }
}
