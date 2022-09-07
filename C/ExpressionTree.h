#ifndef __EXPRESSIONTREE_H__
#define __EXPRESSIONTREE_H__
#include "BinaryTree.h"
BTreeNode * MakeExpTree(char exp[]);
int EvaluateExpTree(BTreeNode *bt);
void ShowPrefixTypeExp(BTreeNode *bt);
void ShowPostfixTypeExp(BTreeNode *bt);
void ShowInfixTypeExp(BTreeNode *bt);
#endif
