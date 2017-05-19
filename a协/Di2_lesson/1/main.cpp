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

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/DI2_lesson/1/input.txt","r",stdin);
#endif
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        if(a < b || (a + b) % 2 != 0 || (a - b) % 2 != 0)
        {
            printf("impossible\n");
            continue;
        }
        else
        {
            printf("%d %d\n",(a+b)/2,(a-b)/2);
        }
    }
}