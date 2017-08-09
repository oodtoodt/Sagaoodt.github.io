#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>
#include<vector>
#define N 1001
vector<int>G[N];
int n,m,low[N],dfn[N],w[1001][1001];
bool is_cut[N];
int father[N];
int tim=0;
void input()
{
    int a,b,wor;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&a,&b,&wor);
        G[a].push_back(b);/*邻接表储存无向边*/
        G[b].push_back(a);
        w[a][b]=wor;
        w[b][a]=wor;
    }
}
void Tarjan(int i,int Father)
{
    father[i]=Father;/*记录每一个点的父亲*/
    dfn[i]=low[i]=tim++;
    for(int j=0;j<G[i].size();++j)
    {
        int k=G[i][j];
        if(dfn[k]==-1)
        {
            Tarjan(k,i);
            low[i]=min(low[i],low[k]);
        }
        else if(Father!=k)/*假如k是i的父亲的话，那么这就是无向边中的重边，有重边那么一定不是桥*/
            low[i]=min(low[i],dfn[k]);//dfn[k]可能！=low[k]，所以不能用low[k]代替dfn[k],否则会上翻过头了。
    }
}
void count()
{
    int rootson=0;
    Tarjan(1,0);
    for(int i=2;i<=n;++i)
    {
        int v=father[i];
        if(v==1)
        rootson++;/*统计根节点子树的个数，根节点的子树个数>=2,就是割点*/
        else{
            if(low[i]>=dfn[v])/*割点的条件*/
            is_cut[v]=true;
        }
    }
    if(rootson>1)
    is_cut[1]=true;
    int fla=0;
    for(int i=1;i<=n;++i)
    if(is_cut[i]){
        fla=1;
    }
    //printf("%d\n",i);
    if (fla==0){
        printf("-1\n");

    }
    else{
        int min=99999;
        for(int i=1;i<=n;++i)
        {
            int v=father[i];
            if(v>0&&low[i]>dfn[v])/*桥的条件*/
            //printf("%d,%d\n",v,i);
            {
                if (w[v][i]<min){
                    min=w[v][i];
                }

            }
        }
        if (min==0){
            printf("1\n");
        }
        else{
            printf("%d\n",min);
        }
    }

}
int main()
{
    while (1){
        scanf("%d%d",&n,&m);
        printf("%d\n",m);
        if (n==0&&m==0){
            return 0;

        }
        else{
            printf("%d\n",m);
            memset(w,0,sizeof(w));
            for(int i = 0; i < 1001; i++) G[i].clear();
            input();
            printf("%d\n",m);
            memset(dfn,-1,sizeof(dfn));
            memset(father,0,sizeof(father));
            memset(low,-1,sizeof(low));
            memset(is_cut,false,sizeof(is_cut));
            count();
        }
    }

    return 0;
}