#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

struct abc
{
    int s, t, l;
};

bool cmp(abc m, abc n)
{
    if (m.t < n.t) return true;
    else if (m.t == n.t){ if (m.s < n.s) return true; else return false;}
    else return false;
}

int main()
{
    abc a[100010];
    int t, i, n, m, f[100010], maxx;
    cin>> t;
    while (t--)
    {
        scanf("%d%d", &n, &m);
        memset(f, 0, sizeof(f));
        for (i = 1; i <= m; i++) {scanf("%d%d%d", &a[i].s, &a[i].t, &a[i].l); f[a[i].t] = max(f[a[i].t], a[i].l);}
        sort(a+1, a+m+1, cmp);
        maxx = 0;
        for (i = 1; i <= m; i++)
        {
            f[a[i].t] = max(f[a[i].t], f[a[i].s]+a[i].l);
            if (f[a[i].t] > maxx) maxx = f[a[i].t];
        }
        cout<< maxx<< endl;
    }
}
