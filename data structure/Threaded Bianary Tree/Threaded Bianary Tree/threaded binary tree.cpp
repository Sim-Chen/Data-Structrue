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


BiThrTree pre;//ȫ�ֱ���,ʼ��ָ��ոշ��ʹ��Ľ��
//void InThreading(BiThrTree p)
//{//ͨ�����������������������,������֮��preָ�����һ�����
//	if(p)
//	{
//		InThreading(p->lchild);
//		if(!p->lchild)
//		{
//			p->LTag=Thread;
//			p->lchild=pre;//����ָ��ǰ��
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
			p=p->rchild;//��p->RTag==Threadʱ����p->rchild��p�ĺ��
			Visit(p->data);
		}
		p=p->rchild;//��p->RTag==Linkʱ����p->rchild��p�������������������������ע�����������̵Ĳ��
	}
}
