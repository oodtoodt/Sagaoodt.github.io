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

const int maxx=105;
int n,m,k;
char a[maxx][maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;
int sum1 = 0,sum2=0,sum3=0;
bool flag = false;
bool flag1,flag2;

int main()
{
#ifdef LOCAL
//    freopen("/Users/ecooodt/Desktop/c++ and acm/cf/ed26/b.txt","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++)
    {
        getchar();
        for(int j = 0; j < m; j ++)
        {
            scanf("%c",&a[i][j]);
        }
    }
    for(int i = 0 ; i< n-1; i++)
    {
        if(a[i][0] != a[i+1][0]) break;
        if(i == n-2) flag2 =true;
    }
    for(int i = 0; i < m-1; i++)
    {
        if(a[0][i] != a[0][i+1]) break;
        if(i == m-2) flag1 = true;
    }
    if(flag1){
        for(int i = 0; i < n; i++)
        {
            if(a[i][0] == 'R') sum3 ++;
            if(a[i][0] == 'G') sum2 ++;
            if(a[i][0] == 'B') sum1 ++;
            for(int j = 1; j < m; j++)
            {
                if(a[i][j] != a[i][0]) flag = true;
            }
        }
        if(sum1 != sum2 || sum1 != sum3) flag = true;
    }
    else if(flag2)
    {
    for(int j = 0; j < m; j++)
    {
    if(a[0][j] == 'R') sum3 ++;
    if(a[0][j] == 'G') sum2 ++;
    if(a[0][j] == 'B') sum1 ++;
    for(int i = 1; i < n; i++){
    if(a[i][j] != a[0][j]) flag = true;
}
}
    if(sum1 != sum2 || sum1 != sum3) flag = true;
}
    else flag = true;
    if(flag)
    {
        printf("NO\n");
    }
    else printf("YES\n");
    return 0;
}
