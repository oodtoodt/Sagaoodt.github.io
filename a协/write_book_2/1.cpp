/*
  ID: oodt
  PROG:poj 1979
  LANG:C++
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>

using namespace std;

const int maxx=30;
int n,m;
int a[maxx][maxx];
int x,y;
int mo[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int sum;

int dfs(int i_x,int i_y)
{
    a[i_x][i_y] = 0;
    sum++;
    for(int i = 0; i < 4; i++)
    {
        if(a[i_x+mo[i][0]][i_y+mo[i][1]])
        {
            dfs(i_x+mo[i][0],i_y+mo[i][1]);
        }
    }

}

int main()
{
#ifdef LOCAL
     freopen("/Users/ecooodt/Desktop/c++ and acm/a协/write_book_2/1.txt","r",stdin);
#endif
    while(scanf("%d%d",&x,&y) && x != 0)
    {
        getchar();
        sum = 0;
        memset(a,0,sizeof(a));
        for(int i = 1; i <= y; i++)//不是很懂这个xy到底怎么弄。。。
        {
            for(int k = 1; k <= x; k++)
            {
                char ch;
                ch = getchar();
                if(ch == '.')
                {
                    a[i][k] = 1;
                }
                if(ch == '@')
                {
                    n = i;
                    m = k;
                }
            }
            getchar();
        }
        dfs(n,m);
        printf("%d\n",sum);
    }
    return 0;
}
