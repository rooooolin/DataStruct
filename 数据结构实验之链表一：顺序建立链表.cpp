#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*Linklist;
int main(int argv,char *argc[])
{
	Linklist L;
	
	L=(Linklist)malloc(sizeof(LNode));
	LNode *s,*r=L;int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		
		s=(LNode*)malloc(sizeof(LNode));
		cin>>s->data;
		r->next=s;
		r=s;
	}
	r->next=NULL;
	L=L->next;
	for(int i=0;i<n;i++)
	{
		if(i==n-1)
			cout<<L->data<<endl;
		else
			cout<<L->data<<" ";
		L=L->next;
	}
	return 0;
}