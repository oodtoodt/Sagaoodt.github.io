/*
  Id: oodt
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

const int maxx=10005;
int n,m,k;
char qq;
char b[6] = {"DCBAS"};

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/shuoj/st/2.txt","r",stdin);
#endif
    bool jinji = false;
    while(~scanf("%d",&n))
    {
//        printf("%d\n",n);
        //printf("?");
        jinji = false;
        int t = 0;
        int q = 0;
        int q1 = 0;
        int a = 0;
//        getchar();
        for (int i = 0; i < n; i++) {
            scanf("%d",&k);
//            k = qq-'0';
//            printf("%d-%d ",i,k);
            if(!jinji){
                if(k == 1){
                    t+=10;
                }
                else{
                    if(t>=5) t-=5;
                }
                if(t >= 100)
                {
                    jinji = true;
                }
            }
            else{
//                printf("%d-%d ",i,k);
                if(k == 1) q++;
                else q1++;
                if(q == 2)
                {
                    a++;
                    q = 0;
                    q1 = 0;
                    t = 0;
                    jinji = false;
                }
                if(q1 == 2)
                {
                    q = 0;
                    q1 = 0;
                    t = 60;
                    jinji = false;
                }
            }
        }
        if(a >= 4) a = 4;
        printf("%c\n",b[a]);
    }
    return 0;
}
