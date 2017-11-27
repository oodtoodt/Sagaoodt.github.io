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

const int maxx=27;
int n,m,k;
int a[maxx][maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
char ch[maxx][maxx];
int vis1[27];
int vis2[27];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Ot 3/j.txt","r",stdin);
#endif
    while(~scanf("%d",&n))
    {
        memset(a,0,sizeof(a));
        memset(vis1,0,sizeof(vis1));
        memset(vis2,0,sizeof(vis2));
        for(int i = 0; i < n; i++)
        {
            scanf("%s",ch[i]);
        }
        for(int i = 0;  i< n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                a[i][j] = ch[i][j] - 'A';
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n;j++)
            vis1[i] += a[i][j];
        }
        for(int j = 0; j < n; j++)
        {
            for(int i = 0; i < n;i++)
            vis2[j] += a[i][j];
        }
        l = 0;
        for(int i = 1; i < n-1; i++)
        {
            if(vis1[i+1] != vis1[i] && vis1[i-1] != vis1[i])
            {
                l = i;
                break;
            }
        }
        if(l == 0){
            if(vis1[0] == vis1[1]) l = n-1;
            else l = 0;
        }
        r = 0;
        for(int i = 1; i < n-1; i++)
        {
            if(vis2[i+1] != vis2[i] && vis2[i-1] != vis2[i])
            {
                r = i;
                break;
            }
        }
        if(r == 0){
            if(vis2[0] == vis2[1]) r = n-1;
            else r = 0;
        }
        char p;
        int ans = 0;
        if(r != 0) ans += vis2[0] - vis2[r];
        else ans += vis2[1] - vis2[r];
//        if(l != 0) ans += abs(vis2[0] - vis1[l]);
//        else ans += abs(vis1[1] - vis1[l]);
        p = ch[l][r] + ans;
        printf("%d %d %c\n",l+1,r+1,p);
    }
    return 0;
}
