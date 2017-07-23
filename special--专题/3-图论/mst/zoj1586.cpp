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
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

const int MAXN = 1005;
const int MAXM = 1005*1005;
int F[MAXN];
int tol;
struct Edge{
    int u,v,w;
}edge[MAXM];
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
int find(int x)
{
    if(F[x] == -1) return x;
    return F[x] = find(F[x]);
}
void addedge(int u,int v,int w)
{
    edge[tol].v = v;
    edge[tol].w = w;
    edge[tol++].u = u;
}
int kruskal(int n)
{
    ans = 0;
    cnt = 0;
    memset(F,-1,sizeof(F));
    sort(edge,edge+tol,cmp);
    for(int i = 0; i < tol; i++)
    {
        int v = edge[i].v;
        int u = edge[i].u;
        int w = edge[i].w;
        int t1 = find(u);
        int t2 = find(v);
        if(t1 != t2)
        {
            ans += w;
            cnt++;
            F[t1] = t2;
        }
        if(cnt == n-1) break;
    }
    printf("%d\n",ans);
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/3-图论/mst/zoj1586.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        tol = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%d",&k);
                addedge(i,j,k+a[i]+a[j]);
            }
        }
        kruskal(n);
    }
    return 0;
}
