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
//#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;

const int maxx=10005;
//int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

const int N = 210;
const int INF = 0x7fffffff;
int n,m,map[N][N],path[N],flow[N],start,End;
queue<int> q;
int bfs(){
    int i,t;
    while(!q.empty())q.pop();
    memset(path,-1,sizeof(path));
    path[start] = 0,flow[start] = INF;
    q.push(start);
    while(!q.empty()){
        t = q.front();
        q.pop();
        if(t == End) break;
        for(int i = 1; i <= m; i++)
        {
            if(i != start && path[i] == -1 && map[t][i])
            {
                flow[i] = min(flow[t],map[t][i]);
                q.push(i);
                path[i] = t;
            }
        }
    }
    if(path[End] == -1) return -1;
    return flow[m]; //一次遍历后的流量增量
}
int Edmonds_Karp(){
    int max_flow = 0,step,now,pre;
    while((step= bfs()) != -1){  //找不到路径时退出
        max_flow += step;
        now = End;
        while(now != start){
            pre = path[now];
            map[pre][now] -= step; //更新正向边的实际容量
            map[now][pre] += step; //添加反向边
            now = pre;
        }
    }
    return max_flow;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/3-图论/net-max流/poj1273.txt","r",stdin);
#endif
    int u,v,cost;
    while(~scanf("%d%d",&n,&m))
    {
        memset(map,0,sizeof(map));
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d%d",&u,&v,&cost);
            map[u][v] += cost; //not just one input.
        }
        start = 1,End = m;
        printf("%d\n",Edmonds_Karp());
    }
    return 0;
}
