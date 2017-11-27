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

int cnt[10];
char str[100];
int mask[1000];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Ot 3/b.txt","r",stdin);
#endif
    int m;
    while(scanf("%d",&m) == 1)
    {
        memset(mask,0,sizeof(mask));
        for(int i = 0; i < m; i++)
        {
            scanf("%s",str);
            memset(cnt,0,sizeof(cnt));
            for(int j = 0; str[j] ; j++)
            {
                for(int k = 1; k <= 9; k++)
                {
                    if(str[j] == '0' + k)
                    {
                        cnt[k] = 1;
                    }
                }
            }
            int t = 1;
            int ans = 0;
            for(int k = 1; k <= 9; k++)
            {
                ans = ans+t*cnt[k];
                t = t+t;
            }
            mask[ans] = 1;
        }
        int res = 0;
        for(int i = 0;  i< 512; i++)
        {
            if(mask[i] == 1) res++;
        }
        printf("%d\n",res);
    }
    return 0;
}
