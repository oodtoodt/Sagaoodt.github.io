#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

const int maxx = 1e7 * 3 + 7;
int n,m,k;
int a[maxx],b[maxx];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0; i < m; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < k; i++)
    {
        scanf("%d",&b[i]);
    }
    for(int i = 0; i < n-m; i++)
    {
        a[m+i] = a[i] + a[i+1];
    }
    sort(a,a+n);
    for(int i = 0; i < k; i++)
    {
//        printf("%d ",a[i]);
        printf("%d\n",a[b[i]-1]);
    }
}