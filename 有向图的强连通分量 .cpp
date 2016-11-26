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
bool reserve;

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
		{
			if(reserve)
				k--;
			DFS(G,w);
			
		}
			

		else

		{
			
			if(reserve&&w>0)
			{
				cunt++;
				k--;
			}
				
			else if(!reserve)
				getStack[k++]=S.data[S.top--];
			break;
		}
	}

	return 0;

}

int ReverseDFSTraverse(MGraph G)
{
	for (int i = 1; i <= G.vexnum; i++)
	{
		visited[i]=false;
	}
	k--;
	for (int i = k; k>=0;)
	{
		if (!visited[getStack[k]])
		{
			DFS(G,getStack[k]);
		}
	}
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
		MGraph G1;

		G.vexnum=n;
		G1.vexnum=n;
		G.arcnum=m;
		G1.arcnum=m;
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
		G1.Edge=new int*[n];
		for (int i = 1; i <= n; i++)

		{

			G.Edge[i]=new int[n];
			G1.Edge[i]=new int[n];
		}

		

		for (int i = 1; i <= m; i++)

		{

			int u,v;

			cin>>u>>v;

			G.Edge[u][v]=1;
			G1.Edge[v][u]=1;

		}

		DFSTraverse(G);
		reserve=true;
		ReverseDFSTraverse(G1);
		cout<<cunt<<endl;

	}

	return 0;

}

