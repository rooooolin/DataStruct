#include <iostream>
#include <cstdio>
using namespace std;


typedef struct AdjMatrix
{
    int w;
    char *info;
}AM;

typedef struct MGraph
{
    int vex[1001];
    AM **arc;
    int vexnum,arcnum;
    int s;
}MG;

void creat(MG &G)
{
    int i,j,k;
	G.arc=new AM*[1001];
	for (int i = 1; i <=G.vexnum; i++)
	{
		G.arc[i]=new AM[G.vexnum];
	}
    for(i=1;i<=G.vexnum;i++)
        for(j=1;j<=G.vexnum;j++)
            G.arc[i][j].w=0;
    for(k=1;k<=G.arcnum;k++)
    {
        cin>>i>>j;
        G.arc[i][j].w=G.arc[j][i].w=1;
    }
}

int cunt;   
void DFS(MG &G,bool *f,int i)
{
    f[i]=true;
    cunt++;
    if(i==G.s)
        cout<<i;
    else
       cout<<" "<<i;
    int k;
	for(k=1;k<=G.vexnum;k++)
        if(G.arc[i][k].w==1&&f[k]==false)
        {
            DFS(G,f,k);       
            cout<<" "<<i;
        }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        MG G;
		cin>>G.vexnum>>G.arcnum>>G.s;
        creat(G);
        bool visited[1001]={false};
        cunt=0;
        DFS(G,visited,G.s);
        if(cunt!=G.vexnum)
            cout<<" "<<0;
        cout<<endl;
    }
    return 0;
}