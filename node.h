#ifndef NODE_H
#define NODE_H
#include "visualnode.h"


struct Node : VisualNode
{
    int   _key;
    Node *_pLeft;
    Node *_pRight;

    void flash();
    bool isTarget();
    void makeRed();

    Node(int key, Node *pLeft=nullptr, Node *pRight=nullptr);
    ~Node();
};

#endif // NODE_H
