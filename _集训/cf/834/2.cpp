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

const int maxx=1000005;
int n,m,k;
char a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
int vis[27];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/cf/834/2.txt","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    getchar();
    for(int i = 0; i < n; i++)
    {
        scanf("%c",&a[i]);
    }
    bool flag = false;
//    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));
    for(int i = 0; i < n; i++)
    {
        if(!vis[a[i]-'A']) {
            vis[a[i]-'A'] = true;
            cnt++;
        }
        if(cnt > m) {
            flag = true;
            break;
        }
        for(int j = i+1; j < n;j++)
        {
            if(a[j] == a[i]) break;
            if(j == n-1) cnt --;
        }
    }
    if(flag)
    {
        printf("NO\n");
    }
    else printf("YES\n");
    return 0;
}
