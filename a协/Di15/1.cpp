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

const int maxx=10005;
const int MOD = 1000000007;
int n,m,k;
int a[maxx];
//long long sh,xi;
typedef long long LL;

LL qk_pow(LL a, LL b, LL p) {
    LL res = 1;
    while(b) {
        if(b&1) res = (res * a) % p;
        a = (a*a) % p;
        b >>= 1;
    }
    return res;
}
LL Comb(LL a, LL b, LL p) {
    if(a < b)   return 0;
    if(a == b)  return 1;
    if(b > a - b)   b = a - b;

    LL ans = 1, ca = 1, cb = 1;
    for(LL i = 0; i < b; ++i) {
        ca = (ca * (a - i))%p;
        cb = (cb * (b - i))%p;
    }
    ans = (ca*qk_pow(cb, p - 2, p)) % p;
    return ans;
}

LL Lucas(int n, int m, int p) {
    LL ans = 1;

    while(n&&m&&ans) {
        ans = (ans*Comb(n%p, m%p, p)) % p;
        n /= p;
        m /= p;
    }
    return ans;
}



int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di15/1.txt","r",stdin);
#endif
//    printf("%lld",MOD);
    while(~scanf("%d%d",&n,&m))
    {
        int a = n - 2;
        int b = n + m - 4;
        printf("%lld\n",Comb(b,a,MOD));
    }
    return 0;
}
