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

typedef long long LL;

const LL maxx=10005;
LL n,m,k;
LL a[maxx];
LL ans = 0,cnt = 0,pos = 0;
LL l = 0,r = 0;

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

LL Lucas(LL n, LL m, LL p) {
    LL ans = 1;

    while(n&&m&&ans) {
        ans = (ans*Comb(n%p, m%p, p)) % p;
        n /= p;
        m /= p;
    }
    return ans;
}

LL check(LL t,LL a,LL b)
{
    LL q = 0;
    while(t > 0)
    {
        q = t%10;
        if(!(q == a || q == b))
        {
            return false;
        }
        t /= 10;
    }
    return true;
}
const LL p = 1000000007;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/1-数论/rsa/cf300c.txt","r",stdin);
#endif
    LL a,b,n,A,B;
    scanf("%lld%lld%lld",&A,&B,&n);
    a = B - A;
    b = A;
    LL t;
    LL ans = 0;
    for(LL i = 0; i <= n; i++)
    {
        t = a*i + b*n;
        if(check(t,A,B))
        {
//            prLLf("%d ",i);
            ans = (ans + Comb(n,i,p)) % p;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
