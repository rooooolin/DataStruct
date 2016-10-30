#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
typedef struct BiNode
{
	char data;
	struct BiNode *lchild,*rchild;
}BiNode,*BiTree;

void Creat(BiTree &bt,string Prestr,string Instr)
{
	if(Prestr.length()==0)
	{
		bt=NULL;
		return;
	}
	char root=Prestr.at(0);
	int index=Instr.find(root);
	string lchid_instr=Instr.substr(0,index);
	string rchind_instr=Instr.substr(index+1);
	int lchild_length=lchid_instr.length();
	int rchind_length=rchind_instr.length();
	string lchild_prestr=Prestr.substr(1,lchild_length);
	string rchild_prestr=Prestr.substr(lchild_length+1);
	bt=(BiTree)malloc(sizeof(BiNode));
	if(bt)
	{
		bt->data=root;
		Creat(bt->lchild,lchild_prestr,lchid_instr);
		Creat(bt->rchild,rchild_prestr,rchind_instr);
	}

}
int height(BiTree bt)
{
	int hl,hr;
	if(bt==NULL) return 0;
	else
	{
		hl=height(bt->lchild);
		hr=height(bt->rchild);
		if(hl>hr)
			return hl+1;
		else
			return hr+1;
	}
}
int main(int argv,char *argc[])
{
	int n;
	while(cin>>n)
	{
		BiTree bt;
		string PreStr,InStr;
		cin>>PreStr>>InStr;
		Creat(bt,PreStr,InStr);
		int hei=height(bt);
		cout<<hei<<endl;
	}
	return 0;
}