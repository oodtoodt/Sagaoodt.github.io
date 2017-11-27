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

const int maxx=1005;
int n,m,k;
//int a[maxx];
int ans = 0,cnt = 0,pos = 0;

struct l
{
    string na;
    double f,s;
}p[maxx];
int cmp(l a,l b)
{
    return a.s < b.s;
}
vector<int> v[maxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Ot 5/b.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        cin>>p[i].na>>p[i].f>>p[i].s;
    }
    sort(p,p+n,cmp);
    for(int i = 0; i < n; i++)
    {
//        printf("%s %.2f %.2f\n",p[i].na,p[i].f,p[i].s);
//        cout<<p[i].na<<p[i].f<<p[i].s<<endl;
    }
    int t;
    double ans = 0;
    double mina = 1e9+7;
    for(int i = 0; i < n; i++)
    {
        ans = p[i].f;
        t = 1;
        v[i].push_back(i);
        for(int j = 0; j < n; j++)
        {
            if(j!=i)
            {
                t++;
                v[i].push_back(j);
                ans += p[j].s;
            }
            if(t == 4)
            {
                if(ans < mina)
                {
                    mina = ans;
                    pos = i;
                }
                break;
            }
        }
    }
    cout<<mina<<endl;
    for(int i = 0; i < 4; i++)
    {
        cout<<p[v[pos][i]].na<<endl;
    }
    return 0;
}
