#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;
typedef struct BiNode
{
	char data;
	struct BiNode *lchild,*rchild;
}BiNode,*BiTree;
struct Node
{
	char node;
	int left,right;
}TrNode[15];
BiTree Creat(int n)
{
	char x;
	BiTree bt;
	bt=(BiNode *)malloc(sizeof(BiNode));
	bt->lchild=bt->rchild=NULL;
	bt->data=TrNode[n].node;
	if(TrNode[n].left!=-1)
		bt->lchild=Creat(TrNode[n].left);
	if(TrNode[n].right!=-1)
		bt->rchild=Creat(TrNode[n].right);
	return bt;
}
BiTree Build(int n)
{
	int j;
	bool v[15];
	memset(v,false,sizeof(v));
	for (int i = 0; i < n; i++)
	{
		char s1,s2,s3;
		cin>>s1>>s2>>s3;
		TrNode[i].node=s1;
		if(s2=='-')
			TrNode[i].left=-1;
		else
		{
			TrNode[i].left=s2-'0';
			v[TrNode[i].left]=true;
		}
		if(s3=='-')
			TrNode[i].right=-1;
		else
		{
			TrNode[i].right=s3-'0';
			v[TrNode[i].right]=true;
		}
	}
	if(n)
	{
		for (j = 0; j < n; j++)
		{
			if(!v[j])
				break;
		}
	}
	BiTree bt=Creat(j);
	return bt;
}
bool judge(BiTree bt1,BiTree bt2)
{
	if(bt1==NULL&&bt2==NULL)
		return true;
	if(bt1!=NULL&&bt2!=NULL)
		if(bt1->data==bt2->data)
			if((judge(bt1->lchild,bt2->lchild)&&judge(bt1->rchild,bt2->rchild))||(judge(bt1->rchild,bt2->lchild)&&judge(bt1->lchild,bt2->rchild)))
				return true;
	return false;
}
int main(int argv,char *argc[])
{
	int n;
	while (cin>>n)
	{
		BiTree bt1=Build(n);
		int m;
		cin>>m;
		BiTree bt2=Build(m);
		if(judge(bt1,bt2))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}