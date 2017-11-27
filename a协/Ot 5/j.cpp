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

int main()
{
#ifdef LOCAL
//    freopen("","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    if(n == m && n != 0) printf("Even %d\n",n*2);
    else if(n == 0 && m == 0)
    {
        printf("Not a moose\n");
    }
    else{
        int t = max(n,m);
        printf("Odd %d\n",t*2);
    }
    return 0;
}
