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
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

const double eps = 1e-8;
int sgn(double x)
{
    if(fabs(x) < eps)return 0;
    if(x < 0)return -1;
    else return 1;
}
struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
    {
        x = _x;y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x - b.x,y - b.y);
    }
    double operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
    double operator *(const Point &b)const
    {
        return x*b.x + y*b.y;
    }
}p[maxx];
struct Line
{
    Point s,e;
    int i,j;
    Line(){}
    Line(Point _s,Point _e,int a,int b)
    {
        s = _s;e = _e;
        i = a,j = b;
    }
};
//判断线段相交
bool inter(Line l1,Line l2)
{
    return 
        max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
        max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
        max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
        max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
        sgn((l2.s-l1.s)^(l1.e-l1.s))*sgn((l2.e-l1.s)^(l1.e-l1.s)) <= 0 &&
        sgn((l1.s-l2.s)^(l2.e-l2.s))*sgn((l1.e-l2.s)^(l2.e-l2.s)) <= 0;
}
const int MAXN = 100010;
Line line[MAXN];
bool flag[MAXN];

void check()
{
    for(int i = 0; i < cnt; i++)
    {
        for(int j = i+1; j < cnt; j++)
        {
            if(inter(line[i],line[j]) && line[i].i != line[j].i && line[i].j!= line[j].j)
            {
                l = i,r = j;
                return ;
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/bisai/peking/5.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        cnt = 0;
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            p[i] = Point(x,y);
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                line[cnt++] = Line(p[i],p[j],i,j);
            }
        }
        l = 0, r = 0;
        check();
        if((!l)&&(!r)){
            printf("NO\n");
        }
        else {
            printf("%d,%d\n",l,r);
            printf("YES\n");
            for(int i = 0; i < n; i++)
            {
                if(i==line[r].i || i == line[r].j) printf("B");
                else printf("A");
            }
            printf("\n");
        }
    }
    return 0;
}
