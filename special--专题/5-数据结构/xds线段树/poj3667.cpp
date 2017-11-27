
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
int n,m,k;
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
const int maxx = 1e6+7;
long long Sum[maxx<<2],lsum[maxx<<2],rsum[maxx<<2],Cov[maxx<<2];
long long  a[maxx];
void Pushup(int rt,int ln,int rn){
    lsum[rt] = lsum[rt<<1];//左子树左最大连续
    rsum[rt] = rsum[rt<<1|1];//右子树右最大连续
    if(lsum[rt] == ln)lsum[rt] += lsum[rt<<1|1];//如果左子树左最大连续占用了整个左区间，那么加上左子树右最大连续
    if(rsum[rt] == rn) rsum[rt] += rsum[rt<<1];//右子树同理
    Sum[rt] = max(lsum[rt<<1|1]+rsum[rt<<1],max(Sum[rt<<1],Sum[rt<<1|1]));//取最大值
}
void PushDown(int rt,int ln,int rn){//ln左子树的数量
    if(Cov[rt] != -1)
    {   //下推标记
        Cov[rt<<1]=Cov[rt<<1|1] = Cov[rt];
        Sum[rt<<1]=lsum[rt<<1] = rsum[rt<<1] = Cov[rt]*ln;//用标记更新整个该区间,左子树,右子树的左最大值
        Sum[rt<<1|1]=lsum[rt<<1|1] = rsum[rt<<1|1] = Cov[rt]*rn;
        Cov[rt] = -1;
    }
}
void Build(int l,int r,int rt)
{
    Sum[rt] = lsum[rt] = rsum[rt] = r-l+1;
    Cov[rt] = -1;
    if(l == r) return ;
    int m = (l+r)>>1;
    Build(ls);
    Build(rs);
    Pushup(rt,m-l+1,r-m);
}
void Update(int L,int R,int C,int l,int r,int rt)
{//A[L, R]+=C
    if(L <= l&& r <= R)
    {
        Sum[rt] = lsum[rt] = rsum[rt] = C ? (r-l+1) : 0;//更新所有数字和，向上保持正确，如果
        Cov[rt] = C;//增加Add标记，表示本区间的Sum正确，子区间的仍需Add调整
        return ;
    }
    int m = (l+r) >>1;
    PushDown(rt,m-l+1,r-m);//下推标记
    if(L <= m)Update(L,R,C,l,m,rt<<1);
    if(R > m)Update(L,R,C,m+1,r,rt<<1|1);
    Pushup(rt,m-l+1,r-m);
}

int Query(int w,int l,int r,int rt)//操作区间，l,r当前节点区间，rt当前节点
{
    if(l == r) return l;
    int m = (l+r)>>1;
    PushDown(rt,m-l+1,r-m);
    if(Sum[rt<<1] >= w) return Query(w,ls);
    if(rsum[rt<<1] + lsum[rt<<1|1] >= w) return m - rsum[rt<<1] + 1;//如果是左子树右+右子树左，即中间区间最大值，就输出左区间的右最大值第一个位置
    return Query(w,rs);
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/5-数据结构/xds线段树/poj3667.txt","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    Build(1,n,1);
    for(int i = 0; i < m; i++)
    {
        int q;
        scanf("%d",&q);
        if(q == 1){
            int t;
            scanf("%d",&t);
            if(Sum[1] < t) printf("0\n");
            else{
                int tt = Query(t,1,n,1);
                printf("%d\n",tt);
                Update(tt,t+tt-1,0,1,n,1);
            }
        }
        else{
            int t1,t2;
            scanf("%d%d",&t1,&t2);
            Update(t1,t1+t2-1,1,1,n,1);
        }
    }
    return 0;
}