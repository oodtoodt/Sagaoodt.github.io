#include<cstdio>
#include<queue>
#include<string>
#include<cstring>

#define maxn 100010//点数的最大值
#define maxm 400010//边数的最大值
#define INF 0x3f3f3f3f
struct Edge
{
    int to, next;
    long long cap, flow;
}edge[maxm];//注意是maxm
typedef long long ll;
int tol;
int n,m;
const int E = 222222;
int head[maxn];
long long gap[maxn], dep[maxn], cur[maxn];
void init()
{
    tol = 0;
    memset(head, -1, sizeof(head));
}
void addedge(int u, int v, long long w, long long rw = 0)
{
    edge[tol].to = v; edge[tol].cap = w; edge[tol].flow = 0;
    edge[tol].next = head[u]; head[u] = tol++;
    edge[tol].to = u; edge[tol].cap = rw; edge[tol].flow = 0;
    edge[tol].next = head[v]; head[v] = tol++;
}
int Q[maxn];
void BFS(int start, int end)
{
    memset(dep, -1, sizeof(dep));
    memset(gap, 0, sizeof(gap));
    gap[0] = 1;
    int front = 0, rear = 0;
    dep[end] = 0;
    Q[rear++] = end;
    while (front != rear)
    {
        int u = Q[front++];
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if (dep[v] != -1)continue;
            Q[rear++] = v;
            dep[v] = dep[u] + 1;
            gap[dep[v]]++;
        }
    }
}
int S[maxn];
ll sap(int start, int end, int N)
{
    BFS(start, end);
    memcpy(cur, head, sizeof(head));
    int top = 0;
    int u = start;
    ll ans = 0;
    while (dep[start] < N)
    {
        if (u == end)
        {
            int Min = INF;
            int inser;
            for (int i = 0; i < top; i++)
            if (Min > edge[S[i]].cap - edge[S[i]].flow)
            {
                Min = edge[S[i]].cap - edge[S[i]].flow;
                inser = i;
            }
            for (int i = 0; i < top; i++)
            {
                edge[S[i]].flow += Min;
                edge[S[i] ^ 1].flow -= Min;
            }
            ans += Min;
            top = inser;
            u = edge[S[top] ^ 1].to;
            continue;
        }
        bool flag = false;
        int v;
        for (int i = cur[u]; i != -1; i = edge[i].next)
        {
            v = edge[i].to;
            if (edge[i].cap - edge[i].flow && dep[v] + 1 == dep[u])
            {
                flag = true;
                cur[u] = i;
                break;
            }
        }
        if (flag)
        {
            S[top++] = cur[u];
            u = v;
            continue;
        }
        int Min = N;
        for (int i = head[u]; i != -1; i = edge[i].next)
        if (edge[i].cap - edge[i].flow && dep[edge[i].to] < Min)
        {
            Min = dep[edge[i].to];
            cur[u] = i;
        }
        gap[dep[u]]--;
        if (!gap[dep[u]])return ans;
        dep[u] = Min + 1;
        gap[dep[u]]++;
        if (u != start)u = edge[S[--top] ^ 1].to;
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/bisai/qingdao/9.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        int s,t;
        scanf("%d%d",&n,&m);
        scanf("%d%d",&s,&t);
        for(int i = 0; i < m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w*E+1,w*E+1);
        }
        ll ans = sap(s, t, n);
        printf("%lld\n", ans % E);
    }

    return 0;
}
