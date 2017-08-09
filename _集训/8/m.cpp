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
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
int b[maxx];
int dp1[maxx];
int dp2[maxx];

void init()
{
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));
    for(int i = 0; i < n; i++)
    {
//        dp[i] = 1;
        for(int j = i; j >= 0; j--)
        {
            if(a[i] > a[j])
            {
                dp1[i] = max(dp1[j]+1,dp1[i]);
            }
        }
    }
    for(int i = n-1; i >= 0; i--)
    {
//        dp[i] = 1;
        for(int j = i; j < n; j++)
        {
            if(a[i] > a[j])
            {
                dp2[i] = max(dp2[j]+1,dp2[i]);
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/8/m.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        double d;
        scanf("%lf",&d);
        a[i] = d * 10000;
    }
    init();
    for(int i = 0 ; i < n ; i++)
    {
        ans = max(ans,dp1[i]+dp2[i]);
//        printf("%d ",dp1[i]+dp2[i]);
    }
//    cout<<endl;
    printf("%d\n",ans+1);
    return 0;
}
