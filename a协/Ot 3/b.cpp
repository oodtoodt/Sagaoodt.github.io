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

const int maxx=1000500;
int n,m,k;
int a[maxx];
long long ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
char ch[maxx];
int vis[11];
const int p = 107;
set<int > s;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Ot 3/b.txt","r",stdin);
#endif
    while(~scanf("%d",&n))
    {
        getchar();
        s.clear();
        for(int i = 0; i < n; i++)
        {
            memset(vis,0,sizeof(vis));
            scanf("%s",ch);
            printf("%s\n",ch);
            m = strlen(ch);
            cnt = 0;
            pos = 0;
            for(int j = 0; j < m; j++)
            {
                int t = ch[j]-'0';
                if(!vis[t])
                {
                    vis[t] = 1;
                    cnt += t * p;
                    pos++;
                }
            }
            cnt += pos;
            s.insert(cnt);
//            printf("%d\n",s.size());
        }
        printf("%d\n",s.size());
    }
    return 0;
}
