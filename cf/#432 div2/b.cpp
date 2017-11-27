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
//    freopen("/Users/ecooodt/Desktop/c++ and acm/cf/#432 div2/b.txt","r",stdin);
#endif
    int ax,ay,bx,by,cx,cy;
    scanf("%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy);
    int x1 = ax - bx;
    int x2 = cx - bx;
    int y1 = ay-by;
    int y2 = cy-by;
    if(x1*x1+y1*y1 == x2*x2+y2*y2) printf("Yes\n");
    else printf("No\n");
    return 0;
}
