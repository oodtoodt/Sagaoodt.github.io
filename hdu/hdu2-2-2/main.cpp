#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
using namespace std;
int f[20];
int s[20]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881,13482720};
int fun(int k,int m)
{
    int kill,i,j,n;
    n=2*k;
    kill=1;
    for(i=1;i<=k;i++)
    {
                if(kill==0)
            kill=n;
        else if(kill<=k)
            return 0;
        n--;
    }
    return 1;
}
int main()
{
    int n,m,j,i,t,k;
    while(scanf("%d",&k),k)
    {
        //      for(i=1;i<=14;i++)
        //      {
        //          for(j=1;;j++)
        //          {
        //              if(fun(i,j))
        //              {
        //                  f[i]=j;
        //                  break;
        //              }
        //          }
        //      }
        printf("%d\n",s[k]);
    }
    return 0;
}
