#include <iostream>
using namespace std;
#include <string>
#include <string.h>
#include <malloc.h>

typedef struct Linknode{
	int data;
	struct Linknode *next;
}LiStack;
void SearchNext(Linknode *head)
{
	Linknode *p=NULL,*q;
	p=head->next;
	for (; p!=NULL; p=p->next)
	{
		q=p->next;
		while (q)
		{
			if(q->data>p->data)
			{
				cout<<p->data<<"-->"<<q->data<<endl;
				break;
			}
			else
				q=q->next;
		}
		if(q==NULL)
		{
			cout<<p->data<<"-->-1"<<endl;
		}
	}
}
int main(int argv,char *argc[])
{
	int t,n;
	cin>>t;
	LiStack *head;
	while (t--)
	{
		cin>>n;
		Linknode *tail,*p,*q;
		head=(Linknode*)malloc(sizeof(Linknode));
		head->next=NULL;
		tail=head;
		for (int i = 0; i < n; i++)
		{
			p=(Linknode*)malloc(sizeof(Linknode));
			cin>>p->data;
			p->next=NULL;
			tail->next=p;
			tail=p;
		}
		SearchNext(head);
		if(t>0)
			cout<<endl;
	}
	return 0;
}
