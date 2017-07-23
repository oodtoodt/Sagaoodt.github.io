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

const int maxx=100050;
int n,m,k;
char a[maxx];
//char b[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int kmpnext[maxx];
void getnext(const char *s,int n)
{
    int i = 0, j = -1;
    kmpnext[0] = -1;
    while(i < n)
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
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/2-字符串/kmp/hdu3746.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",a);
//        getchar();
        int s1 = strlen(a);
        getnext(a,s1);
        int ans = s1 - kmpnext[s1];
        for(int i = 0 ; i <= s1; i++)
        printf("%d ",kmpnext[i]);
        printf("\n%d\n",ans);
        if(ans != s1 && s1 % ans == 0) //循环多次
        printf("0\n");
        else{
            ans = ans - kmpnext[s1] ;
            printf("%d\n",ans);
        }
    }
    return 0;
}
