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
	//	if (data == GetData(cNode)) return; // 데이터 중복을 허용하지 않음
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
	//pRoot를 pvRoot의 오른쪽 하위 노드로 둔다.
	ChangeRightSubTree(pvRoot, *pRoot); 
	while (cNode != NULL && GetData(cNode) != target) {
		pNode = cNode;
		if (target < GetData(cNode)) cNode = GetLeftSubTree(cNode);
		else cNode = GetRightSubTree(cNode);
	}
	//No Target
	if (cNode == NULL) return NULL;
	dNode = cNode;
	//삭제 대상이 단말 노드인 경우
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) {
		if (GetLeftSubTree(pNode) == dNode) RemoveLeftSubTree(pNode);
		else RemoveRightSubTree(pNode);
	}
	//삭제 대상이 하나의 자식노드를 갖는 경우
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) {
		BTreeNode *dcNode; //삭제대상의 자식 노드
		if (GetLeftSubTree(dNode) != NULL) dcNode = GetLeftSubTree(dNode);
		else dcNode = GetRightSubTree(dNode);
		
		if (GetLeftSubTree(pNode) == dNode) ChangeLeftSubTree(pNode, dcNode);
		else ChangeRightSubTree(pNode, dcNode);
	}
	else {
		BTreeNode *mNode = GetRightSubTree(dNode); // 대체노드
		BTreeNode *mpNode = dNode; //  대체노드의 부모 노드
		int delData;

		while (GetLeftSubTree(mNode) != NULL) {
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}
		delData = GetData(dNode);
		SetData(dNode, GetData(mNode));

		//대체노드의 부모노드와 자식 노드를 연결한다.
		if (GetLeftSubTree(mpNode) == mNode) ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
		dNode = mNode;
		SetData(dNode, delData);
	}
	//삭제 노드가 루트 노드인 경우에 대한 추가적인 처리
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
