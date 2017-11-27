#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
    int t, ii, i, j, r, s, n, maxx, minn, p, q, x, y;
    bool f[1010][1010];
    scanf("%d", &t);
    for (ii = 1; ii <= t; ii++)
    {
        scanf("%d%d", &r, &s);
        scanf("%d", &n);
        memset(f, true, sizeof(f));
        for (i = 1; i <= n; i++)
        {
            scanf("%d%d", &x, &y);
            f[x+1][y+1] = false;
        }
        f[0][0] = false; f[r+1][s+1] = false; f[0][s+1] = false; f[r+1][0] = false;
        maxx = 0; minn = 0;
        for (i = 1; i <= r; i++) {f[i][0] = false; f[i][s+1] = false;}
        for (i = 1; i <= s; i++) {f[0][i] = false; f[r+1][i] = false;}
        for (i = 1; i <= r; i++)
        {
            p = -1; q = -1;
            for (j = 1; j <= s; j++)
            {
                if (f[i][j] && p != j-1) {p = j; maxx++;}
                if ((!f[i][j-1] && !f[i][j+1] && f[i][j]) || (f[i][j-1] && f[i][j] && q != j-1)) {q = j; minn++;}
            }
        }
        printf("Case #%d: %d %d\n", ii, maxx, minn);
    }
    return 0;
}