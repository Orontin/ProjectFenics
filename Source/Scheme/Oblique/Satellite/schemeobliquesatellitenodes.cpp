#include "schemeobliquesatellitenodes.h"

#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"

SchemeObliqueSatelliteNodes::SchemeObliqueSatelliteNodes(SchemeObliqueChartScene *scene, QObject *parent): QObject(parent), scene(scene)
{

}

SchemeObliqueSatelliteNodes::~SchemeObliqueSatelliteNodes()
{

}

void SchemeObliqueSatelliteNodes::setNodeDirection(const int &numberRow, const int &numberColumn, const SchemeObliqueObjectNode::DirectionsNode &directionsNode)
{
    SchemeObliqueObjectNode *node = this->top.front();

    for (int i = 0; i < numberRow; i++) {
        if (node->nodeLeftBottom && node->nodeLeftBottom->nodeLeftTop != node) {
            node = node->nodeLeftBottom;
        } else if (node->nodeRightBottom && node->nodeRightBottom->nodeRightTop != node) {
            node = node->nodeRightBottom;
        }
    }

    for (int i = 0; i < numberColumn; i++) {
        if (node->nodeRightBottom && node->nodeRightBottom->nodeRightTop && node->nodeRightBottom->nodeRightTop != node && node->nodeRightBottom->nodeRightTop != node->nodeRightTop) {
            node = node->nodeRightBottom->nodeRightTop;
        } else if (node->nodeRightTop && node->nodeRightTop->nodeRightBottom && node->nodeRightTop->nodeRightBottom != node && node->nodeRightTop->nodeRightBottom != node->nodeRightBottom) {
            node = node->nodeRightTop->nodeRightBottom;
        }
    }

    node->editNode(directionsNode);
    node->partLeftTop->updateColor();
    node->partRightTop->updateColor();
}

void SchemeObliqueSatelliteNodes::setNodeDirections(const QList<int> &nodeDirections)
{
    int position = 0;
    QList<SchemeObliqueObjectNode*> oldTopLocal = this->top;
    for (int halfrow = 0; halfrow < this->scene->info.getSizeHalfrow(); ++halfrow) {
        for (SchemeObliqueObjectNode *schemeObliqueObjectNode : oldTopLocal) {
            SchemeObliqueObjectNode::DirectionsNode dirNode = SchemeObliqueObjectNode::DirectionsNode::GAP;
            switch (nodeDirections[position]) {
            case 0:
                dirNode = SchemeObliqueObjectNode::DirectionsNode::GAP;
                break;
            case 1:
                dirNode = SchemeObliqueObjectNode::DirectionsNode::PARALLEL;
                break;
            case 2:
                dirNode = SchemeObliqueObjectNode::DirectionsNode::LEFT_UP__IN__RIGHT_BOTTOM_NO_NODE;
                break;
            case 3:
                dirNode = SchemeObliqueObjectNode::DirectionsNode::RIGHT_UP__IN__LEFT_BOTTOM_NO_NODE;
                break;
            case 4:
                dirNode = SchemeObliqueObjectNode::DirectionsNode::LEFT_UP__IN__LEFT_BOTTOM;
                break;
            case 5:
                dirNode = SchemeObliqueObjectNode::DirectionsNode::RIGHT_UP__IN__RIGHT_BOTTOM;
                break;
            case 6:
                dirNode = SchemeObliqueObjectNode::DirectionsNode::LEFT_UP__IN__RIGHT_BOTTOM;
                break;
            case 7:
                dirNode = SchemeObliqueObjectNode::DirectionsNode::RIGHT_UP__IN__LEFT_BOTTOM;
                break;
            }
            schemeObliqueObjectNode->editNode(dirNode);
            position++;
        }

        QList<SchemeObliqueObjectNode *> newTopLocal;
        if (oldTopLocal.front()->nodeLeftBottom && oldTopLocal.front()->nodeLeftBottom->nodeRightTop && oldTopLocal.front()->nodeLeftBottom->nodeRightTop == oldTopLocal.front()) {
            newTopLocal.push_back(oldTopLocal.front()->nodeLeftBottom);
        }
        for (int i = 0; i < oldTopLocal.size() - 1; ++i) {
            newTopLocal.push_back(oldTopLocal[i]->nodeRightBottom);
        }
        if (oldTopLocal.back()->nodeRightBottom && oldTopLocal.back()->nodeRightBottom->nodeLeftTop && oldTopLocal.back()->nodeRightBottom->nodeLeftTop == oldTopLocal.back()) {
            newTopLocal.push_back(oldTopLocal.back()->nodeRightBottom);
        }
        oldTopLocal = newTopLocal;
    }
}

