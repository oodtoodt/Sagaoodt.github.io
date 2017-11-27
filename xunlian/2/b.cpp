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

const int maxx=10005;
int n,m,k;
int a[maxx];
int b[maxx];
char ch[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int main()
{
#ifdef LOCAL
//    freopen("/Users/ecooodt/Desktop/c++ and acm/xunlian/2/2.txt","r",stdin);
#endif
    scanf("%s",ch);
    n = strlen(ch);
    int t = 0,q = 0;
    a[0] = 0,b[0] = 0;
    for(int i = 0; i < n; i++)
    {
        if(ch[i] == 'a') t++;
        else q++;
        a[i+1] = t;
        b[i+1] = q;
    }
    a[n+1] = a[n];
    b[n+1] = b[n];
    for(int i = 0; i < n; i++)
    {
//        printf("%d ",a[i]);
    }
//    printf("\n");
    for(int i = 0; i < n; i++)
    {
//        printf("%d ",b[i]);
    }
    ans = 0;
    for(int i = 0; i <= n+1; i++)
    {
        for(int j = i+1; j <= n+1; j++)
        {
            ans = max(ans,n-(b[i]+a[j]-a[i]+b[n]-b[j]));
        }
    }
//    printf("%d\n",n);
    printf("%d\n",ans);
    return 0;
}
