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

const int maxx=10005;
int n,m,k;
int a[maxx];
long long ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

void init()
{
    for(int i = 2; i <= 1000000; i++)
    {
        for(int j = 1; j <= 1000 && j < i && i * j <= m; j++)
        {
                if((i + j) & 1) continue;
                int t = (i - j)/2;
                if(t <= n)
                {
                    cnt++;
                }
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/codechef/cook84/2.txt","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    init();
    printf("%lld\n",cnt);
    return 0;
}
