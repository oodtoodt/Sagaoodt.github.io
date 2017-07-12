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

const int p = 1000000007;
const int maxx=100005;
int n,m,k;
char a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

LL qk_pow(LL a, LL b, LL p) {
    LL res = 1;
    while(b) {
        if(b&1) res = (res * a) % p;
        a = (a*a) % p;
        b >>= 1;
    }
    return res;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/1-数论/rsa/cf327c.txt","r",stdin);
#endif
    scanf("%s%d",a,&k);
//    printf("%s,%d",a,k);
    l = strlen(a);
    int ans = 0;
    LL d = qk_pow(2,l,p);
    LL y,z,x;
    for(int i = 0; i < l; i++)
    {
        if(a[i] == '5' || a[i] == '0')
        {
            x = qk_pow(2,i,p);
            cnt += x,cnt %= p;
            //   printf("%lld\n",ans);
        }
    }
    y = qk_pow(d,k,p);
    y = 1-y;
//    y = ((1 - y) % p + p) % p;
//    z = ((1-d)% p + p) % p;
//    printf("%d\n",z);
    z = qk_pow(1-d,p-2,p);
    ans = (cnt * ((y * z) % p)) % p;
    printf("%d\n",ans);
    return 0;
}
