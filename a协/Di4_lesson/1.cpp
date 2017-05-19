#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;


const int maxx = 100050;
struct ro{
    int a,b;
    int dis;
}road[maxx];
set<int > len;

int cmp(ro a, ro b)
{
    return a.dis < b.dis;
}


int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/Di4_lesson/1.txt","r",stdin);
#endif
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d",&road[i].a,&road[i].b,&road[i].dis);
    }
    if(k == 0)
    {
        printf("-1\n");
        return 0;
    }
    for(int i = 0; i < k; i++)
    {
        int p;
        scanf("%d",&p);
        len.insert(p);
    }
    sort(road,road+m,cmp);
#ifdef LOCAL
    for(int i = 0; i < m; i++)
    {
        printf("%d %d %d\n",road[i].a,road[i].b,road[i].dis);
    }
#endif
    for(int i = 0; i < m; i++)
    {
        if((len.count(road[i].a) && !len.count(road[i].b))||(len.count(road[i].b) && !len.count(road[i].a)))
        {
            printf("%d\n",road[i].dis);
            return 0;
        }
    }
    printf("-1\n");
}