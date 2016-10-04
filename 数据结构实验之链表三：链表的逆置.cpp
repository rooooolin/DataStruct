#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*Linklist;
void ReverseList(Linklist &L)
{
	LNode *pre,*p=L->next,*r=p->next;
	p->next=NULL;
	while(r!=NULL)
	{
		pre=p;
		p=r;
		r=r->next;
		p->next=pre;
	}
	L->next=p;
	LNode *q=NULL;
	q=L->next;
	while(q!=NULL)
	{
		if(q->next!=NULL)
			cout<<q->data<<" ";
		else
			cout<<q->data<<endl;
		q=q->next;              
	} 
	
}
int main(int argv,char *argc[])
{
	Linklist L;
	
	L=(Linklist)malloc(sizeof(LNode));
	LNode *s,*r=L;
	int x;
	cin>>x;
	while(x!=-1)
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		r->next=s;
		r=s;
		cin>>x;
	}
	r->next=NULL;

	
	ReverseList(L);
	
	return 0;
}