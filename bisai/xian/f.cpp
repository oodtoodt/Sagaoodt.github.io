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
typedef long long LL;
const int P = 998244353;

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
    freopen("/Users/ecooodt/Desktop/c++ and acm/bisai/xian/f.txt","r",stdin);
#endif
    while(~scanf("%d%d",&n,&m))
    {
        if(n % 2 == 0 && m % 2 == 1) {printf("0\n");continue;}
        if(n % 2 == 1 && m % 2 == 0) {printf("0\n");continue;}
        LL ans = 0;
        int q = 1;
        if(n/2 % 2 == 1) q = -1;
        if(n % 2 == 1)
        {
            for(int i = 1; i <= m; i+=2)
            {
                LL t = Comb(n,n-i,P) * Comb((n-i)/2,(m - i)/2,P);
                if((m-i)/2 == 1) t *= -1;
                t *= q;
                q *= -1;
                t = (t % P + P) % P;
                ans += t;
                ans %= P;
            }
        }
        else
        {
            for(int i = 0; i <= m; i+=2)
            {
                LL t = Comb(n,n-i,P) * Comb((n-i)/2,(m - i)/2,P);
                if((m-i)/2 == 1) t *= -1;
                t *= q;
                q *= -1;
                t = (t % P + P) % P;
                ans += t;
                ans %= P;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
