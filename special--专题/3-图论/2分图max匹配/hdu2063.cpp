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
const int MAXN = 510;
int uN,vN;
int g[MAXN][MAXN];
int linker[MAXN];
bool used[MAXN];
bool dfs(int u)
{
    for(int v = 0; v < vN; v++)
    {
        if(g[u][v] && !used[v])
        {
            used[v] = true;
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
    int res = 0;
    memset(linker,-1,sizeof(linker));
    for(int u = 0; u < uN; u++)
    {
        memset(used,0,sizeof(used));
        if(dfs(u)) res ++;
    }
    return res;
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/3-图论/2分图max匹配/hdu2063.txt","r",stdin);
#endif
    while(scanf("%d%d%d",&n,&uN,&vN) && n)
    {
        memset(g,0,sizeof(g));
        int a,b;
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d",&a,&b);
            g[a-1][b-1] = 1;
        }
        for(int i = 0; i < vN; i++)
        {
            for(int j = 0; j < uN; j++)
            {
//            g[i][j] = 1;
            }
        }
        ans = hungary();
        printf("%d\n",ans);
    }
    return 0;
}
