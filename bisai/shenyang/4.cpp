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
int a[maxx];
int b[maxx];
int cnt = 0,pos = 0;
int l = 0,r = 0;
int ans[maxx];
int len;

int dis()
{
    ans[1] = a[1];
    len = 1;
    for(int i = 2; i <= n; i++)
    {
        if(a[i] > ans[len])
        ans[++len] = a[i];
        else
        {
            int pos = lower_bound(ans,ans+len,a[i])-ans;
            ans[pos] = a[i];
        }
    }
//    printf("%d\n",len);
    return len;
}
int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/bisai/shenyang/4.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
        }
        int len1 = dis();
        for(int i = n; i >= 1; i--)
        {
            b[n-i+1] = a[i];
        }
//        for(int i = 1; i <=n ;i++) printf("%d ",b[i]);
        //      cout<<endl;
        for(int i = 1; i <= n; i++)
        a[i] = b[i];
        int len2 = dis();
        int res = max(len1,len2);
//        printf("%d\n",n-res);
        if(m >= n -res) printf("A is a magic array.\n");
        else printf("A is not a magic array.\n");
    }
    return 0;
}