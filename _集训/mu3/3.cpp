#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
//nupt2017team05
const int MAXN=5*1e5+5;
long long a[MAXN];
int main()
{
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/mu3/3.txt","r",stdin);
    int T;
    scanf("%lld",&T);
    while(T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        long long ans=0;
        for(int i=0;(k+i)<=n;i++)
        {
        ans+=a[k+i-1]*(n-k+1-i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
