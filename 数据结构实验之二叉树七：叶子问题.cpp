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
void LevelTraversal(BiTree bt)
{
	int front=0,rear=0;
	BiTree Q[100];
	Q[front++]=bt;
	while (rear<front)
	{
		if(Q[rear])
		{
			if(Q[rear]->lchild==NULL&&Q[rear]->rchild==NULL)
				cout<<Q[rear]->data;
			Q[front++]=Q[rear]->lchild;
			Q[front++]=Q[rear]->rchild;
		}
		rear++;
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
		LevelTraversal(bt);
		cout<<endl;
	}
	return 0;
}