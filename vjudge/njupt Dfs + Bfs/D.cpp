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

const int maxx=10005;
int n,m,k;
int a[maxx];
int w,h;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/vjudge/njupt Dfs + Bfs/D.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&w,&h);
        for(int i = 0 ; i < h; i++)
        {
            getchar();
            for(int j = 0; j < w; j++)
            {
                scanf("%c",&a[i][j]);
            }
        }
    }
    return 0;
}
