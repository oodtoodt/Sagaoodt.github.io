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
int m,k;
int a[maxx];
//int b[maxx];

void judge(int n)
{
//    printf("%d ",n);
    int sum = 1;
    for(int i = 2; i < n; i++)
    {
        if(!(n%i))
        {
            sum += i;
//            printf("%d ",i);
        }
    }
    if(sum == n) printf("%5d  PERFECT\n",n);
    else if(sum > n) printf("%5d  ABUNDANT\n",n);
    else printf("%5d  DEFICIENT\n",n);
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di2_lesson/1.txt","r",stdin);
#endif
    bool sta = true;
//    printf("?");
    int ans = 0;
    while(scanf("%d",&m) && m != 0)
    {
        a[ans++] = m;
;
//        printf("?");

    }
    if(sta){sta = false; printf("PERFECTION OUTPUT\n");}
    for(int i = 0 ; i < ans ; i++)
    {
        judge(a[i]);
    }
    printf("END OF OUTPUT\n");
    return 0;
}
