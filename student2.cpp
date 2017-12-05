

#include "node.h"
#include <stdio.h>
#include <algorithm>
#include <deque>

#include "students.h"




/**************************************************************************
 * Sökträd.
 *
 *
 **************************************************************************/

void insertKeyToSearchtree(Node*& pTree, int key){

    if(pTree == nullptr)
    {
        pTree->flash();
        pTree = new Node(key, nullptr, nullptr);
    }
    else if(key < pTree->_key)
    {
        pTree->flash();
        insertKeyToSearchtree(pTree->_pLeft, key);
    }
    else if(key > pTree->_key)
    {
        pTree->flash();
        insertKeyToSearchtree(pTree->_pRight, key);
    }
    else
        ;

}

bool contains(Node *pTree, int key){

    if(pTree == nullptr)
    {
        return false;
    }
    else if( key < pTree->_key)
    {
        pTree->flash();
        return contains(pTree->_pLeft, key);
    }
    else if( key > pTree->_key)
    {
        pTree->flash();
        return contains(pTree->_pRight, key);
    }
    else
        return true;
}


Node* nodeWithMinimumKey(Node *pTree){

    if(pTree == nullptr)
        return nullptr;
    if(pTree->_pLeft == nullptr)
        return pTree;
    return nodeWithMinimumKey(pTree->_pLeft);
}

void removeKeyFromSearchtree(Node* &pTree, int key){

    if(pTree == nullptr) // om den inte har barn
        return;
    else if(key < pTree->_key){
        removeKeyFromSearchtree(pTree->_pLeft, key);
    }
    else if(key > pTree->_key){
        removeKeyFromSearchtree(pTree->_pRight, key);
    }
    else if(pTree->_pLeft == nullptr || pTree->_pRight == nullptr){
        Node *nod = pTree;
        pTree = (pTree->_pLeft != nullptr ? pTree->_pLeft : pTree->_pRight);
        delete nod;
    }
    else{
        pTree->_key = nodeWithMinimumKey(pTree->_pRight)->_key;
        removeKeyFromSearchtree(pTree->_pRight, pTree->_key);
    }
}


