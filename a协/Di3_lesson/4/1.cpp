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

const int maxx=105;
int n,m,k;
char a[maxx];
int d[maxx][maxx];

bool match(char a,char b)
{
    if((a == '(' && b == ')') || (a == '[' && b == ']'))
    return true;
    else
    return false;
}

void dp()
{
    for(int i = 0; i < n; i++)
    {
        d[i+1][i] = 0;
        d[i][i] = 1;
    }
    for(int i = n-2; i >= 0; i--)
    {
        for(int j = i+1; j < n; j++)
        {
            d[i][j] = n;
            if(match(a[i],a[j]))
            {
                d[i][j] = min (d[i][j], d[i+1][j-1]);
            }
            for(int k = i; k < j; k++)
            {
                d[i][j] = min(d[i][j],d[i][k] + d[k+1][j]);
            }
        }
    }
}
void print(int i, int j)
{
    if(i > j) return ;
    if(i == j)
    {
        if(a[i] =='(' || a[j] == ')')
        {
            printf("()");
        }
        else
        {
            printf("[]");
        }
        return ;
    }
    int ans = d[i][j];
    if(match(a[i],a[j]) && ans == d[i+1][j-1])
    {
        printf("%c",a[i]);
        print(i+1,j-1);
        printf("%c",a[j]);
        return ;
    }
    for(int k = i; k < j; k++)
    {
        if(ans ==d[i][k] + d[k+1][j])
        {
            print(i,k);
            print(k+1,j);
            return;
        }
    }
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di3_lesson/4/1.txt","r",stdin);
#endif
    scanf("%d",&m);
    getchar();
    for(int i = 0; i < m; i++)
    {
        getchar();
        fgets(a,104,stdin);
//        gets(a);
        n = strlen(a)-1;
        a[n] = '\0';
//        printf("%d ",n);
        if( n == 0)
        {
            printf("\n\n");
            continue;
        }
        dp();
        print(0,n-1);
        if( i == m-1)
        printf("\n");
        else
        printf("\n\n");
//        printf("%s\n",a);

    }
    return 0;
}
