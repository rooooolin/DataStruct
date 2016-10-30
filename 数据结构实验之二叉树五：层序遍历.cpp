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
		bt=(BiTree)malloc(sizeof(BiNode));
		bt->data=str.at(NodeNum);
		bt->lchild=Creat(str);
		bt->rchild=Creat(str);
	}
	return bt;
}
int LevelTraversal(BiTree bt,int level)
{
	if(!bt||level<0)
		return 0;
	if(0==level)
	{
		cout<<bt->data;
		return 1;
	}
	return LevelTraversal(bt->lchild,level-1)+LevelTraversal(bt->rchild,level-1);
}
int main(int argv,char *argc[])
{
	int n;
	cin>>n;
	while(n--)
	{
		BiTree bt;
		NodeNum=-1;
		string str;
		cin>>str;
		bt=Creat(str);
		int i=0;
		for (int i = 0; ;i++)
		{
			if(!LevelTraversal(bt,i))
				break;
		}
		cout<<endl;
	}
	return 0;
}