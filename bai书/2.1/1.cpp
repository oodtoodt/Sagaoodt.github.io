
/*
  ID: oodt
  PROG:poj1979
  LANG:C++
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>

using namespace std;

const int maxx=55;
int n,m,k;
int f[maxx][maxx];
char ch[maxx][maxx];
int sum = 0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dfs(int x,int y)
{
    sum ++;
    ch[x][y] = '#';
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < m && ny >= 0 && ny < n && ch[nx][ny] == '.'){
            dfs(nx,ny);
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/bai书/2.1/1.txt","r",stdin);
#endif
    while(scanf("%d%d",&n,&m)&&n!=0)
    {
        sum = 0;
        int x,y;
        getchar();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j ++)
            {
                ch[i][j] = getchar();
                if(ch[i][j] == '@')
                {
                    ch[i][j] = '.';
                    x = i;
                    y = j;
                }
            }
            getchar();
        }
        dfs(x,y);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
//                printf("%c",ch[i][j]);
            }
//            printf("\n");
        }
        printf("%d\n",sum);
    }
    return 0;
}
