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

const int MAXN = 110;//最大点数
const int MAXM = 10000;//最大边数
int F[MAXN];//并查集使用
struct Edge
{
    int u,v,w;
}edge[MAXM];//起点／终点／权值
int tol;//边数，加边前赋0
void addedge(int u,int v,int w)
{
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol++].w = w;
}
bool cmp(Edge a,Edge b)
{//将边按照权值大小从小到大排序
    return a.w<b.w;
}
int find(int x)
{
    if(F[x] == -1) return x;
    else return F[x] = find(F[x]);
}
int kruskal(int n)//传入点数，返回最小生成树的权值，如果不连通返回-1
{
    memset(F,-1,sizeof(F));
    sort(edge,edge+tol,cmp);
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < tol; i++)
    {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        int t1 = find(u);
        int t2 = find(v);
        if(t1 != t2)
        {
            ans += w;
//            printf("%d\n",ans);
            F[t1] = t2;
            cnt ++;
        }
        if(cnt == n-1) break;
    }
    if(cnt < n-1) return -1;//不连通
    else return ans;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/3-图论/mst/poj1287.txt","r",stdin);
#endif
    int a,b,c;
    while(scanf("%d%d",&n,&m) && n)
    {
        tol = 0;
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
//            printf("%d %d %d\n",a,b,c);
            addedge(a-1,b-1,c);
        }
        printf("%d\n",kruskal(n));
    }
    return 0;
}
