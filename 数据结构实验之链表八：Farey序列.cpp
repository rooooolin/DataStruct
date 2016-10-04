#include <iostream>
#include <malloc.h>
using namespace std;
typedef struct LNode
{
	int a,b;
	struct LNode *next;
}LNode,*LinkList;

LinkList Init()
{
	LinkList head;
	LNode *p,*q;
	head=(LinkList)malloc(sizeof(LNode));
	head->next=NULL;
	p=new LNode;
	q=new LNode;
	p->a=0;p->b=1;
	q->a=q->b=1;
	head->next=p;
	p->next=q;
	q->next=NULL;
	return head;
}
void ListCreat(LinkList head,int n)
{
	LNode *p,*q,*k;
	p=head->next;
	while (p->next)
	{
		q=p->next;
		if (p->b+q->b<=n)
		{
			k=new LNode;
			k->a=p->a+q->a;
			k->b=p->b+q->b;
			p->next=k;
			k->next=q;
		}
		p=p->next;
	}
}
int main(int argv,char *argc[])
{
	int n;
	cin>>n;
	LNode *head,*p,*q;;
	head=Init();
	for (int i = 2; i <= n; i++)
	{
		ListCreat(head,i);
	}

    p = head->next;  
    int k = 0;  
    while (p!=NULL)  
    {  
        k++;  
        if (k%10==0)  
            cout<<p->a<<"/"<<p->b<<endl;  
        else  
            cout<<p->a<<"/"<<p->b<<"\t";  
        p = p->next;  
    }  
}
