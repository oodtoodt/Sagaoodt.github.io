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
    for(int i = 0; i < 100; i++)
    {
        printf("%d ",i * i);
    }
    printf("\n");
    for(int i = 0; i < 100; i++)
    {
        for(int j = 10000000000000000; j < 10000000000000000; j++)
        {
            if(i * i * 2 == j * j + 1 || (i * i * 2 == j * j - 1))
            {
                printf("%d %d %d\n",i,j,i*i*2);
            }
        }
    }
    return 0;
}
