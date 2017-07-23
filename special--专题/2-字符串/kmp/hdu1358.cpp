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
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/2-字符串/kmp/hdu1358.txt","r",stdin);
#endif
    while(scanf("%d",&n) && n != 0)
    {
        getchar();
        for(int i = 0; i < n; i++)
        {
            scanf("%c",&a[i]);
        }
        int len = strlen(a);
        getnext(a,len);
        printf("Test case #%d\n",++cnt);
        for(int i = 2; i <= len; i++)
        {
            if(kmpnext[i] == -1 || kmpnext[i] == 0) continue;
            int j = i - kmpnext[i];
            if(i % j == 0)
            {
                printf("%d %d\n",i,i/j);
            }
        }
        printf("\n");
    }
    return 0;
}
