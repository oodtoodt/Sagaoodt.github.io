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

const int INF = 0x3f3f3f3f;
//const int m = 1000000;
const int M = 1005;
int cost[M][M];
int lowcost[M];
int pre[M];
bool vis[M];
void Dijkstra(int cost[][M],int lowcost[],int n,int beg)
{
    for(int i = 0; i < n; i++)
    {
        lowcost[i] = cost[0][i];
        pre[i] = -1;
        vis[i] = false;
    }
    lowcost[beg] = 0;
    for(int j = 0; j < n; j++)
    {
        int k = -1;
        int Min = 0;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i] && lowcost[i] > Min)
            {
                Min = lowcost[i];
                k = i;
            }
        }
        if(k == -1) break;
        vis[k] = true;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i] && min(lowcost[k] , cost[k][i]) > lowcost[i])
            {
                lowcost[i] = min(lowcost[k] , cost[k][i]);
                pre[i] = k;
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/3-图论/dij/poj1797.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(cost,0,sizeof(cost));
        memset(lowcost,0,sizeof(lowcost));
        scanf("%d%d",&n,&m);
        for(int i = 0; i < m; i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            cost[a-1][b-1] = c;
            cost[b-1][a-1] = c;
        }
        Dijkstra(cost,lowcost,n,0);
//        for(int i = 0; i < n; i++)
//        printf("%d\n",lowcost[i]);
        printf("Scenario #%d:\n",++cnt);
        printf("%d\n\n",lowcost[n-1]);
    }
    return 0;
}
