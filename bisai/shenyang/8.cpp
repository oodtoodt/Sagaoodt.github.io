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

const int maxx=100050;
int n,m,k;
int a[maxx];
int b[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/bisai/shenyang/8.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i = 0 ; i < n-1; i++)
        {
            int x,y,c;
            scanf("%d%d%d",&x,&y,&c);
            b[i] = a[min(x,y)]-a[max(x,y)];
            if(b[i] < 0) b[i] += c;
            else b[i] -= c;
        }
        for(int i = 0; i < n-1; i++)
        {
            printf("%d ",b[i]);
        }
    }
    return 0;
}
