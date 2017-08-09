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

const int maxx=505;
int n,m,k;
//int a[maxx][maxx];
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
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/3-图论/2分图max匹配/poj3041.txt","r",stdin);
#endif
    while(~scanf("%d%d",&n,&k))
    {
        memset(g,0,sizeof(g));
        int a,b;
        uN = n,vN = n;
        for(int i = 0; i < k; i++)
        {
            scanf("%d%d",&a,&b);
            g[a-1][b-1] = 1;
        }
        printf("%d\n",hungary());

    }
    return 0;
}
