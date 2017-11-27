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
//int a[maxx];
int ans = 0,cnt = 0,pos = 0;
double l = 0,r = 0;
const double pi = 3.14159265358979323;

struct Node{
    double r,x,y,z;
}a[maxx];
double t = 0;
double init = 100*100*100;
const double EPS = 1e-11;

double V(Node a)
{
    return a.r*a.r*a.r*4/3*pi;
}
double V2(int i,double h)
{
    h = a[i].r * 2 - h;
    return pi * h*h*(a[i].r - h/3);
}
int cmp(Node a,Node b)
{
    return a.x<b.x;
}

int ok(double mid)
{
    double ans = 100*100*(mid-t);
    for(int i = 0; i < n; i++)
    {
        double t1 = a[i].z + a[i].r - mid;
        double t2 = mid - (a[i].z -a[i].r);
    }
    if(ans >= init) return false;
    else return true;
}

double erfen()
{
    double mid = (l + r) / 2;
    while(r-l > EPS)
    {
//        printf("%lf,%lf",l,r);
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
//    l--;
    return (l+r)/2;
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/I1/d.txt","r",stdin);
#endif
//    printf("%.11lf\n",EPS);
    while(~scanf("%d%d",&n,&m))
    {
        int x,q,y,z;
        init = 100*100*100;
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d%d%d",&q,&x,&y,&z);
            a[i].r = q*1.0/1000;
            a[i].x = x*1.0/1000;
            a[i].y = y*1.0/1000;
            a[i].z = z*1.0/1000;
        }
//        sort(a,a+n,cmp);
        for(int i = 0; i < n; i++)
        {
            init -= V(a[i]);
        }
        init /= m;
        t = 0;
        printf("%lf\n",init);
        for(int i = 0; i < m; i++)
        {
            l = t+init/10000;
            r = 100;
//            printf("%lf---%lf\n",l,r);
            double t2 = erfen();
            printf("%.9f\n",t2-t);
            t = t2;
        }
//        erfen();
    }
    return 0;
}
