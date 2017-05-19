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
int f[3000];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/wishare/4.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        memset(f,0,sizeof(f));
        int sum = 0;
        scanf("%d",&m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d",&a[i]);
            sum += a[i];
        }
        k = sum;
        sum >>= 1;
//        printf("%d",sum);
//        printf("");
        for(int i = 0; i < m; i++)
        {
            for(int v = sum ; v >= a[i]; v--)
            {
                f[v] = max(f[v],f[v-a[i]]+a[i]);
            }
        }
        printf("%d %d\n",f[sum],k - f[sum]);
    }
    return 0;
}
