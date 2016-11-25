#include <iostream>
using namespace std;
typedef struct
{
	int Edge[21][21];
	int vexnum,arcnum;
}MGraph;
bool visited[21];
int cunt;

int getFirstNeihbor(MGraph G,int v)
{
	for (int i = 1; i <= G.vexnum; i++)
	{
		if(G.Edge[v][i]==1||G.Edge[i][v]==1)
			return i;
	}
	return -1;
}
int getNextNeihbor(MGraph G,int v1,int v2)
{
	if(v1!=-1&&v2!=-1)
	{
		for (int i = v2+1; i <= G.vexnum; i++)
		{
			if(G.Edge[v1][i]==1||G.Edge[i][v1]==1)
				return i;
		}
	}
	return -1;
}

void DFS(MGraph G,int v)
{
	visited[v]=true;
	for (int w = getFirstNeihbor(G,v); w > 0; w=getNextNeihbor(G,v,w))
	{
		if(!visited[w])
			DFS(G,w);
	}
}

void DFSTraverse(MGraph G)
{
	for (int i = 1; i <= G.vexnum; i++)
	{
		visited[i]=false;
	}
	for (int i = 1; i <= G.vexnum; i++)
	{
		if(!visited[i])
		{
			cunt++;
			DFS(G,i);
		}
	}
}

int main(int argv,char *argc[])
{
	int t;
	cin>>t;
	while (t--)
	{
		int n,m;
		cin>>n>>m;
		MGraph G;
		G.vexnum=n;
		G.arcnum=m;
		cunt=0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				G.Edge[i][j]=0;
			}
		}
		for (int i = 1; i <= m; i++)
		{
			int u,v;
			cin>>u>>v;
			G.Edge[u][v]=G.Edge[v][u]=1;
		}
		DFSTraverse(G);
		cout<<cunt<<endl;
	}
	return 0;
}