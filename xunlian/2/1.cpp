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

const int maxx=10005;
int n,m,k;
int a[maxx];
char ch[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;


void prekmp(char x[],int m,int kmpnext[])
{
    int i,j;
    j = kmpnext[0] = -1;
    i = 0;
    while(i < m)
    {
        while(-1 != j && x[i] != x[j]) j = kmpnext[j];
        if(x[++i] == x[++j]) kmpnext[i] = kmpnext[j];
        else kmpnext[i] = j;
    }
}
int kmpnext[10010];
int kmp_count(char x[],int m,char y[],int n)
{//x是模式串，y是主串。
    int i,j;
    int ans = 0;
    prekmp(x,m,kmpnext);
    i = j = 0;
    while(i < n)
    {
        while(-1 != j && y[i] != x[j]) j = kmpnext[j];
        i++;j++;
        if(j >= m)
        {
            ans++;
            j = kmpnext[j];
        }
    }
    return ans;
}


int main()
{
#ifdef LOCAL
//    freopen("/Users/ecooodt/Desktop/c++ and acm/xunlian/2/1.txt","r",stdin);
#endif
    scanf("%s",ch);
    int n = strlen(ch);
    char b[7] = "Danil";
    char c[7] = "Olya";
    char d[7] = "Slava";
    char e[7] = "Nikita";
    char f[7] = "Ann";
//    for(int i = 0; i < )
    ans += kmp_count(b,strlen(b),ch,n);
    ans += kmp_count(c,strlen(c),ch,n);
    ans += kmp_count(d,strlen(d),ch,n);
    ans += kmp_count(e,strlen(e),ch,n);
    ans += kmp_count(f,strlen(f),ch,n);
    if(ans == 1)
    printf("YES\n");
    else if(ans == 0) printf("NO\n");
    else printf("NO\n");
    return 0;
}
