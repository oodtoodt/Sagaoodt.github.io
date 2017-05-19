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

typedef long long ll;
using namespace std;

const int maxx=100005;
int n,m,k;
ll a[maxx],b[maxx];

int cmp (int a,int b)
{
    return a > b;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di1_practise/1/input.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    for(int tt = 0; tt < T; tt++)
    {
        scanf("%d%d",&n,&m);
        for(int i = 0; i < n; i++)
        {
            scanf("%lld",&a[i]);
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%lld",&b[i]);
        }
        sort(a,a+n,cmp);
        sort(b,b+m);
        ll sum = 0;
        for(int i = 0; i < n && i < m; i++)
        {
            if(a[i] > b[i])
            {
                sum += a[i] - b[i];
            }
            else break;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
