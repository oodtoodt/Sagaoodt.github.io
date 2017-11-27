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

const int maxx=10050;
int n,m,k;
//int a[maxx];
int ri[maxx],le;
int cntl = 0,cntr = 0;
int ans = 0,cnt = 0,pos = 0;
int sum = 0;
int l = 0,r = 0;
int vis[1050];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Ot 2/g.txt","r",stdin);
#endif
//    freopen("generators.in","r",stdin);
//    freopen("generators.out","w",stdout);
    while(~scanf("%d%d",&n,&m))
    {
        ans = 0,cnt = 0x3f3f3f3f,pos = 0;
        le = -1;
        sum = 0;
//        printf("%d",cnt);
        memset(ri,0,sizeof(ri));
        for(int i = 0; i < n; i++)
        {
            memset(vis,0,sizeof(vis));
            l = -1,r = 0;
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            int t = a,maxxr = a,maxxl = -1;
            int j = 1;
            while(!vis[t])
            {
                vis[t] = 1;
                t = (t * b + c) % d;
                if(t - maxxr > 0)
                {
                    maxxl = maxxr;
                    l = r;
                    maxxr = t;
                    r = j;
                }
                else if(t > maxxl)
                {
                    l = j;
                    t = maxxl;
                }
                j ++;
            }
            sum += maxxr;
//        le[cntl++] = l;
            if(((maxxr - maxxl) % m != 0) && maxxr - maxxl < cnt && maxxl != -1)
            {
                pos = i;
                le = l;
                cnt = maxxr - maxxl;
            }
            ri[i] = r;
        }
        if(sum % m == 0)
        {
            if(cnt == 0x3f3f3f3f)
            {
                printf("-1\n");
            }
            else{
                printf("%d\n",sum - cnt);
                for(int i = 0; i < n; i++)
                {
                    if(i == pos)
                    printf("%d",le);
                    else
                    printf("%d",ri[i]);
                    if(i != n-1)
                    printf(" ");
                    else printf("\n");
                }
            }
        }
        else
        {
            printf("%d\n",sum);
            for(int i = 0; i < n; i++)
            {
//            printf("???");
                printf("%d",ri[i]);
                if(i != n-1)
                printf(" ");
                else printf("\n");
            }
        }
    }
    return 0;
}
