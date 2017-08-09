/*
  ID: oodt
  PROG:
  LANG:C++
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;

int n,m,k;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000010;
struct qnode{
    int v;
    int c;
    qnode(int _v=0,int _c=0):v(_v),c(_c){}
    bool operator < (const qnode &r) const
        {
            return c > r.c;
        }
};
struct Edge
{
    int v,cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[MAXN];
bool vis[MAXN];
int dist[MAXN];
void Dijkstra(int n,int start)//点的编号从1开始
{
    memset(vis,false,sizeof(vis));
    for(int i = 1; i <= n; i++) dist[i] = INF;
    priority_queue <qnode> que;
    while(!que.empty()) que.pop();
    dist[start] = 0;
    que.push(qnode(start,0));
    qnode tmp;
    while(!que.empty())
    {
//        printf("?");
        tmp = que.top();
        que.pop();
        int u = tmp.v;
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = 0; i < E[u].size(); i++)
        {
            int v = E[u][i].v;
            int cost = E[u][i].cost;
            if(!vis[v]&&dist[v]>dist[u] + cost)
            {
                dist[v] = dist[u] + cost;
                que.push(qnode(v,dist[v]));
            }
        }
    }
}
void addedge(int u,int v,int w)
{
    E[u].push_back(Edge(v,w));
}
int a[MAXN],b[MAXN],c[MAXN];
int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/3-图论/dij/poj1511.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= n; i++)
        {
            E[i].clear();
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        }
        for(int i = 0; i < m; i++)
        {
            addedge(a[i],b[i],c[i]);
        }
        Dijkstra(n,1);
        //printf("%d",dist[])
        long long ans = 0;
        for(int i = 1; i <= n; i++)
        {
//            if(dist[i] != INF)
            ans += dist[i];
        }
        for(int i = 1; i <= n; i++)
        {
            E[i].clear();
        }
        for(int i = 0; i < m; i++)
        {
            addedge(b[i],a[i],c[i]);
        }
        Dijkstra(n,1);
        for(int i = 1; i <= n; i++)
        {
            ans += dist[i];
        }
        printf("%lld\n",ans);
//        Dijkstra(n,n);

    }
    return 0;
}
