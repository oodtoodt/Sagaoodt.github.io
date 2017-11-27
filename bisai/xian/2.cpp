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
const int M = 1e9+7;
typedef long long ll;
typedef long long LL;
const int N = 1e9 + 8;

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
    freopen("/Users/ecooodt/Desktop/c++ and acm/bisai/xian/2.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int p,q,k;
        scanf("%d%d%d",&p,&q,&k);
        ll t = qk_pow(p,k,M);
        ll t1 = qk_pow(p-2*q,k,M);
        ll x = t + t1;
        x = (x % M + M) % M;
        ll y = 2*t % M;
//        printf("%lld,%lld\n",x,y);
        ll ans = (x % M * qk_pow(y,M-2,M) % M) % M;
        printf("%lld\n",ans);
    }
    return 0;
}
