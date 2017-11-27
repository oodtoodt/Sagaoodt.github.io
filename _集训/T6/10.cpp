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

const int maxx=100050;
int n,m,k;
//int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
const int INF = 0x3f3f3f3f;

struct A
{
    int s,e;
}a[maxx];
int pre[maxx];
int cmp(A a,A b)
{
    return a.e<b.e;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/T6/10.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        //int a,b;
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d",&a[i].s,&a[i].e);
        }
        sort(a,a+n,cmp);
        for(int i = 0; i < n; i++)
        {
            printf("%d %d\n",a[i].s,a[i].e);
        }
        int t = a[0].e;
        ans = a[0].e-a[0].s;
        cnt = 1;
        int q = 1;
        memset(pre,-1,sizeof(pre));
        pre[0] = 0;
        for(int i = 1; i < n; i++)
        {
            if(t <= a[i].s){
                while(t<=a[i].s) t = a[q++].e;
                pre[i] = q-1;
                cnt++;
            }
        }
        for(int i = n-1; i >= 0; i--)
        {
            
            if(pre[i] == -1) {
                ans += a[i].e-a[i].s;
            }
            else 
        }
        printf("%d %d\n",cnt,ans);
    }
    return 0;
}
