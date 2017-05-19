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

long long int gcd(long long int a,long long int b)
{
    return a % b == 0 ? b :gcd(b, a % b);
}
long long int lcm(long long int a,long long int b)
{
    return a / gcd(a, b) *b;
}

int main()
{
    freopen("/Users/ecooodt/Desktop/c++ and acm/tianti/5-1/input.txt","r",stdin);
    int m;
    long long int fenzi_s = 0,fenmu_s = 0;
    scanf("%d",&m);
    bool bo=false;
//    printf("%lld / %lld", fenzi_s, fenmu_s);
    for(int i = 0; i < m ;i++)
    {
        long long int fenzi,fenmu;
        scanf("%lld",&fenzi);
        getchar();
        scanf("%lld",&fenmu);
        if(fenzi == 0 || fenmu == 0)
        {
            continue;
        }
        else if(!bo)
        {
            bo = true;
            fenzi_s = fenzi;
            fenmu_s = fenmu;
            continue;
        }
        long long int gcdd = gcd(fenmu_s, fenzi_s);
        fenmu_s /= gcdd;
        fenzi_s /= gcdd;
//        printf("%lld / %lld", fenzi, fenmu);
        long long int lcmm = lcm(fenmu_s, fenmu);
        fenzi *= lcmm / fenmu;
        fenzi_s *= lcmm / fenmu_s;
        fenzi_s += fenzi;
        if(fenzi_s == 0)
        {
            bo = false;
            continue;
        }
        fenmu_s = lcmm;
        gcdd = gcd(fenmu_s, fenzi_s);
        fenmu_s /= gcdd;
        fenzi_s /= gcdd;
    }
    //printf("%lld / %lld\n", fenzi_s, fenmu_s);

    if(!bo)
    {
        printf("0");
        return 0;
    }

    
    
    long long int temp = fenzi_s / fenmu_s;
    fenzi_s -= temp * fenmu_s;
    if(!temp)
    printf("%lld/%lld",fenzi_s,fenmu_s);
    else if(fenzi_s)    printf("%lld %lld/%lld\n", temp,fenzi_s, fenmu_s);
    else    printf("%lld",temp);

}