QStringList SchemeObliqueSatelliteNodes::getNodeDirections()
{
    QStringList listNodeDirections;

    QList<SchemeObliqueObjectNode*> oldTopLocal = this->top;
    for (int halfrow = 0; halfrow < this->scene->info.getSizeHalfrow(); ++halfrow) {
        for (SchemeObliqueObjectNode *schemeObliqueObjectNode : oldTopLocal) {
            listNodeDirections.push_back(QString::number(static_cast<int>(schemeObliqueObjectNode->directionNode)));
        }

        QList<SchemeObliqueObjectNode *> newTopLocal;
        if (oldTopLocal.front()->nodeLeftBottom && oldTopLocal.front()->nodeLeftBottom->nodeRightTop && oldTopLocal.front()->nodeLeftBottom->nodeRightTop == oldTopLocal.front()) {
            newTopLocal.push_back(oldTopLocal.front()->nodeLeftBottom);
        }
        for (int i = 0; i < oldTopLocal.size() - 1; ++i) {
            newTopLocal.push_back(oldTopLocal[i]->nodeRightBottom);
        }
        if (oldTopLocal.back()->nodeRightBottom && oldTopLocal.back()->nodeRightBottom->nodeLeftTop && oldTopLocal.back()->nodeRightBottom->nodeLeftTop == oldTopLocal.back()) {
            newTopLocal.push_back(oldTopLocal.back()->nodeRightBottom);
        }
        oldTopLocal = newTopLocal;
    }

    return listNodeDirections;
}

QList<SchemeObliqueObjectNode::DirectionsNode> SchemeObliqueSatelliteNodes::getNodeDirectionLeft()
{
    QList<SchemeObliqueObjectNode::DirectionsNode> listDirection;

    for (const SchemeObliqueObjectNode *node : this->left) {
        listDirection.push_back(node->directionNode);
    }

    return listDirection;
}

QList<SchemeObliqueObjectNode::DirectionsNode> SchemeObliqueSatelliteNodes::getNodeDirectionRight()
{
    QList<SchemeObliqueObjectNode::DirectionsNode> listDirection;

    for (const SchemeObliqueObjectNode *node : this->right) {
        listDirection.push_back(node->directionNode);
    }

    return listDirection;
}

QList<SchemeObliqueObjectNode::DirectionsNode> SchemeObliqueSatelliteNodes::getNodeDirectionTop()
{
    QList<SchemeObliqueObjectNode::DirectionsNode> listDirection;

    for (const SchemeObliqueObjectNode *node : this->top) {
        listDirection.push_back(node->directionNode);
    }

    return listDirection;
}

QList<SchemeObliqueObjectNode::DirectionsNode> SchemeObliqueSatelliteNodes::getNodeDirectionBottom()
{
    QList<SchemeObliqueObjectNode::DirectionsNode> listDirection;

    for (const SchemeObliqueObjectNode *node : this->bottom) {
        listDirection.push_back(node->directionNode);
    }

    return listDirection;
}

void SchemeObliqueSatelliteNodes::setNodeDirectionLeft(const QList<SchemeObliqueObjectNode::DirectionsNode> &directionLeft)
{
    for (int i = 0; i < directionLeft.size(); i++) {
        this->left[i]->editNode(directionLeft[i]);
    }
}

void SchemeObliqueSatelliteNodes::setNodeDirectionRight(const QList<SchemeObliqueObjectNode::DirectionsNode> &directionRight)
{
    for (int i = 0; i < directionRight.size(); i++) {
        this->right[i]->editNode(directionRight[i]);
    }
}

