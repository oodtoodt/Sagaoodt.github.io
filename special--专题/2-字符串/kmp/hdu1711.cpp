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

const int maxx=1000010;
int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
int b[10010];

void prekmp(int x[],int m,int kmpnext[])
{
    int i,j;
    j = kmpnext[0] = -1;
    i = 0;
    while(i < m)
    {
        while(-1 != j && x[i] != x[j]) j = kmpnext[j];
        if(x[++i] == x[++j]) kmpnext[i] = kmpnext[j];
        else kmpnext[i] = j;
    }
}
int kmpnext[10010];
int kmp_count(int x[],int m,int y[],int n)
{//x是模式串，y是主串。
    int i,j;
    ans = 0;
    prekmp(x,m,kmpnext);
    i = j = 0;
    while(i < n)
    {
        while(-1 != j && y[i] != x[j]) j = kmpnext[j];
        i++;j++;
        if(j >= m)
        {
            return i - m + 1;
            ans++;
            j = kmpnext[j];
        }
    }
    return -1;
//    return i;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/2-字符串/kmp/hdu1711.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(kmpnext,0,sizeof(kmpnext));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d%d",&n,&m);
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%d",&b[i]);
        }
        int t = kmp_count(b,m,a,n);
//        cnt = t - m * ans;
        printf("%d\n",t);
    }
    return 0;
}
