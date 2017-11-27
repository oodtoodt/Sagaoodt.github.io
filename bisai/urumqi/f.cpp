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

const int MAXN = 10010;
const int MAXM = 100010;
struct Edge
{
    int to,next;
}edge[MAXM];
int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];
int Index,top;
int scc;
bool Instack[MAXN];
int out[MAXN],in[MAXN];
void addedge(int u,int v)
{
    edge[tot].to = v;edge[tot].next = head[u];head[u] = tot++;
}
void Tarjan(int u)
{
    int v;
    DFN[u] = Low[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    for(int i = head[u];i != -1;i = edge[i].next)
    {
        v = edge[i].to;
        if(!DFN[v])
        {
            Tarjan(v);
            if( Low[u] > Low[v] )Low[u] = Low[v];
        }
        else if(Instack[v] && Low[u] > DFN[v])Low[u] = DFN[v];
    }
    if(Low[u] == DFN[u])
    {
        scc++;
        do
        {
            v = Stack[--top];
            Instack[v] = false;
            Belong[v] = scc;
        }
        while( v != u );
    }
}
void solve(int n)
{
    memset(DFN,0,sizeof(DFN));
    memset(Instack,false,sizeof(Instack));
    Index = scc = top = 0;
    for(int i = 1;i <= n;i++)
        if(!DFN[i])
            Tarjan(i);
    if(scc == 1)
    {
        printf("0\n");
        return;
    }
    for(int i = 1; i <= scc; i++)
    {
        in[i] = 0;
        out[i] = 0;
    }
    for(int u = 1;u <= n;u++)
    {
        for(int i = head[u];i != -1;i = edge[i].next)
        {
            int v = edge[i].to;
            if(Belong[u] != Belong[v])
            {
                in[Belong[v]]++;
                out[Belong[u]]++;
            }
        }
    }
    int ans1=0,ans2=0;
    for(int i = 1;i <= scc;i++)
    {
        if(in[i]==0)ans1++;
        if(out[i]==0)ans2++;
    }
    printf("%d\n",max(ans1,ans2));
}
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}

int main()
{
#ifdef LOCAL
//    freopen("","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    int u,v,n,m;
    while(T--)
    {
        init();
        scanf("%d%d",&n,&m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }
        solve(n);
    }
    return 0;
}
