#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*Linklist;

int main(int argv,char *argc[])
{
	Linklist Lm,Ln,L;
	L=(Linklist)malloc(sizeof(LNode));
	Ln=(Linklist)malloc(sizeof(LNode));
	Lm=(Linklist)malloc(sizeof(LNode));
	LNode *s,*rm=Lm,*rn=Ln,*r=L;
	int m,n;
	cin>>m>>n;
	for (int i = 0; i < m; i++)
	{
		s=(LNode*)malloc(sizeof(LNode));
		cin>>s->data;
		rm->next=s;
		rm=s;
	}
	rm->next=NULL;
	for (int i = 0; i < n; i++)
	{
		s=(LNode*)malloc(sizeof(LNode));
		cin>>s->data;
		rn->next=s;
		rn=s;
	}
	rn->next=NULL;
	
	LNode *p=NULL,*q=NULL;
	p=Lm->next;q=Ln->next;
	while (p&&q)
	{
		if(p->data>q->data)
		{
			LNode *t;
			t=q;
			r->next=t;
			r=t;
			q=q->next;
		}
		else
		{
			LNode *t;
			t=p;
			r->next=t;
			r=t;
			p=p->next;
		}
	}
	while (p)
	{
		LNode *t;
		t=p;
		r->next=t;
		r=t;
		p=p->next;
	}
	while (q)
	{
		LNode *t;
		t=q;
		r->next=t;
		r=t;
		q=q->next;
	}
	r->next=NULL;
	LNode *k=NULL;
	k=L->next;
	while(k)
	{
		if(k->next!=NULL)
			cout<<k->data<<" ";
		else
			cout<<k->data<<endl;
		k=k->next;
	}
	return 0;
}