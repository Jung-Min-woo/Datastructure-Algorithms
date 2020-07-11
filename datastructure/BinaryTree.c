
#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
BTreeNode * MakeBTreeNode(void)
{
	BTreeNode* newtree = (BTreeNode*)malloc(sizeof(BTreeNode));
	newtree->left = NULL;
	newtree->right = NULL;
	return newtree;
}

BTData GetData(BTreeNode * bt){return bt->data;}
void SetData(BTreeNode * bt, BTData data){bt->data = data;}
BTreeNode * GetLeftSubTree(BTreeNode * bt){return bt->left;}
BTreeNode * GetRightSubTree(BTreeNode * bt){return bt->right;}
void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
	if (main->left != NULL) free(main->left);
	main->left = sub;
}
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
	if (main->right != NULL) free(main->right);
	main->right = sub;
}

void Traverse_InOrder(BTreeNode * target, VisitFuncPtr action)
{
	if (target == NULL) return;
	Traverse_InOrder(target->left, action);
	action(target->data);
	Traverse_InOrder(target->right, action);
}

void Traverse_PreOrder(BTreeNode * target, VisitFuncPtr action)
{
	if (target == NULL) return;
	action(target->data); 
	Traverse_PreOrder(target->left, action);
	Traverse_PreOrder(target->right, action);
}

void Traverse_PostOrder(BTreeNode * target, VisitFuncPtr action)
{
	if (target == NULL) return;
	Traverse_PostOrder(target->left, action);
	Traverse_PostOrder(target->right, action);
	action(target->data);
}
