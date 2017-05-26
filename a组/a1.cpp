/*
  ID: oodt
  PROG:poj1182
  LANG:C++
  照搬题解
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>

using namespace std;

const int maxx=50005;
int n,m,k;
int a[maxx];
int sum;
int father[maxx];
int rak[maxx];

void init(int n)
{
    for(int i = 1; i <= n; i++)
    {
        father[i] = i;//初始时指向自己
    }
    memset(rak,0,sizeof(rak));
}

int find_s(int x)
{
    if(x == father[x]) return x;//自己就是根
    int fx = find_s(father[x]);//寻找并集根
    rak[x] = (rak[x] + rak[father[x]]) % 3;//路径优化
    father[x] = fx;//
    return father[x];//返回根
}

bool un(int x,int y,int pos)
{
    int fx;
    int fy;
    fx = find_s(x);
    fy = find_s(y);
    if (fx == fy)
    {
        if((rak[y] - rak[x] + 3) % 3 != pos)
        {
            return true;
        }
        else return false;
    }
    father[fy] = fx;
    rak[fy] = (rak[x] - rak[y] + 3 + pos) % 3;
    return false;
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/a组/a1.txt","r",stdin);
#endif
    int d,x,y;
    scanf("%d%d",&n,&k);
    init(n);
    for(int i = 0; i < k; i++)
    {
        scanf("%d%d%d",&d,&x,&y);
        if(x > n||y > n|| (x == y && d == 2))
        {
            sum++;
        }
        else if(un(x,y,d-1))
        {
            sum++;
        }
    }
    printf("%d\n",sum);
    return 0;
}
