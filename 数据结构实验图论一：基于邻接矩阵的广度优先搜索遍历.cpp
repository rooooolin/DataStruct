#include iostream
#include limits.h
using namespace std;


typedef struct 
{
	char Vex[100];
	int Edge[100][100];
	int vexnum,arcnum;
}MGraph;

typedef struct
{
	int data[100];
	int front,rear;
}SqQueue;
int cunt;
int getFirstNeighbor(MGraph G,int v)
{
	for (int i = 0; i  G.vexnum; i++)
	{
		if((G.Edge[v][i]0&&G.Edge[v][i]INT_MAX)(G.Edge[i][v]0&&G.Edge[i][v]INT_MAX))
			return i;
	}
	return -1;
}
int getNExtNeighbor(MGraph G,int v1,int v2)
{
	if(v1!=-1&&v2!=-1)
	{
		for (int i = v2+1; i  G.vexnum; i++)
		{
			if((G.Edge[v1][i]0&&G.Edge[v1][i]INT_MAX)(G.Edge[i][v1]0&&G.Edge[i][v1]INT_MAX))
				return i;
		}
	}
	return -1;
}
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
void BFS(MGraph G,int v)
{
	
	coutv ;
	visited[v]=true;
	EnQueue(Q,v);
	while (!IsEmpty(Q))
	{
		DeQueue(Q,v);
		for (int w = getFirstNeighbor(G,v); w = 0; w=getNExtNeighbor(G,v,w))
		{
			if(!visited[w])
			{
				cunt++;
				if(cunt!=G.vexnum-1)
					coutw ;
				else
					coutwendl;
				visited[w]=true;
				EnQueue(Q,w);
			}
		}
	}
}
void BFSTraverse(MGraph G,int t)
{
	for (int i = 0; i  G.vexnum; ++i)
	{
		visited[i]=false;
	}
	
	InitQueue(Q);
	for (int i = t; i  G.vexnum; ++i)
	{
		if(!visited[i])
			BFS(G,i);
	}
}

int main(int argv,char argc[])
{
	int n;
	cinn;
	while (n--)
	{
		MGraph G;
		cunt=0;
		int m,k,t;
		cinkmt;
		G.arcnum=m;
		G.vexnum=k;
		for (int i = 0; i  k; i++)
		{
			for (int j = 0; j  k; j++)
			{
				G.Edge[i][j]=0;
			}
		}
		for (int i = 0; i  m; i++)
		{
			int u,v;
			cinuv;
			G.Edge[u][v]=1;
		}
		BFSTraverse(G,t);
	}
	return 0;
}