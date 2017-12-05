
#include "node.h"
#include <stdio.h>
#include <algorithm>
#include <deque>

#include "students.h"


/**************************************************************************
 * Fler uppgifter.
 **************************************************************************/

bool didIndicatePathToTarget(Node *pTree){

    if(pTree == nullptr){

        return false;
    }
    else if(pTree->isTarget()){

        pTree->flash();
        pTree->makeRed();
        return true;
    }
    else{
        pTree->flash();
        if( didIndicatePathToTarget(pTree->_pLeft) || didIndicatePathToTarget(pTree->_pRight) ){
            pTree->flash();
            pTree->makeRed();
            return true;
        }
    }
    return false;
}






