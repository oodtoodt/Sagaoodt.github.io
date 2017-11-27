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
int l = 0,r = 0;

const int P = 10007;
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
const int maxx = 1e6+7;
long long A[maxx<<2],Col[maxx<<2];//A存储的是连续区间的值
void Pushup(int rt){
    if(!Col[rt<<1] || !Col[rt<<1|1]) Col[rt] = 0;//左右子树标记为空（左右子树不为连续区间）则此处标记为空
    else if(A[rt<<1] != A[rt<<1|1]) Col[rt] = 0;//左右子树连续但不是一个连续则此处标记为空
    else {
        Col[rt] = 1;//连续
        A[rt] = A[rt<<1];//不然的话，左右子树相同，值设为左子树
    }
}

void PushDown(int rt,int ln,int rn){//ln左子树的数量
    if(Col[rt])
    {
        Col[rt<<1] = Col[rt<<1|1] = Col[rt];
        A[rt<<1] = A[rt<<1|1] = A[rt];
        Col[rt] = 0;
    }
}

void Update(int L,int R,int C,int l,int r,int rt,int k)
{//A[L, R]+=C
    if(L <= l&& r <= R && Col[rt])//此处连续则直接更新区间
    {
        if(k == 1) A[rt] = (A[rt] + C) % P;
        if(k == 2) A[rt] = (A[rt] * C) % P;
        if(k == 3) A[rt] = C;
        return ;
    }
    int m = (l+r) >>1;
    PushDown(rt,m-l+1,r-m);//下推标记
    if(L <= m)Update(L,R,C,l,m,rt<<1,k);
    if(R > m)Update(L,R,C,m+1,r,rt<<1|1,k);
    Pushup(rt);
}

int Query(int L,int R,int l,int r,int rt,int mi)//操作区间，l,r当前节点区间，rt当前节点
{
    if(L <= l && r <= R && Col[rt])//此处有值且值连续
    {
        int ans = 1;
        for(int i = 0; i < mi; i++)ans = (ans * A[rt]) % P;
        ans = (ans * (r-l+1)) % P;
        return ans;
    }
    int m = (l+r)>>1;
    PushDown(rt,m-l+1,r-m);
    int ANS = 0;
    if(L <= m) ANS = (ANS + Query(L,R,ls,mi)) % P;
    if(R > m) ANS = (ANS + Query(L,R,rs,mi)) % P;
    return ANS % P;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/5-数据结构/xds线段树/hdu4578.txt","r",stdin);
#endif
    int k,c,x,y;
    while(scanf("%d%d",&n,&m) && n)
    {
        memset(Col,1,sizeof(Col));//初始值皆相同
        memset(A,0,sizeof(A));
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d%d",&k,&x,&y,&c);
            if(k != 4)
            {
                Update(x,y,c,1,n,1,k);
            }
            else {
                int t = Query(x,y,1,n,1,c);
                printf("%d\n",t);
            }
        }
    }
    return 0;
}
