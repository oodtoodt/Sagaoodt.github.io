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

/*
 * 单源最短路径，Dijkstra算法，邻接矩阵形式，复杂度为O(n^2)
 * 求出源beg到所有点的最短路径，传入图的顶点数，和邻接矩阵cost[][]
 * 返回各点的最短路径lowcost[], 路径pre[].pre[i]记录beg到i路径上的父结点，pre[beg]=-1
 * 可更改路径权类型，但是权值必须为非负 *
 */
const int MAXN = 1010;
const int INF = 0x3f3f3f3f;
bool vis[MAXN];
int pre[MAXN];
int cost[MAXN][MAXN];
int lowcost[MAXN];
void Dijkstra(int cost[][MAXN],int lowcost[],int n,int beg)
{
    for(int i = 0; i < n; i++)
    {
        lowcost[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    lowcost[beg] = 0;
    for(int j = 0; j < n; j++)
    {
        int k = -1;
        int Min = INF;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i] && lowcost[i] < Min)
            {
                Min = lowcost[i];
                k = i;
            }
        }
        if(k == -1) break;
        vis[k] = true;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i] && lowcost[k] + cost[k][i] < lowcost[i])
            {
                lowcost[i] = lowcost[k] + cost[k][i];
                pre[i] = k;
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/3-图论/dij/poj1502.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            string s;
            cin>>s;
            if(s == "x")
            {
//                printf("?");
                cost[i+1][j] = INF;
                cost[j][i+1] = INF;
            }
            else {
                cost[i+1][j] = stoi(s);
                cost[j][i+1] = stoi(s);
//                printf("%d ",stoi(s));
            }
        }
    }
    Dijkstra(cost,lowcost,n,0);
//        int ans;
    ans = 0;
    for(int i = 1; i < n; i++)
    {
        ans = max(ans,lowcost[i]);
    }
    printf("%d\n",ans);
    return 0;
}
