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

const int maxx=10005;
int n,m,k;
int a[maxx];
int l,r;
int ans;

int ok(int mid)
{
    ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += (a[i] / mid);
    }
    if(ans >= m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void erfen()
{
    int mid;
    while(l<=r)
    {
        int mid = (l + r) / 2;
        if(ok(mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    printf("%.2f\n",(l-1.0)/100);
    printf("%d",ans);
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di1_practise/4/in.txt","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    int maxn = 0;
    for(int i = 0; i < n; i++)
    {
        double te;
        scanf("%lf",&te);
        a[i] = (int)(te * 100);
        maxn=max(maxn,a[i]);
//        printf("%d",a[i]);
    }
    l = 1; r = maxn;
    erfen();
    return 0;
}