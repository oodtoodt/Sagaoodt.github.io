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
#include <queue>
using namespace std;

const int maxx=305;
int n,m,k;
int a[maxx];
int laby[maxx][maxx];

const int INF = 100000000;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
typedef pair <int,int> P;
queue<P> que;
int d[maxx][maxx];
int sx,sy;
int ex,ey;

void init(){
    for(int i = 0 ; i < maxx; i++){
        fill(d[i],d[i]+maxx,INF);
        fill(laby[i],laby[i]+maxx,INF);
    }
}

bool judge(int x,int y){
    if(x >= 0)
    {
        if(y >= 0)
        {
            if(d[x][y] == INF){//!=inf说明已经访问过
                return true;
            }
        }
    }
    return false;
}

void bfs()
{
    que.push(P(sx,sy));
    d[sx][sy] = 0;//并把距离设为0；
//    int x = 300,y = 300;
    while(que.size()){//直到队列为空
        P p = que.front();que.pop();
        int x = p.first,y = p.second;
        if(laby[p.first][p.second] == INF){
            printf("%d\n",d[x][y]);
            return ;//如果已经是终点，则结束搜索。
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = p.first + dx[i],ny = p.second + dy[i];
            if(judge(nx,ny) && d[x][y] + 1 < laby[nx][ny])
            {
                que.push(P(nx,ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
//    return d[x][y];
    printf("-1\n");
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/bai书/2.1/6.txt","r",stdin);
#endif
    scanf("%d",&n);
    int x,y,t;
    init();
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d%d",&x,&y,&t);
        laby[x][y] = min(laby[x][y],t);
        for(int j = 0; j < 4; j++)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(nx >= 0 && ny >= 0)
            laby[nx][ny] = min(laby[nx][ny],t);
        }
    }
    sx = 0;
    sy = 0;
    bfs();
/*    if(te == INF){
        printf("-1\n");
    }
    else{
        printf("%d\n",t);
        }*/
    return 0;
}
