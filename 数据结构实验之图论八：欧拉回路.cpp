#include <iostream>
#include <memory.h>
using namespace std;
int map[1001][1001],visited[1001],sum,d[2000],n;

void  DFS(int v)
{
	int i;
	visited[v]=1;
	sum++;
	for (int i = 1; i <= n; i++)
	{
		if(visited[i]==0&&map[v][i])
			DFS(i);
	}
}
int main(int argv,char *argc[])
{
	int t;
	cin>>t;
	while (t--)
	{
		int m;
		cin>>n>>m;
		memset(map,0,sizeof(map));
		memset(visited,0,sizeof(visited));
		memset(d,0,sizeof(d));
		for (int i = 0; i < m; i++)
		{
			int u,v;
			cin>>u>>v;
			map[u][v]=map[v][u]=1;
			d[u]++;
			d[v]++;
		}
		DFS(1);
		int i;
		for ( i= 1; i <= n; i++)
		{
			if(d[i]%2==1)
				break;
			
		}
		if(i==n+1&&sum==n)
				cout<<1<<endl;
			else
				cout<<0<<endl;
	}
	return 0;
}