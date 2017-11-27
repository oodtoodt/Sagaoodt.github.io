#include<algorithm>
#include<cstdio>
#include<cmath>

using namespace std;

const int maxx=2005;
typedef long long LL;
int n,m,k;
int a[maxx][maxx];
const int p = 1e9 + 7;

LL qk_pow(LL a, LL b, LL p) {
    LL res = 1;
    while(b) {
        if(b&1) res = (res * a) % p;
        a = (a*a) % p;
        b >>= 1;
    }
    return res;
}

void init()
{
    for(int i = 1; i < 2000; i++)
    {
        int t = 0;
        int q = i;
        for(int j = 1; j <= i; j++)
        {
            if(j == 1) a[i][j] = q--;
            else a[i][j] = (a[i][j-1] * q--) % p;
        }
    }
    for(int i = 1; i < 2000; i++)
    {
//        f[i] = 1;
//        for(int j = 1; j <= i; j++)
        {
//            f[i] *= j;
//            printf("%d\n",f[i]);
        }
//        cout<<endl;
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/mu8/11.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    init();
    while(T--)
    {
        scanf("%d%d",&n,&m);
        long long ans = 0;
        int l = n,r = m - n;
//        if(r <= 0){
//            p
//        }
//        else{
            for(int i = n; i > 0; i--)
            {
                for(int j = 0; j < i; j++)
                {
//                    int t;
                    if(i-j > m-i) continue;
                    //t = min(m-i,i-j);
                    if(j != 0)
                    {
                        ans += (((a[m][i] * qk_pow(a[i][i],p-2,p) % p)% p) * a[n][i]) % p * ((a[m-i][i-j] * qk_pow(a[i-j][i-j],p-2,p) % p) * a[n][i-j] % p) * 2;
                    }
                    else                   ans += (((a[m][i] * qk_pow(a[i][i],p-2,p) % p)% p) * a[n][i]) % p * ((a[m-i][i-j] * qk_pow(a[i-j][i-j],p-2,p) % p) * a[n][i-j] % p);
                    ans %= p;
                    printf("a[%d][%d]/%d! * a[%d][%d] * a[%d][%d]/%d! * a[%d][%d],%d\n",m,i,i,n,i,m-i,i-j,i-j,n,i-j,ans);
                }
            }
            printf("%lld\n",ans);
//        }
    }
    return 0;
}
