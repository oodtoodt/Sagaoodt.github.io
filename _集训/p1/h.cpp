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

void Build(int l,int r,int rt)
{
    if(l == r)
    {
        scanf("%d",&a[rt]);
        return ;
    }
    int m = (l + r) >> 1;
    Build(lson);
    Build(rson);
    a[rt] = a[rt<<1] + a[rt<<1 | 1];
}
void Update(int p,int add,int l,int r,int rt)
{
    if(l == r)
    {
        sum[rt] += add;
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
    a[rt] = a[rt<<1] + a[rt<<1 | 1];
}
int Query(int L,int R,int l,int r,int rt)
{
    if(L <= l && r <= R)
    {
        return sum[rt];
    }
    int m = (l + r) >> 1;
    int ans = 0;
    if(L <= m)
    {
        ans += Query(L,R,lson);
    }
    if(R > m)
    {
        ans += Query(L,R,rson);
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/p1/h.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        Build(1,n,1);
    }
    return 0;
}
