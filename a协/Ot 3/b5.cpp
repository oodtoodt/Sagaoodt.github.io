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

const int maxx=1005;
int n,m,k;
int a[maxx][11];
int ans = 0,cnt = 0,pos = 0;
char ch;
int l = 0,r = 0;

int vis[11];
set<int> s;
int f[maxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Ot 3/b.txt","r",stdin);
#endif
    while(~scanf("%d",&n))
    {
        s.clear();
        getchar();
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        for(int i = 0; i < n; i++)
        {
            memset(vis,0,sizeof(vis));
//            scanf("%s",ch);
//            int m = strlen(ch);
//            for(int j = 0; j < m; j++)
//            {
            while(1)
            {
                ch = getchar();
//                if(i <= n-2)printf("%c",ch);
                if(ch == '\n') break;
                if(ch == EOF) break;
                int t = ch - '0';
                if(!vis[t])
                {
                    vis[t] = 1;
                    a[i][t] = 1;
                }
            }
            int t = 1;
            ans = 0;
            for(int j = 1; j < 10; j++)
            {
                ans += a[i][j]*t;
                t=t+t;
            }
            s.insert(ans);
        }
        printf("%d\n",s.size());
    }
    return 0;
}
