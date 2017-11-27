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
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

struct P
{
    int id,nu;
}a[maxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Ot 8/k.txt","r",stdin);
#endif
    int p;
    scanf("%d%d%d",&n,&k,&p);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a);
    }
    sort(a,a+n);
    
    return 0;
}