void SchemeObliqueSatelliteNodes::setNodeDirectionTop(const QList<SchemeObliqueObjectNode::DirectionsNode> &directionTop)
{
    for (int i = 0; i < directionTop.size(); i++) {
        this->top[i]->editNode(directionTop[i]);
    }
}

void SchemeObliqueSatelliteNodes::setNodeDirectionBottom(const QList<SchemeObliqueObjectNode::DirectionsNode> &directionBottom)
{
    for (int i = 0; i < directionBottom.size(); i++) {
        this->bottom[i]->editNode(directionBottom[i]);
    }
}

QList<SchemeObliqueObjectNode*> SchemeObliqueSatelliteNodes::createNodes(const bool &isNode1_2)
{
    QList<SchemeObliqueObjectNode*> listNodes;

    if (isNode1_2) {
        SchemeObliqueObjectNode *node1 = this->createNode(QPoint(0, 0));
        SchemeObliqueObjectNode *node2 = this->createNode(QPoint(SchemeObliqueChartScene::spaceBetweenNodeOne, SchemeObliqueChartScene::spaceBetweenNodeOne));

        node1->nodeRightBottom = node2;
        node2->nodeLeftTop = node1;

        this->top.push_back(node1);
        this->bottom.push_back(node2);
        this->left.push_back(node1);
        this->right.push_back(node2);

        listNodes.push_back(node1);
        listNodes.push_back(node2);
    } else {
        SchemeObliqueObjectNode *node1 = this->createNode(QPoint(SchemeObliqueChartScene::spaceBetweenNodeOne, 0));
        SchemeObliqueObjectNode *node2 = this->createNode(QPoint(0, SchemeObliqueChartScene::spaceBetweenNodeOne));

        node1->nodeLeftBottom = node2;
        node2->nodeRightTop = node1;

        this->top.push_back(node1);
        this->bottom.push_back(node2);
        this->left.push_back(node2);
        this->right.push_back(node1);

        listNodes.push_back(node1);
        listNodes.push_back(node2);
    }

    return listNodes;
}

void SchemeObliqueSatelliteNodes::removeNodes()
{
    this->top.back()->deleteLater();
    this->bottom.back()->deleteLater();

    top.clear();
    right.clear();
    left.clear();
    bottom.clear();
}

