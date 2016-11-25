#include <iostream>
#include <memory.h>
#include <cstring>
using namespace std;
typedef struct
{
	int **Edge;
	int vexnum,arcnum;
}MGraph;

typedef struct 
{
	int data[100];
	int top;
}Stack;
bool visited[100];
int cunt;
Stack S;
int getStack[100];
int k;
int getFirstNeihbor(MGraph G,int v)
{
	for (int i = 1; i <= G.vexnum; i++)
	{
		if(G.Edge[v][i]==1)
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
			if(G.Edge[v1][i]==1)
				return i;
		}
	}
	return -1;
}

int DFS(MGraph G,int v)
{
	visited[v]=true;
	S.data[++S.top]=v;
	for (int w = getFirstNeihbor(G,v); ; w=getNextNeihbor(G,v,w))
	{
		if(!visited[w]&&w>0)
			DFS(G,w);
		else
		{
			getStack[k++]=S.data[S.top--];
			break;
		}
		
	}
	return 0;
}

void DFSTraverse(MGraph G)
{
	//visited=new bool[G.vexnum];
	//memset(visited,false,sizeof(visited));
	
	//S.data=new int[G.vexnum];
	//memset(S.data,0,sizeof(S.data));
	//getStack=new int[G.vexnum];
	for (int i = 1; i <= G.vexnum; i++)
	{
		if(!visited[i])
		{
			DFS(G,i);
		}
	}
}

int main(int argv,char *argc[])
{
	int n,m;
	while (cin>>n>>m)
	{
		
		S.top=-1;	
		MGraph G;
		G.vexnum=n;
		G.arcnum=m;
		cunt=0;
		k=0;
		/*for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				G.Edge[i][j]=0;
			}
		}*/
		G.Edge=new int*[n];
		for (int i = 1; i <= n; i++)
		{
			G.Edge[i]=new int[n];
		}
		
		for (int i = 1; i <= m; i++)
		{
			int u,v;
			cin>>u>>v;
			G.Edge[u][v]=1;
		}
		DFSTraverse(G);
		cout<<cunt<<endl;
	}
	return 0;
}


http://blog.sina.com.cn/s/blog_66d6def50100wpsb.html