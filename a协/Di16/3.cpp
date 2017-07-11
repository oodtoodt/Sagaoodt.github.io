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

using namespace std;

const int maxx=100005;
int n,m,k;
typedef long long ll;
ll a[maxx];// d[maxx];
ll d[maxx];
ll dp[maxx][2];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di16/3.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lld",&a[i]);
    }
    for(int i = 1; i < n; i++)
    {
        d[i] = abs(a[i] - a[i-1]);
    }
    ll ans = 0;
    memset(dp,0,sizeof(dp));
    for(int i = 1; i < n; i++)
    {
        dp[i][0] = max(d[i],dp[i-1][1] + d[i]);
        dp[i][1] = max(-d[i],dp[i-1][0] - d[i]);
        ans = max(dp[i][1],max(dp[i][0],ans));
    }
    printf("%lld\n",ans);
    return 0;
}
