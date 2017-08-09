//nupt2017tema05
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
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/mu5/11.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        ans = 0;
        int t = 1;
        for(int i = 1; i < n; i++)
        {
            if(a[i]-a[i-1] <= k) {
                t++;
            }
            else {
                //ans = max(t,ans);
                t = 1;
            }
        }
        ans = t;
        printf("%d\n",ans);
    }
    return 0;
}
