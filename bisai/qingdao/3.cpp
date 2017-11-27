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
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
char ch[maxx][maxx];


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
    freopen("/Users/ecooodt/Desktop/c++ and acm/bisai/qingdao/3.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        cnt = 0;
        int t = 0;
        getchar();
//        printf("%d\n",n);
        for(int i = 0; i < n; i++)
        {
            scanf("%s",ch[i]);
            int n = strlen(ch[i]);
            cnt = max(cnt,n);
            t = i;
        }
        for(int i = 0; i < n; i++)
        {
            if(i == t) continue;
            if(!kmp_count(ch[i],strlen(ch[i]),ch[t],cnt))
            {
                printf("No\n");
                break;
            }
            if(i == n-1) printf("%s\n",ch[t]);
        }
    }
    return 0;
}
