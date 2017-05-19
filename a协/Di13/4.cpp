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

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di13/4.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    int q,k;
    int ans = 1;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d",&q,&k);
        int t = n - q - a[q] - k;
        ans = 1;
        if(t < 0) {
            printf("%d\n",ans);
            continue;
        }
        if(t == 0)
        {
            printf("%d\n",ans+1);
            continue;
        }
        int t = n - t;
    }
    return 0;
}
