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
const int INF = 0x3f3f3f3f;
int ans = 0,cnt = 0,pos = 0;
int res = INF;
int l = 0,r = 0;

#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
const int maxx = 1e5+7;
long long Sum[maxx<<2],Add[maxx<<2];
void Pushup(int rt){
    Sum[rt] = Sum[rt<<1] + Sum[rt<<1|1];
}
void Pushdown(int rt,int ln,int rn){//ln左子树的数量
    if(Add[rt] != -1)
    {   //下推标记
        Add[rt<<1]=Add[rt];
        Add[rt<<1|1]=Add[rt];
        //子节点的sum与add对应
        if(Add[rt] == 1)
        {
            Sum[rt<<1] = Sum[rt<<1|1] = 0;
        }
        else{
            Sum[rt<<1]=ln;
            Sum[rt<<1|1]=rn;
        }

        Add[rt] = -1;
    }
}
int Ma,Mi;
void Update(int L,int R,int l,int r,int rt,int val)
{
    if(L <= l&& r <= R)
    {
        if(val)
        {
            Sum[rt] = r-l+1;
            Add[rt] = 0;//增加Add标记，表示本区间的Sum正确，子区间的仍需Add调整
        }
        else {
            Sum[rt] = 0;//更新数字和，向上保持正确
            Add[rt] = 1;
        }
        return ;
    }
    int m = (l+r) >> 1;
    Pushdown(rt,m-l+1,r-m);//下推标记
    if(L <= m)Update(L,R,l,m,rt<<1,val);
    if(R > m)Update(L,R,m+1,r,rt<<1|1,val);
    Pushup(rt);
}

int Query(int L,int R,int l,int r, int rt)
{
    if(L <= l && r <= R)
    {
        return Sum[rt];
    }
    int m = (l+r)>>1;
    Pushdown(rt,m-l+1,r-m);
    int res = 0;
    if(L <= m) res += Query(L,R,ls);
    if(R > m) res += Query(L,R,rs);
    return res;//区域内已有花数
}

int erfen(int ll,int rank)
{
    int l = ll,r = n;
    int mid;
    int ans = -1;
    while(l<=r)
    {
        mid = (l + r) >> 1;
        int t = Query(ll,mid,1,n,1);
        if(t + rank == mid - ll + 1)//已有花+要插 == 区间长度
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            if(t + rank < mid - ll + 1) // <
            r = mid - 1;
            else l = mid + 1;
        }
    }
    return ans;
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/5-数据结构/xds线段树/hdu4614.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    int a,q,b;
    while(T--)
    {
        memset(Sum,0,sizeof(Sum));
        memset(Add,-1,sizeof(Add));
        scanf("%d%d",&n,&m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d",&q,&a,&b);
            a++;
            pos = -1;
            if(q == 1)
            {
                int t = erfen(a,1);
                if(t == -1)printf("Can not put any one.\n");
                else{
                    int te = Query(t,n,1,n,1);//右边已插花数
                    int tt = erfen(a, min(n-t+1-te,b));//右边剩余位置和b
                    printf("%d %d\n",t-1,tt-1);
                    Update(t,tt,1,n,1,1);
                }
            }
            else{
                b++;
                ans = Query(a,b,1,n,1);
                Update(a,b,1,n,1,0);
                printf("%d\n",ans);
            }
        }
        printf("\n");
    }
    return 0;
}
