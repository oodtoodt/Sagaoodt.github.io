/*
  ID: oodt
  PROG:poj 3083
  LANG:C++
  啧啧，利用了dfs的一点灵活性。
  几乎，就差一点，感觉就能摸到ac了。
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include <queue>

using namespace std;

const int maxx=45;
int n,m,k;
char a[maxx][maxx];
int w,h;


const int INF = 100000000;
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int dx1[4] = {0,-1,0,1};
int dy1[4] = {1,0,-1,0};
typedef pair <int,int> P;
queue<P> que;
int d[maxx][maxx];
int sx,sy;
int ex,ey;
int df[maxx][maxx];

//int dx[4] = {0,0,1,-1};
//int dy[4] = {1,-1,0,0};
int cnt = 0;

int dfs(int x,int y)
{
//    a[x][y] = '.';
//    printf("%d,%d\n",x,y);
    int t = (df[x][y] + 3) % 4;
//    df[x][y] = -2;
    for(int i = 0 ; i < 4; i++)
    {
        int nx = x + dx[(i + t ) % 4];
        int ny = y + dy[(i + t ) % 4];
//        printf("%d ",df[nx][ny]);
        if(nx >= 0 && nx < h && ny >= 0 && ny < w ){
            if(a[nx][ny] == 'E')
            {
                return cnt+2;
            }
            if(a[nx][ny] != '#'){
                df[nx][ny] = (i + t) % 4;
                cnt ++;
//                printf("%d ",df[nx][ny]);
                return dfs(nx,ny);
            }
        }
    }
}

int dfs1(int x,int y)
{
//    a[x][y] = '.';
//    printf("%d,%d\n",x,y);
    int t = (df[x][y] + 3) % 4;
//    df[x][y] = -2;
    for(int i = 0 ; i < 4; i++)
    {
        int nx = x + dx1[(i + t ) % 4];
        int ny = y + dy1[(i + t ) % 4];
//        printf("%d ",df[nx][ny]);
        if(nx >= 0 && nx < h && ny >= 0 && ny < w ){
            if(a[nx][ny] == 'E')
            {
                return cnt+2;
            }
            if(a[nx][ny] != '#'){
                df[nx][ny] = (i + t) % 4;
                cnt ++;
//                printf("%d ",df[nx][ny]);
                return dfs1(nx,ny);
            }
        }
    }
}


void init(){
    for(int i = 0; i < maxx; i++){
        for(int j = 0; j < maxx; j++){
            d[i][j] = INF;//初始化
        }
    }
    memset(df,-1,sizeof(df));
    while(!que.empty()){
        que.pop();
    }
}

bool judge(int x,int y){
    if(a[x][y] != '#'){
        if(x >= 0 && x < h)
        {
            if(y >= 0 && y < w)
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
    que.push(P(sx,sy));
    d[sx][sy] = 0;//并把距离设为0；
    while(que.size()){//直到队列为空
        P p = que.front();que.pop();
//        printf("%d,%d\n",p.first,p.second);
        if(p.first == ex && p.second == ey){
            break;//如果已经是终点，则结束搜索。
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = p.first + dx[i],ny = p.second + dy[i];
//            printf("%d,%d\t",nx,ny);
            if(judge(nx,ny))
            {
//                printf("ok");
                que.push(P(nx,ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
//        printf("\n");
    }
    return d[ex][ey];
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/vjudge/njupt Dfs + Bfs/D.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d%d",&w,&h);
        for(int i = 0 ; i < h; i++)
        {
            getchar();
            for(int j = 0; j < w; j++)
            {
                scanf("%c",&a[i][j]);
//                printf("%c",a[i][j]);
                if(a[i][j] == 'S'){
                    sx = i;
                    sy = j;
                }
                if(a[i][j] == 'E'){
                    ex = i;
                    ey = j;
                }
            }
//            printf("\n");
        }
//        printf("%d %c",judge(6,1),a[6][1]);
        if(sx == 0){
            df[sx][sy] = 3;
        }
        else if(sx == h-1) df[sx][sy] = 1;
        else if(sy == 0) df[sx][sy] = 2;
        else df[sx][sy] = 0;
        cnt = 0;
        printf("%d ",dfs(sx,sy));
        init();
        cnt = 0;
        if(sx == 0){
            df[sx][sy] = 3;
        }
        else if(sx == h-1) df[sx][sy] = 1;
        else if(sy == 0) df[sx][sy] = 0;
        else df[sx][sy] = 2;
        printf("%d ",dfs1(sx,sy));
        printf("%d\n",bfs()+1);
    }
    return 0;
}