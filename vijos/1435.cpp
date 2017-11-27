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

const int maxx=10005;
int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

struct Bigint
{
    const static int mod = 10000;
    const static int DLEN = 4;
    int a[600],len;
    Bigint()
        {
            memset(a,0,sizeof(a));
            len = 1;
        }
    Bigint(int v)
        {
            memset(a,0,sizeof(a));
            len = 0;
            do{
                a[len++] = v%mod;
                v /= mod;
            }while(v);
        }
    Bigint(const char s[])
        {
            memset(a,0,sizeof(a));
            int L = strlen(s);
            len = L / DLEN;
            if(L % DLEN) len++;
            int index = 0;
            for(int i = L-1; i >= 0; i -= DLEN)
            {
                int t = 0;
                int k = i - DLEN + 1;
                if(k < 0) k = 0;
                for(int j = k; j <= i; j++)
                t = t*10 + s[j] - '0';
                a[index++] = t;
            }
        }
    Bigint operator + (const Bigint &b)const
        {
            Bigint res;
            res.len = max(len,b.len);
            for(int i = 0; i <= res.len; i++)
            res.a[i] = 0;
            for(int i = 0; i <= res.len; i++)
            {
                res.a[i] += ((i < len)?a[i]:0)+((i < b.len)?b[i]:0);
                res.a[i+1] += res.a[i] / mod;
                res.a[i] %= mod;
            }
            if(res.a[res.len] > 0) res.len ++;
            return res;
        }
    Bigint operator - (const Bigint &b)const
        {
                        Bigint res;
            res.len = max(len,b.len);
            for(int i = 0; i <= res.len; i++)
            res.a[i] = 0;
            for(int i = 0; i <= res.len; i++)
            {
                res.a[i] += ((i < len)?a[i]:0)+((i < b.len)?b[i]:0);
                res.a[i+1] += res.a[i] / mod;
                res.a[i] %= mod;
            }
            if(res.a[res.len] > 0) res.len ++;
            return res;
        }
    Bigint operator * (const Bigint &b)const
        {
            Bigint res;
            for(int i = 0; i < len; i++)
            {
                int up = 0;
                for(int j = 0; j < b.len; j++)
                {
                    int temp = a[i]*b.a[j] + res.a[i+j] + up;
                    res.a[i+j] = temp % mod;
                    up = temp / mod;
                }
                if(up != 0)
                res.a[i+b.len] = up;
            }
            res.len = len + b.len;
            while(res.a[res.len-1] == 0 && res.len > 1) res.len--;
            return res;
        }
    void output()
        {
            printf("%d",a[len-1]);
            for(int i = len-2; i >= 0; i--)
            printf("04d",a[i]);
            printf("\n");
        }
};

void init()
{
    f[1] = 0;
    f[2] = 2;
    f[3] = 4;
    f[4] = 12;
    for(int i = 5 ; i < 1000; i++)
    {
        f[i] = 2*f[n-1]+2*f[n-2]+2*f[n-3]+f[n-4];
    }
}

int main()
{
#ifdef LOCAL
//    freopen("","r",stdin);
#endif
    init();
    scanf("%d",&n);
    
    return 0;
}
