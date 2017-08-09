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

const int N = 205;
const int maxx=105;
int n,m,k;
char f[maxx][N];
int c[N];
char ci[N];
int a[N],b[N];
int ans = 0,cnt = 0,pos = 0;
//int l = 0,r = 0;

void jiafa(char *as,char *bs)
{
//    int lena,lenb;
    int lena = strlen(as);
    int lenb = strlen(bs);
    int lenc = 1;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for(int i = 0; i < lena; i++)
    {
        a[lena-i] = as[i] - '0';
    }
    for(int i = 0; i < lenb; i++)
    {
        b[lenb-i] = bs[i] - '0';
//        printf("%d",b[lenb-i]);
    }
    int x = 0;
    while(lenc <= lena || lenc <= lenb)
    {
        c[lenc] = a[lenc]+b[lenc]+ x;
        x = c[lenc] /10;
        c[lenc++] %= 10;
    }
    c[lenc] = x;
    if(c[lenc] == 0)
    {
        lenc--;
    }
    int t = 0;
    memset(ci,0,sizeof(ci));
    for(int i = lenc; i>=1; i--)
    {
        ci[t++] = c[i] + '0';
//        printf("%d",c[i]);
//        cout<<c[i];
    }
//    cout<<endl;
}
void chengfa(char *s1,char *s2)
{
    int lena = strlen(s1);
    int lenb = strlen(s2);
    int lenc = 1;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for(int i = 0 ; i < lena; i++)
    {
        a[i] = s1[i] - '0';
    }
    for(int i = 0; i < lenb; i++)
    {
        b[i] = s2[i] - '0';
    }
//    if(pos++<3)
    for(int i = 0; i < lena; i++)
    {
//        printf("%d",b[i]);
    }
//    cout<<endl;
    int t = 0;
    int k = 0;
    for(int j = lenb - 1; j >= 0; j--)
    {
        t = k;
        for(int i = lena - 1; i >= 0; i--)
        {
            c[t] += a[i] * b[j];
            t++;
        }
        k++;
        cnt = t;
    }
    for(int i = 0; i < cnt; i++)
    {
//        c[i+1] += c[i] / 10;
//        c[i] %= 10;
        while(c[i] >= 10)
        {
            c[i+1] ++;
            c[i] -= 10;
        }
    }
    if(c[cnt] == 0) cnt--;
    int p = 0;
    for(int i = N-1; i > 0; i--)
    {
        if(c[i] != 0){
            p = i;
            break;
        }
    }
    t = 0;
    memset(ci,0,sizeof(ci));
//    printf("%d\n",cnt);
    for(int i = cnt; i >= 0; i--)
    {
        ci[t++] = c[i] + '0';
//        printf("%d",c[i]);
    }
//    cout<<endl;
}

void init()
{
    f[0][0] = '1';
    f[1][0] = '1';
    f[2][0] = '2';
    char q[2] = "5";
    chengfa(f[2],q);
    chengfa(ci,f[2]);
//    printf("%s\n",ci);
    for(int i = 3; i < maxx; i++)
    {
        for(int j = 0; j < i/2; j++)
        {
            char q[2] = "2";
            chengfa(f[i-j-1],f[j]);
//            if(i == 3) printf("%s\n",ci);
            chengfa(ci,q);
//            if(i == 3) printf("%s\n",ci);
            jiafa(ci,f[i]);
//            if(i <= 10) printf("f[%d] = %s\n",i,ci);
            strcpy(f[i],ci);
//            f[i] += f[i-j-1] * f[j] * 2;
        }
        if(i % 2 == 1)
        {
            chengfa(f[i/2],f[i/2]);
            jiafa(ci,f[i]);
            strcpy(f[i],ci);
//            f[i] += f[i/2] * f[i/2];
        }
    }
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/8/n.txt","r",stdin);
//    freopen("/users/ecooodt/Desktop/c++ and acm/_集训/8/n2.txt","w",stdout);
#endif
    init();
    while(scanf("%d",&n) && n != -1)
    {
        printf("%s\n",f[n]);
    }
//    char a[2] = "2";
//    char b[3] = "99";
//    jiafa(a,b);
    return 0;
}
