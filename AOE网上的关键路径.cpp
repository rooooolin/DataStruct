#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;  
struct edge  
{  
    int v,w,pre;  
}p[50010];  
int n,m,nextj[10010],head[50010],cnt,vis[10010],dis[10010],u,v,w;  
int main()  
{  
    while(cin>>n>>m)  
    {  
        memset(head,-1,sizeof(head));  
        memset(nextj,0,sizeof(nextj));  
        memset(vis,0,sizeof(vis));  
        memset(dis,0,sizeof(dis));  
        cnt=0;vis[n]=1;  
        for(int i=0;i<m;i++)  
        {  
            cin>>v>>u>>w;  
            p[cnt].v=v;p[cnt].w=w;p[cnt].pre=head[u];head[u]=cnt++;  
        }  
        queue<int>q;  
        q.push(n);  
        while(!q.empty())  
        {  
            u=q.front();  
            q.pop();  
            vis[u]=0;  
            for(int i=head[u];~i;i=p[i].pre)  
            {  
                if(dis[p[i].v]<dis[u]+p[i].w||(dis[p[i].v]==dis[u]+p[i].w&&nextj[p[i].v]>u))  
                {  
                    dis[p[i].v]=dis[u]+p[i].w;nextj[p[i].v]=u;  
                    if(!vis[p[i].v])  
                    {  
                        q.push(p[i].v);  
                        vis[p[i].v]=1;  
                    }  
                }  
            }  
        }  
        cout<<dis[1]<<endl;  
        for(int i=1;nextj[i];i=nextj[i])  
        {  
            cout<<i<<" "<<nextj[i]<<endl;;  
        }  
    }  
    return 0;  
}  