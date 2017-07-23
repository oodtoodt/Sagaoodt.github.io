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

const int maxx=100050;
int n,m,k;
//int dp[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
//int dp[maxx]

const int MOD = 1e9+7;
int p[100010];
void init()
{
    memset(p,0,sizeof(p));
    p[0] = 1;
    for(int i = 1; i < 100000; i++)
    {
        int r = 1;
        for(int j = 1;i >= (3*j*j-j)/2; j++, r  *= -1)
        {
            p[i] = p[i] + p[i-(3*j*j-j)/2] * r;
            p[i] = (p[i] % MOD + MOD ) % MOD;
            if(i >= (3*j*j+j)/2)
            {
                p[i] = p[i] + p[i-(3*j*j+j)/2] * r;
                p[i] = (p[i] % MOD + MOD ) % MOD;
            }
            if(i<10)printf("p[%d] = %d\n",i,p[i]);
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/2/f.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    init();
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",p[n]);
    }
    for(int i = 0; i < 6; i++)
    {
//        printf("%d ",p[i]);
    }
    return 0;
}
