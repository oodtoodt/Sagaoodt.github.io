#include <cstdio>
#include <algorithm>

using namespace std;


const int maxx = 2550;
struct fa{
    int s,e;
    int t;
}dou[maxx];
fa one_way[maxx];
set<int > len;

int cmp(fa a, fa b)
{
    return a.dis < b.dis;
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di4_lesson/3.txt","r",stdin);
#endif
    int F;
    scanf("%d",&F);
    while(F--)
    {
        int n,m,w;
        scanf("%d%d%d",&n,&m,&w);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d",&dou[i].s,&dou[i].e,&dou[i].t);
        }
        for(int i = 0; i < w; i++)
        {
            scanf("%d%d%d",&one_way[i].s,&one_way[i].e,&one_way[i].t);
        }
    }
    
}