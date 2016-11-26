#include <iostream>
#include <memory.h>
using namespace std;
#define INF 0x3f3f3f3f 

int map[1001][1001];
bool visited[1001];
int lowcost[1001];
int m,n;
int sum,flag;

void Prime()
{
	int k;
	int temp;
	visited[1]=true;
	for (int i = 1; i <= m; i++)
	{
		lowcost[i]=map[i][1];
	}
	for (int i = 2; i <= m ; i++)
	{
		temp=INF;
		for (int j = 1; j <= m; j++)
		{
			if (!visited[j]&&lowcost[j]<temp)
			{
				temp=lowcost[j];
				k=j;
			}
		}
		if(temp==INF)
		{
			flag=1;
			break;
		}
		visited[k]=true;
		sum+=temp;
		for (int j = 1; j <= m; j++)
		{
			if(!visited[j]&&lowcost[j]>map[j][k])
				lowcost[j]=map[j][k];
		}
	}
}
int main(int argv,char *argc[])
{
	int v,u,cost;
	while (cin>>m>>n)
	{
		memset(map,INF,sizeof(map));
		memset(visited,false,sizeof(visited));
		flag=0;
		sum=0;
		for (int i = 0; i < n; i++)
		{
			cin>>v>>u>>cost;
			map[v][u]=map[u][v]=cost;
		}
		Prime();
		if(!flag)
			cout<<sum<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}