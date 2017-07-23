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
void getnext(char s[],int m)
{
    int i,j;
    j = kmpnext[0] = -1;
    i = 0;
    while(i != m)
    {
        if(j == -1 || s[i] == s[j]) kmpnext[++i] = ++j;
        else j = kmpnext[j];
    }
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/1/f.txt","r",stdin);
#endif
    while(scanf("%s",a) && a[0] != '.')
    {
//        printf("%s\n",a);
        int len = strlen(a);
        getnext(a,len);
        cnt = 0;
        int t = len - kmpnext[len];
//printf("%d %d\n",kmpnext[len],len);
        if(len % t == 0)
        printf("%d\n",len/t);
        else printf("1\n");
//        printf("\n");
    }
    return 0;
}
