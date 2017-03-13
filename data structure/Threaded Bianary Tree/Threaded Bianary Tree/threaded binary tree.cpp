enum PointerTag
{
	Link,
	Thread
};
typedef int TElemType;
struct BiThrNode
{
	 TElemType data;
	 BiThrNode *lchild,rchild;
	 PointerTag LTag,RTag;
	
};
typedef BiThrNode *BiThrTree;


BiThrTree pre;//全局变量,始终指向刚刚访问过的结点
//void InThreading(BiThrTree p)
//{//通过中序遍历进行中序线索化,线索化之后pre指向最后一个结点
//	if(p)
//	{
//		InThreading(p->lchild);
//		if(!p->lchild)
//		{
//			p->LTag=Thread;
//			p->lchild=pre;//左孩子指向前驱
//		}
//		if(!pre->rchild)
//		{
//			pre->RTag=Thread;
//			pre->rchild=p;
//			
//
//		}
//		pre=p;
//		InThreading(p->rchild);
//
//	}
//
//}


//Status InOderTravese_Thr(BiThrTree T,Status(*Visit)(TElemType))
//{
//	BiThrTree p=T->lchild;
//	while(p!=T)
//	{
//		while(p->LTag==Link)
//			p=p->lchild;
//		Visit(p->data);
//		while(p->RTag==Thread&&p->rchild!=T)
//		{
//			p=p->rchild;
//			Visit(p->data);
//		}
//		p=p->rchild;
//	}	
//}
Status InThreading(BiThrTree p)
{
	if(p)
	{
		InThreading(p->lchild);
		if(!p->lchild)
		{
			p->LTag=Thread;
			p->lchild=pre;
		}
		if(!pre->rchild)
		{
			pre->RTag=Thread;
			pre->rchild=p;
		}
		pre=p;
		InThreading(p->rchild);
	}
}

Status InOderTravese_Thr(BiThrTree T,Status(Visit)(TElemType))
{
	BiThrTree p=T->lchild;
	if(p!=T)
	{
		while(p->LTag==Link)
		{
			p=p->lchild;
		}
		Visit(p->data);
		while (p->RTag==Thread&&p->rchild!=T)
		{
			p=p->rchild;//当p->RTag==Thread时，则p->rchild是p的后继
			Visit(p->data);
		}
		p=p->rchild;//当p->RTag==Link时，则p->rchild是p的右子树。右子树不必输出，注意右子树与后继的差别
	}
}
