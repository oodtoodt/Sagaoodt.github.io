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

const int maxx=10005;
int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
int E = 22222222;
int s,t;

const int Na = 210;
const int INF = 0x7fffffff;
int Map[Na][Na],path[Na],flow[Na],start,End;
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
            if(i != start && path[i] == -1 && Map[t][i])
            {
                flow[i] = min(flow[t],Map[t][i]);
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
    while((step= bfs())!=-1){  //找不到路径时退出
        max_flow += step;
        now = End;
        while(now != start){
            pre = path[now];
            Map[pre][now] -= step; //更新正向边的实际容量
            Map[now][pre] += step; //添加反向边
            now = pre;
        }
    }
    return max_flow;
}
int mp[502][502];
int N,M;
bool combine[502];
int minC=INT_MAX;
void search(int &s,int &t){
    bool vis[502];
    int w[502];
    memset(vis,0,sizeof(vis));
    memset(w,0,sizeof(w));
    int tmpj=1000;
    for(int i=0;i<N;i++){
        int max=-INT_MAX;
        for(int j=0;j<N;j++){
            if(!vis[j]&&!combine[j]&&max<w[j]){
                max=w[j];
                tmpj=j;
            }
        }
        if(t==tmpj){minC=w[t];return;}
        vis[tmpj]=1;
        s=t,t=tmpj;
        for(int j=0;j<N;j++){
            if(!vis[j]&&!combine[j])
                w[j]+=mp[t][j];
        }
    }
    minC=w[t];
}
int mincut(){
    int ans=INT_MAX;
    int s,t;
    memset(combine,0,sizeof(combine));
    for(int i=0;i<N-1;i++){
        s=t=-1;
        search(s,t);
        combine[t]=true;
        ans=ans>minC?minC:ans;
        for(int j=0;j<N;j++){
            mp[s][j]+=mp[t][j];
            mp[j][s]+=mp[j][t];
        }
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
        scanf("%d%d",&N,&M);
        scanf("%d%d",&s,&t);
        memset(mp,0,sizeof(mp));
        for(int i = 0; i < M; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            mp[u-1][v-1] = w*(E+1)+1;
            mp[v-1][u-1] = w*(E+1)+1;
        }
        ans = mincut() % (E+1);
//        start = s;End = t;
//        ans = Edmonds_Karp();
        printf("%d\n",ans);
    }
    return 0;
}
