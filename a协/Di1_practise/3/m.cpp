/*
  ID: oodt PROG: LANG:C++
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>

using namespace std;

const int maxx=1005;
int n,m,k;
int a[maxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di1_practise/3/in.txt","r",stdin);
#endif
    while(scanf("%d%d",&m,&n)&&m!=-1)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int ans = 0;
        int t = 0;
        int pos = 0;
        while(pos<n)
        {
            while(a[pos+t] - a[pos] <= m && pos + t < n)
            {
                t++;
            }
            pos = pos + t - 1;
//            printf("%d  ",pos);
            t = 0;
            while(a[pos+t] - a[pos] <= m && pos + t < n)
            {
                t++;
            }
            ans++;
            pos = pos + t;
//            printf("%d  ",pos);
            t = 0;
        }
        printf("%d\n",ans);
    }
    return 0;
}
