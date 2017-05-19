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
#include <map>
#include <vector>
using namespace std;

const int maxx=30005;
int n,m,k;
int a[505][maxx];
map<int ,int > m;

typedef pair<int,int> p;

vector<p> v;
set <int > k;

int solve(int q)
{
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i].first == q)
        {
            for(int i = 0; i < )
        }
    }
}

int main()
{
    memset(a,0,sizeof(a));
#ifdef LOCAL
    freopen("","r",stdin);
#endif
    while(scanf("%d%d",&n,&m)&&n!=0)
    {
        if(m == 0)
        {
            ans = 1;
            continue;
        }
        for(int i = 0 ; i < m ; i++)
        {
            scanf("%d",&k);int t;
            for(int j = 0 ; j < k; j++)
            {
                scanf("%d",&t);
                if(!m.count(t))m[t] = i;
                else
                {
                    v.push_back(i,m[t]);
                }
                a[i][j] = t;
            }
        }
        solve(0);
    }
    return 0;
}
