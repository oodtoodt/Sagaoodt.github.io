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

const int maxx=105;
int n,m,k;
int num[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/p1/i.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--){
        memset(num,-1,sizeof(num));
        scanf("%d%d",&n,&m);
//        num[1] = 100;
//        num[2] = 100;
        int a,b;
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d",&a,&b);
            num[a] = b;
        }
        if(num[1] == -1) num[1] = 100;
        if(num[2] == -1) num[2] = num[1];
        int sum = 0;
        if(num[n] == -1) num[n] = 0;
        for(int i = n; i > 2; i--)
        {
            if(num[i-1] == -1 && num[i] != -1) num[i-1] = num[i];
        }
        for(int i = 1; i <= n; i++)
        {
            sum += num[i];
        }
        int t = num[1] + num[2];
        if(t!=0){
            int d = gcd(t,sum);
            t /= d,sum /= d;
            printf("%d/%d\n",t,sum);
        }
        else printf("0/1\n");
//        else printf("0/%d\n",sum);
    }
    return 0;
}
