#include <iostream>
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


const int maxn = 100000 + 500;
int a[maxn];
int b[maxn];


bool solve(int i_th,int n)
{
    memset(b,0,sizeof(b));
    for(int j = 1; j <= n; j++)
    {
        b[j] = a[j];
    }
    for(int i = 1; i <= n; i++)
    {
//        printf("%d ",b[i]);n
    }
    while(1)
    {
        for(int j = 1; j <= n; j++)
        {
            int temp = (j + i_th - 1) % n + 1;
            b[temp] -= j;
#ifdef LOCAL
//            printf("i_th=%d,j=%d,b[%d]=%d\n",i_th,j,temp,b[temp]);
#endif
            if(b[temp] < 0)
            return false;
        }
        for(int j = 1; j <= n ; j++)
        {
            if(b[j] != 0)
            {
                break;
            }
            if(j == n)
            return true;
        }
    }

}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/DI2_lesson/2/input.txt","r",stdin);
#endif
    int n,m;
    scanf("%d",&n);
    for(int i = 1; i < n+1; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 1; i < n+1; i++)
    {
        bool bo = solve(i,n);
        if(bo)
        {
            printf("YES\n");
            break;
        }
        if(i == n)
        {
            printf("NO\n");
        }

    }

}