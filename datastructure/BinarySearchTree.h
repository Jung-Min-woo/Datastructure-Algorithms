#ifndef __BINARYSEARCHTREE_H_
#define __BINARYSEARCHTREE_H_
#include "BinaryTree.h"

typedef BTData BSTData;

void BSTMakeAndInit(BTreeNode **pRoot);
BSTData BSTGetNodeData(BTreeNode *bst);
void BSTInsert(BTreeNode **pRoot, BSTData data);
BTreeNode* BSTSearch(BTreeNode *bst, BSTData target);

#endif