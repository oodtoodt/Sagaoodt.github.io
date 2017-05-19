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

const int maxx=9;
int n,m,k;
int a[maxx][maxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di9/2.txt","r",stdin);
#endif
    while(scanf("%d%d",&n,&k)&&n!=-1)
    {
        getchar();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                char ch;
                scanf("%c",&ch);
                if(ch == '\n')
                {
                    j--;
                    continue;
                }
                if(ch == '#')
                {
                    a[i][j] = 1;
                }
                else
                {
                    a[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                
            }
        }
    }
    return 0;
}
