x#include <iostream>
#include <sstream>
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


const int maxn = 100000;
int a[maxn];
//int b[maxn];


bool ok(int mid, int m, int n)
{
    int zero = a[0];
    int cnt = 1;
    for(int i = 1; i < n; i++)
    {
        if(a[i] - zero >= mid)
        {
            zero = a[i];
#ifdef LOCAL
            cout<<"zero="<<zero<<endl;
#endif
            cnt++;
        }
        if(i == n - 1)
        {
            if(cnt >= m)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

void erfen(int n, int m)
{
    int l = 0;
    int r = (a[n-1] - a[0]) / (m - 1);
    int mid;
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(ok(mid,m,n))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
#ifdef LOCAL
        printf("mid=%d\n",mid);
#endif
    }
    printf("%d\n",l - 1);
}



int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/DI1_lesson/2/input.txt","r",stdin);
#endif
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a + n);
    for(int i = 0; i < n; i++)
    {
//        printf("%d",a[i]);
    }
    erfen(n,m);
}
