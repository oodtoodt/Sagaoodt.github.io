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


int m,k;

int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;


#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
const int maxx = 1e6+7;
long long Sum[maxx<<2],Add[maxx<<2];
long long a[maxx],n;
void Pushup(int rt){
    Sum[rt] = Sum[rt<<1] + Sum[rt<<1|1];
}
void PushDown(int rt,int ln,int rn){//ln左子树的数量
    if(Add[rt])
    {   //下推标记
        Add[rt<<1]+=Add[rt];
        Add[rt<<1|1]+=Add[rt];
        //子节点的sum与add对应
        Sum[rt<<1]+=Add[rt]*ln;
        Sum[rt<<1|1]+=Add[rt]*rn;
        Add[rt] = 0;
    }
}
void Build(int l,int r,int rt)
{
    if(l == r){
        Sum[rt] = a[l];
        return ;
    }
    int m = (l+r)>>1;
    Build(ls);
    Build(rs);
    Pushup(rt);
}
void Update(int L,int R,int l,int r,int rt)
{//A[L, R]+=C
    if(l == r)
    {
        Sum[rt] = (long long) (sqrt(Sum[rt]));//更新数字和，向上保持正确
        return ;
    }
    int m = (l+r) >>1;
//    PushDown(rt,m-l+1,r-m);//下推标记

    if(r-l+1 == Sum[rt]) return ;
    if(L <= m)Update(L,R,l,m,rt<<1);
    if(R > m)Update(L,R,m+1,r,rt<<1|1);
    Pushup(rt);
}

long long Query(int L,int R,int l,int r,int rt)//操作区间，l,r当前节点区间，rt当前节点
{
    if(L <= l && r <= R)
    {
        return Sum[rt];
    }
    int m = (l+r)>>1;
//    PushDown(rt,m-l+1,r-m);
    long long ANS = 0;
    if(L <= m) ANS += Query(L,R,l,m,rt<<1);
    if(R > m) ANS += Query(L,R,m+1,r,rt<<1|1);
    return ANS;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/5-数据结构/xds线段树/hdu4027.txt","r",stdin);
#endif
    while(~scanf("%lld",&n))
    {
        printf("Case #%d:\n",++cnt);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld",&a[i]);
        }
        Build(1,n,1);
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int t,x,y;
            scanf("%d%d%d",&t,&x,&y);
            if(x > y) swap(x,y);
            if(t == 1)
            {
                printf("%lld\n",Query(x,y,1,n,1));
            }
            else{
                Update(x,y,1,n,1);
            }
        }
        cout<<endl;
    }
    return 0;
}
