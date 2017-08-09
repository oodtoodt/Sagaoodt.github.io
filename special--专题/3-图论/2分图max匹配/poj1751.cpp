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
int b[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

const int MAXN = 810;//最大点数
const int MAXM = 810*810;//最大边数
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
            if(w > 0) printf("%d %d\n",u+1,v+1);
            ans += w;
            F[t1] = t2;
            cnt ++;
        }
        if(cnt == n-1) break;
    }
    if(cnt < n-1) return -1;//不连通
    else return ans;
}
int cost(int t,int q)
{
    int x = a[t] - a[q];
    int y = b[t] - b[q];
    return x*x+y*y;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/3-图论/2分图max匹配/poj1751.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d",&a[i],&b[i]);
    }
    tol = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            addedge(i,j,cost(i,j));
        }
    }
    scanf("%d",&m);
    for(int i = 0; i < m; i++)
    {
        int c,d;
        scanf("%d%d",&c,&d);
        addedge(c-1,d-1,0);
    }
    int res = kruskal(n);
    if(res == -1) printf("\n");
    return 0;
}

