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

const int maxx=10005;
int n,m,k;
int a[maxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/DI12/2.txt","r",stdin);
#endif
    scanf("%d%d%d",&n,&m,&k);//n,s,l;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    int r = a[0];
    int pr = 0;
    int l,pl;
    int ans = 0;
    bool fk = false;
    for(int i = 0; i < n; i++)
    {
        if(abs(a[i] - r) > m)
        {
            if(ans % 2 == 1)
            {
                l = r;
                pl = pr;
            }
            if(i - pl <= k)
            {
                r = a[i];
                pr = i;
                ans ++;
                continue;
            }
            r = a[i-1];
            pr = i - 1;
            ans ++;
            if(ans%2 == 0)
            {
//                printf("")
                if(pr - pl < k)
                {
                    fk = true;
                    break;
                }
            }
        }
    }
    if(fk)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n",ans/2);
    }
    return 0;
}
