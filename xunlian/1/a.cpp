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
char a[maxx];
char b[maxx];
char c[maxx];
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
            return 1;
            ans++;
            j = kmpnext[j];
        }
    }
    return ans;
}
char d[maxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/xunlian/1/a.txt","r",stdin);
#endif
    int t;
    while(scanf("%d",&t))
    {
        if(t == 0) break;
        scanf("%s",a);
        scanf("%s",b);
        scanf("%s",c);
//        printf("%s %s %s\n",a,b,c);
        int cnt = 0;
        int n = strlen(c);
        int qqq = 26;
        while(qqq--)
        {
            for(int i = 0; i < n; i++)
            {
                c[i] ++;
                if(c[i] > 'Z') c[i] -= 26;
            }
            printf("%s\n",c);
            int k1 = strlen(a);
            int k2 = strlen(b);
            if(kmp_count(a,k1,c,n) && kmp_count(b,k2,c,n))
            {
                cnt++;
                strcmp(d,c);
            }
            if(cnt >= 2) {
                printf("ambiguous\n");
                break;
            }
        }
        if(cnt == 1) printf("%s\n",d);
        if(cnt == 0) printf("impossible\n");
    }
    return 0;
}
