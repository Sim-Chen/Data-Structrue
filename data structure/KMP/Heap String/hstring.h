#ifndef  HSTRING_H
#define  HSTRING_H
#include "header.h"

struct HString 
{
	char *ch;
	int length;
};

void StrAssign(HString &T,char *ch)
{
	int i,j;
	if(T.ch)
		free(T.ch);
	i=strlen(ch);
	if(!i)
	{//ch的长度为0
		T.ch=NULL;
		T.length=0;
	}
	else
	{
		T.ch=(char *)malloc(i*sizeof(char));
		if(!T.ch)
			exit (OVERFLOW);
		for(j=0;j<i;j++)
			T.ch[j]=ch[j];
		T.length=i;
	}
}

void StrCopy(HString &T,HString S)
{
	int i;
	if(!T.ch)
		free(T.ch);
	T.ch=(char *)malloc(S.length*sizeof(char));
	if(!T.ch)
		exit(OVERFLOW);
	for(i=0;i<S.length;i++)
		T.ch[i]=S.ch[i];
	T.length=S.length;
}
Status StrEmpty(HString S)
{
	if(S.length==0&&S.ch==NULL)
		return TRUE;
	else
		return FALSE;

}
#endif
