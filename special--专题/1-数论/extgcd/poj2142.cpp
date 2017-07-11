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

int gcd(int a,int b)
{
    return b ? gcd(b,a%b) : a;
}

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
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/1-数论/poj2142.txt","r",stdin);
#endif
    int A,B,D;
    while(scanf("%d%d%d",&A,&B,&D) && (A+B+D))
    {
        int x1,x2,y1,y2;
        int d1 = extgcd(A,B,x1,y1);
        x1 *= D/d1;
        int s = B/d1;
        x1 = (x1 % s + s) % s;
        y1 = (D - A*x1)/B;
        if(y1 < 0) y1 *= -1;
        int d2 = extgcd(A,B,x2,y2);
        y2 *= D/d2;
        s = A/d2;
        y2 = (y2 % s + s) % s;
        x2 = (D - B*y2)/A;
        if(x2 < 0) x2 *= -1;
        if(x1+y1 < x2+y2)
        {
            printf("%d %d\n",x1,y1);
        }
        else{
            printf("%d %d\n",x2,y2);
        }
    }
    return 0;
}
