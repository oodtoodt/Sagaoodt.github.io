#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

const int maxx=50005;
int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

void init()
{
    for(int i = 1;  i < maxx; i++)
    {
        a[i] = i * (i + 1) / 2;
    }
}

int main()
{
#ifdef LOCAL
//    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/tp1/d.txt","r",stdin);
#endif
    while(~scanf("%d",&n))
    {
        init();
        for(int i = 1; i < maxx; i++)
        {
            if(a[i] > n) {
                ans = i-1;
                break;
            }
        }
        int t = n - a[ans];
        if(t == 0){
            for(int i = 0; i < ans; i++) printf(")");
            for(int i = 0; i < ans; i++) printf("(");
        }
        else{
            for(int i = 0; i < t; i++) printf(")");
            printf("(");
            for(int i = 0; i < ans - t + 1; i++) printf(")");
            for(int i = 0; i < ans; i++) printf("(");
        }
        printf("\n");
    }
    return 0;
}
