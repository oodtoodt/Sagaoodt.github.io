#include<iostream>
#include<algorithm>
#include<cstdio>
#include <cstring>

using namespace std;

const int maxx=35;
int n,m,k;
char ch[maxx];


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
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/tp3/g.txt","r",stdin);
#endif
    scanf("%s%d",ch,&n);
    uN = strlen(ch), vN = n;
    for(int i = 0; i < n; i++)
    {
        char t;
        for(int j = 0; j < 6; j++)
        {
            getchar();
            scanf("%c",&t);
//            printf("%c",t);
            for(int k = 0; k < strlen(ch); k++)
            {
                if(t == ch[k])
                {
                    g[k][i] = 1;
                }
            }
        }
//printf("\n");
    }
    if(hungary() == strlen(ch)) printf("YES\n");
    else printf("NO\n");
    return 0;
}
