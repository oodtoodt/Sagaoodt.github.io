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
int b[22];
int a[maxx][22];
char ch[22];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int main()
{
#ifdef LOCAL
//    freopen("","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++)
    {
        scanf("%s",ch);
        for(int j = 0 ; j < m; j++)
        {
            a[i][j] = ch[j]-'0';
        }
    }
    for(int j = 0; j < m; j++)
    {
        for(int i = 0; i < n; i++)
        {
            if(a[i][j] == 1) b[j]++;
        }
    }
    for(int i = 0; i < m ; i++)
    {
        if(b[i] > n/2) printf("0");
        else printf("1");
    }
    printf("\n");
    return 0;
}
