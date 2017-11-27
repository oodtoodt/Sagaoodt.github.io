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

const int maxx=100050;
int n,m,k;
double a[maxx];
double b[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

struct p
{
    double low,high;
}cl[maxx];
int cmp(p a,p b)
{
    return a.high > b.high;
}

int ok(int mid,double q)
{
    if(b[mid] > q) return true;
    else return false;
}

int erfen(double q)
{
    int mid;
    while(l<=r)
    {
        mid = (l + r) / 2;
        if(ok(mid,q))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    l++;
//    r++;
//    printf("%d\n",l);
    return l;
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/xunlian/2/a.txt","r",stdin);
#endif
//    freopen("clothes.in","r",stdin);
//    freopen("clothes.out","w",stdout);
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lf",&a[i]);
    }
    scanf("%d",&m);
    for(int i = 0; i < m; i++)
    {
        scanf("%lf%lf",&cl[i].low,&cl[i].high);
        if(i != 0 && cl[i].high == cl[i-1].high && cl[i].low < cl[i-1].low)
        {
            cl[i-1].low = cl[i-1].low;
            cl[i-1].high = cl[i-1].high;
            i--;
            m--;
        }
    }
    sort(cl,cl+m,cmp);
//    printf("%d\n",cl[0].high);
    int fk = 0;
    if(cl[0].high < 30)
    {
//        printf("?");
        fk = 1;
    }
    double t = cl[0].low;
    double temp = 30;
    b[cnt++] = t;
    for(int i = 1; i < m; i++)
    {
        if(cl[i].high < cl[i-1].low) {
//            printf("??");
            fk = 1;
            break;
        }
        if(cl[i].high < t)
        {
            t = cl[i-1].low;
            b[cnt++] = temp;
        }
        else
        {
            temp = min(cl[i].low,temp);
        }
        if(i == m-1)
        {
            b[cnt++] = min(temp,cl[i].low);
        }
    }
    for(int i = 0; i < cnt; i++)
    {
//        printf("%lf\n",b[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] < b[cnt-1]) {
//            printf("???");
            fk = 1;
            break;
        }
        l = 0, r = cnt-1;
        ans += erfen(a[i]);
    }
    if(fk)
    printf("-1\n");
    else
    printf("%d\n",ans);
    return 0;
}
