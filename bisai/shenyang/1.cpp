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
//int a[maxx];
char ch[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int kmpnext[100050];
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
int dp[maxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/bisai/shenyang/1.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        getchar();
        scanf("%s",ch);
        m = strlen(ch);
        getnext(ch,m);
        dp[0] = 0;
        for(int i = 1; i < m+1; i++)
        {
//            printf("%d ",kmpnext[i]);

            dp[i]=dp[kmpnext[i]]+1;
//            dp[i]%=MOD;
//            ans+=dp[i];
//            ans%=MOD;
            printf("%d ",dp[i]);
        }
        printf("\n");
    }
    return 0;
}
