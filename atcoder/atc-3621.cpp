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

const int maxx=100050;
int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
queue<int> q;
//int dist[maxx];


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

void init()
{
    for(int i = 1; i < maxx; i++)
    {
        addedge(i,(i+1-1)%n+1,1);
        addedge(i,(i*10-1)%n+1,0);
    }
}

int main()
{
#ifdef LOCAL
//    freopen("","r",stdin);
#endif
    scanf("%d",&n);
    init();
    Dijkstra(n,1);
    printf("%d\n",dist[n]+1);
    return 0;
}
