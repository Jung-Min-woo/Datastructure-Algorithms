#include "BinarySearchTree.h"
#include <stdio.h>

int main(void) {
	BTreeNode *bstRoot;
	BTreeNode *sNode;

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 5);


	sNode = BSTSearch(bstRoot, 1);
	if (sNode == NULL) printf("Search Failed\n");
	else printf("Height : %d\n", BSTGetNodeData(sNode));
	
	sNode = BSTSearch(bstRoot, 4);
	if (sNode == NULL) printf("Search Failed\n");
	else printf("Height : %d\n", BSTGetNodeData(sNode));
	return 0;
}