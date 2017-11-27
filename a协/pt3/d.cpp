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

const int maxx=10005;
int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

void init()
{
    dp[1][1] = 0;
    dp[1][0] = 1;
    dp[0][1] = 1;
    for(int i = 2; i < n; i++)
    for(int j = 1; j < i; j++)
    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/pt3/d.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    init();
    while(T--)
    {
        scanf("%d%d",&n,&m);
        
    }
    return 0;
}
