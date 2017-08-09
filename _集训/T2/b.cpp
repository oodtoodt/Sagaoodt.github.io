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
int a[maxx];
long long  ans = 0,cnt = 0,pos = 0;
long long l = 0,r = 0;
long long g,p;
long long pos2 = 0;

int ok(int mid)
{
    int t = mid;
    for(int i = 0 ; i < n; i ++)
    {
        mid += a[i];
        if(mid >= g) {
//            printf("%d\n",mid);
            return 1;
        }
        if(mid < 0) mid = 0;
    }
    if((p/n) * (mid-t) + t + pos >= g) {
//        printf("%d-%lld\n",mid,(p/n) * (mid-t) + mid + pos);
        return 1;
    }
//    if(((p/n)-1) * (mid-t) + mid + pos2 > g) return 1;
//    if(mid )
    return 0;
}
long long mid;
void erfen()
{

    while(l<=r)
    {
        mid = (l + r) / 2;
        if(ok(mid))
        {
//            printf("...");
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    l--;
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/T2/b.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);

    long long sum = g;
    long long sum1 = 0;
    while(T--)
    {
        pos2 = 0;
//        sum = 0;
        pos = 0;
        scanf("%d%lld%lld",&n,&g,&p);
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
            if(i < p%n)
            {
                sum1 += a[i];
                pos = max(pos,sum1);
            }
            sum += a[i];
            pos2 = max(pos,sum1);
        }
        r = g;l = 0;
        erfen();
        printf("%d\n",ok());
        printf("Case #%d: %lld\n\n",cnt++,l);
    }

    return 0;
}
