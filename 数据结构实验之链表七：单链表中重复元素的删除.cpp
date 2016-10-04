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
	LNode *L;
	L=(LNode *)malloc(sizeof(LNode));
	L->next=NULL;
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		LNode *s;
		s=(LNode *)malloc(sizeof(LNode));
		cin>>s->data;
		s->next=L->next;
		L->next=s;
	}
	cout<<n<<endl;
	LinkPrint(L);
	LNode *pre=NULL,*p=NULL,*r=NULL;
	int m=0;
	r=L->next;
	while (r)
	{
		pre=r;
		p=pre->next;
		while(p)
		{
			if(r->data==p->data)
			{
				m++;
				pre->next=p->next;
				free(p);
				p=pre->next;
			}
			else
			{
				pre=p;
				p=p->next;
			}
			
		}
		
		r=r->next;
	}
	cout<<n-m<<endl;
	LinkPrint(L);
	return 0;
}
