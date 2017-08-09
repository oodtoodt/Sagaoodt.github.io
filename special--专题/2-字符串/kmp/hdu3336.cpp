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

const int maxx=200005;
int n,m,k;
char a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int kmpnext[maxx];
void getnext(char s[],int len)
{
    int i,j;
    j = kmpnext[0] = -1;
    i = 0;
    while(i != len)
    {
        if(j == -1 || s[i] == s[j]){
            kmpnext[++i] = ++j;
        }
        else j = kmpnext[j];
    }
}

int dp[maxx];
const int p = 1e4+7;
int main()
{
#ifdef LOCAL
    freopen("/users/ecooodt/desktop/c++ and acm/special--专题/2-字符串/kmp/hdu3336.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",a);
        getnext(a,n);
        ans = 0;
//        printf("%d\n",p);
        for(int i = 1; i <= n; i++)
        {
            dp[i] = dp[kmpnext[i]] + 1;
            ans += dp[i];
            ans %= p;
        }
        printf("%d\n",ans);
    }
    return 0;
}