void SchemeObliqueSatelliteNodes::createNodeRight()
{
    QList<SchemeObliqueObjectNode *> newRight;

    if (this->right.front()->nodeLeftTop) {
        SchemeObliqueObjectNode *node = this->createNode(QPoint(this->right.front()->nodeLeftTop->pos.x() + SchemeObliqueChartScene::spaceBetweenNodeTwo, this->right.front()->nodeLeftTop->pos.y()));
        this->top.push_back(node);
        newRight.push_back(node);

        this->right.front()->nodeRightTop = node;
        node->nodeLeftBottom = this->right.front();

        if (this->right.front()->nodeLeftBottom) {
            SchemeObliqueObjectNode *node = this->createNode(QPoint(this->right.front()->nodeLeftBottom->pos.x() + SchemeObliqueChartScene::spaceBetweenNodeTwo, this->right.front()->nodeLeftBottom->pos.y()));

            newRight.push_back(node);

            this->right.front()->nodeRightBottom = node;
            node->nodeLeftTop = this->right.front();

            node->nodeRightTop = this->right.front()->nodeRightTop;
            this->right.front()->nodeRightTop->nodeRightBottom = node;
        }
    } else if (this->right.front()->nodeLeftBottom) {
        SchemeObliqueObjectNode *node = this->createNode(QPoint(this->right.front()->nodeLeftBottom->pos.x() + SchemeObliqueChartScene::spaceBetweenNodeTwo, this->right.front()->nodeLeftBottom->pos.y()));

        newRight.push_back(node);

        this->right.front()->nodeRightBottom = node;
        node->nodeLeftTop = this->right.front();
    }

    for (int i = 1; i < this->right.size() - 1; ++i) {
        SchemeObliqueObjectNode *node = this->createNode(QPoint(this->right[i]->nodeLeftBottom->pos.x() + SchemeObliqueChartScene::spaceBetweenNodeTwo, this->right[i]->nodeLeftBottom->pos.y()));

        newRight.push_back(node);

        this->right[i]->nodeRightBottom = node;
        node->nodeLeftTop = this->right[i];

        this->right[i]->nodeRightTop = this->right[i]->nodeLeftTop->nodeRightTop->nodeRightBottom;
        this->right[i]->nodeLeftTop->nodeRightTop->nodeRightBottom->nodeLeftBottom = this->right[i];

        this->right[i]->nodeRightTop->nodeRightBottom = this->right[i]->nodeRightBottom;
        this->right[i]->nodeRightBottom->nodeRightTop = this->right[i]->nodeRightTop;
    }

    if (this->right.back() != this->right.front()) {
        if (this->right.back()->nodeLeftBottom) {
            SchemeObliqueObjectNode *node = this->createNode(QPoint(this->right.back()->nodeLeftBottom->pos.x() + SchemeObliqueChartScene::spaceBetweenNodeTwo, this->right.back()->nodeLeftBottom->pos.y()));

            this->bottom.push_back(node);
            newRight.push_back(node);

            this->right.back()->nodeRightBottom = node;
            node->nodeLeftTop = this->right.back();

            if (this->right.back()->nodeLeftTop) {
                this->right.back()->nodeRightTop = this->right.back()->nodeLeftTop->nodeRightTop->nodeRightBottom;
                this->right.back()->nodeLeftTop->nodeRightTop->nodeRightBottom->nodeLeftBottom = this->right.back();

                this->right.back()->nodeRightTop->nodeRightBottom = this->right.back()->nodeRightBottom;
                this->right.back()->nodeRightBottom->nodeRightTop = this->right.back()->nodeRightTop;
            }
        } else if (this->right.back()->nodeLeftTop) {
            this->right.back()->nodeRightTop = this->right.back()->nodeLeftTop->nodeRightTop->nodeRightBottom;
            this->right.back()->nodeLeftTop->nodeRightTop->nodeRightBottom->nodeLeftBottom = this->right.back();
        }
    } else if (this->right.back()->nodeLeftBottom) {
        this->bottom.push_back(right.back()->nodeRightBottom);
    }

    this->right = newRight;
}

