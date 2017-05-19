#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

typedef long long LL;

using namespace std;

int n,m;
int p[505];
bool flag[505];

int ok(LL mid)
{
    memset(flag,0,sizeof(flag));
    LL sum = 0;
    int ans = 1;
    for(int i = n - 1; i >= 0; i--)
    {
        sum += p[i];
        //      if(p[i] > mid)
//        return m + 1;
        if(sum > mid)
        {
            ans++;
            sum = p[i];
            flag[i] = true;
        }
    }
//    printf("ans = %d\t",ans);
    return ans;
}

void solve(LL l,LL r)
{
    LL mid;
    LL ans;
    while(l <= r)
    {
        mid = (l + r) / 2;
        ans = ok(mid) ;
        if(ans > m)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
#ifdef LOCAL
//        printf("mid= %d\t r = %d\t l = %d \n",mid, r,l);
#endif
    }
    ans = ok(l);
    for(int i = 0; i < n  && ans < m; i++)
    {
        if(!flag[i])
        {
            flag[i] = true;
            ans++;
        }
    }
    printf("%d",p[0]);
    for(int i = 1; i < n ; i++)
    {
        if(flag[i-1])
        {
            printf(" /");
        }

        printf(" %d",p[i]);
    }
    printf("\n");
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/Di1_practise/1/input.txt","r",stdin);
#endif
    int nnn;
    scanf("%d",&nnn);
//    printf("1");
    for(int jj = 0; jj < nnn; jj++)
    {
        //memset(p,0,sizeof(p));
        LL l = 0;
        scanf("%d%d",&n,&m);
        //      printf("ok");
        LL sum = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&p[i]);
            if(p[i] > l) l = p[i];
            sum += p[i];
        }
        solve(0,sum);
    }
    return 0;
}