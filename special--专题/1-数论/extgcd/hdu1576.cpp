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
        x = 1;
        y = 0;
    }
    return d;
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/1-数论/hdu1576.txt","r",stdin);
#endif
    int q;
    scanf("%d",&q);
    int b;
    int x,y;
    while(q--)
    {
        scanf("%d%d",&n,&b);
        extgcd(b,9973,x,y);
        x *= n;
        int s = 9973;
//        x = (x%s+s)%s;
        x = x % s;
        while(x <= 0)
        {
            x += s;
        }
        printf("%d\n",x);
    }
    return 0;
}
