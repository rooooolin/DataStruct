#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*Linklist;
void LinkPrint(Linklist &L)
{
	LNode *t=NULL;
	t=L->next;
	while(t)
	{
		if(t->next!=NULL)
			cout<<t->data<<" ";
		else
			cout<<t->data<<endl;
		t=t->next;
	}
}
int main(int argv,char *argc[])
{
	Linklist L,Lm,Ln;
	L=(Linklist)malloc(sizeof(LNode));
	Lm=(Linklist)malloc(sizeof(LNode));
	Ln=(Linklist)malloc(sizeof(LNode));
	int n,countm=0,countn=0;
	cin>>n;
	LNode *s,*r=L,*rm=Lm,*rn=Ln;
	for (int i = 0; i < n; i++)
	{
		s=(LNode*)malloc(sizeof(LNode));
		cin>>s->data;
		r->next=s;
		r=s;
	}
	r->next=NULL;
	LNode *p=NULL;
	p=L->next;
	while (p)
	{
		if(p->data%2==0)
		{
			LNode *t;
			t=p;
			rm->next=t;
			rm=t;
			countm++;
		}
		else
		{
			LNode *t;
			t=p;
			rn->next=t;
			rn=t;
			countn++;
		}
		p=p->next;
	}
	rm->next=NULL;
	rn->next=NULL;
	cout<<countm<<" "<<countn<<endl;
	LinkPrint(Lm);
	LinkPrint(Ln);
	return 0;
}