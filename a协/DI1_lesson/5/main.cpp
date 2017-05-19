/*
  LANG:C++
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
const int maxn = 1000005;
int a[maxn];
struct p{
    int b;
    int id;
}b[maxn];
int c[maxn*2];
int ans;
int n,m,k;

int cmp(p a,p b)

{
    return a.b > b.b;
}

bool judge(int *c)
{
    int day=0;
    int cnt=0;
    for(int i=0;i<ans;i++)
    {
        if(day>c[i])return 0;
        cnt++;
        if(cnt==k)
        {
            cnt=0;
            day++;
        }
    }
    return 1;
}
void ver()
{
    int l = 0;
    int r = m;
    int mid;
    while(l <= r)
    {
        mid = (l + r)/2;
//        memset(c,0,sizeof(c));
        ans = 0;
        for(int i = 0; i < n; i++)
        {
            c[ans++] = a[i];
        }
        for(int i = 0; i < mid; i++)
        {
            c[ans++] = b[i].b;
        }
        sort(c,c+ans);
        if(judge(c))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    l--;
    printf("%d\n",l);
    if(l != -1)
    {
        for(int i = 0; i < l; i++)
        {
            printf("%d ",b[i].id);
        }
        printf("\n");
    }
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/DI1_lesson/5/input.txt","r",stdin);
#endif
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int j = 0; j < m; j++)
    {
        scanf("%d",&b[j].b);
        b[j].id = j + 1;
    }
    sort(a,a+n);
    if(!judge(a))
    {
        printf("-1\n");
        return 0;
    }
    sort(b,b+m,cmp);
    ver();
    return 0;
}