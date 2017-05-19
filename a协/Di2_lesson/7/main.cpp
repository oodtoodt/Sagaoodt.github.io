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

int gcd(int a,int b)
{
    return b == 0 ? a:gcd(b,a%b);
}
bool book[10000];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/DI2_lesson/7/input.txt","r",stdin);
#endif
    int a;
    while(scanf("%d",&a) && a != 0)
    {
        memset(book,0,sizeof(book));
        int sum = 0;
        for(int j = 2; j < sqrt(a) + 0.5; j++)
        {
            if(!book[j])
            if(gcd(a,j) > 1)
            {
                int temp = j;
                while(temp <= (sqrt(a) + 0.5) / 2)
                {
                    book[temp] = true;
                    temp += temp;
                }
                if(a % temp == 0)
                sum += a / temp - 1;
                else
                sum += a / temp;
            }
        }
#ifdef LOCAL
        printf("%d ",a);
#endif
        printf("%d\n",sum);
    }
}