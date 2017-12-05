#include "node.h"

#include "treeviewwidget.h"

void Node::flash()
{
    TreeViewWidget::theOne()->flashNode(this);
}

bool Node::isTarget()
{
    return TreeViewWidget::theOne()->isTarget(this);

}

void Node::makeRed()
{
    TreeViewWidget::theOne()->makeRed(this);
}


Node::Node(int key, Node *pLeft, Node *pRight):
    VisualNode(), _key(key), _pLeft(pLeft), _pRight(pRight)
{
    TreeViewWidget::theOne()->nodeAdded(this);

}

Node::~Node(){
    TreeViewWidget::theOne()->nodeDeleted(this);
}
