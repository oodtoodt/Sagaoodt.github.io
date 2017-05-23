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
#include<sstream>

using namespace std;

const int maxx=105;
int n,m,k;
int a[maxx][maxx];
int b[maxx][maxx];
int dp[maxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di14/3.txt","r",stdin);
#endif
    while(scanf("%d%d",&n,&m) && n != 0)
    {
//        printf("%d",n);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m ; j++)
            {
                scanf("%d",&a[i][j]);
                b[i][j] = j+1;
            }
        }
//        int mans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
//                mans = max(mans, a[i][j]);
            }
        }
        memset(dp,0,sizeof(dp));
        for(int i = 0; i < n; i++)
        {
            for(int j = m ; j >= 0; j--)
            {
                for(int q = 0 ; q < j ; q++)

                dp[j] = max(dp[j],dp[j-b[i][q]] + a[i][q]);

//                printf("%d\n",dp[j]);
//                mans = max(mans,dp[j]);
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}
