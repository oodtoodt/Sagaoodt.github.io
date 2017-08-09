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
#include <sstream>

using namespace std;

const int maxx=10005;
int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/codechef/jl2017/1.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        string s;
        getline(cin,s);
        int i = 0;
        stringstream line(s);
        while(line>>a[i])
        {
            i++;
        }
        int t = i-1;
        bool flag = true;
        ans = 0;
        for(int i = 0 ; i <= t; i++)
        {
            if(a[i] == t && flag)
            {
                flag = false;
                continue;
            }
            ans = max(ans,a[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
