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

const int maxx=10005;
int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
const int INF = 0x3f3f3f3f;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/p2/e.txt","r",stdin);
#endif
    char ch;
    int a1 = 0, a2 = 0,t = INF;
    ans = 1;
    while((ch = getchar()) && ch != EOF)
    {
//        printf(".");
        printf("%d\n",ans);
        if(t == INF){
            t = 0;
        }
        else if(t == 0)
        {
            if(ch == '1')
            {
                t = 1;
            }
            else t = -1;
        }
        else if(t == 1)
        {
            if(ch == '1') continue;
            else {
                t = -1;
                ans += 2;
            }
        }
        else if(t == -1)
        {
            if(ch == '0') continue;
            else{
                t = 0;
                ans += 2;
            }
        }
    }
    if(ans == 1 && t == 1) ans += 2;
    printf("%d\n",ans);
    return 0;
}
