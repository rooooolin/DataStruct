#include <iostream>
#include<stdlib.h>
#include <string>
#include <string.h>
#include <iomanip>
#include <stdio.h>
using namespace std;
typedef struct BiNode
{
	char data[22];
	int cont;
	struct BiNode *leftchild,*rightchild;
}BiNode,*BiTree;
bool flag;
void BST_insert(BiTree &T,char *s)
{
	if(T==NULL)
	{
		T=(BiTree)malloc(sizeof(BiNode));
		T->cont=1;
		strcpy(T->data,s);
		T->leftchild=T->rightchild=NULL;
		
	}
	else
	{
		int temp=strcmp(T->data,s);
		if(temp>0)
			BST_insert(T->leftchild,s);
		else if(temp<0)
			BST_insert(T->rightchild,s);
		else
			T->cont++;
	}
	
}

void cot(BiTree T,int n)
{
	if(T)
	{
		cot(T->leftchild,n);
		cout<<T->data<<" ";
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<T->cont*100.0/n<<"%"<<endl;
		cot(T->rightchild,n);
	}
}
int main(int argv,char *argc[])
{
	int n;
	char str[22];
	BiTree T;
	T=NULL;
	cin>>n;
	getchar();
	for (int i = 0; i < n; i++)
	{
		
		gets(str);
		for (int j = 0; j < strlen(str); j++)
		{
			if(str[j]>='A'&&str[j]<='Z')
				str[j]+=32;
		}
		BST_insert(T,str);
	}
	cot(T,n);
	return 0;
}