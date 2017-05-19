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

const int maxx=10005;
int n,m,k;
char b[maxx];
char a[maxx];
int a_s[27];
int b_s[27];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/wishare/1.txt","r",stdin);
#endif
    scanf("%s",a);
    scanf("%s",b);
    int a_l=strlen(a);
    int b_l=strlen(b);
    memset(a_s,0,sizeof(a_s));
    memset(b_s,0,sizeof(b_s));
    for (int i = 0; i < a_l; i++) {
        a_s[a[i]-'a']++;
    }
    for (int i = 0; i < b_l; i++) {
        b_s[b[i]-'a']++;
    }
    int sum = 0;
    for(int i = 0; i < 26; i++)
    {
        sum += abs(a_s[i] - b_s[i]);
    }
    printf("%d\n",sum);
    return 0;
}