void SchemeObliqueSatelliteNodes::createNodeLeft()
{
    QList<SchemeObliqueObjectNode *> newLeft;

    if (this->left.front()->nodeRightTop) {
        SchemeObliqueObjectNode *node = this->createNode(QPoint(this->left.front()->nodeRightTop->pos.x() - SchemeObliqueChartScene::spaceBetweenNodeTwo, this->left.front()->nodeRightTop->pos.y()));

        this->top.push_front(node);
        newLeft.push_back(node);

        this->left.front()->nodeLeftTop = node;
        node->nodeRightBottom = this->left.front();

        if (this->left.front()->nodeRightBottom) {
            SchemeObliqueObjectNode *node = this->createNode(QPoint(this->left.front()->nodeRightBottom->pos.x() - SchemeObliqueChartScene::spaceBetweenNodeTwo, this->left.front()->nodeRightBottom->pos.y()));

            newLeft.push_back(node);

            this->left.front()->nodeLeftBottom = node;
            node->nodeRightTop = this->left.front();

            node->nodeLeftTop = this->left.front()->nodeLeftTop;
            this->left.front()->nodeLeftTop->nodeLeftBottom = node;
        }
    } else if (this->left.front()->nodeRightBottom) {
        SchemeObliqueObjectNode *node = this->createNode(QPoint(this->left.front()->nodeRightBottom->pos.x() - SchemeObliqueChartScene::spaceBetweenNodeTwo, this->left.front()->nodeRightBottom->pos.y()));

        newLeft.push_back(node);

        this->left.front()->nodeLeftBottom = node;
        node->nodeRightTop = this->left.front();
    }

    for (int i = 1; i < this->left.size() - 1; ++i) {
        SchemeObliqueObjectNode *node = this->createNode(QPoint(this->left[i]->nodeRightBottom->pos.x() - SchemeObliqueChartScene::spaceBetweenNodeTwo, this->left[i]->nodeRightBottom->pos.y()));

        newLeft.push_back(node);

        this->left[i]->nodeLeftBottom = node;
        node->nodeRightTop = this->left[i];

        this->left[i]->nodeLeftTop = this->left[i]->nodeRightTop->nodeLeftTop->nodeLeftBottom;
        this->left[i]->nodeRightTop->nodeLeftTop->nodeLeftBottom->nodeRightBottom = this->left[i];

        this->left[i]->nodeLeftTop->nodeLeftBottom = this->left[i]->nodeLeftBottom;
        this->left[i]->nodeLeftBottom->nodeLeftTop = this->left[i]->nodeLeftTop;
    }

    if (this->left.back() != this->left.front()) {
        if (this->left.back()->nodeRightBottom) {
            SchemeObliqueObjectNode *node = this->createNode(QPoint(this->left.back()->nodeRightBottom->pos.x() - SchemeObliqueChartScene::spaceBetweenNodeTwo, this->left.back()->nodeRightBottom->pos.y()));

            this->bottom.push_front(node);
            newLeft.push_back(node);

            this->left.back()->nodeLeftBottom = node;
            node->nodeRightTop = this->left.back();

            if (this->left.back()->nodeRightTop) {
                this->left.back()->nodeLeftTop = this->left.back()->nodeRightTop->nodeLeftTop->nodeLeftBottom;
                this->left.back()->nodeRightTop->nodeLeftTop->nodeLeftBottom->nodeRightBottom = this->left.back();

                this->left.back()->nodeLeftTop->nodeLeftBottom = this->left.back()->nodeLeftBottom;
                this->left.back()->nodeLeftBottom->nodeLeftTop = this->left.back()->nodeLeftTop;
            }
        } else if (this->left.back()->nodeRightTop) {
            this->left.back()->nodeLeftTop = this->left.back()->nodeRightTop->nodeLeftTop->nodeLeftBottom;
            this->left.back()->nodeRightTop->nodeLeftTop->nodeLeftBottom->nodeRightBottom = this->left.back();
        }
    } else if (this->left.back()->nodeRightBottom) {
        this->bottom.push_front(left.back()->nodeLeftBottom);
    }

    this->left = newLeft;
}

void SchemeObliqueSatelliteNodes::createNodeTop()
{
    QList<SchemeObliqueObjectNode *> newTop;

    if (this->top.front()->nodeLeftBottom && this->top.front()->nodeLeftBottom->nodeRightTop == this->top.front()) {
        SchemeObliqueObjectNode *node = this->createNode(QPoint(this->top.front()->nodeLeftBottom->pos.x(), this->top.front()->nodeLeftBottom->pos.y() - SchemeObliqueChartScene::spaceBetweenNodeTwo));

        this->left.push_front(node);
        newTop.push_back(node);

        this->top.front()->nodeLeftTop = node;
        node->nodeRightBottom = this->top.front();

        this->top.front()->nodeLeftBottom->nodeLeftTop = node;
        node->nodeLeftBottom = this->top.front()->nodeLeftBottom;
    }

    if (this->top.back() != this->top.front()) {
        for (int i = 0; i < this->top.size() - 1; ++i) {
            SchemeObliqueObjectNode *node = this->createNode(QPoint(this->top[i]->nodeRightBottom->pos.x(), this->top[i]->nodeRightBottom->pos.y() - SchemeObliqueChartScene::spaceBetweenNodeTwo));

            newTop.push_back(node);

            this->top[i]->nodeRightTop = node;
            node->nodeLeftBottom = this->top[i];

            this->top[i]->nodeRightBottom->nodeRightTop->nodeLeftTop = node;
            node->nodeRightBottom = this->top[i]->nodeRightBottom->nodeRightTop;
        }
    }

    if (this->top.back()->nodeRightBottom && this->top.back()->nodeRightBottom->nodeLeftTop == this->top.back()) {
        SchemeObliqueObjectNode *node = this->createNode(QPoint(this->top.back()->nodeRightBottom->pos.x(), this->top.back()->nodeRightBottom->pos.y() - SchemeObliqueChartScene::spaceBetweenNodeTwo));

        this->right.push_front(node);
        newTop.push_back(node);

        this->top.back()->nodeRightTop = node;
        node->nodeLeftBottom = this->top.back();

        this->top.back()->nodeRightBottom->nodeRightTop = node;
        node->nodeRightBottom = this->top.back()->nodeRightBottom;
    }

    this->top = newTop;
}

