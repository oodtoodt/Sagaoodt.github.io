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

typedef long long ll;
const int maxx = 1e9+7;

int main()
{
#ifdef LOCAL
//    freopen("","r",stdin);
#endif
    ll n;
    scanf("%I64d",&n);
    ll ans = 1;
    ll a = 2;
    n--;
    while(n>0)
    {
        if(n % 2 == 1)
        {
            ans = (ans * a) % maxx;
        }
        n /= 2;
        a = (a * a) % maxx;
//        printf("%lld ",a);
    }
//    printf("\n");
    ans = (ans + 1 ) % maxx;
    printf("%I64d\n",ans);
    return 0;
}
