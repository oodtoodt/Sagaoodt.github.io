#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxx = 100005;
int a[maxx];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/vjudge/njupt DP/2.txt","r",stdin);
#endif
    int n;
    scanf("%d",&n);

    for(int i = 0; i < n; i++)
    {
        memset(a,0,sizeof(a));
        int m;
        scanf("%d",&m);
        for(int j = 0; j < m; j++)
        {
            scanf("%d",&a[j]);
        }
        //      printf("\n");
        int maxsum,sum;
        int temp = 0,posl = 0,posr = 0;
        sum = 0;
        maxsum = -10000;
        for(int j = 0; j < m; j++)
        {
            sum += a[j];
            if(sum > maxsum)
            {
                maxsum = sum;
                posl = temp;
                posr = j;
            }
            if(sum < 0)
            {
                sum = 0;
                temp = j + 1;
            }
//            printf("%d  ",maxsum);
        }
        printf("Case %d:\n",i+1);
        printf("%d %d %d\n",maxsum,posl + 1, posr + 1);
        if(i != n-1)
        {
            printf("\n");
        }
    }
}