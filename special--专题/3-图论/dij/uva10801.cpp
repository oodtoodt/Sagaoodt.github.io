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
#include <sstream>
using namespace std;

const int maxx = 10;
int n,m,k;
int a[maxx];
int c[105];
int b[5][105];
int len[105];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
/*
 * 单源最短路径，Dijkstra算法，邻接矩阵形式，复杂度为O(n^2)
 * 求出源beg到所有点的最短路径，传入图的顶点数，和邻接矩阵cost[][]
 * 返回各点的最短路径lowcost[], 路径pre[].pre[i]记录beg到i路径上的父结点，pre[beg]=-1

 * 可更改路径权类型，但是权值必须为非负 *
 */
const int MAXN = 105;
const int INF = 0x3f3f3f3f;
bool vis[MAXN];
int pre[MAXN];
int cost[MAXN][MAXN];
int lowcost[MAXN];
void Dijkstra(int cost[][MAXN],int lowcost[],int n,int beg)
{
    for(int i = 0; i <= n; i++)
    {
        lowcost[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    lowcost[beg] = 0;
    for(int j = 0; j < 100; j++)
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
        for(int i = 0; i < 100; i++)
        {
            if(!vis[i] && lowcost[k] + cost[k][i] + 60 < lowcost[i])
            {
                lowcost[i] = lowcost[k] + cost[k][i] + 60;
                printf("%d ",lowcost[i]);
                pre[i] = k;
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/3-图论/dij/uva10801.txt","r",stdin);
#endif
    while(~scanf("%d%d",&n,&m))
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
//        getchar();
        memset(cost,0x3f,sizeof(cost));
        for(int l = 0; l < n; l++)
        {
//            printf("?");
            cnt = 0;
            while(1)
            {
                char ch;
                scanf("%d",&c[cnt++]);
                ch = getchar();
                if(ch == '\n')break;
            }
//            len[i] = cnt;
//            cout<<endl;
            for(int i = 0; i < cnt; i++)
            {
                for(int j = i+1; j < cnt; j++)
                {
                    int temp = abs(c[j]-c[i]) * a[l];
                    if(temp < cost[c[i]][c[j]])
                    {
                        cost[c[i]][c[j]] = temp;
                        cost[c[i]][c[j]] = temp;
                    }
                }
            }
        }
        Dijkstra(cost,lowcost,100,0);
        int t = lowcost[m];
        if(t >= INF)
        printf("IMPOSSIBLE\n");
        else
        printf("%d\n",t-60);
/*        for(int i = 1; i < len[i]; i++)
        {
            cost[b[0][i-1]][b[0][i]] = (b[0][i]-b[0][i-1]) * a[0];
        }
*/
    }
    return 0;
}
