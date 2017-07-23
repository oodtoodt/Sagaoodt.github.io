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

const int maxx=1000050;
int n,m,k;
char a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

const int Maxn = 1000010;
char Ma[Maxn*2];
int Mp[Maxn*2];
void Manacher(char s[],int len)
{
    int l = 0;
    Ma[l++] = '$';
    Ma[l++] = '#';
    for(int i = 0; i < len; i++)
    {
        Ma[l++] = s[i];
        Ma[l++] = '#';
    }
    Ma[l] = 0;
    int mx = 0,id = 0;
    for(int i = 0 ; i < l; i++)
    {
        Mp[i] = mx > i ? min(Mp[id*2-i],mx-i) : 1;
        while(Ma[i + Mp[i]] == Ma[i-Mp[i]]) Mp[i]++;
        if(i + Mp[i] > mx)
        {
            mx = Mp[i] + i;
            id = i;
        }
    }
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/1/c.txt","r",stdin);
#endif
    while(scanf("%s",a) && a[0] != 'E')
    {
//        printf("%s\n",a);
        int len = strlen(a);
        Manacher(a,len);
        ans = 0;
        printf("Case %d: ",++cnt);
        for(int i = 0; i < len*2+2; i++)
        {
            ans = max(ans,Mp[i] - 1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
