#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<set>

using namespace std;

const int maxx=105;
int n,m[maxx],k;
int a[maxx][maxx];
int ans = 0,cnt = 0,pos = 0;
const int INF = 0x3f3f3f3f;
set<int > data;
int minn[maxx];
int cost[maxx][maxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/T4/j.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        data.clear();
        scanf("%d",&n);
        for(int i = 0; i < n; i++) minn[i] = INF;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&m[i]);
            for(int j = 0; j < m[i]; j++)
            {
                scanf("%d%d",&cost[i][j],&a[i][j]);
                data.insert(cost[i][j]);
            }
        }
        int t = 0;
        double ans = 0;
        for(set<int>::iterator it = data.begin(); it != data.end(); ++it)
        {
            t = 0;
            for(int i = 0; i < n; i++)
            {
                minn[i] = INF;
            }
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m[i]; j++)
                {
                    if(cost[i][j] >= *it && a[i][j] < minn[i])
                    {
                        minn[i] = a[i][j];
                    }
                }
                t += minn[i];
            }
            ans = max(ans,*it*1.0/t);
//            printf("%d,%d,%.3f\n",*it,t,ans);
        }
        printf("%.3f\n",ans);
    }
    return 0;
}
