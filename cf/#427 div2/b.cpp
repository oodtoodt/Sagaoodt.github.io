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

const int maxx=100005;
int n,m,k;
int a[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int main()
{
#ifdef LOCAL
//    freopen("","r",stdin);
#endif
    scanf("%d",&k);
    getchar();
    int sum = 0;
    char ch;
    while((ch=getchar()) && ch != '\n'&&ch != EOF)
    {
//        ans += 9-ch+'0';
        a[cnt++] = ch - '0';
        sum += ch - '0';
    }
    if(sum >= k) printf("0\n");
    else {
        sort(a,a+cnt);
        for(int i = 0; i < cnt; i++)
        {
            sum += 9-a[i];
            if(sum >= k)
            {
                printf("%d\n",i+1);
                return 0;
            }
        }
    }
    return 0;
}