void SchemeObliqueSatelliteNodes::createNodeBottom()
{
    QList<SchemeObliqueObjectNode *> newBottom;

    if (this->bottom.front()->nodeLeftTop && this->bottom.front()->nodeLeftTop->nodeRightBottom == this->bottom.front()) {
        SchemeObliqueObjectNode *node = this->createNode(QPoint(this->bottom.front()->nodeLeftTop->pos.x(), this->bottom.front()->nodeLeftTop->pos.y() + SchemeObliqueChartScene::spaceBetweenNodeTwo));

        this->left.push_back(node);
        newBottom.push_back(node);

        this->bottom.front()->nodeLeftBottom = node;
        node->nodeRightTop = this->bottom.front();

        this->bottom.front()->nodeLeftTop->nodeLeftBottom = node;
        node->nodeLeftTop = this->bottom.front()->nodeLeftTop;
    }

    if (this->bottom.back() != this->bottom.front()) {
        for (int i = 0; i < this->bottom.size() - 1; ++i) {
            SchemeObliqueObjectNode *node = this->createNode(QPoint(this->bottom[i]->nodeRightTop->pos.x(), this->bottom[i]->nodeRightTop->pos.y() + SchemeObliqueChartScene::spaceBetweenNodeTwo));

            newBottom.push_back(node);

            this->bottom[i]->nodeRightBottom = node;
            node->nodeLeftTop = this->bottom[i];

            this->bottom[i]->nodeRightTop->nodeRightBottom->nodeLeftBottom = node;
            node->nodeRightTop = this->bottom[i]->nodeRightTop->nodeRightBottom;
        }
    }

    if (this->bottom.back()->nodeRightTop && this->bottom.back()->nodeRightTop->nodeLeftBottom == this->bottom.back()) {
        SchemeObliqueObjectNode *node = this->createNode(QPoint(this->bottom.back()->nodeRightTop->pos.x(), this->bottom.back()->nodeRightTop->pos.y() + SchemeObliqueChartScene::spaceBetweenNodeTwo));

        this->right.push_back(node);
        newBottom.push_back(node);

        this->bottom.back()->nodeRightBottom = node;
        node->nodeLeftTop = this->bottom.back();

        this->bottom.back()->nodeRightTop->nodeRightBottom = node;
        node->nodeRightTop = this->bottom.back()->nodeRightTop;
    }

    this->bottom = newBottom;
}

void SchemeObliqueSatelliteNodes::removeNodeRight()
{
    QList<SchemeObliqueObjectNode *> newRight;

    if (this->right.front()->nodeLeftTop && this->right.front()->nodeLeftBottom) {
        newRight.push_back(this->right.front()->nodeLeftTop);
        newRight.push_back(this->right.front()->nodeLeftBottom);

        this->right.front()->nodeLeftTop->nodeRightBottom = this->right.front()->nodeLeftBottom;
        this->right.front()->nodeLeftBottom->nodeRightTop = this->right.front()->nodeLeftTop;

        delete this->right.front();
        this->right.front() = nullptr;
    } else if (this->right.front()->nodeLeftTop) {
        this->bottom.pop_back();

        newRight.push_back(this->right.front()->nodeLeftTop);

        this->right.front()->nodeLeftTop->nodeRightBottom = nullptr;

        delete this->right.front();
        this->right.front() = nullptr;
    } else if (this->right.front()->nodeLeftBottom) {
        this->top.pop_back();

        newRight.push_back(this->right.front()->nodeLeftBottom);

        this->right.front()->nodeLeftBottom->nodeRightTop = nullptr;

        delete this->right.front();
        this->right.front() = nullptr;
    }

    for (int i = 1; i < this->right.size() - 1; ++i) {
        newRight.push_back(this->right[i]->nodeLeftBottom);

        this->right[i]->nodeLeftTop->nodeRightBottom = this->right[i]->nodeLeftBottom;
        this->right[i]->nodeLeftBottom->nodeRightTop = this->right[i]->nodeLeftTop;

        delete this->right[i];
        this->right[i] = nullptr;
    }

    if (this->right.back()) {
        if (this->right.back()->nodeLeftTop && this->right.back()->nodeLeftBottom) {
            newRight.push_back(this->right.back()->nodeLeftBottom);

            this->right.back()->nodeLeftTop->nodeRightBottom = this->right.back()->nodeLeftBottom;
            this->right.back()->nodeLeftBottom->nodeRightTop = this->right.back()->nodeLeftTop;

            delete this->right.back();
            this->right.back() = nullptr;
        } else if (this->right.back()->nodeLeftTop) {
            this->bottom.pop_back();

            this->right.back()->nodeLeftTop->nodeRightBottom = nullptr;

            delete this->right.back();
            this->right.back() = nullptr;
        }
    }

    this->right = newRight;
}

