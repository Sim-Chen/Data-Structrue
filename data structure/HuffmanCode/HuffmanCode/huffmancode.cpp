#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

typedef struct  
{
	int weight;
	int parent,lchild,rchild;

}HTNode,*Huffmantree;

typedef vector <vector <string> > HuffmanCode;

int Min(Huffmantree HT, int i)
{
	int j,index;
	unsigned int k=256;
	for (j=1;j<=i;j++)
	{
		if(HT[j].weight<k&&HT[j].parent==0)
			k=HT[j].weight,index=j;
	}
	HT[index].parent=1;
	return index;
}
void Select(Huffmantree HT,int i,int &s1,int &s2)
{	
	int j;
	s1=Min(HT,i);
	s2=Min(HT,i);
	if(s1>s2)
	{
		j=s1;
		s1=s2;
		s2=j;

	}
		
}

void HuffmanCoding(Huffmantree &HT,HuffmanCode &HC,int *w,int n)
{//w存放n个字符的权值，构造hufffman树，并求出n个字符的编码
	if(n<=1)
		return ;
	int m=2*n-1;//n个字符，n个叶子结点，有2n-1个结点
	HT=(Huffmantree)malloc((m+1)*sizeof(HTNode));
	Huffmantree p;
	int i,s1,s2;
	int c, f;
	for(p=HT+1, i=1; i<=n;++p,++i,++w)
	{//初始化前n个叶子结点
		(*p).lchild=0;
		(*p).rchild=0;
		(*p).parent=0;
		(*p).weight=*w;

	}
	for(;i<=m;++i)
	{//初始化后n+1个结点
		(*p).lchild=0;
		(*p).rchild=0;
		(*p).parent=0;
		(*p).weight=0;
	}
	for(i=n+1;i<=m;++i)
	{//在HT[1....i-1]中选择parent为0且weight最小的结点，其序号为s1和s2
		Select(HT,i-1,s1,s2);//遍历HT从HT[1....i-1]中选择两个最小的结点
		HT[s1].parent=i,HT[s2].parent=i;
		HT[i].lchild=s1,HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}

	vector <vector<string>>cd;
	
	for (i=1;i<=n;++i)
	{
		int start=n-1;
		for( c=i, f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
		{//从叶子结点到根结点遍历,逆向求出编码.不断地求parent，直到根结点。c为当前结点的序号
			if(HT[f].lchild==c)//找到序号为c的叶子结点，然后找他的parent，判断c是否为parent的左右孩子
				HC[i].push_back("0");
			else
				HC[i].push_back("1");

		}
	}


}

int main()
{
	Huffmantree HT;
	HuffmanCode HC;
	int n,i;
	HuffmanCode a;
	for (int k=0; k!=4;++k)
	{
		a.push_back(vector<string> ("a") );
	}
	cout<<"请输入权值的个树\n";
	cin>>n;
	int *w= (int *)malloc(n*sizeof(int));
	cout<<"请依次输入"<<n<<"个权值"<<endl;
	for (i=0;i<=n-1;i++)
		cin>>w[i];
	
	
	HuffmanCoding(HT,HC,w,n);
	for (int j=1;j!=HC.size();++j)
	{
		for(int k=HC[j].size()-1;k>=0;k--)
			cout<<HC[j][k]<<" ";
		cout<<endl;
	}
	return 0;
}

