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

const int maxx=40005;
int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
int dp[maxx];

void init()
{
    memset(dp,0,sizeof(dp));
    ans = 0;
    pos = 0;
    for(int i = 0 ; i < n; i++)
    {
        if(a[i] > dp[pos])
        {
            dp[++pos] = a[i];
        }
        else
        {
            *lower_bound(dp,dp+pos,a[i]) = a[i];
            //dp[t] = a[i];
//            printf(".")
        }
    }
    printf("%d\n",pos);
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/8/m1.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        init();
//        printf("%d\n",ans+1);
    }
    return 0;
}
