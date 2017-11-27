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
const int maxx=100050;
ll n,m,k;
ll a[maxx];
ll ans = 0,cnt = 0,pos = 0;
ll l = 0,r = 0;
ll g,p;
ll max1[maxx];
ll t = 0;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/tp2/b.txt","r",stdin);
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/tp2/b1.txt","w",stdout);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
//        memset(a,0,sizeof(a));
        scanf("%lld%lld%lld",&n,&g,&p);
        for(ll i = 0; i < n; i++)
        {
            scanf("%lld",&a[i]);
            a[i] = max(a[i-1]+a[i],0l;);
        }
        memset(max1,0,sizeof(max1));
        for(ll i = 0 ; i < n; i++)
        {
            max1[i+1] = max(a[i],max1[i]);
        }
        l = 0,r = g;
        if(p < n) ans = max1[p];
        else if(a[n] > 0 && g/a[n] < p/n) ans = g;
        else if(p % n == 0) ans = max1[n];
        else
        {
            ans = p * a[n] ;
        }
        //erfen();
        
    }
    return 0;
}
