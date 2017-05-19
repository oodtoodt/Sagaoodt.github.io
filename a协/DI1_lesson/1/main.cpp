#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>


using namespace std;

struct node{
    int a,b;
};
int cmp(node a,node b){
    if(a.b!=b.b)
    {
        return a.b<b.b;
    }
    return a.a<b.a;
}
const int maxn = 5 * 100000;
node p[maxn];
int main()
{
    freopen("/Users/ecooodt/Desktop/c++ and acm/DI1_lesson/1/input.txt","r",stdin);
    int n;

    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d",&p[i].a,&p[i].b);
    }
    sort(p,p+n,cmp);
    for(int i = 0; i < n; i++)
    {
//        printf("%d %d\n",p[i].a,p[i].b);
    }
    int temp = p[0].b;
    int t = 1;
    int sum = 1;
    if(n != 1)
    for(;;)
    {
        if(p[t].a > temp)
        {
            temp = p[t].b;
            t++;
            sum++;
        }
        else
        {
            t++;
        }
//        printf("temp = %d\n",temp);
        if(t == n)
        {
            break;
        }
    }
    else
    {
        sum = 1;
    }
    printf("%d\n",sum);
}