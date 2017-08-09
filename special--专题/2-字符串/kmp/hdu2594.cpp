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

const int maxx=50005;
int n,m,k;
char a[maxx*2],b[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int kmpnext[maxx*2];
void getnext(char s[],int len)
{
    int i,j;
    j = kmpnext[0] = -1;
    i = 0;
    while(i < len)
    {
        if(j == -1 || s[i] == s[j]){
            kmpnext[++i] = ++j;
        }
        else{
            j = kmpnext[j];
        }
    }
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/2-字符串/kmp/hdu2594.txt","r",stdin);
#endif
    while(~scanf("%s%s",a,b))
    {
//        int la,lb;
        int la = strlen(a);
        int lb = strlen(b);
        strcat(a,b);
        int len = strlen(a);
//        printf("%d\n",len);
        getnext(a,len);
//        for(int i = 0; i <= len; i++)
//        {
//            printf("%d ",kmpnext[i]);
//        }
        int t =  kmpnext[len];
        while(t > la || t > lb)
        {
            t = kmpnext[t];
        }
        for(int i = 0 ; i < t; i++)
        {
            printf("%c",a[i]);
            if(i == t-1) printf(" ");
        }
        printf("%d\n",t);
    }
    return 0;
}
