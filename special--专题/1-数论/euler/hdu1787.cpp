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

long long euler(long long n)
{
    long long ans = n;
    for(int i = 2;i*i <= n;i++)
    {
    	if(n % i == 0)
        {
    		ans -= ans/i;
    		while(n % i == 0)
            n /= i;
        }
    }
    if(n > 1)ans -= ans/n;
  	return ans;
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/1-数论/euler/hdu1787.txt","r",stdin);
#endif
    while(scanf("%d",&n) && n != 0)
    {
        printf("%d\n",n-euler(n)-1);
    }
    return 0;
}
