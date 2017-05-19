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

const int maxx=500005;
int n,m,k;
int a[maxx];
int l,r;


int ok(int mid)
{
    int pos = 0;
    int sum = 0;
//    printf("%d\t",mid);
    for(int i = 0; i <= n; i++)
    {
//        printf("%d %d\t",pos,sum);
        if(a[i] - pos > mid)
        {
            if(i == 0) return true;
            pos = a[i-1];
            sum++;
        }
        if(sum >= m) return true;
    }
    return false;
}

void erfen()
{
    int mid;
    while(l<=r)
    {
//        printf("\n");
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
    printf("%d\n",l);
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di1_practise/7/1.txt","r",stdin);
#endif
    while(scanf("%d%d%d",&k,&n,&m)==3)
    {
        memset(a,0,sizeof(a));
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
//            r = max(r,a[i]);
        }
        l = 0;
        sort(a,a+n);
        a[n] = k;
        r = a[n];
        for(int i = 1; i <= n; i++)
        {
            l = max(l,a[i]-a[i-1]);
        }
        erfen();
    }
    return 0;
}
