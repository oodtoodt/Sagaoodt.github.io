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
#include <vector>

using namespace std;

const int maxx=25;
int n,m;
int en,em;
int a[maxx][maxx];
int w,h;
int minx = maxx;
typedef pair<int,int> p;
vector<p> stone;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool ok (int x,int y)
{
    if(x >= 0 && x < h)
    {
        if(y >= 0 && y < w)
        {
            return true;
        }
    }
    return false;
}

void Dfs(int x,int y,int sum)
{
    if(sum >= 10)
    {
        return ;
    }
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(ok(nx,ny))
        {
            if(a[nx][ny]==1){
                continue;
            }
//            printf("%d,%d,%d\n",x,y,sum);
            while(!a[nx][ny])
            {
                nx += dx[i];
                ny += dy[i];
            }
//            printf("nx = %d,ny = %d,dx[i]=%d,dy[i] = %d\n",nx,ny,dx[i],dy[i]);
            if(ok(nx,ny))
            {
                if(a[nx][ny] == 1)
                {
                    a[nx][ny] = 0;
                    Dfs(nx-dx[i],ny-dy[i],sum+1);
                    a[nx][ny] = 1;
                }
                if(a[nx][ny] == 3)
                {
                    minx = min(minx,sum+1);
                }
            }
        }
    }
}
int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/bai书/2.1/4.txt","r",stdin);
#endif
    while(scanf("%d%d",&w,&h)&&w!=0)
    {
        minx = maxx;
        stone.clear();
//        memset()
        memset(a,0,sizeof(a));
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j] == 2)
                {
                    n = i;
                    m = j;
                    a[i][j] = 0;
                }
                if(a[i][j] == 3)
                {
                    en = i;
                    em = j;
//                    a[i][j] == 0;
                }
            }
        }
        Dfs(n,m,0);
        if(minx > 10)
        {
            printf("-1\n");
        }
        else
        printf("%d\n",minx);
    }
    return 0;
}
