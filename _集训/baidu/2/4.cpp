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
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/baidu/2/4.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b,c;
        scanf("%d-%d-%d",&a,&b,&c);
//        printf("%d %d %d\n",a,b,c);
        if(b == 2 && c == 29 && (a % 400 == 0 || (a % 4 == 0 && a % 100 != 0)))
        {
            if(a % 100 >= 72 && (a+100-a%100) % 400 != 0) printf("%d\n",a + 29);
            else printf("%d\n",a + 28);
        }
        else if(a % 100 >= 89 &&  (a + 100 - a % 100) % 400 != 0)
        {
            if(a % 100 >= 94 && a % 100 <= 95)
            {
                printf("%d\n",a+6);
            }
            else if(a % 100 < 94)
            {
                if(a % 4 == 2)
                {
                    if(b > 2) printf("%d\n",a+12);
                    else printf("%d\n",a+6);
                }
                if(a % 4 > 2) printf("%d\n",a+12);
            }
            else if(a % 100 <= 97 || (a % 100 == 98 && b < 2))
            {
                printf("%d\n",a+7);
            }
            else printf("%d\n",a+6);
        }
        else if(a % 4 < 2)
        {
            printf("%d\n",a+6);
        }
        else if(a % 4 == 2)
        {
            if(b <= 2) printf("%d\n",a+6);
            else if(b > 2) printf("%d\n",a + 11);
        }
        else if(a % 4 > 2) printf("%d\n",a + 11);
    }
    return 0;
}
