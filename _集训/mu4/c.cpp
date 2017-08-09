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

int euler[3000001];
void geteuler()
{
	memset(euler,0,sizeof(euler));
	euler[1] = 1;
	for(int i = 2;i <= 3000000;i++)
    if(!euler[i])
    for(int j = i;j <= 3000000; j += i)
    {
        if(!euler[j])
        euler[j] = j;
        euler[j] = euler[j]/i*(i-1);
    }
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/mu4/c.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    int l,r;
    geteuler();
    while(T--)
    {
        scanf("%d%d%d",&l,&r,&k);
        int t = (l+r)*(r-l+1)/2;
        printf("%d\n",euler[t]+euler[r]);
    }
    return 0;
}
