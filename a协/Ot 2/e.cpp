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

const int maxx=105;
int n,m,k;
int a[maxx][maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int main()
{
#ifdef LOCAL
//    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Ot 2/e.txt","r",stdin
#endif
    freopen("easy.in","r",stdin);
    freopen("easy.out","w",stdout);
    while(~scanf("%d%d",&n,&m))
    {
        memset(a,-1,sizeof(a));
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&k);
            for(int j = 0; j < k; j++)
            {
                scanf("%d",&a[i][j]);
            }
            cnt = max(cnt,k);
        }
        int sum = 0;
        for(int i = 0; i < cnt && (m != 0); i++)
        {
            for(int j = 0; j < n && (m != 0); j++)
            {
                if(a[j][i] == -1)
                {
                    sum += 50;
                    m--;
                }
                else if(a[j][i] >= sum)
                {
                    sum += a[j][i];
                    m--;
                }
//            printf("%d\n",sum);
            }
        }
        printf("%d\n",sum+m*50);
    }
    return 0;
}
