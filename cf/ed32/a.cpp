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
//    freopen("","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    if(n > 2)
    for(int i = 1; i < n-1; i++)
    {
        if(a[i] > a[i-1] && a[i] > a[i+1] || a[i] < a[i-1] && a[i] < a[i+1])
        {
            ans ++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
