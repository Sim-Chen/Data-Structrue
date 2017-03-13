#ifndef  KMP_H
#define  KMP_H
#include "sqstring.h"

void  get_next(SString T,int next[])
{//��ģʽ��T��next����ֵ����������next��.
	int i=1,j=0;
	next[1]=0;
	while (i<T[0])
	{
		if (j==0||T[i]==T[j])
		{
			++i;
			++j;
			next[i]=j;
		}
		else
			j=next[j];
	}

}
int Index_KMP(SString S,SString T,int pos,int next[])
{//����ģʽ��T��next������T������S�е�pos���ַ�֮���λ�õ�KMP�㷨
	//���У�T�ǿգ�1<<pos<<Strlength(S)
	int i=pos,j=1;
	while(i<=S[0]||j<=T[0])
	{
		if (j==0||S[i]==T[j])
		{
			++i;
			++j;

		}
		else
			j=next[j];
		if(j>T[0])
			return i-T[0];
		else
			return 0;
	}

}


#endif