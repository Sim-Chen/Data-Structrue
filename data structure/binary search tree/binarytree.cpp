#include "Binary Tree.h"


Status lookup(Node* node,int target)
{//
	if(node==NULL)//¿ÕÊ÷
		return ERROR;
	else
	{
		if(node->data==target)
			return TRUE;
		else
		{
			if(target<node->data)
				return(lookup(node->left,target));
			else
				return(lookup(node->right,target));
		}
	}
}

Node* NewNode(int data)
{
	Node * node=(Node *)malloc(sizeof(Node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return (node);

}
Node* insert(Node* node,int data)
{
	if(node==NULL)//¿ÕÊ÷
		return(NewNode(data));
	else
	{
		if(data<=node->data)
			node->left=insert(node->left,data);
		else
			node->right=insert(node->right,data);

		 return node;
	}

}
int size(Node*node)
{   
	if(node==NULL)
		return 0;
	else
	{
		int cnt1=size(node->right);
		int cnt2=size(node->left);
		return cnt1+cnt2+1;
	}
	 
		
	

}

int maxDepth(Node* node)
{
	if(node==NULL)
		return 0;
	else
	{
		int lmaxdeep=maxDepth(node->left);
		int rmaxdeep=maxDepth(node->right);
		if(lmaxdeep-rmaxdeep>0)
			return lmaxdeep+1;
		else
			return rmaxdeep+1;
	}
	
}

int minValue(Node* node)
{
	Node* current;
	while(current->left!=NULL)
	{
		current=current->left;
	}
	return current->data;

}

int maxValue(Node* node)
{
	Node* current;
	while(current->right!=NULL)
	{
		current=current->right;
	}
	return current->data;
}
void printTree(Node* node)
{
	if(node==NULL)
		return;
	 printTree(node->left);
	 printf("%d ",node->data);
	 printTree(node->right);
	

}
void printPostorder(Node*node)
{
	if(node==NULL)
		return;
	printPostorder(node->left);
	printPostorder(node->right);
	printf("%d ",node->data);
}
int hasPathSum(Node*node,int sum)
{
	if(node==NULL)
		return (sum==0);
	else
	{
		int subSum=sum-node->data;
		return(hasPathSum(node->left,subSum)||hasPathSum(node->right,subSum));
	}
	
}
void printPathRecur(Node*node,int path[],int pathLen);
void printPaths(Node*node)
{
	int path[1000];
	printPathRecur(node,path,0);

	

}
void printArray(int ints[],int len)
{
	int i;
	for(i=0;i<len;i++)
		printf("%d ",ints[i]);
	printf("\n");
}
void printPathRecur(Node*node,int path[],int pathLen)
{
	if(node==NULL)
		return;
	path[pathLen]=node->data;
	path++;
	if(node->left==NULL&&node->right==NULL)
	{
		printArray(path,pathLen);
	}
	else
	{
		printPathRecur(node->left,path,pathLen);
		printPathRecur(node->right,path,pathLen);
	}
}
Node* mirror(Node* node)
{
	if(node==NULL)
		return node;
	else
	{
		Node *temp;
		mirror(node->left);
		mirror(node->right);

		temp=node->left;
		node->left=node->right;
		node->right=temp;
		return node;
	}
  
}
Node* doubleTree(Node*node)
{
	Node* leftnode;
	if(node==NULL)
		return node;
	doubleTree(node->left);
	doubleTree(node->right);
	leftnode=node->left;
	node->left=NewNode(node->data);
	node->left->left=leftnode;
	return node;


}

bool sameTree(Node*node1,Node*node2)
{
	if(node1==NULL&&node2==NULL)
		return TRUE;
	else if(node1!=NULL&&node2!=NULL)
	{
		return 
		{
			node1->data==node2->data&&
			sameTree(node1->left,node2->left)
			&&sameTree(node1->right,node2->right);
		}
	}
	else
		return FALSE;
}
int countTree(int numKeys)
{
	if(numKeys<1)
		return 1;
	else
	{
		int sum=0;
		int left,right,root;
		for(root=1;root<=numKeys;root++)
		{
			left=countTree(root-1);
			right=countTree(numKeys-root);
			sum+=left*right;
		}
		return(sum);
	}
}
int isBST(Node* node)
{
	if(node==NULL)
		return TRUE;
	if(node->left!=NULL&&maxValue(node->left)>node->data)
		return(FALSE);
	if(node->right!=NULL&&minValue(node->right)<node->data)
		return(FALSE);
	if(!isBST(node->left)||!isBST(node->right))
		return(FALSE);
	return TRUE;
}

int isBSTUtil(Node* node,int min,int max);
int isBST2(Node*node)
{
	return isBSTUtil(node,0,0);

}
int isBSTUtil(Node* node,int min,int max)
{
	if(node==NULL)
		return TRUE;
	if(node->data<min||node->data>max)
		return FALSE;
	return 
		isBSTUtil(node->left,min,node->data)&&
		isBSTUtil(node->right,node->data,max);

}