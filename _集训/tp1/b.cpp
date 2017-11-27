#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include <queue>

using namespace std;

const int maxx=205;
int n,m,k;
char a[maxx][maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;


const int INF = 100000000;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
typedef pair <int,int> P;
queue<P> que;
int d[maxx][maxx];
int sx,sy;
int ex,ey;
int ans1 = INF,ans2 = INF;
bool judge(int x,int y){
    if(a[x][y] != '#'){
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

void bfs()
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
        if(a[p.first][p.second] == '$'){
            ans2 = min(ans2,d[p.first][p.second]);
        }
        if(a[p.first][p.second] == '@')
        {
            ans1 = min(ans1,d[p.first][p.second]);
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
//    return d[ex][ey];
}


int main()
{
#ifdef LOCAL
//    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/tp1/2.txt","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++)
    {
        getchar();
        for(int j = 0; j < m; j++)
        {
            scanf("%c",&a[i][j]);
            if(a[i][j] == '%')
            {
                sx = i,sy = j;
            }
        }
    }
    bfs();
    if(ans1 < ans2)
    printf("Yes\n");
    else
    printf("No\n");
    return 0;
}
