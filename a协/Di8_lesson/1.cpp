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

const int maxx=200005;
int n,m,k;
int a[maxx];
int b[maxx];
int ans_z,ans;
int maxn = 0;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di8_lesson/1.txt","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    ans_z = 0;
    ans = 0;
    memset(b,0,sizeof(b));
    int temp = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        if(a[i] < 0)
        {
            if(ans_z > 0)            b[ans_z] = temp;
            ans_z++;
            temp = 0;
        }
        else temp++;
    }
    int plo = m - ans_z;
    if(plo < 0)
    {
        printf("-1\n");
        return 0;
    }
    sort(b+1,b+ans_z);
    for(int i = 1; i < ans_z; i++)
    {
        printf("%d",b[i]);
    }
    while(b[t] <= plo)
    {
        plo
    }
    return 0;
}
