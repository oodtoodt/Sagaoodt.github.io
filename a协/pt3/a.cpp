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

const int maxx=10050;
int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
map<int,int> ma;
char ch[60];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/pt3/a.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ma.clear();
        scanf("%d",&n);
        getchar();
        for(int i = 0; i < n; i++)
        {
            scanf("%s%d",ch,&m);
            ma[m]++;
        }
        int t = 0;
        for(map<int,int> ::iterator it = ma.begin(); it != ma.end(); ++it)
        {
            t = max(it->second,t);
        }
        ans = 999999;
        for(map<int,int> ::iterator it = ma.begin(); it != ma.end(); ++it)
        {
            if(it->second == t)
            ans = min(ans,it->first);
        }
        printf("%d\n",ans);
    }
    return 0;
}
