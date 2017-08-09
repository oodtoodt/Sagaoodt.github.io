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
typedef long long LL;
int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
long long dp[maxx][maxx];
const int p = 1e9 + 7;
LL qk_pow(LL a, LL b, LL p) {
    LL res = 1;
    while(b) {
        if(b&1) res = (res * a) % p;
        a = (a*a) % p;
        b >>= 1;
    }
    return res;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/T5/a.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    int t = qk_pow(2,p-2,p);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i = 1; i <= n; i++)
        {
            if(i == 1) a[i] = 1;
            if(i == n) a[i] = 0;
            if(a[i] == 1)
            for(int j = 1 ; j <= i; j++)
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                for(int j = i-1; j >= 2; --j)
                {
                    dp[i][j] = (dp[i-1][j] * t + dp[i][j+1] * t) % p;
                }
                dp[i][1] = (dp[i-1][1] + dp[i][2]) % p;
            }
        }
        printf("Case #%d: %lld\n",++cnt,dp[n][1] * t % p);
    }
    printf("%d\n",t);
    return 0;
}
