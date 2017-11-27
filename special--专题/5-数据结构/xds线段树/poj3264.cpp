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


#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
const int maxx = 1e6+7;
const int INF = 0x3f3f3f3f;
long long Min[maxx<<2],Add[maxx<<2],Max[maxx<<2],Sum[maxx<<2];
long long a[maxx];
void Pushup(int rt){
    Min[rt] = min(Min[rt<<1],Min[rt<<1|1]);
    Max[rt] = max(Max[rt<<1],Max[rt<<1|1]);
}

void Build(int l,int r,int rt)
{
    if(l == r){
        Sum[rt] = a[l];
        Max[rt] = a[l];
        Min[rt] = a[l];
        return ;
    }
    int m = (l+r)>>1;
    Build(ls);
    Build(rs);
    Pushup(rt);
}
long long Ma = 0,Mi = INF;
long long Query(int L,int R,int l,int r,int rt)//操作区间，l,r当前节点区间，rt当前节点
{
    if(L <= l && r <= R)
    {
        Ma = max(Ma,Max[rt]);
        Mi = min(Mi,Min[rt]);
        return Ma-Mi;
    }
    int m = (l+r)>>1;
//    PushDown(rt,m-l+1,r-m);
    long long ANS = 0;
    if(L <= m) ANS= max(ANS,Query(L,R,l,m,rt<<1));
    if(R > m) ANS = max(ANS,Query(L,R,m+1,r,rt<<1|1));
    return ANS;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/5-数据结构/xds线段树/poj3264.txt","r",stdin);
#endif
    memset(Min,0x3f,sizeof(Min));
    memset(Max,0,sizeof(Max));
    int q;
    scanf("%d%d",&n,&q);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
    }
    Build(1,n,1);
    while(q--)
    {
        Ma = 0,Mi = INF;
        scanf("%d%d",&l,&r);
        Query(l,r,1,n,1);
        printf("%d\n",Ma-Mi);
    }
//    printf("%d\n",Query(1,n,1,n,1));
    return 0;
}
