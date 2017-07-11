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

using namespace std;

const int maxx=1000005;
long long n,m,k;
char ch[maxx];
long long a[maxx];
long long b[maxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di16/2.txt","r",stdin);
#endif
    scanf("%s",ch);
    int len = strlen(ch);
    scanf("%lld%lld",&n,&m);

    a[0] = (ch[0] - '0' ) % n;
    for(int i = 1; i < len; i++){
        a[i] = (a[i-1]*10 + ch[i] - '0') % n;
    }
    b[len-1] = (ch[len-1] -'0') % m;
    long long p = 1;
    for(int i = len-2; i >= 0; i--){
        p = p * 10 % m;
        b[i] = (b[i+1] + (ch[i] - '0')*p) % m;
    }

    for(int i = 0; i < len-1; i++)
    {
//        printf("%lld,%lld\n",a[i],b[i]);
        if(!a[i] && !b[i+1] && ch[0] != '0' && ch[i+1] != '0'){
            printf("YES\n");
            for(int j = 0; j <= i; j++)
            {
                printf("%c",ch[j]);
            }
            printf("\n");
            for(int j = i+1; j < len; j++)
            {
                printf("%c",ch[j]);
            }
            printf("\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
