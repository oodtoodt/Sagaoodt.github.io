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

const int maxx=200005;
int n,m,k;
int a[maxx];
int w[maxx];
int ans[maxx] = {0},cnt = 0,pos = 0;
int l = 0,r = 0;

void lis()
{
    ans[1] = a[1];
    int len=1;
    for(int i=2; i < n; ++i){
        if(a[i]>ans[len])
        ans[++len]=a[i];
        else{
            int pos=upper_bound(ans,ans+len,a[i])-ans;
            ans[pos] = a[i];
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/bisai/nanning/l.txt","r",stdin);
#endif
    int i = 1;
    while(~scanf("%d",&a[i]))
    {
        if(a[i] >= 10000) {
            a[i] -= 10000;
            w[i] = 5;
        }
        else if(a[i] >= 0) w[i] = 1;
        else i--;
        i++;
    }
    n = i;
    for(int i = 1; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    for(int i = 1; i < n; i++)
    {
        printf("%d ",w[i]);
    }
    lis();
    return 0;
}
