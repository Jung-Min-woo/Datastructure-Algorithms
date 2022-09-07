#include "AVLRebalance.h"
#include <stdlib.h>

int GetHeight(BTreeNode * bst)
{
	int leftH, rightH; //height of left or right
	if (bst == NULL) return 0;
	leftH = GetHeight(GetLeftSubTree(bst));
	rightH = GetHeight(GetRightSubTree(bst));
	return leftH > rightH ? leftH++ : rightH++;
}
int GetHeightDiff(BTreeNode * bst)
{
	int lsh, rsh; // sub tree height
	if (bst == NULL) return 0;
	lsh = GetHeight(GetLeftSubTree(bst));
	rsh = GetHeight(GetRightSubTree(bst));
	return lsh - rsh;
}

BTreeNode * Rotate_LL(BTreeNode * bst)
{
	BTreeNode *pnode, *cnode;
	pnode = bst;
	cnode = GetLeftSubTree(pnode);
	ChangeLeftSubTree(pnode, GetRightSubTree(cnode));
	ChangeRightSubTree(cnode, pnode);
	return cnode;
}

BTreeNode * Rotate_RR(BTreeNode * bst)
{
	BTreeNode *pnode, *cnode;
	pnode = bst;
	cnode = GetRightSubTree(pnode);
	ChangeRightSubTree(pnode, GetLeftSubTree(cnode));
	ChangeLeftSubTree(cnode, pnode);
	return cnode;
}

BTreeNode * Rotate_RL(BTreeNode * bst)
{
	BTreeNode *pnode, *cnode;
	pnode = bst;
	cnode = GetRightSubTree(pnode);
	ChangeRightSubTree(pnode, Rotate_LL(cnode));
	return Rotate_RR(pnode);
}

BTreeNode * Rotate_LR(BTreeNode * bst)
{
	BTreeNode *pnode, *cnode;
	pnode = bst;
	cnode = GetLeftSubTree(pnode);
	ChangeLeftSubTree(pnode, Rotate_RR(cnode));
	return Rotate_LL(pnode);
}

BTreeNode * Rebalance(BTreeNode ** pRoot)
{
	int hDiff = GetHeightDiff(*pRoot);
  	// �����μ��� +2 �̻��̸� LL���� �Ǵ� LR�����̴�.
	if (hDiff > 1) {
		if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0) *pRoot = Rotate_LL(*pRoot);
		else *pRoot = Rotate_LR(*pRoot);
	}
	// �����μ��� -2 �����̸� RR���� �Ǵ� RL�����̴�.
	if (hDiff < -1) {
		if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0) *pRoot = Rotate_RR(*pRoot);
		else *pRoot = Rotate_RL(*pRoot);
	}
	return *pRoot;
}