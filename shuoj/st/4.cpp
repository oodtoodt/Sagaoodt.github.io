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

typedef long long LL;
const LL maxx=1000000007;
LL n,m,k;
//int a[maxx];

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
    freopen("/Users/ecooodt/Desktop/c++ and acm/shuoj/st/4.txt","r",stdin);
#endif
    while(~scanf("%lld",&n))
    {
        LL t = qk_pow(2,n,maxx);
        printf("%lld\n",t-1);
    }
    return 0;
}
