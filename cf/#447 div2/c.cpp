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
set<int> s;

int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/cf/#447 div2/c.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        s.insert(a[i]);
    }
    int fk = 0;
    for(int i = 0; i < n; i++)
    {
            if(a[i]%a[0])
            {
                fk = 1;
                break;
            }
    }
    if(fk)
    {
        printf("-1\n");
    }
    else{
        printf("%d\n",n*2);
        for(int i = 0; i < n; i++)
        {
            printf("%d %d",a[i],a[0]);
            if(i != n-1) {
                printf(" ");
            }
            printf("\n");
//            else printf("%d\n",a[i]);
        }
    }
    return 0;
}
