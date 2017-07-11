/*
  ID: oodt
  PROG:hdu2669
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

int extgcd(int a, int b, int &x, int &y)
{
    int d = a;
    if(b != 0) {
        d  = extgcd(b, a % b, y, x);
        y -= (a/b) * x;
    }else {
        x = 1, y = 0;
    }
    return d;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/1-数论/hdu2669.txt","r",stdin);
#endif
    while(~scanf("%d%d",&n,&m))
    {
        int x,y;
        int d = extgcd(n,m,x,y);
        if(d == 1)
        {
            while(x<=0){
                x += m;
                y -= n;
            }
            printf("%d %d\n",x,y);
        }
        else{
            printf("sorry\n");
        }
    }
    return 0;
}
