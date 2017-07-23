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
char a[maxx];
char b[maxx];
char a_[maxx];
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
int kmpnext[100010];
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
            j = kmpnext[j];
        }
    }
    return 0;
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/FUZHOU_re/b.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(a_,0,sizeof(a_));
        scanf("%s",a);
        scanf("%s",b);
        int len = strlen(a);
        int lenb = strlen(b);
        for(int i = 0; i < len; i++)
        {
            a_[i] = a[len-1-i];
        }
        if(strcmp(b,"0") == 0)
        {
            printf("Alice\n");
            continue;
        }
        if(!kmp_count(b,lenb,a,len) && !kmp_count(b,lenb,a_,len))
        {
            printf("Bob\n");
        }
        else
        printf("Alice\n");
//        printf("%s\n%s\n",a,a_);
    }
    return 0;
}
