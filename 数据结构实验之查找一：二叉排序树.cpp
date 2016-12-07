#include <iostream>
#include<stdlib.h>
using namespace std;

typedef struct BiNode
{
	int data;
	struct BiNode *leftchild,*rightchild;
}BiNode,*BiTree;
bool flag;
int BST_insert(BiTree &T,int k)
{
	if(T==NULL)
	{
		T=(BiTree)malloc(sizeof(BiNode));
		T->data=k;
		T->leftchild=T->rightchild=NULL;
		return 1;
	}
	else if(k==T->data)
		return 0;
	else if(k<T->data)
		return BST_insert(T->leftchild,k);
	else
		return BST_insert(T->rightchild,k);
}
void Creat_BST(BiTree &T,int str[],int n)
{
	T=NULL;
	int i=0;
	while (i<n)
	{
		BST_insert(T,str[i]);
		i++;
	}
}
void Judge(BiTree T1,BiTree T2)
{
	if(T1&&T2)
	{
		if(T1->data!=T2->data)
		{
			flag=false;
			return ;
		}
		Judge(T1->leftchild,T2->leftchild);
		Judge(T1->rightchild,T2->rightchild);
	}
}
int main(int argv,char *argc[])
{
	int n,l;
	while (cin>>n)
	{
		if(0==n)
			break;
		cin>>l;
		BiTree T;
		int str[11];
		for (int i = 0; i < n; i++)
		{
			cin>>str[i];
		}
		Creat_BST(T,str,n);
		while (l--)
		{
			flag=true;
			BiTree T_temp;
			int str_temp[11];
			for (int i = 0; i < n; i++)
			{
				cin>>str_temp[i];
			}
			Creat_BST(T_temp,str_temp,n);
			Judge(T,T_temp);
			if(flag)
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
	}
	return 0;
}