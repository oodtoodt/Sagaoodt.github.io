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

const int maxx=1005;
int n,m,k;
int a[maxx];
int b[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int main()
{
#ifdef LOCAL
//    freopen("","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i = 0; i < n-1; i++)
        {
            scanf("%d",&b[i]);
        }
        int cnt = a[0];
        for(int i = 0; i < n; i++)
        {
            if(m * b[i] > cnt){
                printf("No\n");
                break;
            }
            else {
                cnt -= m * b[i];
                cnt += a[i+1];
            }
            if(i == n-1) printf("Yes\n");
        }
    }
    return 0;
}
