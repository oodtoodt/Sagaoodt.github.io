/*
  Id:
  LANG:C++
  problem:
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxx = 1e3;
double f[maxx][maxx];
int n,s;
double sum;

void vr()
{
    memset(f,0,sizeof(f));
    f[1][2]=(1.0/s);
    f[2][2]=1.0/s/s;
//    f[2][3]=f[2][2]*(2/s)+f[1][2]*1.0/(s-1);
    f[2][3]=f[1][2]*1/s;
    f[1][3]=f[1][2]*1/s+f[0][2]*1/(s-0);
//    f[2][4]=f[2][3]*(2/s)+f[1][3]*1.0/(s-1);
//    f[2][4]=f[1][3]*(s-1)/s;
    for(int i = 1; i <= s; i++)
    {
        for(int k = i + 2; k < maxx; k++)
        {
//            f[i][k]=f[i][k-1]*(i*1.0/s)+f[i-1][k]*(1.0/(s-1));
            if(i == s)
            {
                f[i][k]=f[i-1][k-1]*(s-i+1)/s;
            }
            else
            {
                f[i][k]=f[i-1][k-1]*(s-i+1)/s+f[i][k-1]*i/s;
            }
        }
    }

}
void Sumup()
{
    for(int i = s; i < 100; i++)
    {
        sum += f[s][i] * i;
        printf("f[%d][%d] = %f\n",s,i,f[s][i]);
    }
    printf("%.4f",sum * n);
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di6_lesson/1.txt","r",stdin);
#endif
    scanf("%d%d",&n,&s);
    vr();
    Sumup();
    return 0;
}