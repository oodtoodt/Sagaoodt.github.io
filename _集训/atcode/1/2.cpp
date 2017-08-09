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
typedef long long ll;

int main()
{
#ifdef LOCAL
//    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/atcode/1/","r",stdin);
#endif
    ll n;
    scanf("%lld",&n);
    ll a,b;
    a = n * (n-1);
    b = 2;
    printf("2\n%lld %lld\n",a,b);
    return 0;
}
