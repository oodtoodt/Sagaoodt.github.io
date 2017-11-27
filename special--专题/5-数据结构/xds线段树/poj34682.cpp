#include <iostream>
#include <cstdio>
#include <cstring>
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
using namespace std;
const int maxx = 1e6+7;
long long Sum[maxx<<2],Add[maxx<<2];
long long  a[maxx],n;
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
void Update(int L,int C,int l,int r,int rt)
{//A[L, R]+=C
    if(l == r)
    {
        Sum[rt] += C;//到达叶修改
        return;
    }
    int m = (l+r) >>1;//根据条件判断往左子树还是右
    if(L <= m)Update(L,C,l,m,rt<<1);
    else Update(L,C,m+1,r,rt<<1|1);
    Pushup(rt);//子更新，本更新
}
void Update(int L,int R,int C,int l,int r,int rt)
{//A[L, R]+=C
    if(L <= l&& r <= R)
    {
        Sum[rt] += C*(r-l+1);//更新数字和，向上保持正确
        Add[rt] += C;//增加Add标记，表示本区间的Sum正确，子区间的仍需Add调整
        return ;
    }
    int m = (l+r) >>1;
    PushDown(rt,m-l+1,r-m);//下推标记
    if(L <= m)Update(L,R,C,l,m,rt<<1);
    if(R > m)Update(L,R,C,m+1,r,rt<<1|1);
    Pushup(rt);
}

long long Query(int L,int R,int l,int r,int rt)//操作区间，l,r当前节点区间，rt当前节点
{
    if(L <= l && r <= R)
    {
        return Sum[rt];
    }
    int m = (l+r)>>1;
    PushDown(rt,m-l+1,r-m);
    long long ANS = 0;
    if(L <= m) ANS += Query(L,R,l,m,rt<<1);
    if(R > m) ANS += Query(L,R,m+1,r,rt<<1|1);
    return ANS;
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        memset(Add,0,sizeof(Add));
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld",&a[i]);
        }
        Build(1,n,1);
        char s[100];
        for(int i = 0; i < m; i++)
        {
            int l,r;
            scanf("%s",s);
            scanf("%d",&l);
            scanf("%d",&r);
            int c;
            if(s[0] == 'C')
            {
                scanf("%d",&c);
                Update(l,r,c,1,n,1);
            }
            if(s[0] == 'Q')
            {
                long long ans = Query(l,r,1,n,1);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}