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
#include <map>
using namespace std;

const int maxx=1005;
int n,m,k;
int a[maxx];
map <int,int> data;
map <int,int> q[maxx];
int b[maxx];
int s[maxx];
//map <int,int> c;
/*struct node
{
    int num,id;
}a[maxx];
int cmp(node a,node b)
{
    if(a.num == b.num)  return a.id <  b.id;
    return a.num < b.num;
}
*/

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di11/2.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
//        a[i] = i + 1;
    }
    //sort(a,a+n,cmp);
    for(int i = 0; i < n; i++)
    {
        //   printf("%d_%d ",a[i].num,a[i].id);
    }
    memset(b,0,sizeof(b));
    memset(s,0,sizeof(s));
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n ; j++)
        {
            if(a[j] > a[i])
            {
                data[a[j]+a[i]]++;
                b[i] ++;
                q[i][a[j]+a[i]]++;
//                s[i]++;
//                printf("ok");
            }
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        long long temp = 1;
        temp *= b[i];
//        printf("%d ",temp);
        bool fk = true;
        int temp1 = 0;
        for(int j = a[i]*2 + 1; j < n*2+1; j++)
        {
            if(data.count(j))
            {
                if(fk) {temp1 = 0;fk = false;}
                temp1 += data[j]-q[i][j];
//                printf(" %d ",temp1);
            }
//            printf("%d",temp);
        }
//        if(!c.count(a[i]))
        if()
        temp *= temp1;
        else temp *= temp-1;
        ans += temp;
//        printf("\n");
        //      c[a[i]] = 1;
    }
    printf("%lld\n",ans);
    return 0;
}
