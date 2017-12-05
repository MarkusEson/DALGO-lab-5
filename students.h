#ifndef STUDENT1_H
#define STUDENT1_H


#include "node.h"



/**************************************************************************
 * Trädklättring.
 **************************************************************************/

void flashPreOrder(Node *pTree);
void flashInOrder(Node *pTree);
void flashPostOrder(Node *pTree);

void flashNodesAtIncreasingDepth(Node *pTree);

int numberOfNodes(Node *pTree);
int height(Node *pTree);


/**************************************************************************
 * Sökträd.
 **************************************************************************/

void insertKeyToSearchtree(Node* &pTree, int key);
bool contains(Node *pTree, int key);
void removeKeyFromSearchtree(Node* &pTree, int key);



/**************************************************************************
 * Serialisering.
 **************************************************************************/
void saveTree(FILE* fp, Node *pTree);
Node* readTree(FILE *fp);



/**************************************************************************
 * Fler uppgifter.
 **************************************************************************/
bool didIndicatePathToTarget(Node *pTree);




#endif // STUDENT1_H
