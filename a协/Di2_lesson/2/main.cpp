#include <iostream>
//#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>
//#include <functional>
//#define LL long long

using namespace std;


const int maxn = 100005;
long long a[maxn];
long long b[maxn];

int main()
{
//    printf("ok");
#ifdef LOCAL
//    freopen("/Users/ecooodt/Desktop/c++ and acm/DI2_lesson/2/2.txt","r",stdin);
#endif
//    printf("%d",-5%5)
    memset(a,0,sizeof(a));
    long long n,m;
    scanf("%lld",&n);
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%lld",&a[i]);
        sum += a[i];
    }
    long long t = n*(1+n)/2;
    if(sum % t != 0)
    {
        printf("NO\n");
        return 0;
    }
    sum /= t;

    for(int i = 1; i < n; i++)
    {
        b[i-1] = a[i-1] - a[i];
    }
    b[n-1] = a[n-1] - a[0];


    for(int i = 0 ; i < n ; i++)
    {
        b[i] += sum;
        if(b[i] == 0)
        {
            continue;
        }
//        printf("%d\n",b[i]);
        if(b[i] % n != 0 || b[i] < 0)
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}