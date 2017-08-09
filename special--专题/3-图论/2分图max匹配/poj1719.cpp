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

const int MAXM = 1005;
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
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/3-图论/2分图max匹配/poj1719.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        uN = n,vN = m;
        memset(g,0,sizeof(g));
        memset(a,0,sizeof(a));
        for(int i = 0; i < m; i++)
        {
            int b;
            scanf("%d%d",&a[i],&b);
            g[a[i]-1][i] = 1;
            g[b-1][i] = 1;
        }
//        printf("%d\n",res);
        if(hungary() < n)
        {
            printf("NO\n");
        }
        else{
            int t = 0;
            for(t = 0; t < m; t++)
            {
                if(linker[t] == -1) printf("%d",a[t]);
                else printf("%d",linker[t]+1);
                if(t != m-1) printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
