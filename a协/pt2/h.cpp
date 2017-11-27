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

const int maxx=305;
int n,m,k;
//int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
int vis[maxx];
struct aa
{
    int s,e;
}a[maxx];

int cmp(aa a,aa b)
{
    return a.e<b.e;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/pt2/h.txt","r",stdin);
#endif
    while(scanf("%d",&n) && n)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d",&a[i].s,&a[i].e);
        }
        sort(a,a+n,cmp);
        for(int i = 0; i < n; i++)
        {
//            printf("%d\n",a[i].e);
        }
        ans = 0;
        for(int i = 0; i < 5; i++)
        {
            memset(vis,0,sizeof(vis));
            cnt = 0;
            double d = i + 0.5;
            while(d < 1000)
            {
                for(int j = 0; j < n; j++)
                {
//                printf("%d %d %f\n",a[j].s,a[j].e,d);
                    if(!vis[j] && a[j].s < d && a[j].e > d)
                    {
                        cnt ++;
                        vis[j] = 1;
                        break;
                    }
                }
                d += 5;
            }
            ans = max(ans,cnt);
        }
        printf("%d\n",ans);
    }
    return 0;
}
