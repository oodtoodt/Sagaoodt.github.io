#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>

using namespace std;

const int maxx=100005;
int n,m,k;
//int a[maxx];
int a[maxx<<2];
int sum[maxx<<2];
int ans = 0,cnt = 0,pos = 0;
//typedef long long ll;
#define rson m+1,r,rt<<1|1
#define lson l,m,rt<<1

//struct P
//    int a,b,c;//a[maxx];
//int cmp(P a,P b)
//    return a.c > b.c;
//int vis[maxx];

//void Build()
void Pushup(int rt){
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void Pushdown(int rt,int m)
{
    if(a[rt]){
        a[rt<<1] = a[rt];
        a[rt<<1|1] = a[rt];
        sum[rt<<1] = (m - (m>>1)) * a[rt];
        sum[rt<<1|1] = (m >> 1) * a[rt];
        a[rt] = 0;
    }
}
void Build(int l,int r,int rt)
{
    a[rt] = 0;
//    sum[rt] = 1;
    if(l == r){
        scanf("%d",&sum[rt]);
        return ;
    }
    int m = (l+r) >> 1;
    Build(lson);
    Build(rson);
    Pushup(rt);
}
void Update(int L,int R,int c,int l,int r,int rt){
    if(L <= l && r <= R)
    {
        a[rt] = c;
        sum[rt] = c * (r-l+1);
        return ;
    }
    Pushdown(rt,r-l+1);
    int m = (l+r) >> 1;
    if(L <= m) Update(L,R,c,lson);
    if(R > m) Update(L,R,c,rson);
    Pushup(rt);
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/T3/d.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
//        memset(a,0,sizeof(a));
//memset(vis,0,sizeof(vis));
        ans = 0;
        scanf("%d",&n);
        scanf("%d",&m);
        //sort(a,a+m,cmp);
        int a,b,c;
            //printf("%d %d %d\n",a[i].a,a[i].b,a[i].c);
        Update(1,n,1,1,n,1);
            for(int i = 0; i < m; i++)
            {
                scanf("%d%d%d",&a,&b,&c);
                Update(a,b,c,1,n,1);
            }
            //ans += a[i].c * (a[i].);
            printf("Case %d: The total value of the hook is %d.\n",++cnt,sum[1]);
    }
    return 0;
}