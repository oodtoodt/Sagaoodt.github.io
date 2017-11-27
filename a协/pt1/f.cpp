#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;

const int maxx=200050;
int n,m,k,L;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/pt1/f.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&L);
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        pos = 0,l = 0,r = 0;
        while(pos < l)
        {
            if(pos - a[l] > L)
            {
                int t = a[r];
                pos = a[l] + L + 1;
                
            }
            else
            {
                while(a[r]-a[l] < L) r++;
                l = r-1;
                ans ++;
            }
        }
    }
    return 0;
}
