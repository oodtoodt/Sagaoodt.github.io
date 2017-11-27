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
char a[maxx],b[maxx];
char ch[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int kmpnext[10010];
void getnext(const char *s,int m)
{
    int i,j;
    j = kmpnext[0] = -1;
    i = 0;
    while(i != m)
    {
        if(j == -1 || s[i] == s[j])
        kmpnext[++i] = ++j;
        else
        j = kmpnext[j];
    }
}

int num[maxx];
const int p = 1e9 + 7;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/ccpc_net/4.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        memset(num,0,sizeof(num));
        cnt = 0;
        scanf("%s%s",a,b);
        int lena = strlen(a);
        int lenb = strlen(b);
        for(int i = 0; i < lenb; i++) ch[cnt++] = b[lenb - i - 1];
        ch[cnt++] = '$';
        for(int i = 0; i < lena; i++) ch[cnt++] = a[lena - i - 1];
        getnext(ch,lena+lenb+1);
        printf("%s\n",ch);
        int tt = 0;
        for(int i = lenb+1; i <= lena+lenb+1; i++) {
            tt = max(tt,kmpnext[i]);
        }
        for(int i = 0; i < lena+lenb+1; i++)
        {
            printf("%d ",kmpnext[i]);
        }
        printf("\n");
        for(int i = lenb+1; i <= lena+lenb+1; i++)
        {
            num[kmpnext[i]] ++;
        }
        int t = 0;
        int sum[maxx];
//        bool flag = false;
        for(int i = 1; i < lenb + 1; i++)
        {
            if(sum[kmpnext[i]] == 0)
            if(kmpnext[i] != 0) sum[kmpnext[i]] = i-1;
        }
        for(int i = 1; i <= tt; i++)
        {
            printf("%d ",num[i]);
        }
        printf("\n");
//        num[1] += sum;
        for(int i = tt-1; i > 0; i--)
        {
            num[i] += sum[i];
        }
//        else num[1]+=sum;
        ans = 0;
        for(int i = 1; i <= tt; i++)
        {
            ans += (num[i] * i) % p;
            ans %= p;
        }
//        printf("%d\n",ans);
        for(int i = 1; i <= tt; i++)
        {
            printf("%d ",num[i]);
        }
        printf("\n");
    }
    return 0;
}
