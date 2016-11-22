#include <iostream>
#include <limits.h>
using namespace std;

struct  node
{
	int data;
	node *next;
};
node *AlGraph[100],*p;
typedef struct
{
	int data[100];
	int front,rear;
}SqQueue;
int cunt;

void InitQueue(SqQueue &Q)
{
	Q.rear=Q.front=0;
}
void EnQueue(SqQueue &Q,int x)
{
	
		Q.data[Q.rear]=x;
		Q.rear++;

}
void DeQueue(SqQueue &Q,int &x)
{
	if(Q.rear==Q.front)
		;
	else
	{
		x=Q.data[Q.front];
		Q.front++;
	}
}
bool IsEmpty(SqQueue Q)
{
	if(Q.rear==Q.front)
		return true;
	else
		return false;
}
SqQueue Q;
bool visited[100];
void BFS(int v,int k)
{
	int q;
	
	visited[v]=true;
	EnQueue(Q,v);
	while (!IsEmpty(Q))
	{
		cunt++;
		if(cunt!=k)
			cout<<(q=Q.data[Q.front])<<" ";
		else
			cout<<(q=Q.data[Q.front])<<endl;
		DeQueue(Q,v);
		for (p=AlGraph[q]->next; p; p=p->next)
		{
			if(!visited[p->data])
			{
				
				visited[p->data]=true;
				EnQueue(Q,p->data);
			}
		}
	}
}


int main(int argv,char *argc[])
{
	int n;
	cin>>n;
	while (n--)
	{
		cunt=0;
		int m,k,t;
		cin>>k>>m>>t;
		for (int i = 0; i < k; i++)
		{
			AlGraph[i]=new node;
			AlGraph[i]->next=NULL;

		}
		for (int i = 0; i < m; i++)
		{
			int u,v;
			cin>>u>>v;
			p=new node;
			p->data=v;
			p->next=AlGraph[u]->next;
			AlGraph[u]->next=p;
			p=new node;
			p->data=u;
			p->next=AlGraph[v]->next;
			AlGraph[v]->next=p;
		}
		for (int i = 0; i < k; i++)
		{
			for (node *p = AlGraph[i]->next; p ; p=p->next)
			{
				for (node *q= p->next; q ; q=q->next)
				{
					if(p->data>q->data)
					{
						int temp=p->data;
						p->data=q->data;
						q->data=temp;
					}
				}
			}
		}
		
		BFS(t,k);
	}
	return 0;
}