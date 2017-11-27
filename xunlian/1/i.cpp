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

const int maxx=1000500;
int n,m,k;
int a[maxx];
int b[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
map <int ,int > mp;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/xunlian/1/i.txt","r",stdin);
#endif
    int bo = 0;
    while(scanf("%d%d",&n,&m) && n)
    {
        mp.clear();
        if(!bo)
        {
            bo = 1;
        }
        else printf("\n");
        memset(b,0,sizeof(b));
        memset(a,0,sizeof(a));
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        int t;
        for(int i = n-1; i >= 0; i--)
        {
            if(mp.empty()) b[i] = n;
            else b[i] = b[i+1];
            if(mp.count(a[i]) != 0)
            {
                b[i] = min(mp[a[i]],b[i]);
            }
            mp[a[i]] = i;
        }
        for(int i = 0; i < m; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(b[x-1] > y-1)
            {
                printf("OK\n");
//                break;
            }
            else
            {
//                while(x++) if(x == )
                printf("%d\n",a[b[x-1]]);
            }
        }
    }
    return 0;
}
