#ifndef __AVLREBALANCE_H__
#define __AVLREBALANCE_H__
#include "BinarySearchTree.h"

int GetHeight(BTreeNode *bst);
int GetHeightDiff(BTreeNode *bst);
BTreeNode* Rotate_LL(BTreeNode *bst);
BTreeNode* Rotate_RR(BTreeNode *bst);
BTreeNode* Rotate_RL(BTreeNode *bst);
BTreeNode* Rotate_LR(BTreeNode *bst);

BTreeNode* Rebalance(BTreeNode **pRoot);

#endif