void SchemeObliqueSatelliteNodes::removeNodeLeft()
{
    QList<SchemeObliqueObjectNode *> newLeft;

    if (this->left.front()->nodeRightTop && this->left.front()->nodeRightBottom) {
        newLeft.push_back(this->left.front()->nodeRightTop);
        newLeft.push_back(this->left.front()->nodeRightBottom);

        this->left.front()->nodeRightTop->nodeLeftBottom = this->left.front()->nodeRightBottom;
        this->left.front()->nodeRightBottom->nodeLeftTop = this->left.front()->nodeRightTop;

        delete this->left.front();
        this->left.front() = nullptr;
    } else if (this->left.front()->nodeRightTop) {
        this->bottom.pop_front();

        newLeft.push_back(this->left.front()->nodeRightTop);

        this->left.front()->nodeRightTop->nodeLeftBottom = nullptr;

        delete this->left.front();
        this->left.front() = nullptr;
    } else if (this->left.front()->nodeRightBottom) {
        this->top.pop_front();

        newLeft.push_back(this->left.front()->nodeRightBottom);

        this->left.front()->nodeRightBottom->nodeLeftTop = nullptr;

        delete this->left.front();
        this->left.front() = nullptr;
    }

    for (int i = 1; i < this->left.size() - 1; ++i) {
        newLeft.push_back(this->left[i]->nodeRightBottom);

        this->left[i]->nodeRightTop->nodeLeftBottom = this->left[i]->nodeRightBottom;
        this->left[i]->nodeRightBottom->nodeLeftTop = this->left[i]->nodeRightTop;

        delete this->left[i];
        this->left[i] = nullptr;
    }

    if (this->left.back()) {
        if (this->left.back()->nodeRightTop && this->left.back()->nodeRightBottom) {
            newLeft.push_back(this->left.back()->nodeRightBottom);

            this->left.back()->nodeRightTop->nodeLeftBottom = this->left.back()->nodeRightBottom;
            this->left.back()->nodeRightBottom->nodeLeftTop = this->left.back()->nodeRightTop;

            delete this->left.back();
            this->left.back() = nullptr;
        } else if (this->left.back()->nodeRightTop) {
            this->bottom.pop_front();

            this->left.back()->nodeRightTop->nodeLeftBottom = nullptr;

            delete this->left.back();
            this->left.back() = nullptr;
        }
    }

    this->left = newLeft;
}

void SchemeObliqueSatelliteNodes::removeNodeTop()
{
    QList<SchemeObliqueObjectNode *> newTop;

    if (this->top.front()->nodeLeftBottom && top.front()->nodeLeftBottom->nodeRightTop && this->top.front()->nodeLeftBottom->nodeRightTop == this->top.front()) {
        newTop.push_back(this->top.front()->nodeLeftBottom);

        this->top.front()->nodeLeftBottom->nodeRightTop = nullptr;
    } else {
        this->left.pop_front();

        this->top.front()->nodeLeftBottom->nodeLeftTop = nullptr;
    }

    for (int i = 0; i < this->top.size() - 1; ++i) {
        newTop.push_back(this->top[i]->nodeRightBottom);

        this->top[i]->nodeRightBottom->nodeLeftTop = nullptr;
        this->top[i]->nodeRightBottom->nodeRightTop = nullptr;

        delete this->top[i];
        this->top[i] = nullptr;
    }

    if (this->top.back()->nodeRightBottom && this->top.back()->nodeRightBottom->nodeLeftTop && this->top.back()->nodeRightBottom->nodeLeftTop == this->top.back()) {
        newTop.push_back(this->top.back()->nodeRightBottom);

        this->top.back()->nodeRightBottom->nodeLeftTop = nullptr;

        delete this->top.back();
        this->top.back() = nullptr;
    } else {
        this->right.pop_front();

        this->top.back()->nodeRightBottom->nodeRightTop = nullptr;

        delete this->top.back();
        this->top.back() = nullptr;
    }

    this->top = newTop;
}

