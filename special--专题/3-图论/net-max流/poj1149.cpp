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

const int maxx=1050;
int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
int pre[maxx];

const int N = 1050;
const int INF = 0x7fffffff;
int Map[N][N],path[N],flow[N],start,End;
queue<int> q;
int bfs()
{
    int i,t;
    while(!q.empty()) q.pop();
    memset(path,-1,sizeof(path));
    path[start] = 0,flow[start] = INF;
    q.push(start);
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        if(t == End) break;
        for(int i = 0; i <= End; i++)
        {
            if(i != start && path[i] == -1 && Map[t][i])
            {
                flow[i] = min(flow[t],Map[t][i]);
                q.push(i);
                path[i] = t;
            }
        }
    }
    if(path[End] == -1) return -1;
    return flow[End];
}
int Edmonds_Karp(){
    int max_flow = 0,step,now,pre;
    while((step = bfs()) != -1)
    {
        max_flow += step;
        now = End;
        while(now != start)
        {
            pre = path[now];
            Map[pre][now] -= step;
            Map[now][pre] += step;
            now = pre;
        }
    }
    return max_flow;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/3-图论/net-max流/poj1149.txt","r",stdin);
#endif
    while(~scanf("%d%d",&m,&n))
    {
        memset(pre,0,sizeof(pre));
        memset(Map,0,sizeof(Map));
        for(int i = 1; i <= m; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i = 1; i <= n; i++)
        {
            int A,B;
            scanf("%d",&A);
            for(int j = 1; j <= A; j++)
            {
                scanf("%d",&k);
                if(pre[k] == 0){
                    Map[0][i] += a[k];
                    pre[k] = i;
                }
                else {
                    Map[pre[k]][i] = INF;
                    pre[k] = i;
                }
            }
            scanf("%d",&B);
            Map[i][n+1] = B;
        }
        start = 0,End = n+1;
        printf("%d\n",Edmonds_Karp());
    }
    //scanf("%d%d",&n,&m);
    return 0;
}
