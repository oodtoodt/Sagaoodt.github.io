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
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;

const int maxx=100050;
const int maxxx = 1050;
int n,m;
int a[maxx],b[maxx];//a是生命值，b是防御力
int maxa,maxb,maxp;
long long k[maxxx];
int p[maxxx];//k是消耗，p是伤害。
long long ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
long long f[maxx][11];
const int INF = 1e18+7;

void init()
{
    for(int i = 0; i < maxxx; i++)
    {
        for(int j = 0; j <= 10; j++)
        {
            f[i][j] = INF;
            if(i == 0){
                f[i][j] = 0;
            }
        }
    }
    for(int def = 0; def <= maxb; def++)
    {//对于每一种防御力
        for(int xue = 1; xue <= maxa+maxp; xue++)
        {//对于每一种血量
            for(int i = 0; i < m; i++)
            {//对于每一种技能
                if(p[i] > def)
                if(xue - p[i] +def < 0) f[xue][def] = min(f[xue][def],k[i]);
                else
                f[xue][def] = min(f[xue][def],f[xue-p[i]+def][def]+k[i]);
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/baidu/1/3.txt","r",stdin);
#endif
    while(scanf("%d%d",&n,&m) == 2)
    {
        maxp = maxa = maxb = 0;
//        memset(p,0,sizeof(p));
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            maxa = max(a[i],maxa);
            maxb = max(b[i],maxb);
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%lld%d",&k[i],&p[i]);
            maxp = max(maxp,p[i]);
        }
        if(maxp <= maxb) printf("-1\n");
        else{
            init();
            ans = 0;
            for(int i = 0; i < n; i++)
            {
                long long res = INF;
                for(int j = a[i] ; j <= maxp+maxa; j ++) {
                    res = min(res,f[j][b[i]]);
//                printf("%d\n",ans);
                }
                ans += res;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
