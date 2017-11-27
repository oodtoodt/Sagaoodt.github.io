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
char a[5][2][10];
int v[10];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/bisai/nanning/j.txt","r",stdin);
#endif
    scanf("%d",&n);
    for(int i = 0; i < 5; i++)
    {
        getchar();
        scanf("%s %s",a[i][0],a[i][1]);
    }
    for(int i = 0; i < 5; i++)
    {
        int cnt = 0;
        int q = 1;
        memset(v,0,sizeof(v));
        while(strcmp(a[i][0],a[i][1]))
        {
            if(a[i][0][0] == a[i][1][0]) {
                while(!v[q]) q++;
                swap(a[i][0][0],a[i][0][q++]);
                cnt++;
            }
            else for(int j = 1; j < n; j++)
            if(a[i][0][0] == a[i][1][j]){
                swap(a[i][0][0],a[i][0][j]);
                v[j] = 1;
                cnt++;
                break;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
