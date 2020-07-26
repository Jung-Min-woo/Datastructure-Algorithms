#include "BinarySearchTree.h"
#include "AVLRebalance.h"
#include <stdlib.h>

void BSTMakeAndInit(BTreeNode ** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
	return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
	if (*pRoot == NULL) {
		*pRoot = MakeBTreeNode();
		SetData(*pRoot, data);
	}
	else if (data < GetData(*pRoot)) {
		BSTInsert(&(*pRoot)->left, data);
		*pRoot = Rebalance(pRoot);
	}
	else if (data > GetData(*pRoot)) {
		BSTInsert(&(*pRoot)->right, data);
		*pRoot = Rebalance(pRoot);
	}
	else return NULL;
	return *pRoot;
	//BTreeNode *pNode = NULL; // parent Node
	//BTreeNode *cNode = *pRoot; // current Node
	//BTreeNode *nNode = NULL; // new Node
	//while (cNode != NULL) {	
	//	if (data == GetData(cNode)) return; // ������ �ߺ��� ������� ����
	//	pNode = cNode;	
	//	if (GetData(cNode) > data) cNode = GetLeftSubTree(cNode);
	//	else cNode = GetRightSubTree(cNode);
	//}
	//nNode = MakeBTreeNode();
	//SetData(nNode, data);
	//if (pNode != NULL) {
	//	if (data < GetData(pNode)) MakeLeftSubTree(pNode, nNode);
	//	else MakeRightSubTree(pNode, nNode);
	//}
	//else *pRoot = nNode;
}
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
	BTreeNode *cNode = bst;
	BSTData cd;
	while (cNode != NULL) {
		cd = GetData(cNode);
		if (target == cd) return cNode;
		else if (target < cd) cNode = GetLeftSubTree(cNode);
		else cNode = GetRightSubTree(cNode);
	}
	return NULL;
}

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
{
	BTreeNode *pvRoot = MakeBTreeNode();
	BTreeNode *pNode = pvRoot;
	BTreeNode *cNode = *pRoot;
	BTreeNode *dNode;
	//pRoot�� pvRoot�� ������ ���� ���� �д�.
	ChangeRightSubTree(pvRoot, *pRoot); 
	while (cNode != NULL && GetData(cNode) != target) {
		pNode = cNode;
		if (target < GetData(cNode)) cNode = GetLeftSubTree(cNode);
		else cNode = GetRightSubTree(cNode);
	}
	//No Target
	if (cNode == NULL) return NULL;
	dNode = cNode;
	//���� ����� �ܸ� ����� ���
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) {
		if (GetLeftSubTree(pNode) == dNode) RemoveLeftSubTree(pNode);
		else RemoveRightSubTree(pNode);
	}
	//���� ����� �ϳ��� �ڽĳ�带 ���� ���
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) {
		BTreeNode *dcNode; //��������� �ڽ� ���
		if (GetLeftSubTree(dNode) != NULL) dcNode = GetLeftSubTree(dNode);
		else dcNode = GetRightSubTree(dNode);
		
		if (GetLeftSubTree(pNode) == dNode) ChangeLeftSubTree(pNode, dcNode);
		else ChangeRightSubTree(pNode, dcNode);
	}
	else {
		BTreeNode *mNode = GetRightSubTree(dNode); // ��ü���
		BTreeNode *mpNode = dNode; //  ��ü����� �θ� ���
		int delData;

		while (GetLeftSubTree(mNode) != NULL) {
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}
		delData = GetData(dNode);
		SetData(dNode, GetData(mNode));

		//��ü����� �θ���� �ڽ� ��带 �����Ѵ�.
		if (GetLeftSubTree(mpNode) == mNode) ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
		dNode = mNode;
		SetData(dNode, delData);
	}
	//���� ��尡 ��Ʈ ����� ��쿡 ���� �߰����� ó��
	if (GetRightSubTree(pvRoot) != *pRoot) *pRoot = GetRightSubTree(pvRoot);
	free(pvRoot); 
	return dNode;
}
void ShowIntData(int data) {
	printf("%d ", data);
}
BTreeNode * BSTshowAll(BTreeNode * bst)
{
	Traverse_InOrder(bst, ShowIntData);
}
