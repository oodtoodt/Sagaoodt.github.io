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
const int p = 1000000007;
long long n,m,k;
int a[maxx];
long long sum = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

long long euler(long long n)
{
    long long ans = n;
    for(int i = 2;i*i <= n;i++)
    {
    	if(n % i == 0)
        {
    		ans -= ans/i;
    		while(n % i == 0)
            n /= i;
        }
    }
    if(n > 1)ans -= ans/n;
  	return ans;
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/1-数论/euler/hdu3501.txt","r",stdin);
#endif
    long long ans;
    while(scanf("%lld",&n) && n)
    {
        ans = euler(n);
//        long long ans;
        ans = ans * n / 2;
        sum = (n - 1) * n / 2 ;
        ans = (sum - ans) % p;
        printf("%lld\n",ans);
    }
    return 0;
}
