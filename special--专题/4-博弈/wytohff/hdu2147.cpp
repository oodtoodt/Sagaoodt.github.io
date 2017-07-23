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
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/4-博弈/wytohff/hdu2147.txt","r",stdin);
#endif
    while(scanf("%d%d",&n,&m) && n)
    {
        if(n % 2 == 1 && m % 2 == 1){
            printf("What a pity!\n");
        }
        else
        printf("Wonderful!\n");
    }
    return 0;
}
