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

using namespace std;

const int maxx=10005;
int n,m,k;
int a[maxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/shuoj/st/1.txt","r",stdin);
#endif
    while(~scanf("%d%d",&n,&m))
    {
        memset(a,0,sizeof(a));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                scanf("%d",&k);
                if(k == 1)a[j] ++;
            }
        }
        for(int i = 0; i < m; i++)
        {
            printf("%d",a[i]);
            if(i != m-1)
            {
                printf(" ");
            }
            else
            {
                printf("\n");
            }
        }
    }
    return 0;
}
