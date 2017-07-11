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

typedef long long ll;

const ll maxx=10005;
ll n,m,k;
ll a[maxx];
ll ans = 0,cnt = 0,pos = 0;
ll l = 0,r = 0;

ll extgcd(ll a, ll b, ll &x, ll &y)
{
    ll d = a;
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
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/1-数论/poj1061.txt","r",stdin);
#endif
    ll x,y;
    scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
    ll c,t;
    ll p = x - y;
    ll a = n - m;
    ll b = l;
    ll d = extgcd(a,b,x,y);
//    prllf("%d ",d);
    if(!(p % d))
    {
        x *= p/d;
        ll s = b/d;
//        printf("%lld ",x);
//        printf("%lld ",x%s);
//        x = (x % s + s) % s;
        x = x % s;
        while(x<=0)
        {
//            x += s;
        }
        printf("%lld\n",x);
    }
    else{
        printf("Impossible\n");
    }
    return 0;
}
