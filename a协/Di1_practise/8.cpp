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
#include <set>

using namespace std;

const int maxx=505;
int n,m,k;
int a[maxx];
int b[maxx];
int c[maxx];
//set<int> data;
int d[maxx*maxx];
int l,r;

bool erfen(int t)
{
    int mid;
//    printf("\n");
    while(l<=r)
    {
        mid = (l + r) / 2;
//        printf("%d %d %d ",mid,l,r);
        if(d[mid] < t)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
        if(d[mid] == t)
        {
            return true;
        }
    }
    return false;
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di1_practise/8.txt","r",stdin);
#endif
    int ans = 1;
    int q;
    while(scanf("%d%d%d",&q,&n,&m) == 3)
    {
//        printf("%d%d%d\n",l,n,m);
        for(int i = 0; i < q; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&b[i]);
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%d",&c[i]);
        }
//    int ans = 0;
        int num = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < q; j++)
            {
//                data.insert(a[j]+b[i]);
                d[num++] = a[j]+b[i];
            }
        }
        sort(d,d+num);
        int s;
        scanf("%d",&s);
        printf("Case %d:\n",ans);
//    printf("%d",s);
        for(int i = 0; i < s; i++)
        {
            int t;
            scanf("%d",&t);
            for(int j = 0; j < m; j++)
            {
                l = 0; r = n*q;
//                printf("%d",n*l);
                int temp = t-c[j];
                if(erfen(temp))
                {
                    printf("YES\n");
                    break;
                }
                else if(j == m-1){
                    printf("NO\n");
                }
            }
        }
        ans++;
    }
    return 0;
}
