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

int n,m,k;
int ans = 0,cnt = 0,pos = 0;

#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
const int maxx = 1e6+7;
long long Sum[maxx<<2],Col[maxx<<2];
long long  Rank[maxx],Rn = 0;
int  vis[maxx];
struct node
{
    int l,r;
}q[10010];

void SetRank(){//调用前，所有y值被无序存入Rank数组，下标为[1..Rn]
    int I = 2;
    //第一步排序
    sort(Rank+1,Rank+Rn);
    //第二步去除重复值
    for(int i = 2; i < Rn; i++) if(Rank[i]!=Rank[i-1]) Rank[I++]=Rank[i];
    for(int i = I-1; i >= 2; i--) if(Rank[i] != Rank[i-1]+1) Rank[I++] = Rank[i-1] + 1;//如果相邻数字间距大于1，在其中加上任意数字。
    //有什么影响呢。
    //update是二分查找整个区间的l,r所在位置，每次覆盖。
    //那么中间本应没有被覆盖到的点离散化后能够有一个剩余在里面，还是举一个例子来的直观。
    Rn=I;
    sort(Rank+1,Rank+Rn);
    //此时，所有y值被从小到大无重复地存入Rank数组，下标为[1..Rn]
//    printf("%d\n",Rn);
    for(int i = 1; i < Rn; i++)
    printf("%d %d\n",i,Rank[i]);
}

void PushDown(int rt,int ln,int rn){//ln左子树的数量
    if(Col[rt])
    {   //下推标记
        Col[rt<<1]=Col[rt];
        Col[rt<<1|1]=Col[rt];
        //子节点的sum与add对应//因为不需要更新整个上叶，所以不需要后两个参数
//        Sum[rt<<1]=Add[rt];
//        Sum[rt<<1|1]=Add[rt];
        Col[rt] = 0;
    }
}

void Update(int L,int C,int l,int r,int rt)
{//A[L, R]+=C
    if(l == r)
    {
        Sum[rt] = C;//到达叶修改
        return;
    }
    int m = (l+r) >>1;//根据条件判断往左子树还是右
    if(L <= m)Update(L,C,ls);
    else Update(L,C,rs);
//    Pushup(rt);//子更新，本更新
}
void Update(int L,int R,int C,int l,int r,int rt)
{//A[L, R]+=C
    if(L <= l&& r <= R)
    {
//        Sum[rt] = C;//更新数字和，向上保持正确
        Col[rt] = C;//增加Add标记，表示本区间的Sum正确，子区间的仍需Add调整
        return ;
    }
    int m = (l+r) >>1;
    PushDown(rt,m-l+1,r-m);//下推标记
    if(L <= m)Update(L,R,C,ls);
    if(R > m)Update(L,R,C,rs);//因为实际上一定是访问整体，所以前面的判断和两个参数可有可无。
//    Pushup(rt);
}

void Query(int L,int R,int l,int r,int rt)//操作区间，l,r当前节点区间，rt当前节点
{
    if(Col[rt])//这里其实是n的时间度，遍历全部。
    {
        if(!vis[Col[rt]]) ans++;//如果当前节点的更新值没有被访问过
        vis[Col[rt]] = 1;
        return ;
    }
    if(l == r) return ;//去掉了上面的判断这里要有一个结束循环
    int m = (l+r)>>1;
//    PushDown(rt,m-l+1,r-m);//因为这里，查询只有一次且查询之前一定是update操作，所以不需要这个更新。
//    long long ANS = 0;
    if(L <= m) Query(L,R,ls);
    if(R > m) Query(L,R,rs);
//    return ANS;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/5-数据结构/xds线段树/poj2528.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(Rank,0,sizeof(Rank));
        Rn = 1;
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d",&q[i].l,&q[i].r);
            Rank[Rn++] = q[i].l;
            Rank[Rn++] = q[i].r;
        }
        SetRank();
        memset(Col,0,sizeof(Col));
        for(int i = 1; i <= n; i++)
        {
            int l = lower_bound(Rank+1,Rank+Rn,q[i].l)-Rank;
            int r = lower_bound(Rank+1,Rank+Rn,q[i].r)-Rank;
//            printf("%d %d\n",l,r);
            Update(l,r,i,1,Rn,1);
        }
        memset(vis,0,sizeof(vis));
        ans = 0;
        Query(1,Rn,1,Rn,1);
        printf("%d\n",ans);
    }
    return 0;
}
