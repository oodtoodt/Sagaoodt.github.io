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

int extgcd(int a,int b,int &x,int &y)
{
    int d = a;
    if(b)
    {
        d = extgcd(b,a%b,y,x);
        y -= (a/b) * x;
    }
    else
    {
        x = 1, y = 0;
    }
    return d;
}



int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/1/j.txt","r",stdin);
#endif
    int T,a,b;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&a,&b);
        int x,y;
        extgcd(b,9973,x,y);
        int s = 9973;
        x *= a;
        x = (x % s + s ) % s;
        printf("%d\n",x);
    }
    return 0;
}
