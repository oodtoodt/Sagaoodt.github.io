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
//    freopen("/Users/ecooodt/Desktop/c++ and acm/cf/#427 div2//a.txt","r",stdin);
#endif
    int s,v1,v2,t1,t2;
    scanf("%d%d%d%d%d",&s,&v1,&v2,&t1,&t2);
    int f1 = v1*s+t1*2;
    int f2 = v2*s+t2*2;
    if(f1== f2)
    {
        printf("Friendship\n");
    }
    else if(f1 > f2)
    {
        printf("Second\n");
    }
    else  printf("First\n");
    return 0;
}
