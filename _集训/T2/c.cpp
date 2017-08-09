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

const int maxx=20;
int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
int dp[maxx];
int vis[maxx];
int b[maxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/T2/c.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
//    printf("%d",a[0]);
    memset(dp,0,sizeof(dp));
    for(int i = 0; i < n ; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            for(int p = j+1; p < n; p++)
            {
                if(a[i] + a[j] > a[p] && (!vis[i] && !vis[j]&&!vis[p]))
                {
                    cnt++;
                    vis[i] = vis[j] = vis[p] = 1;
                }
            }
        }
    }
    if(n <= 2) printf("0\n");
    else printf("%d\n",cnt);
    return 0;
}
