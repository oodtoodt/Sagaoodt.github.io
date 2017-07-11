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

LL extgcd(LL a, LL b, LL &x, LL &y)
{
    LL d = a;
    if(b != 0) {
        d  = extgcd(b, a % b, y, x);
        y -= (a/b) * x;
    }else {
        x = 1, y = 0;
    }
    return d;
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/1-数论/rsa/hdu1211.txt","r",stdin);
#endif
    LL p,q,e,l,x,y;
    while(~scanf("%lld%lld%lld%lld",&p,&q,&e,&l))
    {
        n = p * q;
        LL F = (p-1)*(q-1);
        LL D = extgcd(e,F,x,y);
//x *= /D;
        LL s = F/D;
        x = (x % s + s) % s;
//        printf("%lld",x);
        for(LL i = 0; i < l; i++)
        {
            LL c;
            scanf("%lld",&c);
            c = qk_pow(c,x,n);
            printf("%c",c);
        }
        printf("\n");
    }
    return 0;
}
