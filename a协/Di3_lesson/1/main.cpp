#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxxx = 2000 + 5;
int a[maxxx];
int dp[maxxx];
int b[maxxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di3_lesson/1/1.txt","r",stdin);
#endif
    int k;
    scanf("%d",&k);
    while(k--)
    {
        int s;
        scanf("%d",&s);
        for(int i = 1; i < s + 1; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i = 1; i < s ; i++)
        {
            scanf("%d",&b[i]);
        }
        memset(dp,0,sizeof(dp));
        dp[1] = a[1];//key
        for(int i = 2; i <= s; i++)
        {
            dp[i] = min(dp[i-1] + a[i] , dp[i-2] + b[i-1]);
//            else dp[i+1] = dp[i] + a[i];
        }
//        printf("%d\n",dp[s]);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int h = 8, m = 0, ss;
        ss = dp[s];
        m = ss / 60;ss %= 60;
        h += m / 60;m = m % 60;
        printf("%02d:%02d:%02d",h,m,ss);
        if(h < 12)//fk h,m,scanf("%d",&
        printf(" am\n");
        else
        printf(" pm\n");
    }
}