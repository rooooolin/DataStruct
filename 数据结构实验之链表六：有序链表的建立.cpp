#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*Linklist;
void LinkPrint(LNode *L)
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
	LNode *s,*L;
	L=(LNode *)malloc(sizeof(LNode));
	L->next=NULL;
	int n;
	cin>>n;
	
	for (int i = 0; i < n; i++)
	{
		s=(LNode*)malloc(sizeof(LNode));
		cin>>s->data;
		LNode *pre=NULL,*p=NULL;
			pre=L;p=L->next;
		while(p)
		{
			if(s->data<p->data)
			{
				s->next=p;
				pre->next=s;
				break;
			}
			p=p->next;
			pre=pre->next;
		}
		if(!p)
		{
			s->next=p;
			pre->next=s;
		}
		/*if(i==0)
		{
			s->next=L->next;
			L->next=s;
		}
		else
		{
		LNode *pre=L,*p=L->next;
		while(p!=NULL&&p->data<s->data)
		{
			pre=p;
			p=p->next;
		}
		pre->next=s;
		s->next=p;
		}*/
	
	}
	LinkPrint(L);
	return 0;
}
