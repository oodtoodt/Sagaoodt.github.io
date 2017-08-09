#include <cstdio>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int dp[103];

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
        tmp = que.top();
        que.pop();
        int u = tmp.v;
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = 0; i < E[u].size(); i++)
        {
            int v = E[tmp.v][i].v;
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


int main()
{
//    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/atcode/1/1.txt","r",stdin);
    int cnt = 0;
    int a,b;
    int n,m;
    scanf("%d%d",&n,&m);
//    for(int i = 0 ; i < )
//    while(~scanf("%d%d",&a,&b))
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d",&a,&b);
        addedge(a,b,1);
//        cnt ++;
//        n = max(b,n);
//        n = max(a,n);
    }
    Dijkstra(n,1);
//    printf("%d\n",n);
    int t = dist[n];
    if(t > 2)
    {
        printf("IMPOSSIBLE\n");
//        printf("%d",t);
    }

    else
    {
        printf("POSSIBLE\n");
//        printf("%d",t);
    }
}