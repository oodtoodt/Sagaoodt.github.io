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
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;

const int maxx=105;
int n,m,k;
int a[maxx][maxx];
int ans = 0,cnt[3],pos = 0;
int l = 0,r = 0;
int vis[maxx][maxx];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int t;

void dfs(int x,int y,int p)
{
    cnt[t] ++;
    vis[x][y] = true;
    for(int i = 0 ; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m ){
            if(!vis[nx][ny] && a[nx][ny] == p){
                dfs(nx,ny,p);
            }
        }
    }
//    vis[x][y] = false;
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/baidu/2/5.txt","r",stdin);
#endif
    while(~scanf("%d%d",&n,&m))
    {
        int s1 = 0,s2 = 0,s3 = 0,s4 = 0;
        memset(cnt,0,sizeof(cnt));
        for(int i = 0; i < n; i++)
        {
            getchar();
            for(int j = 0; j < m; j++)
            {
                char ch;
                scanf("%c",&ch);
                if(ch == '0') a[i][j] = 0;
                else a[i][j] = 1;
//                printf("%d",a[i][j]);
                if(a[i][j] == 0 && s1 == 0) s1 = i,s2 = j;
                else if(a[i][j] == 1 && s3 == 0)s3 = i,s4 = j;
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
//                printf("%d",a[i][j]);
            }
//            printf("\n");
        }
        memset(vis,0,sizeof(vis));
        t = 0;
        dfs(s1,s2,0);
        t = 1;
//        memset(vis,0,sizeof(vis));
        dfs(s3,s4,1);
        t = 2;
        for(int i = 0; i < n ; i++)
        {
            for(int j = 0 ; j < m; j++)
            {
                if(!vis[i][j] && a[i][j] == 0)
                {
                    dfs(i,j,0);
                    break;
                }
            }
        }
        ans = cnt[0]+cnt[1]+cnt[2];
//        printf("%d %d %d %d\n",cnt[0],cnt[1],cnt[2],ans);
        if(cnt[0] + cnt[1] == n * m) printf("1\n");
        else if(ans == n * m) printf("0\n");
        else printf("-1\n");
    }
    return 0;
}
