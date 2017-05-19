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

const int maxx=1005;
int n,m,k;
int a[maxx];
int l = 0, r = 0;
int ans;
int t1;

int ok(int mid)
{
    if(mid*mid*mid > ans)
    {
        return false;
    }
    else return true;
}

bool erfen()
{
    int mid;
    while(l<=r)
    {
        mid = (l + r) / 2;
        if(ok(mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    l--;
//    printf("%d\t",l);
    if(l*l*l == ans)
    return true;
    else return false;
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di13/1.txt","r",stdin);
#endif
    while(scanf("%d",&n),n != 0)
    {
        for(int i = -maxx ; i < 105 ; i ++)
        {
            t1 = i * i * i;
//            printf("%d %d %d\t",t1,n,maxx);
            l = -maxx;
            ans = n - t1;
            r = maxx;
            if(t1 > n)
            {
                printf("Impossible\n");
                break;
            }
            if(erfen())
            {
                printf("%d %d\n",i,l);
                break;
            }
        }
    }
    return 0;
}
