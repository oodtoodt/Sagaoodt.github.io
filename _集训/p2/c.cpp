#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>

using namespace std;

const int maxx=3005;
int n,m,k;
int child[maxx];
const int INF = 0x3f3f3f3f;
int a[maxx],w[maxx];
int ans[maxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/p2/c.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0; i < maxx; i++)
    {
        child[i] = 0;
//        a[i] = INF;
    }
    int cnt = 0;
    for(int i = 0; i < n-1; i++)
    {
        scanf("%d",&m);
//        if(child[m] == INF) child[m] = 1;
        //else child[m]++;
        child[m]++;
    }
    for(int i = 0 ; i < n; i++)
    {
        if(child[i] != 0) w[cnt++] = child[i];
    }
    a[0] = 1;
    for(int i = 0; i < cnt; i++)
    {
        for(int j = n-1; j >= 0; j--)
        {
            if(j-w[i] >= 0)
            if(a[j-w[i]] != 0)
            {
                if(a[j] != 0)
                a[j] = min(a[j],a[j-w[i]]+1);
                else a[j] = a[j-w[i]]+1;
            }
        }
    }
//    ans[0] = 0;
    for(int i = 0; i < n; i++)
    {
        if(i != n-1)
        printf("%d ",a[i]-1);
        else printf("%d\n",a[i]-1);
    }
    return 0;
}
