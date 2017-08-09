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
int p[60];

void init()
{
    for(int i = 2; i < 60; i++)
    {
        if(!p[i]) p[++p[0]] = i;
        for(int j = 1; j <= p[0] && p[j] <= 60/i; j++)
        {
            p[p[j]*i] = 1;
            if(i % p[j] == 0) break;
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/1-数论/rc容斥/hdu2204.txt","r",stdin);
#endif
    while(~scanf("%d",&n))
    {
        int t = pow(n,1.0/)
    }
    return 0;
}
