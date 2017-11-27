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
    r = n;
    while(a[l] == 0 && l < n) l++;
    while(a[r-1] == 1 && r > 0) r--;
    int cnt = 0;
    for(int i = l; i < r; i++)
    {
        if(a[i] == 0) cnt++;
    }
    printf("%d %d %d\n",cnt,l,r);
    if(cnt > r - l - cnt) printf("%d\n",n - (r-l-cnt));
    else printf("%d\n",n - cnt);
    return 0;
}
