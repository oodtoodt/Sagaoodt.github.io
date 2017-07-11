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

const int maxx=10005;
LL n,m,k;
//LL a[maxx];
LL ans = 0,cnt = 0,pos = 0;
LL l = 0,r = 0;

LL qk_pow(LL a, LL b) {
    LL res = 1;
    while(b) {
        if(b&1) res = (res * a) ;
        a = (a*a) ;
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
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/1-数论/poj2115.txt","r",stdin);
#endif
    LL A,B,C,x,y;
    while(scanf("%lld%lld%lld%lld",&A,&B,&C,&k) && k != 0)
    {
        if(A == B)
        {
            printf("0\n");
            continue;
        }
        LL a = C;
        LL b = qk_pow(2,k);
//        printf("%lld ",b);
        LL c = B - A;
        LL d = extgcd(a,b,x,y);
        if(c % d)
        {
            printf("FOREVER\n");
        }
        else
        {
//            printf("%lld ",d);
            x *= c/d;
            LL s = b/d;
            //x = (x % s + s) % s;
            x %= s;
            if(x <= 0)
            {
                x += s;
            }
            printf("%lld\n",x);
        }
    }
    return 0;
}
