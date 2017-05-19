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

const int maxx=100005;
int n,m,k;
int a[maxx];
int l,r;

int ok(int mid)
{
    int ans = 1;
    int pos = a[0];
//    printf("%d",)
//    printf("%d\n",mid);
    for(int i = 0; i < n; i++)
    {
        if(a[i] - pos >= mid)
        {
            ans++;
            pos = a[i];
        }
//        printf("%d ",pos);
        if(ans >= m)
        {
            return true;
        }
    }
    return false;
}

void erfen()
{
    int mid;
    while(l<=r)
    {
        mid = (l + r) / 2;
//        printf("\n",mid);
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
    printf("%d\n",l);
}



int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di1_practise/5/1.txt","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        if(a[i] > r) r = a[i];
    }
    l = 1;
    sort(a,a+n);
    erfen();
    return 0;
}