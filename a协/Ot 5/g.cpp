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

const int maxx=100050;
int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

struct ss{
    int sum,p,id;
    bool operator < (const ss &b)const {
        if(sum != b.sum)
        return sum < b.sum;
        else if(p != b.p)
        return p > b.p;
        else return id > b.id;
    }
}team[maxx];
set<ss> s;

void init()
{
    s.clear();
    for(int i = 1 ; i <= n; i++)
    {
        team[i].id = i;
        team[i].sum = 0;
        team[i].p = 0;
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Ot 5/g.txt","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    init();
    for(int i = 0; i < m; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x != 1)
        {
            s.erase(team[x]);
            team[x].sum++;
            team[x].p += y;
            s.insert(team[x]);
        }
        else
        {
            team[x].sum++;
            team[x].p += y;
        }
        cnt = 0;
        for(set<ss>::iterator it = s.begin(); it != s.end(); ++it)
        {
//            printf("%d %d\n",(*s.begin()).id,(*s.begin()).sum);
            if(*s.begin() < team[1]) cnt++;
            else break;
        }
        printf("%d\n",s.size() - cnt);
    }
    return 0;
}
