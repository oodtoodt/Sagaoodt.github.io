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

const int maxx=60005;
int n,m,k;
int a[maxx];
int b[maxx];
double l,r;


int ok(double mid)
{
    double min_s = 100000000,max_x = 0;
    for(int i = 0; i < n; i++)
    {
        min_s = min(a[i] + b[i]*mid,min_s);
        max_x = max(a[i] - b[i]*mid,max_x);
        if(min_s < max_x)
        {
            return true;
        }
    }
    return false;
}

void erfen()
{
    double mid;
    while(r-l > 1e-7)
    {
        mid = (l + r) / 2;
        if(ok(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    printf("%.12lf",mid);
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di11/5.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&b[i]);
    }
    l = 0; r = 1000000000;
    erfen();
    return 0;
}
