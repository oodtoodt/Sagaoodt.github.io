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

const int maxx=500005;
int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;


int ok(int mid)
{
    int pos = 0,cnt = 0;
    for(int i = 1; i <= n+1; i++)
    {
        if(a[i] - pos > mid)
        {
            pos = a[i-1];
            cnt ++;
        }
        if(cnt >= m) return true;
    }
    return false;
}

void erfen()
{
    int mid;
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
    }
    l--;
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/T3/e.txt","r",stdin);
#endif
    int L;
    while(~scanf("%d%d%d",&L,&n,&m))
    {
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
            //b[i] = a[i]-a[i-1];
        }
        a[0] = 0;
        a[n+1] = L;
        sort(a,a+n+2);
        for(int i = 0; i <= n+1; i++)
        {
//            printf("%d ",a[i]);
        }
        l = 0;
        for(int i = 1; i <= n+1; i++)
        {
            l = max(a[i]-a[i-1],l);
        }
        r = L;
        erfen();
        printf("%d\n",l+1);
    }
    return 0;
}
