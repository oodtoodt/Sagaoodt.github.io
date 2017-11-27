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
char a[maxx];
char b[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/xunlian/1/j.txt","r",stdin);
#endif
    while(scanf("%s",a))
    {
        if(a[0] == '0')
        {
            break;
        }
        scanf("%s",b);
//        printf("%s\n%s\n",a,b);
//        printf("%d %d ",a[0]-'A',b[0]-'A');
        int n = strlen(b);
        int m = strlen(a);
        for(int i = 0; i < n; i++)
        {
            int t = (a[i % m] - 'A' + b[i] - 'A' + 1) % 26 + 'A' ;
            printf("%c",t);
        }
        printf("\n");
        printf("%d + %d",'m'-'a' , 'n'-'a');
    }
    return 0;
}
