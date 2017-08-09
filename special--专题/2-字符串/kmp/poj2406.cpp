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

const int maxx=1000050;
int n,m,k;
char a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int kmpnext[maxx];
void getnext(const char *s,int m)
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
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/2-字符串/kmp/poj2406.txt","r",stdin);
#endif
    while(scanf("%s",a) && a[0] != '.')
    {
        int len = strlen(a);
        getnext(a,len);
        int t = len - kmpnext[len];
        if(len % t == 0)
        printf("%d\n",len/t);
        else printf("1\n");
    }
    return 0;
}
