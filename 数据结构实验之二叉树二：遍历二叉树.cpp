#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
typedef struct BiNode
{
	char data;
	struct BiNode *lchild,*rchild;
}BiNode,*BiTree;
int NodeNum;
BiTree Creat(string str)
{
	BiTree bt;
	if(str.at(++NodeNum)==',')
		bt=NULL;
	else
	{
		bt=(BiNode *)malloc(sizeof(BiNode));
		bt->data=str.at(NodeNum);
		bt->lchild=Creat(str);
		bt->rchild=Creat(str);
	}
	return bt;
}
void  InOrderTraverse(BiTree bt)
{
	if(bt)
	{
		InOrderTraverse(bt->lchild);
		cout<<bt->data;
		InOrderTraverse(bt->rchild);
	}
}
void PostOrderTraverse(BiTree bt)
{
	if(bt)
	{
		PostOrderTraverse(bt->lchild);
		 PostOrderTraverse(bt->rchild);
		 cout<<bt->data;
	}
}
int main(int argv,char *argc[])
{
	string str;
	
	while (cin>>str)
	{
		NodeNum=-1;
		BiTree bt;
		bt=Creat(str);
		InOrderTraverse(bt);
		cout<<endl;
		PostOrderTraverse(bt);
		cout<<endl;
	}
	return 0;
}