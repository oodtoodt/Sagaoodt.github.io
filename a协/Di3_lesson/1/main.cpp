#include <cstdio>
#include <algorithm>

using namespace std;

const int maxxx = 2000 + 5;
int p[maxxx];
int dp[maxxx];
int ad[maxxx];

int main()
{
    int k;
    while(scnaf("%d",&k) != 0)
    {
        int s;
        scanf("%d",&s);
        for(int i = 0; i < s; i++)
        {
            scanf("%d",&p[i]);
        }
        for(int i = 0; i < s - 1; i++)
        {
            scanf("%d",&ad[i]);
        }
    }
}