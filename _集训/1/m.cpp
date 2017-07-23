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

const int maxn = 1000005;
int euler[maxn];
void geteuler()
{
	memset(euler,0,sizeof(euler));
	euler[1] = 1;
	for(int i = 2;i <= maxn;i++){
        if(!euler[i]){
            for(int j = i;j <= maxn; j += i)
            {
                if(!euler[j]){
                    euler[j] = j;
                }
                euler[j] = euler[j]/i*(i-1);
            }
        }
    }
}


long long dp[1000000];
void check()
{
    dp[2] = 1;
    for(int i = 3; i <= maxn; i++)
    {
        dp[i] = dp[i-1] + euler[i];
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/1/m.txt","r",stdin);
#endif
    geteuler();
    check();
    while(scanf("%d",&n)&&n)
    {
        printf("%lld\n",dp[n]);
        //        printf("%d\t%d\n\n",n,euler[n]);
    }
    return 0;
}
