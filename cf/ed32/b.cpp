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
char a[maxx];
int ans = 0,cnt = 0,pos = 0;

int main()
{
#ifdef LOCAL
//    freopen("","r",stdin);
#endif
    scanf("%d",&n);
    getchar();
    for(int i = 0; i < n; i++)
    {
        scanf("%c",&a[i]);
    }
    int l = 0,r = 0,u = 0,d = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == 'R') r++;
        if(a[i] == 'D') d++;
        if(a[i] == 'L') l++;
        if(a[i] == 'U') u++;
    }
//    printf("%d %d\n",l,r);
    int t = min(l,r)*2+min(u,d)*2;
    printf("%d\n",t);
    return 0;
}
