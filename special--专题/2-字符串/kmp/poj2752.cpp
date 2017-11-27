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

const int maxx=400050;
int n,m,k;
char a[maxx];
int sum[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int kmpnext[400010];
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
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/2-字符串/kmp/poj2752.txt","r",stdin);
#endif
    while(~scanf("%s",a))
    {
        int len = strlen(a);
        getnext(a,len);
        memset(sum,0,sizeof(sum));
        cnt = 0;
        for(int i = len; i != 0;)
        {
            sum[cnt++] = kmpnext[i];
            i = kmpnext[i];
        }
        for(int i = cnt-2; i >= 0; --i)
        {
            printf("%d ",sum[i]);
        }
        printf("%d\n\n",len);
    }
    return 0;
}
