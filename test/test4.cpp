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
}a[maxx];
//int c[maxx],p[maxx];
int f[maxx];
int q[maxx];
int cmp(node a,node b)
{
    return a.c < b.c;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/test/test4.txt","r",stdin);
#endif
    scanf("%d%d",&n,&k);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
//        scanf("%d%d",&c[i],&p[i]);
        scanf("%d%d",&a[i].c,&a[i].p);
    }
    sort(a,a+n,cmp);
    memset(q,0,sizeof(q));
    for(int i = 0; i < n; i++)
    {
        if(a[i].c >= k) break;
//        printf("%d,%d\n",a[i].c,a[i].p);
        for(int j = i+1; j < n; j++)
        {
            if(a[i].c + a[j].c > k) break;
//            if(i == j) continue;
            ans = max(ans,a[i].p+a[j].p);
//            printf("a[i].p=%d,a[j].p=%d,%d\n",a[i].p,a[j].p,ans);
        }
    }
    printf("%d\n",ans);
    return 0;
}
