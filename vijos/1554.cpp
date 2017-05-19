/*
  ID: oodt
  PROG:1554
  LANG:C++
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>

using namespace std;

const int maxx=200005;
long long int m;
int n;
int a[maxx];
bool fk,fk1=0;

void change(long long int T)
{
    while(T--)
    {
        if(a[1] == 0)
        {
            if(a[2] == a[2*n])
            {
                fk1 = 1;
            }
            else fk1 = 0;
            fk = true;
        }
        if(a[2*n] == 0)
        {
            if(a[2*n-1] == a[1])
            {
                fk1=true;
            }
            else fk1 = 0;
            fk = false;
        }
        for(int i = 2 ; i < 2*n; i++)
        {
            if(a[i-1] == a[i+1] && a[i-1]!=0)
            {
                a[i] = 1;
                a[i-1] = 0;
            }
            else if(a[i-1]!=0 && a[i+1]!=0)
            {
                a[i] = 2;
                a[i-1] = 0;
            }
        }
        if(fk)
        {
            if(fk1)
            {
                a[1] = 1;
            }
            else a[1] = 2;
            a[2*n] = 0;
        }
        else
        {
            if(fk1)
            {
                a[2*n] = 1;
            }
            else a[2*n] = 2;
            a[1] = 0;
            a[2*n-1] = 0;
        }
        for(int i = 1; i < 2*n+1; i++)
        {
            printf("%d",a[i]);
            if(i!=2*n)
            {
                printf(" ");
            }
            else
            cout<<endl;
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/vijos/1554.txt","r",stdin);
#endif
    memset(a,0,sizeof(a));
    scanf("%d %lld",&n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&a[2*i-1]);
    }
    change(m);
    for(int i = 1; i < 2*n+1; i++)
    {
        printf("%d",a[i]);
        if(i!=2*n)
        {
            printf(" ");
        }
        else
        cout<<endl;
    }
    return 0;
}