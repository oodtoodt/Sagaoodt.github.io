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
struct node{
    int c,p;
};//a[maxx];
int c[maxx],p[maxx];
int f[maxx];
int q[maxx];
int cmp(node a,node b)
{
    return a.p > b.p;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/test/test4.txt","r",stdin);
#endif
    scanf("%d%d",&n,&k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d",&c[i],&p[i]);
    }
//    sort(a,a+n,cmp);
    memset(q,0,sizeof(q));
    for(int i = 0; i < n; i++)
    {
        for(int j = k; j >= 0; j--)
        {
            if(j - c[i] >= 0)
            {
                if(f[j] < f[j-c[i]] + p[i])
                {
                    if(q[j-c[i]] + 1 == 3) continue;
                    f[j] = f[j-c[i]]+p[i];
                    q[j] = q[j-c[i]] + 1;
                }
                else f[j] = f[j];
//                f[j] = max(f[j], f[j-c[i]] + p[i]);
            }
            else f[j] = f[j];
//            printf("f[%d] = %d\n",j,f[j]);
        }
    }
    printf("%d",f[k]);
    return 0;
}
