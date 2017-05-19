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

const int maxx=10;
int n,m,k;
int a[maxx][maxx];
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

void dfs(int x,int y,int )
{
    
}

void solve()
{
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            dfs(i,j,1,a[i][j]);
        }
    }
}
int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/write_book_2/3.txt","r",stdin);
#endif
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; i++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    solve();
    return 0;
}
