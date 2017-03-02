#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "header.h"
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

Status lookup(Node* node,int target);
Node* NewNode(int data);
Node* insert(Node* node,int data);
int size(Node* node);
int maxDepth(Node* node);
int minValue(Node* node);
int maxValue(Node* node);
void printTree(Node* node);
void printPostorder(Node*node);
int hasPathSum(Node*node,int sum);
void printPaths(Node*node);
Node* mirror(Node* node);
Node* doubleTree(Node*node);
bool sameTree(Node*node1,Node*node2);
int countTree(int numKeys);
int isBST(Node* node);
int isBST2(Node*node);
#endif