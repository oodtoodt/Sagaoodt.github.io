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
const int INF = 0x3f3f3f3f;
int n,m,k;
char s[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
int a[27];
int len[27];

int main()
{
#ifdef LOCAL
//    freopen("","r",stdin);
#endif
    scanf("%s",s);
    n = strlen(s);
    memset(a,-1,sizeof(a));
    memset(len,0,sizeof(len));
    for(int i = 0; i < n; i++)
    {
        int t = s[i]-'a';
        if(a[t] != -1) len[t] = max(len[t],i-a[t]);
        else len[t] = i+1;
        a[t] = i;
//
    }
    for(int i = 0; i < 26; i++)
    {
        len[i] = max(len[i],n - a[i]);
    }
    ans = INF;
    for(int i = 0; i < 26; i++)
    {
//        printf("%c %d %d\n",i+'a',a[i],len[i]);
//        printf("%d ",len[i]);
        ans = min(ans,len[i]);
    }
    printf("%d\n",ans);
    return 0;
}