void SchemeObliqueSatelliteNodes::removeNodeBottom()
{
    QList<SchemeObliqueObjectNode *> newBottom;

    if (this->bottom.front()->nodeLeftTop && this->bottom.front()->nodeLeftTop->nodeRightBottom && this->bottom.front()->nodeLeftTop->nodeRightBottom == this->bottom.front()) {
        newBottom.push_back(this->bottom.front()->nodeLeftTop);

        this->bottom.front()->nodeLeftTop->nodeRightBottom = nullptr;
    } else {
        this->left.pop_back();

        this->bottom.front()->nodeLeftTop->nodeLeftBottom = nullptr;
    }

    for (int i = 0; i < this->bottom.size() - 1; ++i) {
        newBottom.push_back(this->bottom[i]->nodeRightTop);

        this->bottom[i]->nodeRightTop->nodeLeftBottom = nullptr;
        this->bottom[i]->nodeRightTop->nodeRightBottom = nullptr;

        delete this->bottom[i];
        this->bottom[i] = nullptr;
    }

    if (this->bottom.back()->nodeRightTop && this->bottom.back()->nodeRightTop->nodeLeftBottom && this->bottom.back()->nodeRightTop->nodeLeftBottom == this->bottom.back()) {
        newBottom.push_back(this->bottom.back()->nodeRightTop);

        this->bottom.back()->nodeRightTop->nodeLeftBottom = nullptr;

        delete this->bottom.back();
        this->bottom.back() = nullptr;
    } else {
        this->right.pop_back();

        this->bottom.back()->nodeRightTop->nodeRightBottom = nullptr;

        delete this->bottom.back();
        this->bottom.back() = nullptr;
    }

    this->bottom = newBottom;
}

SchemeObliqueObjectNode *SchemeObliqueSatelliteNodes::getTopFront()
{
    return top.front();
}

SchemeObliqueObjectNode *SchemeObliqueSatelliteNodes::getTopBack()
{
    return top.back();
}

SchemeObliqueObjectNode *SchemeObliqueSatelliteNodes::getBottomFront()
{
    return bottom.front();
}

SchemeObliqueObjectNode *SchemeObliqueSatelliteNodes::getBottomBack()
{
    return bottom.back();
}

SchemeObliqueObjectNode *SchemeObliqueSatelliteNodes::getRightFront()
{
    return right.front();
}

SchemeObliqueObjectNode *SchemeObliqueSatelliteNodes::getRightBack()
{
    return right.back();
}

SchemeObliqueObjectNode *SchemeObliqueSatelliteNodes::getLeftFront()
{
    return left.front();
}

SchemeObliqueObjectNode *SchemeObliqueSatelliteNodes::getLeftBack()
{
    return left.back();
}

int SchemeObliqueSatelliteNodes::getSizeTop()
{
    return top.size();
}

int SchemeObliqueSatelliteNodes::getSizeBottom()
{
    return bottom.size();
}

int SchemeObliqueSatelliteNodes::getSizeLeft()
{
    return left.size();
}

int SchemeObliqueSatelliteNodes::getSizeRight()
{
    return right.size();
}

SchemeObliqueObjectNode *SchemeObliqueSatelliteNodes::createNode(const QPoint &pos)
{
    SchemeObliqueObjectNode *node = new SchemeObliqueObjectNode(pos, SchemeObliqueObjectNode::standartDirectionObliqueNode);

    this->scene->addItem(node);

    return node;
}
