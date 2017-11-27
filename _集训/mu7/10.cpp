//nupt2017team05
#include<algorithm>
#include<cstdio>
#include<cmath>

using namespace std;

const int maxx=200050;
int n,m,k;
int a[maxx];
int l = 0,r = 0;
int q[32];

void init()
{
    q[0] = 1;
    q[1] = 2;
    for(int i = 2; i < 31; i++)
    {
        q[i] = q[i-1] << 1;
//        printf("%d\n",q[i]);
    }
}

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/mu7/10.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    init();
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i = 0; i < 31; i++)
        {
            if(q[i] > m) {
                l = i-1,r = i;
                break;
            }
        }
//        printf("%d\n",q[l]);
        int t = 1;
        
        for(int i = 1; i <= n; i++)
        {
            printf("%d",a[i]);
            if(i != n) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
