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

const int maxx=1050;
int n,m,k;
int a[maxx];
int b[maxx];
int c[maxx*maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
int cmp(int a,int b)
{
    return b < a;
}

int main()
{
#ifdef LOCAL
//    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/tp1/a.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
//    char ch[10];
    int t1;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            c[cnt++] = a[i] * a[j];
        }
    }
    sort(c,c+cnt,cmp);
    int temp = cnt;
    cnt = 0;
    int t;
    for(int i = 0 ; i < temp; i++)
    {
        t = c[i];
//        printf("%d\n",t);
        while(t)
        {
            b[cnt++] = t % 10;
            t /= 10;
        }
        if(cnt == 1){
            printf("%d\n",c[i]);
            return 0;
        }
        for(int q = 1; q < cnt; q++)
        {
//            printf("%d ",b[q]);
            if(b[q] - b[q-1] != -1) {
                cnt = 0;
                break;
            }
            if(q == cnt - 1)
            {
                printf("%d\n",c[i]);
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}
