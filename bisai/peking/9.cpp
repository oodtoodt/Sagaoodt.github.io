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
const int INF = 0x3f3f3f3f;
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
//    printf("*");
    a[rt] = min(a[rt<<1],a[rt<<1|1]);
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
    a[rt] = min(a[rt<<1] , a[rt<<1|1]);
}
int Query(int L,int R,int l,int r,int rt)
{
    if(L <= l && r <= R)
    {
        return a[rt];
    }
    int m = (l + r) >> 1;
    int ans = INF;
    if(L <= m) ans = min(Query(L,R,lson),ans);
    if(R > m) ans = min(Query(L,R,rson),ans);
    return ans;
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/bisai/peking/9.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int w = pow(2,n)+0.5;
//        printf("\n%d",w);
        Build(1,w,1);
//        printf("*");
//        for(int i = 1; i <= w; i++)
//        {
//            printf("%d ",a[i]);
//        }
        scanf("%d",&k);
//        printf("%d\n",k);
        int x,y,q;
        for(int i = 0; i < k; i++)
        {
            scanf("%d%d%d",&q,&x,&y);
//            printf("%d,%d,%d,%d\n",i,q,x,y);//这里
            if(q == 1)
            {
                long long t = Query(x+1,y+1,1,w,1);
                printf("%lld\n",t*t);
            }
            else Update(x+1,y,1,w,1);
        }
        q = x = y =0;
    }
    return 0;
}
