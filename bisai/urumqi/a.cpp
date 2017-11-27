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

const int maxx=55;
int n,m,k;
int a[maxx];
int b[maxx];
int s1[maxx][maxx];
int s2[maxx][maxx];
int t1[maxx];
int t2[maxx];
int cnt = 0,pos = 0;
int l = 0,r = 0;
set<int> ans[55];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/bisai/urumqi/a.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        int t = 0;
        l = 0;
        r = 0;
        memset(t1,0,sizeof(t1));
        memset(t2,0,sizeof(t2));
        memset(s2,0,sizeof(s2));
        memset(s1,0,sizeof(s1));
        for(int i = 0; i < n; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(t != x)
            {
                t = x;
                a[l++] = x;
            }
            s1[x][t1[x]++] = y;
        }
        t = 0;
        for(int i = 0; i < m; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            s2[x][t2[x]++] = y;
        }
//        printf("%d\t%d\n",l,r);
        int x,y;
        for(int i = 0; i < l; i++)
        {
            x = a[i];
            for(int j = 0; j < t1[x]; j++)
            {
                int y = s1[x][j];
                for(int k = 0; k < t2[y]; k++)
                {
                    ans[i].insert(s2[y][k]);
                }
            }
        }
        for(int i = 0; i < l; i++)
        {
            for(set<int> :: iterator it = ans[i].begin(); it != ans[i].end(); ++it)
            {
                printf("%d %d\n",a[i],(*it));
            }
        }
        for(int i = 0; i < l; i++)
        {
            ans[i].clear();
        }
        if(T != 0)printf("\n");
    }
    return 0;
}
