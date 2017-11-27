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

const int maxx=10005;
int n,m,k;
//int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Ot 3/b.txt","r",stdin);
#endif
    int t,tc,n;
    char a[10];
    int freq[1005][10];
    while(~scanf("%d",&n))
    {
        memset(freq,0,sizeof(freq));
        for(int i = 0; i < n; i++)
        {
            scanf("%s",a);
            for(int j = 0; j < strlen(a); j++)
            {
                freq[i][a[j]-'0'] = 1;
            }
        }
        int cnt =1;
        for(int i = 1; i < n; i++)
        {
            bool found = false;
            for(int j = 0; j < i; j++)
            {
                bool mat = true;
                for(int k = 0; k < 10; k++)
                {
                    if(freq[i][k] != freq[j][k])
                    {
                        mat = false;
                        break;
                    }
                }
                if(mat)
                {
                    found = true;
                    break;
                }
            }
            if(!found) cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
