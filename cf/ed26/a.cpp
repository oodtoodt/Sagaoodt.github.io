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
char a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int main()
{
#ifdef LOCAL
//    freopen("/Users/ecooodt/Desktop/c++ and acm/cf/ed26/a.txt","r",stdin);
#endif
    scanf("%d",&n);
    getchar();
    char ch;
    int t = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%c",&ch);
//        printf("%c",ch);
        if(ch == ' '){
            t = 0;
            continue;
        }
        if(ch >= 'A' && ch <= 'Z') t ++;
//        printf("%d\n",t);
        ans = max(t,ans);
    }
    printf("%d\n",ans);
    return 0;
}
