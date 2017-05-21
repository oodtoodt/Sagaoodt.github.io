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

const int maxx=1005;
int n,m,k;
int a[maxx];
int dp[maxx];
int dp2[maxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di3_lesson/2/input.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        double k;
        scanf("%lf",&k);
        a[i] = k * 100000;
    }
    int max1 = 0,max2 = 0;
//    dp[0] = 1;
    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(a[j] < a[i])
            dp[i] = max(dp[j] + 1,dp[i]);
        }
//        max1 = max(max1,dp[i]);
    }
//    dp2[n-1] = 1;
    for(int i = n-1; i >= 0; i--)
    {
        dp2[i] = 1;
        for(int j = n-1; j > i; j--)
        {
            if(a[j] < a[i])
            dp2[i] = max(dp2[j] + 1, dp2[i]);
        }
//        max2 = max(max2,dp2[i] + dp[]);
    }
    int t = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            t = max(t, dp[i] + dp2[j]);
        }
    }
    printf("%d\n",n-t);
    return 0;
}
