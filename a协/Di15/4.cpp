/*
  ID: oodt
  PROG:
  LANG:C++
*/
#include <bitset>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include <queue>
using namespace std;

const int maxx=25;
int n,m,k;
char a[maxx][maxx];


const int INF = 100000000;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
//typedef pair <int,int> P;
struct P{
    int x,y,t,cnt;
    P (int a,int b,int c,int d){
        x = a;
        y = b;
        t = c;
        cnt = d;
    }
};
queue<P> que;
int book[maxx][maxx][1<<11];
int sx,sy;
int ex,ey;
int ans = 0;

void init(){
    memset(book,0,sizeof(book));
    while(!que.empty())
    {
        que.pop();
    }
}

bool judge(int x,int y){
    if(x >= 0 && x < n)
    {
        if(y >= 0 && y < m)
        {
            if(a[x][y] != '*'){
                return true;
            }
        }
    }
    return false;
}

int bfs()
{
    que.push(P(sx,sy,0,0));
//    d[sx][sy][0] = 0;//并把距离设为0；
    book[sx][sy][0] = 1;
    while(que.size()){//直到队列为空
        P p = que.front();que.pop();
        if(p.t == k - 1)
        {
            return -1;
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = p.x + dx[i],ny = p.y + dy[i];
            if(judge(nx,ny))
            {
                if(a[nx][ny] == '^'){
                    return p.t + 1;
                }
                if(a[nx][ny] == '.'){
                    if(!book[nx][ny][p.cnt]){
                        book[nx][ny][p.cnt] = 1;
                        que.push(P(nx,ny,p.t+1,p.cnt));
                    }
                    continue;
                }
                if(a[nx][ny] >= 'A' && a[nx][ny] <= 'Z' && !book[nx][ny][p.cnt])
                {
                    bitset<10> can= static_cast<bitset<10> > (p.cnt);
//                    cout<<"门"<<a[nx][ny]<<" "<<p.cnt<<endl;
                    //                  cout<<can;
//                    cout<<endl<<can[a[nx][ny]-'A'];
//                    printf("\n");
                    if(can[a[nx][ny] - 'A']){
                        book[nx][ny][p.cnt] = 1;
//                        printf("进去了！\n");
                        que.push(P(nx,ny,p.t+1,p.cnt));
                    }
                    continue;
                }
                if(a[nx][ny] >= 'a' && a[nx][ny] <= 'z')
                {
                    bitset<10> can= static_cast<bitset<10> > (p.cnt);
//                    cout<<"key"<<endl;
                    for(int i = 0; i < 10; i++)
                    {
                        if(i == a[nx][ny] - 'a')
                        {
                            can[i] = 1;
                        }
//                        cout<<can[i];
//                        printf("%d",can[i]);
                    }
//                    cout<<can;
//                    printf("\n");
                    int t = can.to_ulong();
                    if(!book[nx][ny][t]){
                        book[nx][ny][t] = 1;
                        que.push(P(nx,ny,p.t+1,t));
                    }
                    continue;
                }
//                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return -1;
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di15/4.txt","r",stdin);
#endif
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        for(int i = 0; i < n; i++)
        {
            getchar();
            init();
            for(int j = 0; j < m; j++)
            {
                scanf("%c",&a[i][j]);
//                printf("%c",a[i][j]);
                if(a[i][j] == '@'){
                    sx = i;
                    sy = j;

                    a[i][j] = '.';
                }
            }
//            printf("\n");
        }
        
        int ans = bfs();
        printf("%d\n",ans);
    }
    return 0;
}
