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

const int p = 1e9+7;
const int maxx=100005;
int n,m,k;
int a[6];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
const int INF = 0x3f3f3f3f;
int vis[maxx];

void dfs(int x,int dis)
{
    ans = min(ans,dis);
    if(dis == )
    if(!vis[x])
    {
        for(int i = 0; i < 6; i++)
        {
            vis[x] = 1;
            if(dis + abs(a[i+1] - x) < ans)
            dfs(a[i+1],dis + abs(a[i+1] - x));
            vis[x] = 0;
        }
    }
//    printf("%d %d %lld %d %d %d\n",x,y,t1,t2,t3,ans);
//    return ans;
}



int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/p1/d.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&n,&m);
        for(int i = 0; i < 6; i++)
        {
            scanf("%d",&a[i]);
        }
        ans = INF;
        long long res = 0;
        for(int i = 1; i <= m; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
//            printf("%lld\n",ans);
//            if(a < b)
            dfs(a,b);
//            int t = 
            res += (ans % p * i % p) % p;
            res = res % p;
        }
        printf("%lld\n",res);
    }
    return 0;
}
