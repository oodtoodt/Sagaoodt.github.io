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

const int maxx=1000500;
int n,m,k;
long long  f[maxx];
long long fac[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
typedef long long LL;

const int p = 1e9+7;
LL qk_pow(LL a, LL b, LL p) {
    LL res = 1;
    while(b) {
        if(b&1) res = (res * a) % p;
        a = (a*a) % p;
        b >>= 1;
    }
    return res;
}

void init(){
    f[0] = 1;
    f[1] = 0;
    f[2] = 1;
    fac[1] = 1;
    fac[0] = 1;
    fac[2] = 2;
    for(int i = 3; i <= 1000000; i++)
    {
        fac[i] = (fac[i-1]*i) % p;
        f[i] = ((i-1) % p * (f[i-1]+f[i-2]) % p) % p;
    }
}
long long C(int n,int m)
{
    if(n < m) return 0;
    if(n == m) return 1;
    long long ans = 1;
    ans = qk_pow(((LL)fac[m]*fac[n-m])%p,p-2,p);
    ans = (ans % p * (LL)fac[n] % p) % p;
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Ot 9/e.txt","r",stdin);
#endif
    int T;
    
    scanf("%d",&T);
    init();
    while(T--)
    {
        scanf("%d%d",&n,&m);
        long long ans = C(n,m)*f[n-m];
        ans = ans % p;
        printf("%lld\n",ans);
    }
    return 0;
}
