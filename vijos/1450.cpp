/*
  ID: oodt
  PROG:1450
  LANG:C++
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>

using namespace std;

const int maxx=200005;
int n,m,k;
double l = 0,r = 0;
double a[maxx],b[maxx],c[maxx];


 int ok(double mid)
{
    double time = 0;
    for(int i = 0; i < n; i++)
    {
        time += c[i]/mid;
        if(time>b[i]) return true;
        if(time<a[i]) time = a[i];
    }
    return false;
}

void erfen()
{
    double mid;
    while(r-l>0.0000000000000001)
    {
        mid = (l + r) / 2;
        if(ok(mid))
        {
            l = mid + 0.000001;
        }
        else
        {
            r = mid - 0.000001;
        }
//        printf("%d\n",mid);
    }
    printf("%.2f\n",r);
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/vijos/1450.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lf%lf%lf",&a[i],&b[i],&c[i]);
//        c[i] *= 1000;
        if(c[i] > r)
        {
            r = c[i];
        }
    }
    erfen();
    return 0;
}
