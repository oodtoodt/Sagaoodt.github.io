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

const int maxx=105;
int n,m,k;
int a[maxx];
int b[maxx];
int c[maxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/cf/#418 div2/A.txt","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        c[i] = a[i];
    }
    for(int i = 0; i < m; i++)
    {
        scanf("%d",&b[i]);
    }

//    sort(c,c+n);
    for(int i = 0;i < n;i ++)
    //printf("%d",c[i]);
    if(m == 1){
        for(int i = 0; i < n; i++)
        {
            if(a[i] == 0)
            {
                a[i] = b[0];
                c[i] = b[0];
            }
        }
        sort(c,c+n);
        for(int i = 0; i < n; i++)
        {
            if(a[i] != c[i]){
                printf("Yes\n");
                return 0;
            }
        }
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    return 0;
}
