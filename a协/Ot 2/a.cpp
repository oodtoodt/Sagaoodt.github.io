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

const int maxx=1000050;
long long n,m,k;
//int a[maxx];
bool stillr[maxx];
bool stillc[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Ot 2/a.txt","r",stdin);
#endif
    freopen("adjustment.in","r",stdin);
    freopen("adjustment.out","w",stdout);
    char ch;
    scanf("%d%d",&n,&m);
    memset(stillr,0,sizeof(stillr));
    memset(stillc,0,sizeof(stillc));
//    for(int i = 0; i < n; i++)
    {
//        for(int j = 0; j < n; j++)
        {
//            a[i][j] = i+j;
        }
    }
    long long sumr = (1+n)*n/2;
    long long sumc = (1+n)*n/2;
    long long cntr = n;
    long long cntc = n;
    for(int i = 0; i < m; i++)
    {
        getchar();
        scanf("%c %d",&ch,&k);
        if(ch == 'R')
        {
            if(!stillr[k])
            {
                sumr -= k;
                cntr --;
                printf("%lld\n",k*cntc+sumc);
//                printf("%d\");
                stillr[k] = true;
            }
            else
            printf("0\n");
        }
        else
        {
            if(!stillc[k])
            {
                printf("%lld\n",k*cntr+sumr);
                cntc --;
                sumc -= k;
                stillc[k] = true;
            }
            else
            printf("0\n");
        }
    }
    return 0;
}
