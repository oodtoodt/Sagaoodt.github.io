#include<cstdio>
#include <algorithm>
#include <string>

#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;

const int E = 222222;
int s,t;
const int max_n=205;
const int max_m=205;
const int max_e=max_m*2;
const int inf=1e9;

int point[max_n],Next[max_e],v[max_e],remain[max_e],tot;
int cur[max_n],deep[max_n],last[max_n],num[max_n];
int n,m,x,y,cap,maxflow;
queue <int> q;

inline void add(int x,int y,int cap){
    ++tot; Next[tot]=point[x]; point[x]=tot; v[tot]=y; remain[tot]=cap;
    ++tot; Next[tot]=point[y]; point[y]=tot; v[tot]=x; remain[tot]=0;
}

inline void bfs(int t){
    for (int i=1;i<=n;++i)
      deep[i]=n;
    deep[t]=0;
    while (!q.empty()) q.pop();
    q.push(t);

    while (!q.empty()){
        int now=q.front(); q.pop();
        for (int i=point[now];i!=-1;i=Next[i])
          if (deep[v[i]]==n&&remain[i^1]){
            deep[v[i]]=deep[now]+1;
            q.push(v[i]);
          }
    }
}

inline int addflow(int s, int t) {
    int ans=inf,now=t;
    while (now!=s) {
        ans=min(ans, remain[last[now]]);
        now=v[last[now] ^ 1];
    }
    now=t;
    while (now != s) {
        remain[last[now]]-=ans;
        remain[last[now]^1]+=ans;
        now=v[last[now]^1];
    }
    return ans;
}

inline void isap(int s,int t){
    int now=s;
    bfs(t);
    for (int i=1;i<=n;++i) ++num[deep[i]];
    for (int i=1;i<=n;++i) cur[i]=point[i];

    //在残量网络中没有源点到汇点的通路 
    while (deep[s]<n){
        //如果到达汇点则进行增广，重新回到源点准备下一轮增广 
        if (now==t){
            maxflow+=addflow(s,t);
            now=s;
        }

        bool has_find=false;
        //当前弧优化 
        for (int i=cur[now];i!=-1;i=Next[i]){
            int u=v[i];
            if (deep[u]+1==deep[now]&&remain[i]){
                has_find=true;
                cur[now]=i;
                last[u]=i;
                now=u;
                break;
            }
        }

        //没有找到出边，重新进行标号
        if (!has_find){
            int minn=n-1;
            for (int i=point[now];i!=-1;i=Next[i])
              if (remain[i])
                minn=min(minn,deep[v[i]]);
            //GAP优化
            if (!(--num[deep[now]])) break;
            num[deep[now]=minn+1]++;
            cur[now]=point[now];
            if (now!=s)
              now=v[last[now]^1];
        }
    }
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
        tot=-1;
        memset(point,-1,sizeof(point));
        memset(Next,-1,sizeof(Next));
        scanf("%d%d",&n,&m);
        scanf("%d%d",&s,&t);
        //   cnt = 0;
        for(int i = 0; i < m; i++)
        {
//            printf("ojbk\n");
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w*(E+1)+1);
            add(v,u,w*(E+1)+1);
        }
        isap(s,t);
        printf("%d\n",maxflow % (E+1));
    }
}
