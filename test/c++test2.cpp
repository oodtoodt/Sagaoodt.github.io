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

const int maxx=10050;
int n,m,k;
int a[maxx];
long long ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
vector<int> v (maxx);

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/test/test4.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    v.clear();
    for(int i = 0; i < n; i++)
    {
        if(a[i] == 0) {
            v.clear();
            printf("0\n");
            continue;
        }
        else{
            if(a[i] < 128){
                v.push_back(a[i]);
                int m = v.size();
//                printf("m=%d ",m);
                long long t = 1;
                for(int i = 0; i < m; i++)
                {
//                    printf("%d ",v[i]);
                    if(i != m-1)
                    ans += (v[i]-128) * t;
                    else{
                        ans += v[i]*t;
                    }
//                    printf("%lld ",ans);
                    t *= 128;
                }
                if(ans % 2 == 0)
                {
                    ans = ans / 2;
                }
                else{
                    ans = ans / 2;
                    ans = -ans;
                    ans--;
                }
                printf("%lld\n",ans);
                ans = 0;
                v.clear();
            }
            else v.push_back(a[i]);
        }
    }
    return 0;
}
