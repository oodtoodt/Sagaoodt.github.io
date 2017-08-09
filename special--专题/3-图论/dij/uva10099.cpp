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

const int M = 105;
const int INF = 0x3f3f3f3f;
int pre[M];
int cost[M][M];
int lowcost[M];
bool vis[M];
void Dijkstra(int n,int beg)
{
    for(int i = 0; i < n; i++)
    {
        vis[i] = false;
        lowcost[i] = cost[0][i];
        pre[i] = -1;
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
                lowcost[i] = min(lowcost[k],cost[k][i]);
                pre[i] = k;
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/3-图论/dij/uva10099.txt","r",stdin);
#endif
    while(~scanf("%d%d",&n,&r) && n)
    {
        memset(lowcost,0,sizeof(lowcost));
        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0 ; j < n; j++)
            {
                cost[i][j] = 0;
            }
        }
        for(int i = 0; i < r; i++)
        {
            int c1,c2,p;
            scanf("%d%d%d",&c1,&c2,&p);
            c1--,c2--;
            cost[c1][c2] = p;
            cost[c2][c1] = p;
        }
        int s,d;
        scanf("%d%d%d",&s,&d,&l);
        Dijkstra(n,s-1);
//        printf("%d\n",lowcost[d-1]);
        int t = lowcost[d-1] - 1;
        printf("Scenario #%d\n",++cnt);
        printf("Minimum Number of Trips = ");
        if(!(l%t)) printf("%d\n\n",l/t);
        else printf("%d\n\n",l/t+1);
    }
    return 0;
}
