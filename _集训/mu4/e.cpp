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

const int maxx=5;
int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
const int INF = 0x3f3f3f3f;
//bool vis[maxx];

void dfs(int x,int p,int dir)
{
    printf("%d %d\n",x,p);
    if(p > k && x == 2)
    {
        ans = min(ans,p);
        return ;
    }
//    vis[x] = true;
//    bool flagl = false;
//    bool flagr = false;
    if(dir == r)
    {
        if(x == 4) dfs(1,a[1]+p,r);
        else dfs(x+1,a[x+1]+p,r);
    }
    if(dir == l)
    {
        if(x == 1) dfs(4,a[4]+p,l);
        else dfs(x-1,a[x-1]+p,l);
    }
//    if(flagl) dfs(l,p+a[l]);
//    vis[x] = false;
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/mu4/e.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ans = INF;
        scanf("%d",&k);
        for(int i = 1; i <= 4; i++)
        {
            scanf("%d",&a[i]);
        }
        dfs(2,0,r);
        dfs(2,0,l);
        printf("%d\n",ans);
    }
    return 0;
}
