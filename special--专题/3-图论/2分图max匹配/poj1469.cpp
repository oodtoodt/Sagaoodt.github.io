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

const int MAXM = 505;
int g[MAXM][MAXM];
int uN,vN;
bool vis[MAXM];
int linker[MAXM];
bool dfs(int u)
{
    for(int v = 0; v < vN; v++)
    {
        if(!vis[v] && g[u][v])
        {
            vis[v] = true;
            if(linker[v] == -1 || dfs(linker[v]))
            {
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}
int hungary()
{
    memset(linker,-1,sizeof(linker));
    int res = 0;
    for(int u = 0 ; u < uN ; u++)
    {
        memset(vis,0,sizeof(vis));
        if(dfs(u)) res++;
    }
    return res;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/3-图论/2分图max匹配/poj1469.txt","r",stdin);
#endif
    int T;
    int p;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        uN = n, vN = m;
        memset(g,0,sizeof(g));
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&k);
            for(int j = 0; j < k; j++)
            {
                scanf("%d",&p);
                g[i][p-1] = 1;
            }
        }
        int res = hungary();
        if(res < n) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
