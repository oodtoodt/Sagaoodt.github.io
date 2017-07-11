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

const int maxx=100005;
int n,m,k;
char a[maxx];
int t[26];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/shuoj/st/3.txt","r",stdin);
#endif
    while(~scanf("%s",a))
    {
        memset(t,0,sizeof(t));
//    printf("%s",a);
        char z[7] = "ilovcs";
        int len = strlen(a);
        for(int i = 0; i < len; i++)
        {
//            if(a[i]<'Z' && a[i] > 'A')
            if(a[i] == z[0] || a[i] == 'I')t[0]++;
            if(a[i] == z[1] || a[i] == 'L')t[1]++;
            if(a[i] == z[2] || a[i] == 'O')t[2]++;
            if(a[i] == z[3] || a[i] == 'V')t[3]++;
            if(a[i] == z[4] || a[i] == 'C')t[4]++;
            if(a[i] == z[5] || a[i] == 'S')t[5]++;
            if(a[i] == 'e' || a[i] == 'E')t[6]++;
        }
        t[6]/=2;
//        int t1 = 0;
        int ans = 11111110;
        for(int i = 0; i < 7; i++)
        {
            ans = min(ans,t[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
