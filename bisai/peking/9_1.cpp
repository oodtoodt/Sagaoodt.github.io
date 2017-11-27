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

const int maxx=140005;
int n,m,k;
int a[maxx<<2];
int b[maxx<<2];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int INF = 0x3f3f3f3f;

void Build(int l,int r,int rt)
{
    if(l == r)
    {
        scanf("%d",&a[rt]);
        b[rt] = a[rt];
        return ;
    }
    int m = (l + r) >> 1;
    Build(lson);
    Build(rson);
    a[rt] = min(a[rt<<1] , a[rt<<1 | 1]);
    b[rt] = max(b[rt<<1] ,b[rt<<1|1]);
}
void Update(int p,int add,int l,int r,int rt)
{
    if(l == r)
    {
        a[rt] = add;
        b[rt] = add;
        return ;
    }
    int m = (l+r) >> 1;
    if(p <= m)
    {
        Update(p,add,lson);
    }
    else
    {
        Update(p,add,rson);
    }
    a[rt] = min(a[rt<<1] , a[rt<<1 | 1]);
    b[rt] = max(b[rt<<1] , b[rt<<1 | 1]);
}
int Query(int L,int R,int l,int r,int rt)
{
    if(L <= l && r <= R)
    {
        return a[rt];
    }
    int m = (l + r) >> 1;
    int ans = INF;
    if(L <= m)
    {
        ans = min(Query(L,R,lson),ans);
    }
    if(R > m)
    {
        ans = min(Query(L,R,rson),ans);
    }
    return ans;
}

int Q2(int L,int R,int l,int r,int rt)
{
    if(L <= l && r <= R)
    {
        return b[rt];
    }
    int m = (l + r) >> 1;
    int ans = -INF;
    if(L <= m)
    {
        ans = max(Q2(L,R,lson),ans);
    }
    if(R > m)
    {
        ans = max(Q2(L,R,rson),ans);
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/bisai/peking/9.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int w = pow(2,n)+0.5;
        Build(1,w,1);
        scanf("%d",&m);
        for(int i = 0; i < m; i++)
        {
            int q,x,y;
            scanf("%d%d%d",&q,&x,&y);
            if(q == 1){
                long long t = Query(x+1,y+1,1,w,1);
                if(t < 0){
                    long long temp = Q2(x+1,y+1,1,w,1);
                    if(temp < 0) printf("%lld\n",temp*temp);
                    else printf("%lld\n",temp*t);
                }
                else printf("%lld\n",t*t);
            }
            else Update(x+1,y,1,w,1);
        }
    }
    return 0;
}
