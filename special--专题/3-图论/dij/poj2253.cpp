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

const int maxx=205;
int n,m,k;
int a[maxx][2];
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
int cost[MAXN][MAXN];
int lowcost[MAXN];
int pre[MAXN];
void Dijkstra(int cost[][MAXN],int lowcost[],int n,int beg)
{
    for(int i = 0; i < n; i++)
    {
        lowcost[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    lowcost[beg] = 0;
    for(int j = 0; j < n; j++)//遍历所有顶点
    {
        int k = -1;
        int Min = INF;
        for(int i = 0; i < n; i++)//找到一个符合条件的值
        {//起初在未获取最短路径的顶点中，找到离源点最近的顶点。
            //现为在未取得与源点间的最大距离的顶点中
            //找到更新后距离源点最大距离最小的点（我的天。
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
            if(!vis[i] && max(lowcost[k],cost[k][i]) < lowcost[i])
            {
                lowcost[i] = max(lowcost[k],cost[k][i]);
                pre[i] = k;//替换lowcost意义为路径中的最大值
            }//原为与起点之间的最短距离。
        }
    }
}

void init()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cost[i][j] = (a[i][0]-a[j][0])* (a[i][0]-a[j][0]) + (a[i][1] - a[j][1]) * (a[i][1] - a[j][1]);
            cost[j][i] = (a[i][0]-a[j][0])* (a[i][0]-a[j][0]) + (a[i][1] - a[j][1]) * (a[i][1] - a[j][1]);
//            printf("dis between %d and %d is %d\n",i,j,cost[i][j]);
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/3-图论/dij/poj2253.txt","r",stdin);
#endif
    while(scanf("%d",&n) && n)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d",&a[i][0],&a[i][1]);
        }
        init();
        Dijkstra(cost,lowcost,n,1);
//        int t = 0;
//        ans = INF;
//        printf("%d\n",lowcost[0]);
        double t = lowcost[0];
        printf("Scenario #%d\n",++cnt);
        printf("Frog Distance = %.3f\n\n",sqrt(t));
    }
    return 0;
}

