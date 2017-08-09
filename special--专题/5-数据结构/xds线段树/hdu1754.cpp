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

const int maxx=205000;
int n,m,k;
int a[maxx<<2];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

void Build(int l,int r,int rt)
{
    if(l == r)
    {
        scanf("%d",&a[rt]);
        return ;
    }
    int m = (l+r) >> 1;
    Build(lson);
    Build(rson);
    a[rt] = max(a[rt<<1],a[rt<<1|1]);
}
void Update(int p,int add,int l,int r,int rt)
{
    if(l == r)
    {
        a[rt] = add;
        return ;
    }
    int m = (l+r) >> 1;
    if(p<=m) Update(p,add,lson);
    else Update(p,add,rson);
    a[rt] = max(a[rt<<1] , a[rt<<1|1]);
}
int Query(int L,int R,int l,int r,int rt)
{
    if(L <= l && r <= R)
    {
        return a[rt];
    }
    int m = (l + r) >> 1;
    int ans = 0;
    if(L <= m) ans = max(Query(L,R,lson),ans);
    if(R > m) ans = max(Query(L,R,rson),ans);
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/5-数据结构/xds线段树/hdu1754.txt","r",stdin);
#endif
    while(~scanf("%d%d",&n,&m))
    {
        Build(1,n,1);
//    getchar();
        char ch[2];
        //while(scanf("%c",&ch) && ch != EOF)
        for(int i = 0 ; i < m; i++)
        {
            getchar();
            scanf("%s",ch);
            int a,b;
            scanf("%d%d",&a,&b);
            if(ch[0] == 'Q') printf("%d\n",Query(a,b,1,n,1));
            else Update(a,b,1,n,1);
        }
    }
    return 0;
}
