1/*
  ID: oodt
  PROG:
  LANG:C++
  ver1.0


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


int m,k,n;
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
const int maxx = 1e5+7;
const int INF = 0x3f3f3f3f;
long long Min[maxx<<2],Add[maxx<<2],Max[maxx<<2],Sum[maxx<<2];
void Pushup(int rt){
    Min[rt] = min(Min[rt<<1],Min[rt<<1|1]);
    Max[rt] = max(Max[rt<<1],Max[rt<<1|1]);
}
void Build(int l,int r,int rt)
{
    if(l == r){
        Max[rt] = 0;
        Min[rt] = n+1;
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
        if(C == -1){
            Min[rt] = n+1;
            Max[rt] = 0;
        }
        else{
            Min[rt] = C;//到达叶修改
            Max[rt] = C;//到达叶修改
        }
        return ;
    }
    int m = (l+r) >>1;//根据条件判断往左子树还是右
    if(L <= m)Update(L,C,l,m,rt<<1);
    else Update(L,C,m+1,r,rt<<1|1);
    Pushup(rt);//子更新，本更新
}

long long Ma = 0,Mi = INF;
long long Query(int L,int R,int l,int r,int rt)//操作区间，l,r当前节点区间，rt当前节点
{
    if(L <= l && r <= R)
    {
        Ma = max(Ma,Max[rt]);
        Mi = min(Mi,Min[rt]);
        return 0;
    }
    int m = (l+r)>>1;
//    PushDown(rt,m-l+1,r-m);
    long long ANS = 0;
    if(L <= m) Query(L,R,l,m,rt<<1);
    if(R > m) Query(L,R,m+1,r,rt<<1|1);
    return 0;
}

int h[maxx];
int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/5-数据结构/xds线段树/hdu1540.txt","r",stdin);
#endif
    cnt = 0;
    while(~scanf("%d%d",&n,&m))
    {
        Build(1,n,1);
        for(int i = 0; i < m; i++)
        {
            getchar();
            char ch;
            scanf("%c",&ch);
            if(ch == 'D')
            {
                scanf("%d",&k);
                Update(k,k,1,n,1);
                h[cnt++] = k;
            }
            else if(ch == 'Q')
            {
                Ma = 0, Mi = INF;
                scanf("%d",&k);
                Query(1,k,1,n,1);
                int ma = Ma;
                Ma = 0, Mi = INF;
                Query(k,n,1,n,1);
                int mi = Mi;
                if(ma == mi) printf("0\n");
                else printf("%d\n",mi-ma-1);
            }
            else{
                int t = h[--cnt];
                Update(t,-1,1,n,1);
            }
        }
    }
    return 0;
}
*/

/*
  ID: oodt
  PROG:
  LANG:C++
  ver2.0
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

#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
const int maxx = 1e5+7;
int Sum[maxx<<2],lsum[maxx<<2],rsum[maxx<<2];
void Pushup(int rt,int ln,int rn){
    lsum[rt] = lsum[rt<<1];//左子树左最大连续
    rsum[rt] = rsum[rt<<1|1];//右子树右最大连续
    if(lsum[rt] == ln)lsum[rt] += lsum[rt<<1|1];//如果左子树左最大连续占用了整个左区间，那么加上左子树右最大连续
    if(rsum[rt] == rn) rsum[rt] += rsum[rt<<1];//右子树同理
    Sum[rt] = max(lsum[rt<<1|1]+rsum[rt<<1],max(Sum[rt<<1],Sum[rt<<1|1]));//取最大值
}
void Build(int l,int r,int rt)
{
    Sum[rt] = lsum[rt] = rsum[rt] = r-l+1;
//    Cov[rt] = -1;
    if(l == r) return ;
    int m = (l+r)>>1;
    Build(ls);
    Build(rs);
//    Pushup(rt,m-l+1,r-m);
}
void Update(int L,int C,int l,int r,int rt)
{//A[L, R]+=C
    if(l == r)
    {
        Sum[rt] = lsum[rt] = rsum[rt] = C;
//        Cov[rt] = C;//增加Add标记，表示本区间的Sum正确，子区间的仍需Add调整
        return ;
    }
    int m = (l+r) >>1;
//    PushDown(rt,m-l+1,r-m);//下推标记
    if(L <= m)Update(L,C,ls);
    else Update(L,C,rs);
    Pushup(rt,m-l+1,r-m);
}

int Query(int H,int l,int r,int rt)//操作区间，l,r当前节点区间，rt当前节点
{
    if(l == r || Sum[rt] == 0 || Sum[rt] == r -l + 1) return Sum[rt];
    int m = (l+r)>>1;
    if(H <= m){
        //H<=mid时，看左子树，
        int mid = m - rsum[rt<<1] + 1;//左子树右边连续区间的左界
        if(H >= mid) return Query(H,ls)+Query(m+1,rs);//左子树最大+右子树的左最大
        else return Query(H,ls);//左子树最大
    }
    else {
        int mid = m + 1 + lsum[rt<<1|1] - 1;
        if(H <= mid)
        {
            return Query(H,rs)+Query(m,ls);
        }
        else return Query(H,rs);
    }
}
int his[maxx];
int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/5-数据结构/xds线段树/hdu1540.txt","r",stdin);
#endif
    while(~scanf("%d%d",&n,&m))
    {
        memset(his,0,sizeof(his));
        Build(1,n,1);
        cnt = 0;
        for(int i = 0; i < m; i++)
        {
            getchar();
            char ch;
            int x = -1;
            scanf("%c",&ch);
//printf("%s\t",ch);
            if(ch == 'D')
            {
                scanf("%d",&x);
                Update(x,0,1,n,1);
                his[cnt++] = x;
            }
            else if(ch == 'Q')
            {
                scanf("%d",&x);
                int a = Query(x,1,n,1);
                printf("%d\n",a);
            }
            else{
                x = his[--cnt];
                Update(x,1,1,n,1);
            }
        }
    }
    return 0;
}