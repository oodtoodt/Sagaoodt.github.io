#include<stdio.h>
#include<string.h>

#define maxn 500+10
#define maxv 2000+10
#define max(a,b) (a>b?a:b)
#define mem(a,b) memset(a,b,sizeof(a))

struct node
{
    int u,v,k;
} q[maxv];
int pre[maxn],rank[maxn],error[maxn];
int n,m;

void init()
{
    for(int i=0; i<=n; ++i)
        pre[i]=i,rank[i]=0;
}

int Find(int x)
{
    if(x==pre[x])
        return x;
    int temp=pre[x];
    pre[x]=Find(temp);
    rank[x]=(rank[x]+rank[temp])%3;
    return pre[x];
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        int i,j,k,u,v;
        char op;
        for(i=1; i<=m; ++i)
        {
            scanf("%d %c %d",&q[i].u,&op,&q[i].v);
            if(op=='>')
                q[i].k=2;
            else if(op=='<')
                q[i].k=1;
            else if(op=='=')
                q[i].k=0;
        }
        mem(error,-1);
        for(i=0; i<n; ++i)
        {
            init();//注意这里要初始化，因为每次建立的关系都有可能不一样
            for(j=1; j<=m; ++j)
            {
                if(q[j].u==i||q[j].v==i)
                    continue;
                u=q[j].u,v=q[j].v,k=q[j].k;
                int fx=Find(u),fy=Find(v);
                if(fx!=fy)
                {
                    pre[fy]=fx;
                    rank[fy]=(rank[u]+k+3-rank[v])%3;
                }
                else
                {
                    if((rank[v]+3-rank[u])%3!=k)
                    {
                        error[i]=j;
                        break;
                    }
                }
            }
        }
        int cnt=0,ans=0;
        for(i=0; i<n; ++i)
        {
            if(error[i]==-1)
                ++cnt,v=i;
            ans=max(ans,error[i]);
        }
        if(!cnt)
            printf("Impossible\n");
        else if(cnt>1)
            printf("Can not determine\n");
        else
            printf("Player %d can be determined to be the judge after %d lines\n",v,ans);
    }
    return 0;
}
