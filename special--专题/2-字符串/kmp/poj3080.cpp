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

const int maxx=65;
int n,m,k;
char a[11][maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/2-字符串/kmp/poj3080.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
        {
            scanf("%s",a[i]);
        }
        int len = strlen(a[0]);
        char dna[maxx];
        for(int j = 0; j < len; j++)
        {
            for(int k = j+1; k < len; k++)
            {
                if(k - j >= maxl)
                {
                    int pos = 0;
                    for(int q = 0; q < k-j; q++)
                    {
                        dna[pos++] = a[0][q];
                    }
                }
                for(int i )
            }
        }
        for(int i = 0; i < n; i++)
        {
            if()
        }
    }
    return 0;
}
