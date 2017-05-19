/*
  ID: oodt
  PROG:poj-3669
  LANG:C++
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<queue>

using namespace std;

const int maxx=305;
int n,m,k;

typedef pair<int, int> P;
int laby[maxx][maxx];
int d[maxx][maxx];
int inF = 100000000;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

void bfs()
{
    queue<P> que;
    que.push(P(0,0));
    d[0][0] = 0;
    while(!que.empty())
    {
//        printf("ok ");
        P p = que.front();
        que.pop();
        int x = p.first,y = p.second;
        if(laby[x][y] == inF)
        {
            printf("%d\n",d[x][y]);
            return ;
        }
        for(int i = 0; i < 4; i++)
        {
            if(x+dx[i] >= 0 && y+dy[i] >= 0)
            {
                if(d[x+dx[i]][y+dy[i]] == inF)
                {
                    if(d[x][y] + 1 < laby[x+dx[i]][y+dy[i]])
                    {//下一秒会不p会死
                        que.push(P(x+dx[i],y+dy[i]));
                        d[x+dx[i]][y+dy[i]] = d[x][y] + 1;
                    }
                }
            }
        }
    }
    printf("-1\n");
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/write_book_2/2.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0; i < maxx; i++)
    {
        fill(d[i],d[i]+maxx,inF);
        fill(laby[i],laby[i]+maxx,inF);
    }
    for(int k = 0; k < n; k++)
    {
        int x,y,T;
        scanf("%d%d%d",&x,&y,&T);
        laby[x][y] = min(laby[x][y],T);
        for(int i = 0; i < 4; i++)
        {
            if(x+dx[i] >= 0 && y+dy[i] >= 0)
            laby[x+dx[i]][y+dy[i]] = min(laby[x+dx[i]][y+dy[i]], T);
        }
    }
    bfs();
    return 0;
}
