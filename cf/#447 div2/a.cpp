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
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int main()
{
#ifdef LOCAL
//    freopen("/Users/ecooodt/Desktop/c++ and acm/cf/#447 div2/a.txt","r",stdin);
#endif
    char a[105];
    scanf("%s",a);
    int n = strlen(a);
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                if(a[i] == 'Q' && a[j] == 'A' && a[k] == 'Q') ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
