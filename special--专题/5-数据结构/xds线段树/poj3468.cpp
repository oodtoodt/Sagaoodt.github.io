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

typedef long long ll;
const int maxx=100500;
int n,m,k;
//int a[maxx];
ll col[maxx<<2];
ll sum[maxx<<2];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

void Pushup(int rt){
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void Pushdown(int rt,int m)
{
    if(col[rt]){
        col[rt<<1] += col[rt];
        col[rt<<1|1] += col[rt];
        sum[rt<<1] += 1ll * (m - (m>>1)) * col[rt];
        sum[rt<<1|1] += 1ll * (m >> 1) * col[rt];
        col[rt] = 0;
    }
}
void Build(int l,int r,int rt)
{
    col[rt] = 0;
//    sum[rt] = 1;
    if(l == r){
        scanf("%lld",&sum[rt]);
        return ;
    }
    int m = (l+r) >> 1;
    Build(lson);
    Build(rson);
    Pushup(rt);
}
void Update(int L,int R,int c,int l,int r,int rt){
    if(L <= l && r <= R)
    {
        col[rt] += c;
        sum[rt] += (ll)c * (r-l+1);
        return ;
    }
    Pushdown(rt,r-l+1);
    int m = (l+r) >> 1;
    if(L <= m) Update(L,R,c,lson);
    if(R > m) Update(L,R,c,rson);
    Pushup(rt);
}
ll Query(int L,int R,int l,int r,int rt){
    if(L<=l && r<=R)
    {
        return sum[rt];
    }
    Pushdown(rt,r-l+1);
    int m = (l+r) >> 1;
    ll res = 0;
    if(L<=m) res += Query(L,R,lson);
    if(m < R) res += Query(L,R,rson);
    return res;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/5-数据结构/xds线段树/poj3468.txt","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    Build(1,n,1);
    char ch[2];
    int a,b,c;
    for(int i = 0; i < m; i++)
    {
        scanf("%s%d%d",ch,&a,&b);
        if(ch[0] == 'Q') printf("%lld\n",Query(a,b,1,n,1));
        else {
            scanf("%d",&c);
            Update(a,b,c,1,n,1);
        }
    }
    return 0;
}
