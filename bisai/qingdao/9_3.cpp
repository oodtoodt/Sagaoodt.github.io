#include<iostream>

#include<cstring>

#include<stdio.h>

#include <cstdio>

#include <string.h>

using namespace std;
const int N=20005;
const int M=890000;//边是双向存的（注意不是无向）要开正常的2倍大
const int E = 222222;
const int inf=0x7fffffff;
int Head[N];
struct Edge
{
    int v,next,w;
} Edge[M];

int cnt,n,s,t,m;
void addEdge(int u,int v,int w)//这里存的还是一条有向边
{
    Edge[cnt].v=v;
    Edge[cnt].w=w;
    Edge[cnt].next=Head[u];
    Head[u]=cnt++;
    Edge[cnt].v=u;
    Edge[cnt].w=0;
    Edge[cnt].next=Head[v];
    Head[v]=cnt++;
}

int sap()
{
    int pre[N],cur[N],dis[N],gap[N];
    int flow=0,aug=inf,u;
    bool flag;
    for(int i=0; i<n; i++)
    {
        cur[i]=Head[i];
        gap[i]=dis[i]=0;
    }
    gap[s]=n;
    u=pre[s]=s;
    while(dis[s]<n)
    {
        flag=0;
        for(int &j=cur[u]; j!=-1; j=Edge[j].next)
        {
            int v=Edge[j].v;
            if(Edge[j].w>0&&dis[u]==dis[v]+1)
            {
                flag=1;
                if(Edge[j].w<aug) aug=Edge[j].w;
                pre[v]=u;
                u=v;
                if(u==t)
                {
                    flow+=aug;
//printf("%d\n",flow);
                    while(u!=s)
                    {
                        u=pre[u];
                        Edge[cur[u]].w-=aug;
                        Edge[cur[u]^1].w+=aug;//异或是找与其配对的边
                    }
                    aug=inf;
                }
                break;
            }
        }
        if(flag) continue;
        int mindis=n;
        for(int j=Head[u]; j!=-1; j=Edge[j].next)
        {
            int v=Edge[j].v;
            if(Edge[j].w>0&&dis[v]<mindis)
            {
                mindis=dis[v];
                cur[u]=j;
            }
        }
        if((--gap[dis[u]])==0)
        break;
        gap[dis[u]=mindis+1]++;
        u=pre[u];
    }
    return flow;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/bisai/qingdao/9.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
//        memset(point,-1,sizeof(point));
//        memset(Next,-1,sizeof(Next));
        memset(Head,-1,sizeof(Head));
        scanf("%d%d",&n,&m);
        scanf("%d%d",&s,&t);
           cnt = 0;
        for(int i = 0; i < m; i++)
        {
//            printf("ojbk\n");
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u,v,w*(E+1)+1);
            addEdge(v,u,w*(E+1)+1);
        }
        printf("%d\n",sap() % (E+1));
    }
}
