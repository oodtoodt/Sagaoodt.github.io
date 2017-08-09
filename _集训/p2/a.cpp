#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>

using namespace std;

const int maxx=10005;
int n,m,k;
int a[26];
const int INF = 0x3f3f3f3f;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/p2/a.txt","r",stdin);
#endif
    scanf("%d",&n);
    getchar();
    char ch;
    for(int i = 0; i < n; i++)
    {
        ch = getchar();
        a[ch-'a']++;
    }
    int ans = 0;
    int t = 0;
    for(int i = 0; i < 26; i++)
    {
//        printf("%d\n",a[i]);
    }
    for(int i = 0; i < 26; i++)
    {
//        printf("%d %d\n",a[i],t);
//        t = max(a[i],t);
        while(a[i] != 0)
        {
            ans ++;
            t = i;
            while(a[t] != 0){
                a[t++]--;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
