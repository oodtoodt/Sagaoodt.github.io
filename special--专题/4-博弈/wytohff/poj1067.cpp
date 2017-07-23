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
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/4-博弈/wytohff/poj1067.txt","r",stdin);
#endif
    int a,b;
    while(~scanf("%d%d",&a,&b))
    {
        int k = abs(a-b);
        int a_k = floor(k * (1.0 + sqrt(5.0))/2);
        if(a_k == min(a,b))
        {
            printf("0\n");
        }else
        printf("1\n");
    }
    return 0;
}
