#include <cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int n,m,k;
int ans;

int main()
{
    int T;
    scanf("%d",&T);
    int a,b,c,ab,bc,ac,abc;
    while(T--)
    {
        ans = 0;
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d%d%d%d%d%d",&a,&b,&c,&ab,&bc,&ac,&abc);
//            printf("%d %d %d %d %d %d %d\n",a,b,c,ab,bc,ac,abc);
            if(bc >= abc && ac >= abc && ab >= abc)
            {
                bc -= abc;
                ac -= abc;
                ab -= abc;
            }
            else{
                continue;
            }
//            printf("%d %d %d %d %d %d %d\n",a,b,c,ab,bc,ac,abc);
            if(a >= ac + ab + abc && b >= ab + bc + abc && c >= ac + bc + abc)
            {
                a -= (ac + ab + abc);
                b -= (ab + bc + abc);
                c -= (ac + bc + abc);
                ans = max(ans,a + b + c + ab + bc + ac + abc);
            }
            else{
                continue;
            }
//            printf("%d %d %d %d %d %d %d\n",a,b,c,ab,bc,ac,abc);
        }
//        printf("%d %d %d %d %d %d %d\n",a,b,c,ab,bc,ac,abc);
        printf("%d\n",ans);
    }
    return 0;
}
