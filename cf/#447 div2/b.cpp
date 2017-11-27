1/*
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
long long n,m,k;
int a[maxx];
long long ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
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
const int p = 1e9+7;

int main()
{
#ifdef LOCAL
//    freopen("","r",stdin);
#endif
    scanf("%lld%lld%lld",&n,&m,&k);
//    printf("%lld %lld %lld\n",n%2,m%2,k);
//    printf("%d %d %d\n",n%2 != m%2,k == -1,n%2 != m%2&&k == -1);
    if((n % 2 != m % 2) && (k == -1)) printf("0\n");
    else{
        long long t = qk_pow(2,m-1,p);
        ans = qk_pow(t,n-1,p);
        printf("%lld\n",ans);
    }
    return 0;
}
