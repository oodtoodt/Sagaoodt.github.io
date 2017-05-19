/*
  ID: oodt
  PROG:
  LANG:C++
  2500500025
  2147483648
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>

using namespace std;

typedef long long ll;

const int maxx=100005;
long long n,m,k;
ll a[maxx];

void er()
{
    for(int i = 1; i < maxx; i++)
    {
        a[i] = i * (i+1) / 2;
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di1_practise/6/1.txt","r",stdin);
#endif
//    er();
    scanf("%lld",&n);
    ll l,r,temp;
    while(n--)
    {
        scanf("%lld",&k);
        ll q = sqrt(k*2);
        l =  q*(q+1)/2;
        if(k>l)
        {
            temp = k-q*(q+1)/2;
        }
        else temp = k-q*(q-1)/2;
        printf("%d\n",temp%9?temp%9:9);
    }
    return 0;
}
