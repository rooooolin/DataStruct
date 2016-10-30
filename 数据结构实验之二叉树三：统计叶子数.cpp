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
int LeafCount;
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
void  LeafNum(BiTree bt)
{
	
	if(bt)
	{
		if(bt->lchild==NULL&&bt->rchild==NULL)
			LeafCount++;
		LeafNum(bt->lchild);
		LeafNum(bt->rchild);
	}
	
}

int main(int argv,char *argc[])
{
	string str;
	
	while (cin>>str)
	{
		LeafCount=0;
		NodeNum=-1;
		BiTree bt;
		bt=Creat(str);
		LeafNum(bt);
		cout<<LeafCount<<endl;
	}
	return 0;
}