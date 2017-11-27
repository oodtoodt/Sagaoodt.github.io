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

const int maxx=1000500;
int n,k;
int a[maxx];
int b[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
map<int,int> m;
int sum = 0;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/pt1/g.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        m.clear();
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
            a[i] = 10000 - (100 - a[i])*(100-a[i]);
        }
        for(int i = 0; i < n; i++)
        {
            m[a[i]]++;
        }
        ans = 0;
        for(map<int,int > ::iterator it = m.begin(); it != m.end(); ++it)
        {
            if(it->second > ans) ans = it->second;
        }
        cnt = 0;
        for(map<int,int > ::iterator it = m.begin(); it != m.end(); ++it)
        {
            if(it->second == ans) b[cnt++] = it->first;
        }
        sort(b,b+cnt);
        printf("Case #%d:\n",++sum);
        if(cnt * ans == n && cnt != 1) printf("Bad Mushroom\n");
        else
        {
            for(int i = 0; i < cnt; i++)
            {
                printf("%d",b[i]);
                if(i == cnt - 1) printf("\n");
                else printf(" ");
            }
        }
    }
    return 0;
}
