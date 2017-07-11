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

using namespace std;

const int maxx=1505;
int n,m,k;
char a[maxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/cf/#418 div2/C.txt","r",stdin);
#endif
    scanf("%d%s",&n,a+1);
    scanf("%d",&k);
    while(k--)
    {
        char ch;
        int pos = 1;
        scanf("%d %c",&m,&ch);
//        printf("%c",ch);
        int res = 0;
        for(int i = 1; i <= n; i++)
        {
            while(pos <= n && m >= (a[pos]!=ch))
            {
                if(a[pos++] != ch){
                    m--;
                }
            }
            if(a[i] != ch){
                m++;
            }
            res = max(res,pos-i);
        }
        printf("%d\n",res);
    }
    return 0;
}
