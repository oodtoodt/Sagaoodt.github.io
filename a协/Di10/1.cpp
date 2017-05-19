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
#include <set>

using namespace std;

const int maxx=100005;
int n,m,k;
int a[maxx];
set<int> s[maxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di10/1.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(int i = 0; i < m; i++)
    {
        int a,int b;
        scanf("%d%d",&a,&b);
        if(set[a].find(b))
        {
            printf("-1");
            continue;
        }
        else
        {
            
        }
    }
    return 0;
}
