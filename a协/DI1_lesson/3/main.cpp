#include <cstdio>
#include <algorithm>
#define LL long long
using namespace std;

const int maxn = 100000+5;
int boy[maxn],bike[maxn];
int b;

bool cmp(int a,int b){
    return a > b;
}

bool ok(int mid,int a,int n)
{
    LL res = 0;
    for(int i = 0; i < mid; i++)
    {
        int temp = bike[i] - boy[mid-i-1];
#ifdef LOCAL
        printf("mid=%d,temp=%d\n",mid,temp);
#endif
        if(temp > 0)
        {
            res += (LL)temp;
        }
    }
    if(res > a)
    {
        return false;
    }
    return true;
}

void fo(int n, int m, int a)
{
    int l = 0;
    int mid;
    int r = min(m,n);
    while(l <= r)
    {
        mid = (r + l) / 2;
        if(ok(mid,a,n))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    LL sum = 0;
    for(int i = 0; i < l - 1; i++)
    {
        sum += bike[i];
    }
    printf("%d %lld",l - 1,sum>a?sum-a:0);
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/DI1_lesson/3/input.txt","r",stdin);
#endif
    int n,m,a;
    scanf("%d%d%d",&n,&m,&a);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&boy[i]);
    }
    for(int i = 0; i < m; i++)
    {
        scanf("%d",&bike[i]);
    }
    sort(boy,boy+n,cmp);

    sort(bike,bike+m);
#ifdef LOCAL
    for(int i = 0; i < n; i++)
    {
        printf("%d ",boy[i]);
    }
    printf("\n");
    for(int i = 0; i < m; i++)
    {
        printf("%d ",bike[i]);
    }
    printf("\n");
#endif
    fo(n,m,a);
    //let the richest boy buy the cheapest bike
    //default is low to high
}