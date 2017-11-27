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
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
int t;

int main()
{
#ifdef LOCAL
//    freopen("/Users/ecooodt/Desktop/c++ and acm/cf/#432 div2/a.txt","r",stdin);
#endif
    scanf("%d%d%d",&n,&k,&t);
    if(t <= k) printf("%d\n",t);
    else if(t > k && t <= n) printf("%d\n",k);
    else if(t > n) printf("%d\n",k + n - t);
    return 0;
}
