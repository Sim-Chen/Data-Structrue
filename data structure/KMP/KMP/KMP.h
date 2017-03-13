#ifndef  KMP_H
#define  KMP_H
#include "sqstring.h"

void  get_next(SString T,int next[])
{//求模式串T的next函数值并存入数组next中.
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
{//利用模式串T的next函数求T在主串S中第pos个字符之后的位置的KMP算法
	//其中，T非空，1<<pos<<Strlength(S)
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