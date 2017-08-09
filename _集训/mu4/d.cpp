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

const int maxx=60005;
int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int kmpnext[maxx];
void getnext(const int *s,int m)
{
    int i,j;
    j = kmpnext[0] = -1;
    i = 0;
    while(i != m)
    {
        if(j == -1 || s[i] == s[j])
        kmpnext[++i] = ++j;
        else
        j = kmpnext[j];
    }
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/mu4/d.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        getnext(a,n);
        for(int i = 0; i <= n; i++)
        {
            printf("%d ",kmpnext[i]);
        }
    }
    return 0;
}
