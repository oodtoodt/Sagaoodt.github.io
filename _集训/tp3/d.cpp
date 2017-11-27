#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>

using namespace std;

const int maxx=20;
int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
int vis[maxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/tp3/d.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                if(a[i] + a[j] > a[k] && !vis[i] && !vis[j] && !vis[k])
                {
                    vis[i] = vis[j] = vis[k] = 1;
                    cnt++;
                }
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
