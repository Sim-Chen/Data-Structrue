#include "Binary Tree.h"
#include "header.h"

int main()
{
	Node* tree;
	tree=insert(tree,4);
	tree=insert(tree,5);
	tree=insert(tree,2);
	tree=insert(tree,1);
	tree=insert(tree,3);
	int count =size(tree);
	printf("the size of tree is %d\n",count);
	int deep=maxDepth(tree);
	printf("the max depth of the tree is %d\n",deep);
	printTree(tree);
	printf("\n");
	printPostorder(tree);
	printf("\n");
	int number=hasPathSum(tree,9);
	Node* node1=mirror(tree);
	printTree(node1);
	Node* node2=doubleTree(tree);
	printf("\n");
	printTree(node2);
	system("pause");
	
	return 0;
}