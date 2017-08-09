#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>

using namespace std;

const int maxx=10005;
int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/T4/f.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
//        if(k == 2) k = 3;
        int t,cha;
        int a,b;
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d",&a,&b);
            if(k == 1)
            {
                if(a & 1 && b & 1) printf("Bob\n");
                else printf("Alice\n");
            }
            else{
                int ti = 2 * (k + 1);
                if(a > b) cha = a-b,t = b % ti;
                else cha = b-a,t = a % ti;
                if(t == k + 1 || t == (k + 1) * 2) printf("Alice\n");
                else if(!(cha & 1)){//偶
                        if(t / (k+1)  == 0)
                        {
                            printf("Bob\n");
                        }
                        else {
                            printf("Alice\n");
                        }
                }
                else{
                    if(t / (k + 1) != 0)
                    {
                        printf("Bob\n");
                    }
                    else
                    {
//                        printf("%d %d %d\n",cha,t,k);
                        printf("Alice\n");
                    }
                }
            }

        }
    }
    return 0;
}
