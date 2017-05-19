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
#include <cstdlib>

using namespace std;

const int maxx=10005;
int n,m,k;

int maxsum = -1;
int id;

void change()
{
    k = m;
    int n_k = 0;
    for(int i = 0; i < 16; i++)
    {
        if(k & 1)        n_k += 1 << (15 - i);
        k >>= 1;
    }
    if(n_k > maxsum)
    {
        maxsum = n_k;
        id = m;
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/wishare/2.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&m);
        change();
    }
    printf("%d %d\n",maxsum,id);
    return 0;
}
