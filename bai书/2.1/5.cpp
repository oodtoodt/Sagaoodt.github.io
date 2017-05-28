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

const int maxx=1005;
int n,m,k;
char a[maxx][maxx];

const int INF = 100000000;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
typedef pair <int,int> P;
queue<P> que;
int d[maxx][maxx];
int sx,sy;
int ex,ey;

bool judge(int x,int y){
    if(a[x][y] != 'X'){
        if(x >= 0 && x < n)
        {
            if(y >= 0 && y < m)
            {
                if(d[x][y] == INF){
                    return true;
                }
            }
        }
    }
    return false;
}

int bfs()
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            d[i][j] = INF;//初始化
        }
    }
    que.push(P(sx,sy));
    d[sx][sy] = 0;//并把距离设为0；
    while(que.size()){//直到队列为空
        P p = que.front();que.pop();
        if(p.first == ex && p.second == ey){
            break;//如果已经是终点，则结束搜索。
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = p.first + dx[i],ny = p.second + dy[i];
            if(judge(nx,ny))
            {
                que.push(P(nx,ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[ex][ey];
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/bai书/2.1/5.txt","r",stdin);
#endif
//    int cnt = 0;
    P tp[10];
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0; i < n; i++)
    {
        getchar();
        for(int j = 0; j < m; j++)
        {
            scanf("%c",&a[i][j]);
            int t = a[i][j] - '0';
            if(t < 10 && t > 0){
                tp[t-1] = P(i,j);
            }
            if(a[i][j] == 'S'){
                sx = i;
                sy = j;
            }
        }
    }
    int ans = 0;
    for(int i = 0 ; i < k; i++)
    {
        ex = tp[i].first;
        ey = tp[i].second;
        ans += bfs();
        while(que.size()){
            que.pop();
        }
//        printf("sx = %d sy = %d \t ex = %d ey = %d\n%d\n",sx,sy,ex,ey,ans);
        sx = ex;
        sy = ey;
    }
    printf("%d\n",ans);
    return 0;
}
