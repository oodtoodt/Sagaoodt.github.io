#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
#include <string>
//#include 

using namespace std;

double h[1000+5];
int dp_1[1000+5];
int dp_2[1000+5];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/Di3_lesson/2/input.txt","r",stdin);
#endif
    memset(dp_1,0,sizeof(dp_1));
    memset(dp_2,0,sizeof(dp_2));
    int s;
    scanf("%d",&s);
    for(int i = 0; i < s; i++)
    {
        scanf("%lf",&h[i]);
    }


    for(int i = 0; i < s; i++)
    {
        int maxn = 0;
        for(int j = 0; j < i; j++)
        {
            if(h[j] < h[i])
            {
                maxn = max(maxn,dp_1[j]);
            }
        }
        dp_1[i] = maxn + 1;
    }
    int maxn = dp_1[0];
    for(int i = 0; i < s; i++)
    {
#ifdef LOCAL
        printf("dp_1[%d]=%d\n",i, dp_1[i]);
#endif
        if(dp_1[i] > maxn)
        maxn = dp_1[i];
    }


    for(int i = s-1; i >= 0; i--)
    {
        int maxn_2 = 0;
        for(int j = s-1; j >= i; j--)
        {
            if(h[j] < h[i])
            {
                maxn_2 = max(maxn_2,dp_2[j]);
            }
        }
        dp_2[i] = maxn_2 + 1;
    }
    int maxn_2 = dp_2[0];
    for(int i = 0; i < s; i++)
    {
#ifdef LOCAL
        printf("dp_2[%d]=%d\n",i, dp_2[i]);
#endif
        if(dp_2[i] > maxn_2)
            maxn_2 = dp_2[i];
    }
    maxn = max(maxn,maxn_2);
    printf("%d\n",s - maxn);
}
