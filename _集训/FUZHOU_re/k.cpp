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
typedef long long LL;

const int maxx=10005;
const int p = 1e9+7;
int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

const int maxn(10005), mod(100003);
int tC[maxn * maxn]; //tC 表示 table of C

inline int loc(int n, int k) // C(n, k)返回在一维数组中的位置
{
    int locate = (1 + (n >> 1)) * (n >> 1); // (n >> 1) 等价于 (n / 2)
    locate += k;
    locate += (n & 1) ? (n + 1) >> 1 : 0; // (n & 1) 判断n是否为奇数
    return locate;
}

inline int C(int n, int k)
{
    if(k > n) return 0;
    k = min(n - k, k);
    return tC[loc(n, k)];
}

void calcC(int n)
{
    for(int i = 0; i < n; i++)
    {
        tC[loc(i, 0)] = 1;
        for(int j = 1, e = i >> 1; j <= e; j++)
        tC[loc(i, j)] = (C(i - 1, j) + C(i - 1, j - 1) ) % p;
    }
}
//int A[maxx];
int f[10005][10005];
void init()
{
    int r = -1;
    a[1] = 0;
    a[2] = 1;
    for(int i = 3; i < 10001;i++)
    {
        a[i] = i * a[i-1] + r;
        r *= -1;
        a[i] = a[i] % p;
    }
    for(int i = i; i < 10; i++)
    {
//        printf("%d ",a[i]);
    }
//    f[3] = 4;
    LL t = 1;
    for(int i = 1; i < 10005; i++)
    {
        for(int j = 1; j < i; j++)
        {
            f[i][j] = (C(i,j) * t * a[i-j]) % p;
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/FUZHOU_re/k.txt","r",stdin);
#endif
    int T;
    init();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
//        LL t = Comb(n,m,p);
//        int k = n-m;
//        ans = 0;
        printf("%d\n",f[n][m] + 1);

    }
    return 0;
}
