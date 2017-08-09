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

const int MAXN = 505;
int g[MAXN][MAXN];
int uN,vN;
bool used[MAXN];
int linker[MAXN];
bool dfs(int u)
{
    for(int v = 0; v < vN; v++)
    {
        if(!used[v] && g[u][v])
        {//如果这两点有边且无有被标记过
            used[v] = true;
            if(linker[v] == -1 || dfs(linker[v]))
            {//如果是孤立点--或不是故里点搜索该点对应女生的增广路。
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
    for(int u = 0; u < uN; u++)
    {
        memset(used,0,sizeof(used));
        if(dfs(u)) res++;
    }
    return res;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/3-图论/2分图max匹配/poj1274.txt","r",stdin);
#endif
    while(~scanf("%d%d",&n,&m))
    {
        uN = n,vN = m;
        int a;
        memset(g,0,sizeof(g));
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&k);
            for(int j = 0; j < k; j++)
            {
                scanf("%d",&a);
                g[i][a-1] = 1;
            }
        }
        ans = hungary();
        printf("%d\n",ans);
    }
    return 0;
}
