#ifndef SQSTRING_H
#define SQSTRING_H
#include "header.h"
#define  Max_Str_Len 40
typedef char SString[Max_Str_Len+1];//0号单元存放串的长度
//#define DestroyString ClearString
Status StrAssign(SString T,char *chars);
void StrCopy(SString T,SString S);
Status StrEmpty(SString S);
int StrCompare(SString S,SString T);
int StrLength(SString S);
void ClearString(SString S);
Status Contact(SString T,SString S1,SString S2);
Status SubString(SString Sub,SString S,int pos,int len);
int Index(SString S,SString T,int pos);
Status  StrInsert(SString S ,int pos,SString T);
Status StrDelete(SString S int pos, int len);
Status Replace(SString S, SString T, SString V);
void StrPrint();
#endif