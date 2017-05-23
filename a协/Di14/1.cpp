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
#include <stack>

using namespace std;

const int maxx=1005;
int n,m,k;
int w[maxx];
int b[maxx];
stack<int> s;
int vis[maxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di14/1.txt","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&w[i]);
    }
    for(int i = 0; i < m; i++)
    {
        scanf("%d",&b[i]);
    }

    int ans = 0;
//    int cnt = 0;
    for(int i = 1 ; i < m; i++)
    {
        memset(vis,0,sizeof(vis));
        for(int j = i-1 ; j >= 0 ; j--)
        {
            if(b[i] == b[j])
            {
                break;
            }
            if(!vis[b[j]])
            {
                vis[b[j]] = 1;
                ans += w[b[j]-1];
//                printf("%d %d\t",w[b[j]],b[j]);
            }
        }
//        printf("\n");
    }
    printf("%d\n",ans);
    return 0;
}
