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

using namespace std;

const int maxx=105;
int n,m,k;
int a[maxx];
char ch[maxx][maxx];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dfs(int x,int y,char c)
{
    ch[x][y] = '.';
    for(int i = 0 ; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m ){
            if(ch[nx][ny] == c){
                dfs(nx,ny,c);
            }
        }
    }
}



int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/bai书/2.1/2.txt","r",stdin);
#endif
    while(scanf("%d%d",&n,&m)&&n!=0)
    {
        getchar();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                ch[i][j] = getchar();
            }
            getchar();
        }
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(ch[i][j] != '.'){
                    dfs(i,j,ch[i][j]);
                    res++;
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
