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
char b[maxx][52];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
char a[1000010];


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
int kmpnext[52];
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
            cnt++;
            return 1;
            j = kmpnext[j];
        }
    }
//    return ans;
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/1/d.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)

    {
        cnt = 0;
        scanf("%d",&n);
        getchar();
        for(int i = 0; i < n; i++)
        {
            scanf("%s",b[i]);
        }
        scanf("%s",a);
        int t = strlen(a);
        for(int i = 0; i < n; i++)
        {
            int m = strlen(b[i]);
            kmp_count(b[i],m,a,t);
        }
        //printf("%s",a);
        printf("%d\n",cnt);
    }
    return 0;
}
