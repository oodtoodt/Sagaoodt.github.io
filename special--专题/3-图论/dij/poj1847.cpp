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

const int maxx=105;
int n,m,k;
//int a[maxx][maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

const int INF = 0x3f3f3f3f;
const int M = 105;
int cost[M][M];
int lowcost[M];
int pre[M];
bool vis[M];
void Dijkstra(int cost[][M],int lowcost[],int n,int beg)
{
    for(int i = 0; i < n; i++)
    {
        vis[i] = false;
        pre[i] = -1;
        lowcost[i] = INF;
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
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/3-图论/dij/poj1847.txt","r",stdin);
#endif
    int A,B;
    while(~scanf("%d%d%d",&n,&A,&B))
    {
        memset(cost,0,sizeof(cost));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            cost[i][j] = INF;
        }
        memset(lowcost,0,sizeof(lowcost));
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&k);
            for(int j = 0; j < k; j++)
            {
                scanf("%d",&m);
                if(j == 0) {
                    cost[i][m-1] = 0;
                }
                else cost[i][m-1] = 1;
            }
        }
        Dijkstra(cost,lowcost,n,A-1);
        if(lowcost[B-1] == INF) printf("-1\n");
        else printf("%d\n",lowcost[B-1]);
    }
    return 0;
}
