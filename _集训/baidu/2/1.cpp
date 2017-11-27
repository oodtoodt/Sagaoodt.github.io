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

const int maxx=10005;
int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/baidu/2/1.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ans = 0;
        scanf("%d",&n);
        int i;
        for(i = 1; i < sqrt(n-1); i++)
        {
            if((n-1) % i == 0)
            {
                ans += 2;
            }
        }
//        printf("%d\n",i);
        if((n-1) % i == 0) ans ++;
        printf("%d\n",ans);
    }
    return 0;
}
