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
ll a[maxx],b[maxx];
ll ans = 0,cnt = 0,pos = 0;
ll l = 0,r = 0;
ll g,p;
ll max1[maxx],max2[maxx];
ll t1,t2;

ll ok(ll mid)
{
//    printf("%d,%d,%d\n",t1 * a[n-1] + max1[t2-1] + mid, max1[t2-1] + mid,mid);
    if(max(t1 * a[n-1] + max1[t2-1] + mid, max1[t2-1] + mid) >= g) return false;
    return true;
}

int erfen()
{
    ll mid;
    while(l<=r)
    {
        mid = (l + r) / 2;
        if(ok(mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
//        printf("%d ",mid);
    }
//    printf("\n");
//    l--;
//
    return l;
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/tp2/b.txt","r",stdin);
//    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/tp2/b1.txt","w",stdout);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
//        memset(a,0,sizeof(a));
        scanf("%lld%lld%lld",&n,&g,&p);
        for(ll i = 1; i <= n; i++)
        {
            scanf("%lld",&a[i]);
            //printf("%d ",a[i]);
        }
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&);
        }
        for(int i = 0; i < n;i ++) max2[i] = max(b[i],max2[i-1]);
        for(ll i = 0 ; i < n; i++)
        {
            max1[i] = max(a[i],max1[i-1]);
            printf("%d ",max1[i]);
        }
        l = 0,r = g;
        t1 = p / n;
        t2 = (p + n - 1) % n + 1;
        ans = g - erfen();
        }
        printf("Case #%lld: %lld\n",++cnt,max(g - ans,0ll));
    }
    return 0;
}