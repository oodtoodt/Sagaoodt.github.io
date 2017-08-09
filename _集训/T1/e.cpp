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

const int maxx=200005;
int n,m,k;
long long a[maxx];
long long b[maxx];
long long c[maxx];
long long ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/T1/e.txt","r",stdin);
#endif
    while(scanf("%d",&n) && n)
    {
        ans = 0;
        for(int i = 0 ; i < n; i ++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[i] = x - y;
            b[i] = y - z;
            c[i] = z - x;
        }
        sort(a,a+n);
        sort(b,b+n);
        sort(c,c+n);
        for(int i = 0 ;i < n; i ++)
        {
            ans += a[i] * (2*i - n + 1);
            ans += b[i] * (2*i - n + 1);
            ans += c[i] * (2*i - n + 1);
        }
        printf("%lld\n",ans/2);
    }
    return 0;
}
