#include "node.h"
#include <stdio.h>
#include <algorithm>
#include <deque>

#include "students.h"


/**************************************************************************
 * Trädklättring.
 *
 *
 **************************************************************************/

void flashPreOrder(Node *pTree){

    if(pTree == nullptr)
        return;
    pTree->flash();
    flashPreOrder(pTree->_pLeft);       // 1. Noden 2. Vänster 3. Höger
    flashPreOrder(pTree->_pRight);
}

void flashInOrder(Node *pTree){

    if(pTree == nullptr)
        return;

    flashInOrder(pTree->_pLeft);        // 1. Vänster  2. Noden  3. Höger
    pTree->flash();
    flashInOrder(pTree->_pRight);


}

void flashPostOrder(Node *pTree){

    if(pTree == nullptr)
        return;

    flashPostOrder(pTree->_pLeft);      // 1. Vänster  2. Höger  3. Noden
    flashPostOrder(pTree->_pRight);
    pTree->flash();
}



void flashNodesAtIncreasingDepth(Node *pTree){

    std::deque<Node*> que;
    que.push_back(pTree);

    while(!que.empty()){

        if(que.front() != nullptr)
        {
            Node *p = que.front();
            p->flash();
            que.push_back(p->_pLeft);
            que.push_back(p->_pRight);
        }
        que.pop_front();
    }
}

int numberOfNodes(Node *pTree){

    if(pTree == nullptr)
        return 0;

    int sizeLeft = numberOfNodes(pTree->_pLeft);
    int sizeRight = numberOfNodes(pTree->_pRight);
    int sizeTot = 1 + sizeLeft + sizeRight;
    return sizeTot;
}

int height(Node *pTree){

    if(pTree == nullptr)
        return -1;

    int left = height(pTree->_pLeft);
    int right = height(pTree->_pRight);

    int totHeight = 0;
    if(left > right)
        totHeight = left;
    else
        totHeight = right;

    return 1 + totHeight;
}


