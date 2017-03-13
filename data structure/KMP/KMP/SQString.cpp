#include"sqstring.h"
Status StrAssign(SString T,char *chars)
{//生成一个其值等于chars的串T
	int i;
	if(strlen(chars)>Max_Str_Len)
		return ERROR;
	else
		T[0]=strlen(chars);
	for(i=1;i<=T[0];i++)
		T[i]=*(chars+i-1);//
	return OK;

}
void StrCopy(SString T,SString S)
{//由串S复制串T
	int i;
	for (i=0;i<=S[0];i++)
	{
		T[i]=S[i];
	}

}
Status StrEmpty(SString S)
{
	if (S[0]==0)
		return TRUE;
	else
		return FALSE;
}
int StrCompare(SString S,SString T)
{
	int i;
	for(i=1;i<=S[0]&&i<=T[0];i++)
		if(S[i]!=T[i])
			return S[i]-T[i];
	return S[0]-T[0];
}
int StrLength(SString S)
{
	return S[0];
}
void ClearString(SString S)
{
	S[0]=0;
}

Status Contact(SString T,SString S1,SString S2)
{
	int i;
	if (S1[0]+S2[0]<=Max_Str_Len)
	{
		for (i=1;i<=S1[0];i++)
		{
			T[i]=S1[i];
		}
		for (i=1;i<S2[0];i++)
		{
			T[S1[0]+i]=S2[i];
		}
		T[0]=S1[0]+S2[0];
		return TRUE;
	}
	else
	{
		for(i=1;i<=S1[0];i++)
			T[i]=S1[i];
		for(i=1;i<Max_Str_Len-S1[0];i++)
			T[S1[0]+i]=S2[i];
		T[0]=Max_Str_Len;
		return FALSE;
	}
}

Status SubString(SString Sub,SString S,int pos,int len)
{
	int i;
	if (pos<1||pos>S[0]||len<0||len>S[0]-pos+1)
	 return ERROR;
	for(i=1;i<len;i++)
		Sub[i]=S[pos+i-1];
	Sub[0]=len;
	return OK;
}

int Index(SString S,SString T,int pos)
{//返回子串T在主串S中第pos个字符之后的位置,若不存在,返回0

	int i,j;
	if(1<pos&&pos<=S[0])
	{
		i=pos;
		j=1;
		while (i<=S[0]&&j<=T[0])
		{
			if(S[i]==T[j])//继续比较后继字符
			{
				++i;
				++j;
			}
			else
			{
				i=i-j+2;
				j=1;
			}
			
			
		}
		if (j>T[0])
			return i-T[0];
		else
			return 0;

		
	
	}
	else
		return 0;
}
Status StrInsert(SString S ,int pos,SString T)
{//在串S的第pos个位置插入串T.完全插入返回TRUE,部分插入返回FALSE
	int i ;
	if(pos<1||pos>S[0]+1)
		return ERROR;
	if (S[0]+T[0]<=Max_Str_Len)
	{//完全插入
		for(i=S[0];i>=pos;i--)
			S[i+T[0]]=S[i];
		for(i=pos;i<=pos+T[0];i++)
			S[i]=T[i-pos+1];
		S[0]+=T[0];
		return TRUE;

	}
	else
	{
		for(i=Max_Str_Len;i>=pos+T[0];i--)
			S[i]=S[i-T[0]];
		for(i=pos;i<pos+T[0]&&i<=Max_Str_Len;i++)
			S[i]=T[i-pos+1];
		S[0]=Max_Str_Len;
	}


}
Status StrDelete(SString S int pos, int len)
{
	int i;
	if(pos<1||pos>S[0]-len+1||len<0)
		return ERROR;
	for(i=pos+len;i<=S[0];i++)
	{
		S[i-len]=S[i];
	}
	S[0]-=len;
	return OK;

}