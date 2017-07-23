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

const int maxx=10005;
int n,m,k;
//int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

const int MAXN = 510;//最大点数
const int MAXM = MAXN*MAXN;//最大边数
int F[MAXN];//并查集使用
struct Edge{
    int u,v,w;
}edge[MAXM];
int tol;
void addedge(int u,int v,int w)
{
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol++].w = w;
}
int find(int x)
{
    if(F[x] == -1) return x;
    return F[x] = find(F[x]);
}
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
int kruskal(int n)
{
    memset(F,-1,sizeof(F));
    sort(edge,edge+tol,cmp);
    cnt = 0;
    ans = 0;
    for(int i = 0; i < tol; i++)
    {
        int v = edge[i].v;
        int w = edge[i].w;
        int u = edge[i].u;
        int t1 = find(u);
        int t2 = find(v);
        if(t1 != t2)
        {
            cnt++;
            ans = max(ans,w);
            F[t1] = t2;
        }
        if(cnt == n-1) break;
    }
    if(cnt < n-1) return -1;
    else return ans;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/3/m.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
//        init();
        tol = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int a;
                scanf("%d",&a);
                if(j!=i) addedge(i,j,a);
//                printf("%d")
                pos ++;
            }
//            printf("%d\n",pos);
        }
        int ans = kruskal(n);
//        dijkstra(cost,lowcost,n,0);
        printf("%d\n",ans);
    }
    return 0;
}
