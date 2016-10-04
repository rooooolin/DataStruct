#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct DNode{
	int data;
	struct DNode *prior,*next;
}DNode,*DLinklist;

int main(int argv,char *argc[])
{
	int n,m;
	cin>>n>>m;
	DLinklist L;
	DNode *r;
	L=(DLinklist)malloc(sizeof(DNode));
	L->next=NULL;
	L->prior=NULL;
	r=L;
	for (int i = 0; i < n; i++)
	{
		DNode *s;
		s=(DNode *)malloc(sizeof(DNode));
		cin>>s->data;
		s->prior=r;
		s->next=r->next;
		r->next=s;
		r=s;
	}
	int x;
	for (int i = 0; i < m; i++)
	{
		
		cin>>x;
		DNode *p;
		p=new DNode;
		p=L->next;
		while(p)
		{
			if(p->data==x)
			{

				 if(p->next==NULL)  
                {  
					cout<<p->prior->data<<endl;  
                    break;  
                }  
                else if(p==L->next)  
                {  
                    cout<<p->next->data<<endl;  
                }  
                else  
                {  
					cout<<p->prior->data<<" "<<p->next->data<<endl;  
                    break;  
                }  
			}
			p=p->next;
		}
	}
	
	return 0;
}