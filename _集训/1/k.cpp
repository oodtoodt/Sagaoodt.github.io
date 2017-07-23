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
ll b[maxx];

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
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/1/k.txt","r",stdin);
#endif
    ll T;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&m);
        for(ll i = 0; i < m; i++)
        {
            scanf("%lld",&a[i]);
        }
        for(ll i = 0; i < m; i++)
        {
            scanf("%lld",&b[i]);
        }
//        printf("%d%d",n,m);
        cnt = 0;
        ll a0 = a[0],b0 = b[0];
        ll x,y,d,a1,b1,c;
        for(ll i = 1; i < m; i++)
        {
            a1 = a[i];
            b1 = b[i];
            c = b1 - b0;
            d = extgcd(a0,a1,x,y);
            if(!(c%d)){
                x *= c/d;
                ll t = a1/d;
                x = (x % t + t) % t;
//                x %= b1/d;
                b0 = b0 + x * a0;
                a0 = a0/d*a1;//lcm a0,a1
                b0 = (b0%a0+a0) % a0;
            }
            else{
                b0 = n*3;
//                return 0;
                break;
            }
        }
//        while(b0<=0) b0 += a0;
//        while(b0<n){
//            printf("%d\n",b0);
//            b0+=a0;
//            cnt ++;
        //        }
//        printf("%lld\n",cnt);
//        ans += 
        if(b0 > n)
        printf("0\n");
        else
        printf("%lld\n",(n-b0)/a0+1-(b0==0?1:0));
    }
    return 0;
}
