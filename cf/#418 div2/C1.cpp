/*
  ID: oodt
  PROG:
  LANG:C++
  这个还是很key的一道题233.
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>

using namespace std;

const int maxx=10005;
int n,m,k;
char a[maxx];
int dp[30][maxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/cf/#418 div2/C.txt","r",stdin);
#endif
    int q;
    scanf("%d%s",&n,a+1);
    scanf("%d",&q);
    memset(dp,-1,sizeof(dp));
    for(int i = 0; i < 26; i++)
    {
        char no = i + 'a';
        for(int j = 1; j <= n; j++)
        {
            int num = 0;
            for(int k = j; k >= 1; k--)
            {
                if(a[k] == no) ++num;
                dp[i][j-k+1-num] = max(dp[i][j-k+1-num],j-k+1);
            }
        }
    }
    while(q--)
    {
        char ch;
        scanf("%d %c",&m,&ch);
//        printf("%c",ch);
        int t = dp[ch-'a'][m];
        if(t == -1)
        printf("%d\n",n);
        else
        printf("%d\n",t);
    }
    return 0;
}
