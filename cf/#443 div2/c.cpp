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
    freopen("/Users/ecooodt/Desktop/c++ and acm/cf/#443 div2/c.txt","r",stdin);
#endif
    while(~scanf("%d",&n))
    {
        for(int i = 0; i <= 10; i++)
        {
            a[i] = 2;
        }
        for(int i = 0; i < n; i++)
        {
            getchar();
            char ch;
            int g;
            pos = 0;
            scanf("%c%d",&ch,&g);
            if(ch == '|')
            {
                while(g > 0)
                {
                    if(g % 2 == 1)
                    a[pos] = 1;
                    g /= 2;
                    pos++;
                }
            }
            else if(ch == '&')
            {
                while(g > 0)
                {
                    if(g % 2 == 0)
                    a[pos] = 0;
                    g /= 2;
                    pos++;
                }
            }
            else if(ch == '^')
            {
                while(g > 0)
                {
                    if(g % 2 == 1)
                    a[pos] = a[pos] ^ 1;
                    pos++;
                    g /= 2;
                }
            }
        }
        for(int i = 0; i < 5; i++)
        {
            printf("%d ",a[i]);
        }
        int ans1 = 0,ans2 = 0;
        for(int i = 0; i <= 10; i++)
        {
            if(a[i] == 2) continue;
            if(a[i] == 1) ans1 += (1<<i);
            if(a[i] == 3) ans2 += (1<<i);
            if(a[i] == 0) {
                ans1 += (1<<i);
                ans2 += (1<<i);
            }
        }
        cout<<endl;
        printf("2\n");
        printf("| %d\n",ans1);
        printf("^ %d\n",ans2);
//        printf(2);
    }
    return 0;
}
