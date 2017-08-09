//nupt2017team05
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#define mm 1000000007
using namespace std;
long long n, i, j, maxl, l, k, a[30][100010], b[30], tt, ttt;
long long ans = 0, ans2;
int t=0;
char s[100010];
bool ss[30];
void cmp()
{
    long long i, j, maxi = 0, maxx = 0;;
    bool bb = true;
    for (i = 1; i <= 26; i++)
        if (maxi < a[i][0] && !b[i]) {maxi = a[i][0]; maxx = i;}
    for (i = 1; i <= 26; i++)
    {
        if (a[i][0] == maxi && maxx != i && !b[i])
        {
            j = maxi;
            while (a[maxx][j] == a[i][j] && j >= 1) j--;
            if (j != 0)
                if (a[i][j] > a[maxx][j])
                {
                    maxx = i;
                    bb = true;
                }
                else bb = true;
            else
                bb = false;
        }
    }
    if (!bb)
    {
        for (i = 1; i <= 26; i++)
        {
            if (a[i][0] == maxi && !b[i])
            {
                j = maxi;
                while (a[maxx][j] == a[i][j] && j >= 1) j--;
                if (j == 0) b[i] = tt--;
            }
        }
    }
    else b[maxx] = tt--;
}

int main()
{
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/mu1/1.txt","r",stdin);
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/mu1/2.txt","w",stdout);
    while (scanf("%lld", &n) != EOF)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(ss, true, sizeof(ss));
        maxl = 0; tt = 25; ttt = 0; ans = 0;
        //getchar();
        for (i = 1; i <= n; i++)
        {
            //gets(s);
            scanf("%s",s);
            l = strlen(s);
            if (l > maxl) maxl = l;
            for (j = l-1; j >= 0; j--)
                a[s[j]-'a'+1][l-j]++;
            if (l > 1) ss[s[0]-'a'+1] = false;
        }
        for (i = 1; i <= 26; i++)
        {
            for (j=1;j<=100000;j++){
                a[i][j+1]=a[i][j+1]+a[i][j]/26;
                a[i][j]%=26;
            }
            j=100000;
            while (a[i][j]!=0&&j>1){
                j--;
            }
            a[i][0]=j;
            /*for (j = 1; j <= maxl; j++)
            {
                k = j;
                while (a[i][k] >= 26)
                {
                    a[i][k+1] += a[i][k] / 26;
                    a[i][k] %= 26;
                    k++;
                }
                if (a[i][k] != 0 && k > a[i][0]) a[i][0] = k;
            }*/
            if (a[i][0] != 0) ttt++;
        }
        while (tt >= 26-ttt) cmp();
        if (ttt == 26)
        {
            i = 1;
            while (b[i] != 0) i++;
            ttt = 1;
            while (b[i] == 0 && !ss[i])
            {
                j = 1;
                while (b[j] != ttt) j++;
                ttt++;
                swap(b[j], b[i]);
                i = j;
            }
        }
        for (i = maxl; i >= 1; i--)
        {
            ans *= 26;
            ans = ans % mm;
            ans = (ans+mm) % mm;
            for (j = 1; j <= 26; j++)
            {
                ans += (a[j][i] * b[j]) % mm;
                ans %= mm;
                ans = (ans+mm) % mm;
            }
        }
        printf("Case #%d: %lld\n", ++t, ans);
    }
    return 0;
}