#include <iostream>
#include <limits.h>

using namespace std;
int cunt;
typedef struct
{
	char Vex[100];
	int Edge[100][100];
	int vexnum,arcnum;
}MGraph;
int getFirstNeighbor(MGraph G,int v)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if(G.Edge[v][i]>0&&G.Edge[v][i]<INT_MAX)
			return i;
	}
	return -1;
}
int getNextNeighbor(MGraph G,int v1,int v2)
{
	if(v1!=-1&&v2!=-1)
	{
		for (int i = v2+1; i < G.vexnum; i++)
		{
			if(G.Edge[v1][i]>0&&G.Edge[v1][i]<INT_MAX)
				return i;
		}
	}
	return -1;
}
bool visited[100];
void DFS(MGraph G,int v)
{
	cunt++;
	if(cunt!=G.vexnum)
		cout<<v<<" ";
	else
		cout<<v<<endl;
	visited[v]=true;
	for (int w = getFirstNeighbor(G,v); w>=0; w=getNextNeighbor(G,v,w))
	{
		if(!visited[w])
		{
			DFS(G,w);
			
		}
	}
}
void DFSTraverse(MGraph G)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		visited[i]=false;
	}
	for (int i = 0; i < G.vexnum; i++)
	{
		if(!visited[i])
			DFS(G,i);
		
	}
}
int main(int argv,char *argc[])
{
	int n;
	cin>>n;
	while (n--)
	{
		cunt=0;
		MGraph G;
		int k,m;
		cin>>k>>m;
		G.arcnum=m;
		G.vexnum=k;
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < k; j++)
			{
				G.Edge[i][j]=0;
			}
		}
		for (int i = 0; i < m; i++)
		{
			int u,v;
			cin>>u>>v;
			G.Edge[u][v]=1;
			
		}
		DFSTraverse(G);
	}
	return 0;
}
